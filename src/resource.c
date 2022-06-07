#include "resource.h"

ALLEGRO_FONT *pirulen_36;
ALGIF_ANIMATION *chess_gif;
ALLEGRO_BITMAP *archer;
ALGIF_ANIMATION *heart_gif;
ALLEGRO_BITMAP *infinite_png;
ALLEGRO_BITMAP *queens_png;

float bgm_gain = 1.0f;
float se_gain = 1.0f;
ALLEGRO_SAMPLE *eight_queens_bgm_sp;
ALLEGRO_SAMPLE_INSTANCE *eight_queens_bgm_spi;
ALLEGRO_SAMPLE *easter_egg_bgm_sp;
ALLEGRO_SAMPLE_INSTANCE *easter_egg_bgm_spi;
ALLEGRO_SAMPLE *click_se_sp;
ALLEGRO_SAMPLE_INSTANCE *click_se_spi;
ALLEGRO_SAMPLE *roll_se_sp;
ALLEGRO_SAMPLE_INSTANCE *roll_se_spi;

void load_sound(const char *filename, ALLEGRO_SAMPLE **sp, ALLEGRO_SAMPLE_INSTANCE **spi, ALLEGRO_PLAYMODE playmode) {
    *sp = al_load_sample(filename);
    *spi = al_create_sample_instance(*sp);
    al_set_sample_instance_playmode(*spi, playmode);
    al_attach_sample_instance_to_mixer(*spi, al_get_default_mixer());
}

void destroy_sound(ALLEGRO_SAMPLE *sp, ALLEGRO_SAMPLE_INSTANCE *spi) {
    al_destroy_sample_instance(spi);
    al_destroy_sample(sp);
}

void load_resource() {
    pirulen_36 = al_load_ttf_font("res/font/pirulen.ttf", 36, 0);
    chess_gif = algif_load_animation("res/image/chess.gif");
    archer = al_load_bitmap("res/image/archer.png");
    heart_gif = algif_load_animation("res/image/heart.gif");
    infinite_png = al_load_bitmap("res/image/infinite.png");
    queens_png = al_load_bitmap("res/image/queens.png");

    load_sound("res/sound/8_queens_bgm.wav", &eight_queens_bgm_sp, &eight_queens_bgm_spi, ALLEGRO_PLAYMODE_LOOP);
    load_sound("res/sound/easter_egg_bgm.wav", &easter_egg_bgm_sp, &easter_egg_bgm_spi, ALLEGRO_PLAYMODE_LOOP);
    load_sound("res/sound/click_se.wav", &click_se_sp, &click_se_spi, ALLEGRO_PLAYMODE_ONCE);
    load_sound("res/sound/roll_se.wav", &roll_se_sp, &roll_se_spi, ALLEGRO_PLAYMODE_ONCE);
}

void destroy_resource() {
    al_destroy_font(pirulen_36);
    algif_destroy_animation(chess_gif);
    al_destroy_bitmap(archer);
    algif_destroy_animation(heart_gif);
    al_destroy_bitmap(infinite_png);
    al_destroy_bitmap(queens_png);

    destroy_sound(eight_queens_bgm_sp, eight_queens_bgm_spi);
    destroy_sound(easter_egg_bgm_sp, easter_egg_bgm_spi);
    destroy_sound(click_se_sp, click_se_spi);
    destroy_sound(roll_se_sp, roll_se_spi);
}

void set_bgm_gain(float gain) {
    bgm_gain = gain;
    al_set_sample_instance_gain(eight_queens_bgm_spi, gain);
    al_set_sample_instance_gain(easter_egg_bgm_spi, gain);
}

void set_se_gain(float gain) {
    se_gain = gain;
    al_set_sample_instance_gain(click_se_spi, gain);
    al_set_sample_instance_gain(roll_se_spi, gain);
}
