#include "resource.h"

ALLEGRO_FONT *pirulen_36;
ALGIF_ANIMATION *chess_gif;
ALLEGRO_BITMAP *archer;

void load_resource() {
    pirulen_36 = al_load_ttf_font("res/font/pirulen.ttf", 36, 0);
    chess_gif = algif_load_animation("res/image/chess.gif");
    archer = al_load_bitmap("res/image/archer.png");
}

void destroy_resource() {
    al_destroy_font(pirulen_36);
    algif_destroy_animation(chess_gif);
    al_destroy_bitmap(archer);
}
