#include "result.h"
#include "resource.h"

int result_count;

struct {
    int a;
    int b;
    int c;
    int p;
} rate;

void result_init() {
    for (int i=0; i<heart_gif->frames_count; ++i) {
        printf("frame[%2d].duration = %d\n", i, heart_gif->frames[i].duration);
    }

    result_count = 0;
    rate.a = 3;
    rate.b = 6;
    rate.c = 12;
    rate.p = rate.a * rate.b * rate.c * heart_gif->frames_count;
}

void result_destroy() {}

int result_process(ALLEGRO_EVENT event) {
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        // button 1 is left click
        if (event.mouse.button == 1) {
            al_play_sample_instance(click_se_spi);
            return MSG_GAME_RESTART;
        }
        // button 2 is left click
        if (event.mouse.button == 2) {
            al_play_sample_instance(click_se_spi);
            return MSG_BACK_TO_MENU;
        }
        // button 3 is middle click
        if (event.mouse.button == 3) {
            al_play_sample_instance(click_se_spi);
            return MSG_TERMINATE;
        }
    }

    if (event.type == ALLEGRO_EVENT_TIMER && event.timer.source == scene_timer) {
        result_count = (result_count + 1) % rate.p;
    }

    return MSG_NOPE;
}

void result_draw() {
    al_clear_to_color(al_map_rgb(255, 255, 200));

    int size = 200;

    al_draw_scaled_bitmap(
        algif_get_frame_bitmap(heart_gif, (result_count / rate.a) % heart_gif->frames_count),
        0,
        0,
        heart_gif->width,
        heart_gif->height,
        (WIDTH - size) / 2,
        (HEIGHT - size) / 2 - size,
        size,
        size,
        0);

    al_draw_scaled_bitmap(
        algif_get_frame_bitmap(heart_gif, (result_count / rate.b) % heart_gif->frames_count),
        0,
        0,
        heart_gif->width,
        heart_gif->height,
        (WIDTH - size) / 2,
        (HEIGHT - size) / 2,
        size,
        size,
        0);

    al_draw_scaled_bitmap(
        algif_get_frame_bitmap(heart_gif, (result_count / rate.c) % heart_gif->frames_count),
        0,
        0,
        heart_gif->width,
        heart_gif->height,
        (WIDTH - size) / 2,
        (HEIGHT - size) / 2 + size,
        size,
        size,
        0);
}
