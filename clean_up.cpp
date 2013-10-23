#include "header.h"
#include "globals.h"

bool clean_up() {

    for (int i=0;i<255;i++) {
        if (BITMAPS[i] != NULL) {
            SDL_FreeSurface(BITMAPS[i]);
            Mix_FreeChunk(SOUNDS[i]);
        }
    }

    TTF_CloseFont(FONT_GEORGIA);

    SDL_FreeSurface(MAIN_SCREEN); // this is important and needs to stay

    return true;
}
