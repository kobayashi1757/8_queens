#include "resource.h"

ALLEGRO_FONT *pirulen_36;
ALGIF_ANIMATION *chess_gif;
ALLEGRO_BITMAP *archer;
ALLEGRO_BITMAP *GBI; // Game Basic Interface
ALLEGRO_BITMAP *heart; 
ALGIF_ANIMATION *JI_gif ;
ALGIF_ANIMATION *JD_gif;
ALGIF_ANIMATION *JH_gif;
ALGIF_ANIMATION *JJ_gif;
ALGIF_ANIMATION *Queen_gif;
ALLEGRO_FONT *score;



void load_resource() {
    pirulen_36 = al_load_ttf_font("../res/font/pirulen.ttf", 36, 0);
    chess_gif = algif_load_animation("../res/image/chess.gif");
    archer = al_load_bitmap("../res/image/archer.png");
    GBI = al_load_bitmap("../res/image/game_basic_interface.png"); //Game basic Interface
    JI_gif = algif_load_animation("../res/image/Johnny_idle.gif"); //Johnny Idle
    JD_gif = algif_load_animation("../res/image/Johnny_dead.gif"); //Johnny dead
    JH_gif = algif_load_animation("../res/image/Johnny_hurt.gif"); //Johnny hurt
    JJ_gif = algif_load_animation("../res/image/Johnny_jump.gif"); //Johnny jump
    Queen_gif = algif_load_animation("../res/image/queen2.gif"); // queen idle
    heart = al_load_bitmap("../res/image/heart.png");
    score = al_load_ttf_font("../res/font/pirulen.ttf", 40, 0);
}
void destroy_resource() {
    al_destroy_font(pirulen_36);
    algif_destroy_animation(chess_gif);
    al_destroy_bitmap(archer);
}
