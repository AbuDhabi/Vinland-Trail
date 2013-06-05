#include "header.h"
#include "globals.h"

int main_menu() {
    int menu_item_selected = 0;
    // if nothing's on, start playing
    if (Mix_Playing(-1) == 0) Mix_PlayChannel(-1, SOUNDS[SND_MAIN_MENU], 0);
    // message processing loop
    bool done = false;
    while (!done) {
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                //done = true;
                return -1;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    if (event.key.keysym.sym == SDLK_DOWN) {
                        menu_item_selected++;
                        if (menu_item_selected > 2) menu_item_selected = 0;
                    }
                    if (event.key.keysym.sym == SDLK_UP) {
                        menu_item_selected--;
                        if (menu_item_selected < 0) menu_item_selected = 2;
                    }
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        if (menu_item_selected == 0) { return 1; } // new game
                        else if (menu_item_selected == 1) { return 2; } // history
                        else if (menu_item_selected == 2) { return -1; } // end game
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_1) {
                        Mix_HaltChannel(-1);
                        return 1; // go to new game!
                        //done = true;
                    }
                    if (event.key.keysym.sym == SDLK_2) {
                        //2Mix_HaltChannel(-1);
                        return 2; // go to history!
                        //done = true;
                    }
                    if (event.key.keysym.sym == SDLK_3 || event.key.keysym.sym == SDLK_ESCAPE) {
                        Mix_HaltChannel(-1);
                        return -1; // go to hell
                        //done = true;
                    }
                    break;
                }
            } // end switch
        } // end of message processing
        
        print_full_picture(BITMAPS[IMG_MAIN_MENU]);
        put_text_at(-1,240,"1 - START GAME");
        put_text_at(-1,290,"2 - READ HISTORY");
        put_text_at(-1,340,"3 - EXIT GAME");
        
        rectangleRGBA(MAIN_SCREEN, 240,230+menu_item_selected*50,400,270+menu_item_selected*50,255,0,0,255);
        rectangleRGBA(MAIN_SCREEN, 240+1,230+menu_item_selected*50+1,400-1,270+menu_item_selected*50-1,255,0,0,255);
        
        if (Mix_Playing(-1) == 0) Mix_PlayChannel(-1, SOUNDS[SND_MAIN_MENU], 0);
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    
    Mix_HaltChannel(-1);
    //Mix_HaltMusic();
    
    
    return 0; // this is the code for exiting the game
}
