#include "header.h"
#include "globals.h"

int clear_screen() {
    
    SDL_FillRect(MAIN_SCREEN, 0, SDL_MapRGB(MAIN_SCREEN->format, 0, 0, 0));
    return 0;
}
