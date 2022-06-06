#include "result.h"
#include "resource.h"

void result_init() {}

void result_destroy() {}

int result_process(ALLEGRO_EVENT event) {
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        // button 1 is left click
        if (event.mouse.button == 1) {
            return MSG_GAME_RESTART;
        }
        // button 2 is left click
        if (event.mouse.button == 2) {
            return MSG_BACK_TO_MENU;
        }
        // button 3 is middle click
        if (event.mouse.button == 3) {
            return MSG_TERMINATE;
        }
    }
    return MSG_NOPE;
}

void result_draw() {
    al_clear_to_color(al_map_rgb(255, 255, 200));
    al_draw_text(pirulen_36, al_map_rgb(0, 0, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTER, "This is result");
}
