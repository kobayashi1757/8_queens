#include "game.h"
#include "resource.h"

enum { PLAYER_IDLE, PLAYER_ROLL };
enum { DIR_LEFT, DIR_RIGHT };

struct {
    int x;
    int y;
    int ox;
    int oy;
    int frame;
    int state;
    int dir;
} player;

void game_init() {
    player.x = player.y = player.frame = 0;
    player.state = PLAYER_IDLE;
    player.dir = DIR_RIGHT;
}

void game_destroy() {}

int game_process(ALLEGRO_EVENT event) {
    // button 1 is left click
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && event.mouse.button == 1) {
        al_play_sample_instance(click_se_spi);
        return MSG_GAME_OVER;
    }

    if (event.type == ALLEGRO_EVENT_KEY_DOWN && player.state == PLAYER_IDLE) {
        player.ox = player.x;
        player.oy = player.y;

        if (event.keyboard.keycode == key_left && player.x > 0) {
            --player.x;
        } else if (event.keyboard.keycode == key_right && player.x < 7) {
            ++player.x;
        } else if (event.keyboard.keycode == key_up && player.y > 0) {
            --player.y;
        } else if (event.keyboard.keycode == key_down && player.y < 7) {
            ++player.y;
        }

        if (player.x != player.ox || player.y != player.oy) {
            al_play_sample_instance(roll_se_spi);
            player.frame = 0;
            player.state = PLAYER_ROLL;
            if (player.x != player.ox) {
                player.dir = (player.x < player.ox) ? DIR_LEFT : DIR_RIGHT;
            }
        }
    }

    // only update frame count when the event is from the scene timer
    // don't update for keyboard event
    if (event.type == ALLEGRO_EVENT_TIMER && event.timer.source == scene_timer) {
        ++player.frame;
        if (player.state == PLAYER_ROLL && player.frame >= 21) {
            player.state = PLAYER_IDLE;
            player.frame = 0;
        }
    }

    return MSG_NOPE;
}

void game_draw() {
    int unit = WIDTH / 8;

    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            al_draw_filled_rectangle(
                i*unit,
                j*unit,
                (i+1)*unit,
                (j+1)*unit,
                (i+j)%2 ? al_map_rgb(245, 227, 205) : al_map_rgb(176, 122, 76));
        }
    }

    if (player.state == PLAYER_IDLE) {
        al_draw_scaled_bitmap(
            archer,
            64.0f*(player.frame / 10 % 4),
            64.0f*5,
            64.0f,
            64.0f,
            player.x*unit,
            player.y*unit,
            unit,
            unit,
            player.dir == DIR_LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0);
    } else {
        al_draw_scaled_bitmap(
            archer,
            64.0f*(player.frame / 3 % 7),
            64.0f*2,
            64.0f,
            64.0f,
            (player.x*(player.frame/21.0f)+player.ox*(1-player.frame/21.0f))*unit,
            (player.y*(player.frame/21.0f)+player.oy*(1-player.frame/21.0f))*unit,
            unit,
            unit,
            player.dir == DIR_LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0);
    }

}

// queens.c
struct {
    int board[8][8];
    int counter; // ~300 到 0 扣血
} queens;

// timer event -> --counter;
void queens_process(ALLEGRO_EVENT);

// tell if counter == 0
bool queens_attack();

// player.c
struct {
    int life;
} player;

void player_process(ALLEGRO_EVENT);

void rand_queens(int n) {}
