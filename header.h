#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

// image enums
#define IMG_INTRO 0
#define IMG_MAIN_SCREEN 1
#define IMG_MAIN_MENU 2
#define IMG_HISTORY 3
#define IMG_NAMING 4
#define IMG_CLASS 5
#define IMG_INITIAL_BUYING 6
#define IMG_HIGH_SEAS_1 7
#define IMG_HIGH_SEAS_2 8
#define IMG_ENDSCREEN 9
#define IMG_BECALMED 10
#define IMG_VINLAND_REACHED 11
#define IMG_SCURVY 12
#define IMG_BOAT_DAMAGED 13
#define IMG_BERGEN 14
#define IMG_REYKYAVIK 15
#define IMG_GREENLAND 16
#define IMG_WHALING 17
#define IMG_FISHING 18
#define IMG_PILLAGE 19
#define IMG_BUYING 20
#define IMG_REPAIR 21

//sound enums
#define SND_OPENING 0
#define SND_MAIN_MENU 1
#define SND_VICTORY 2

//misc enums
#define WARRIOR 1
#define SAILOR 2
#define MERCHANT 3

#ifdef __cplusplus
    #include <cstdlib>
    #include <stdlib.h>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#endif

#include <cstring>
#include <time.h>

#include "partymember.h"
#include "equipment.h"

bool load_media();
bool show_intro();
bool clean_up();
int main_menu();
int read_history();
int name_party_members();
int choose_class();
int buy_stuff();
int high_seas();
int print_full_picture(SDL_Surface* image);
int game_over();
int put_text_at(int x, int y, const char *text);
int random_event();
int vinland_reached();
int clear_screen();
int calculate_score();
int go_fishing_or_whaling(int choice);
int change_health(int partymember, int change);
int landmark_reached(int which);
int buy_at_landmark();
int pillage_city();
int repair_boat();
int how_many_alive();

#endif // HEADER_H_INCLUDED
