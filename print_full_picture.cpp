#include "header.h"
#include "globals.h"

int print_full_picture(SDL_Surface* image) {
    // this function prints out the specified image
    // and returns to wherever it was launched from
    // no delays are made
    //SDL_Flip is needed after this!
    
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (MAIN_SCREEN->w - image->w) / 2;
    dstrect.y = (MAIN_SCREEN->h - image->h) / 2;
        
    // clear screen
    //SDL_FillRect(MAIN_SCREEN, 0, SDL_MapRGB(MAIN_SCREEN->format, 0, 0, 0));        
    // draw bitmap

    SDL_BlitSurface(image, 0, MAIN_SCREEN, &dstrect); 
    //SDL_Flip(MAIN_SCREEN);
    //SDL_Delay(200);

    return 0;
}
