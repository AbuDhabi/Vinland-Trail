#include "header.h"
#include "globals.h"

int choose_class() {
    int menu_item_selected = 0;
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
                        if (menu_item_selected == 0) { CLASS = 1; } // warrior
                        else if (menu_item_selected == 1) { CLASS = 2; } // sailor
                        else if (menu_item_selected == 2) { CLASS = 3; } // merchant
                        return 4;
                    }
                    if (event.key.keysym.sym == SDLK_1) {
                        CLASS = 1;
                        return 4; // go to buying stuff
                        //Mix_HaltChannel(-1);
                        //return 1; 
                        //done = true;
                    }
                    if (event.key.keysym.sym == SDLK_2) {
                        CLASS = 2;
                        //Mix_HaltChannel(-1);
                        return 4; // go to purchasing screen
                        //done = true;
                    }
                    if (event.key.keysym.sym == SDLK_3) {
                        CLASS = 3;
                        //Mix_HaltChannel(-1);
                        return 4; // go to purchasing screen
                        //done = true;
                    }
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        //Mix_HaltChannel(-1);
                        return 1; // go to party selection
                        //done = true;
                    }
                    break;
                }
            } // end switch
        } // end of message processing

        print_full_picture(BITMAPS[IMG_CLASS]);
        put_text_at(-1,48,"CHOOSE YOUR PROFESSION");
        put_text_at(-1,420,"PRESS A NUMBER OR SELECT AND PRESS ENTER TO CONTINUE");
        char classes[3][80] = {"1 - WARRIOR","2 - SAILOR","3 - MERCHANT"};
        for (int i=0; i<3; i++) {
            put_text_at(-1,320-(4-i)*50,classes[i]);
        }
        rectangleRGBA(MAIN_SCREEN, 240,110+menu_item_selected*50,400,150+menu_item_selected*50,255,0,0,255);
        rectangleRGBA(MAIN_SCREEN, 240+1,110+menu_item_selected*50+1,400-1,150+menu_item_selected*50-1,255,0,0,255);
        
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
  
    }

    
    
    return 0;
}
