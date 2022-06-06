#pragma once
#include "global.h"

extern ALLEGRO_FONT *pirulen_36;
extern ALGIF_ANIMATION *chess_gif;
extern ALLEGRO_BITMAP *archer;
extern ALLEGRO_BITMAP *GBI; // Game Basic Interface
extern ALLEGRO_BITMAP *heart; // HP heart
extern ALGIF_ANIMATION *JI_gif; // Johnny Idle 
extern ALGIF_ANIMATION *JD_gif; // Johnny dead 
extern ALGIF_ANIMATION *JH_gif; // Johnny hurt 
extern ALGIF_ANIMATION *JJ_gif; // Johnny jump
extern ALGIF_ANIMATION *Queen_gif; // Queen 
extern ALLEGRO_FONT *score;

void load_resource();
void destroy_resource();
