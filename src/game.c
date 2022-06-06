#include "game.h"
#include "resource.h"

enum { PLAYER_IDLE, PLAYER_ROLL };
enum { DIR_LEFT, DIR_RIGHT };

struct {
    float x;
    float y;
    float ox;
    float oy;
    int frame;
    int state;
    int dir;
    int HP; // 血量
} player;

double j_idle_begin_time;
int heart_size;
int number;

void game_init() {
    player.HP = 3;
    player.x = 0.4; // 放大要調整
    player.y = 2.9; // 放大要調整
    player.frame = 0;
    player.state = PLAYER_IDLE;
    player.dir = DIR_RIGHT;
    j_idle_begin_time = al_get_time();
    
}

void game_destroy() {}

int game_process(ALLEGRO_EVENT event) {
    // button 1 is left click
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && event.mouse.button == 1) {
        return MSG_GAME_OVER;
    }

    if (event.type == ALLEGRO_EVENT_KEY_DOWN && player.state == PLAYER_IDLE) {
        player.ox = player.x;
        player.oy = player.y;

        // 測試血量顯示
        if( event.keyboard.keycode == ALLEGRO_KEY_W && player.HP > 0 ){
            --player.HP;
        }
        if (event.keyboard.keycode == key_left && player.x > 1.3) {
            --player.x;
        } else if (event.keyboard.keycode == key_right && player.x < 7) {
            ++player.x;
        } else if (event.keyboard.keycode == key_up && player.y > 3.0) {
            --player.y;
        } else if (event.keyboard.keycode == key_down && player.y < 9) {
            ++player.y;
        }

        if (player.x != player.ox || player.y != player.oy) {
            player.frame = 0; // 不懂
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
    float unit = WIDTH / 8-8.8; // 如果調視窗大小，要重調
    al_draw_bitmap(GBI, 0, 0, 0); // 這個是背景buffer
    // 學長的手繪棋盤
    // for (int i=0; i<8; ++i) {
    //     for (int j=0; j<8; ++j) {
    //         al_draw_filled_rectangle(
    //             i*unit,
    //             j*unit,
    //             (i+1)*unit,
    //             (j+1)*unit,
    //             (i+j)%2 ? al_map_rgb(245, 227, 205) : al_map_rgb(176, 122, 76));
    //     }
    // }
    

    if (player.state == PLAYER_IDLE) {
        al_draw_bitmap(algif_get_bitmap(JI_gif, al_get_time() - j_idle_begin_time), player.x*unit,player.y*unit,player.dir == DIR_LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0 );
        // 學長的幀數idle
        // al_draw_tinted_scaled_rotated_bitmap_region(
        //     archer,
        //     64.0f*(player.frame / 10 % 4),
        //     64.0f*5,
        //     64.0f,
        //     64.0f,
        //     al_map_rgba_f(1.0f, 1.0f, 1.0f, 1.0f),
        //     0.0f,
        //     0.0f,
        //     player.x*unit,
        //     player.y*unit,
        //     unit/64.0f,
        //     unit/64.0f,
        //     0.0f,
        //     player.dir == DIR_LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0);
    } else {
        al_draw_bitmap(algif_get_bitmap(JJ_gif, al_get_time() - j_idle_begin_time), (player.x*(player.frame/21.0f)+player.ox*(1-player.frame/21.0f))*unit,(player.y*(player.frame/21.0f)+player.oy*(1-player.frame/21.0f))*unit, player.dir == DIR_LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0);
        // 學長的幀數移動
        // al_draw_tinted_scaled_rotated_bitmap_region(
        //     archer,
        //     64.0f*(player.frame / 3 % 7),
        //     64.0f*2,
        //     64.0f,
        //     64.0f,
        //     al_map_rgba_f(1.0f, 1.0f, 1.0f, 1.0f),
        //     0.0f,
        //     0.0f,
        //     (player.x*(player.frame/21.0f)+player.ox*(1-player.frame/21.0f))*unit, 這個是目標x
        //     (player.y*(player.frame/21.0f)+player.oy*(1-player.frame/21.0f))*unit, 這個是目標y
        //     unit/64.0f,
        //     unit/64.0f,
        //     0.0f,
        //     player.dir == DIR_LEFT ? ALLEGRO_FLIP_HORIZONTAL : 0); 這個是左右判定
    }
    heart_draw();
    score_draw();
}

void heart_draw(){
    heart_size = 60;
    if(player.HP >= 1){
        al_draw_scaled_bitmap(heart, 0, 0, 22, 23, 50, 50, heart_size, heart_size, 0);
    }
    if(player.HP >= 2){
        al_draw_scaled_bitmap(heart, 0,0 , 22, 23, 120, 50, heart_size, heart_size, 0);
    }
    if(player.HP >= 3){
        al_draw_scaled_bitmap(heart, 0,0 , 22, 23, 190, 50, heart_size, heart_size, 0);
    }
}

void score_draw(){
    number = al_get_time() - j_idle_begin_time;
    // number = number*10;
    al_draw_textf(score, al_map_rgb(255,255,255), 400,55, ALLEGRO_ALIGN_LEFT,  "Score: %3d",number);

}