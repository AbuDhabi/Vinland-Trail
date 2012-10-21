#include "header.h"
#include "globals.h"

SDL_Surface* load_bitmap(const char * path) {
    SDL_Surface * temp;
    temp = IMG_Load(path);
    if (!temp) {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return NULL;
    } else {
        return temp;
    }
}

Mix_Chunk* load_sound(const char * path) {
    Mix_Chunk * temp;
    temp = Mix_LoadWAV(path);
    if (!temp) {
        printf("Unable to load wave file: %s\n", Mix_GetError());
        return NULL;
    } else {
        return temp;
    }
}

bool load_media() {
    // prevent undefined shit with media
    for (int i=0;i<255;i++) {
        BITMAPS[i] = NULL;
        SOUNDS[i] = NULL;
    }
    
    FONT_GEORGIA = TTF_OpenFont("data//font//georgia.ttf", 16);
    if (FONT_GEORGIA == NULL){
        printf("Unable to load font: %s %s \n", "data//font//georgia.ttf", TTF_GetError());
        // Handle the error here.
    }
    // load images
    BITMAPS[IMG_INTRO] = load_bitmap("data//img//titlescreen.png");
    BITMAPS[IMG_MAIN_MENU] = load_bitmap("data//img//mainmenu.png");
    BITMAPS[IMG_HISTORY] = load_bitmap("data//img//history.png");
    BITMAPS[IMG_NAMING] = load_bitmap("data//img//blank.png");
    BITMAPS[IMG_CLASS] = load_bitmap("data//img//class.png");
    BITMAPS[IMG_INITIAL_BUYING] = load_bitmap("data//img//blank.png");
    BITMAPS[IMG_HIGH_SEAS_1] = load_bitmap("data//img//high_seas_1.png");
    BITMAPS[IMG_HIGH_SEAS_2] = load_bitmap("data//img//high_seas_2.png");
    BITMAPS[IMG_ENDSCREEN] = load_bitmap("data//img//endscreen.png");
    BITMAPS[IMG_BECALMED] = load_bitmap("data//img//becalmed.png");
    BITMAPS[IMG_VINLAND_REACHED] = load_bitmap("data//img//vinland.png");
    BITMAPS[IMG_SCURVY] = load_bitmap("data//img//scurvy.png");
    BITMAPS[IMG_BOAT_DAMAGED] = load_bitmap("data//img//boatdamage.png");
    BITMAPS[IMG_BERGEN] = load_bitmap("data//img//landmark1.png");
    BITMAPS[IMG_REYKYAVIK] = load_bitmap("data//img//landmark2.png");
    BITMAPS[IMG_GREENLAND] = load_bitmap("data//img//landmark3.png");
    BITMAPS[IMG_WHALING] = load_bitmap("data//img//whaling.png");
    BITMAPS[IMG_FISHING] = load_bitmap("data//img//fishing.png");
    BITMAPS[IMG_PILLAGE] = load_bitmap("data//img//pillage.png");
    BITMAPS[IMG_BUYING] = load_bitmap("data//img//blank.png");
    BITMAPS[IMG_REPAIR] = load_bitmap("data//img//blank.png");
    BITMAPS[IMG_BEICED] = load_bitmap("data//img//beiced.png");
    
    //load sounds
    SOUNDS[SND_MAIN_MENU] = load_sound("data//snd//menu.ogg");
    SOUNDS[SND_OPENING] = load_sound("data//snd//opening.ogg");
    SOUNDS[SND_VICTORY] = load_sound("data//snd//victory.ogg");


    return true;
}


