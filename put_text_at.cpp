#include "header.h"
#include "globals.h"

int put_text_at(int x, int y, const char *text) {
    //SDL_Flip is needed after this!
    SDL_Surface * text_surface;
    text_surface = TTF_RenderText_Solid(FONT_GEORGIA, text, DEFAULT_COLOR);
    SDL_Rect text_rect;
    if (x == -1) 
        text_rect.x = (MAIN_SCREEN->w - text_surface->w) / 2;
    else
        text_rect.x = x;
    if (y == -1)
        text_rect.y = (MAIN_SCREEN->h - text_surface->h) / 2;
    else
        text_rect.y = y;
    SDL_BlitSurface(text_surface,0,MAIN_SCREEN,&text_rect);        
    //SDL_Flip(MAIN_SCREEN);
    
    return 0;
}
