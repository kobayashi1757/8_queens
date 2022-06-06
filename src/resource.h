#pragma once
#include "global.h"

extern ALLEGRO_FONT *pirulen_36;
extern ALGIF_ANIMATION *chess_gif;
extern ALLEGRO_BITMAP *archer;
extern ALGIF_ANIMATION *heart_gif;

extern float bgm_gain;
extern float se_gain;
extern ALLEGRO_SAMPLE_INSTANCE *bgm_spi;
extern ALLEGRO_SAMPLE_INSTANCE *click_se_spi;
extern ALLEGRO_SAMPLE_INSTANCE *roll_se_spi;

void load_resource();
void destroy_resource();

void set_bgm_gain(float);
void set_se_gain(float);
