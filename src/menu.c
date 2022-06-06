#include "menu.h"
#include "resource.h"

double chess_gif_start_time;

void menu_init() {
    chess_gif_start_time = al_get_time();
}

void menu_destroy() {}

int menu_process(ALLEGRO_EVENT event) {
    // button 1 is left click
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && event.mouse.button == 1) {
        al_play_sample_instance(click_se_spi);
        return MSG_GAME_START;
    } else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && event.mouse.button == 2) {
        al_play_sample_instance(click_se_spi);
        return MSG_CHANGE_SETTING;
    }
    return MSG_NOPE;
}

void menu_draw() {
    al_clear_to_color(al_map_rgb(200, 255, 255));
    al_draw_text(pirulen_36, al_map_rgb(0, 0, 0), WIDTH/2, 450, ALLEGRO_ALIGN_CENTER, "This is menu");
    al_draw_bitmap(algif_get_bitmap(chess_gif, al_get_time() - chess_gif_start_time), (WIDTH - chess_gif->width)/2, 50, 0);
}
