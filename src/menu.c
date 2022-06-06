#include "menu.h"
#include "resource.h"

struct {
    float old_angle;
    float base_angle;
    float angle;
    bool pressed;
} easter_egg;

void menu_init() {
    easter_egg.angle = easter_egg_mode ? (ALLEGRO_PI / 2) : 0.0f;
    easter_egg.pressed = false;
}

void menu_destroy() {}

int menu_process(ALLEGRO_EVENT event) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
            al_play_sample_instance(click_se_spi);
            return MSG_GAME_START;
        } else if (event.keyboard.keycode == ALLEGRO_KEY_S) {
            al_play_sample_instance(click_se_spi);
            return MSG_CHANGE_SETTING;
        }
    }

    // easter egg    
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button == 1
        && ((event.mouse.x - 250)*(event.mouse.x - 250)+(event.mouse.y - 350)*(event.mouse.y - 350)) < 2500) {
        easter_egg.pressed = true;
        easter_egg.old_angle = easter_egg.angle;
        easter_egg.base_angle = atan2f(event.mouse.x - 250, event.mouse.y - 350);
    } else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && event.mouse.button == 1) {
        easter_egg.pressed = false;
        
        const float d_theta = 0.1f;
        if (fabs(cos(easter_egg.angle)) < d_theta) {
            easter_egg_mode = true;
            al_stop_sample_instance(eight_queens_bgm_spi);
            al_play_sample_instance(easter_egg_bgm_spi);
        } else {
            easter_egg_mode = false;
            al_stop_sample_instance(easter_egg_bgm_spi);
            al_play_sample_instance(eight_queens_bgm_spi);
        }
    }

    if (easter_egg.pressed) {
        ALLEGRO_MOUSE_STATE mouse_state;
        al_get_mouse_state(&mouse_state);
        int dx = mouse_state.x - 250;
        int dy = mouse_state.y - 350;
        easter_egg.angle = easter_egg.old_angle + (atan2f(dx, dy) - easter_egg.base_angle);
    }

    return MSG_NOPE;
}

void menu_draw() {
    al_clear_to_color(al_map_rgb(200, 177, 177));
    al_draw_text(pirulen_36, al_map_rgb(0, 0, 0), WIDTH/2, 450, ALLEGRO_ALIGN_CENTER, "This is menu");
    al_draw_rotated_bitmap(infinite_png, 50.0f, 50.0f, 250.0f, 350.0f, -easter_egg.angle, 0);
    al_draw_bitmap(queens_png, 300.0f, 300.0f, 0);
}