CC := g++
CFLAGS := -Wall -std=c++17 -O2 -v
ALLEGRO_LIBRARIES := allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_dialog-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5
ALLEGRO_FLAGS := $(shell pkg-config --cflags --libs $(ALLEGRO_LIBRARIES)) -lallegro -lallegro_main

OUT:= game
SOURCE = gif.c bitmap.c algif.c lzw.c main.cpp scene.c global.c resource.c menu.c result.c game.c 
# SOURCE = main.cpp scene.cpp GameWindow.cpp  charater.cpp global.cpp
OBJ = gif.o bitmap.o algif.o lzw.o main.o scene.o global.o resource.o menu.o result.o game.o

all: 
	$(CC) -c -g $(CFLAGS) $(SOURCE) $(ALLEGRO_FLAGS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(ALLEGRO_FLAGS)
	rm $(OBJ)

.PHONY:clean
clean:
	rm $(OUT)
