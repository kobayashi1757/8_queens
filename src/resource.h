#pragma once
#include "global.h"

extern ALLEGRO_FONT *pirulen_36;
extern ALGIF_ANIMATION *chess_gif;
extern ALLEGRO_BITMAP *archer;
extern ALGIF_ANIMATION *heart_gif;
extern ALLEGRO_BITMAP *infinite_png;
extern ALLEGRO_BITMAP *queens_png;

extern float bgm_gain;
extern float se_gain;
extern ALLEGRO_SAMPLE_INSTANCE *eight_queens_bgm_spi;
extern ALLEGRO_SAMPLE_INSTANCE *easter_egg_bgm_spi;
extern ALLEGRO_SAMPLE_INSTANCE *click_se_spi;
extern ALLEGRO_SAMPLE_INSTANCE *roll_se_spi;

void load_resource();
void destroy_resource();

void set_bgm_gain(float);
void set_se_gain(float);
