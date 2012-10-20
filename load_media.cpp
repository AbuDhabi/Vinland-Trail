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
    
    FONT_GEORGIA = TTF_OpenFont("georgia.ttf", 16);
    if (FONT_GEORGIA == NULL){
        printf("Unable to load font: %s %s \n", "georgia.ttf", TTF_GetError());
        // Handle the error here.
    }
    // load images
    BITMAPS[IMG_INTRO] = load_bitmap("titlescreen.png");
    BITMAPS[IMG_MAIN_MENU] = load_bitmap("mainmenu.png");
    BITMAPS[IMG_HISTORY] = load_bitmap("history.png");
    BITMAPS[IMG_NAMING] = load_bitmap("blank.png");
    BITMAPS[IMG_CLASS] = load_bitmap("class.png");
    BITMAPS[IMG_INITIAL_BUYING] = load_bitmap("blank.png");
    BITMAPS[IMG_HIGH_SEAS_1] = load_bitmap("high_seas_1.png");
    BITMAPS[IMG_HIGH_SEAS_2] = load_bitmap("high_seas_2.png");
    BITMAPS[IMG_ENDSCREEN] = load_bitmap("endscreen.png");
    BITMAPS[IMG_BECALMED] = load_bitmap("becalmed.png");
    BITMAPS[IMG_VINLAND_REACHED] = load_bitmap("vinland.png");
    BITMAPS[IMG_SCURVY] = load_bitmap("scurvy.png");
    BITMAPS[IMG_BOAT_DAMAGED] = load_bitmap("boatdamage.png");
    BITMAPS[IMG_BERGEN] = load_bitmap("landmark1.png");
    BITMAPS[IMG_REYKYAVIK] = load_bitmap("landmark2.png");
    BITMAPS[IMG_GREENLAND] = load_bitmap("landmark3.png");
    BITMAPS[IMG_WHALING] = load_bitmap("whaling.png");
    BITMAPS[IMG_FISHING] = load_bitmap("fishing.png");
    BITMAPS[IMG_PILLAGE] = load_bitmap("pillage.png");
    BITMAPS[IMG_BUYING] = load_bitmap("blank.png");
    BITMAPS[IMG_REPAIR] = load_bitmap("blank.png");
    BITMAPS[IMG_BEICED] = load_bitmap("beiced.png");
    
    //load sounds
    SOUNDS[SND_MAIN_MENU] = load_sound("menu.ogg");
    SOUNDS[SND_OPENING] = load_sound("opening.ogg");
    SOUNDS[SND_VICTORY] = load_sound("victory.ogg");


    return true;
}


