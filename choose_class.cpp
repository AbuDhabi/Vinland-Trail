#include "header.h"
#include "globals.h"

int choose_class() {

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
                    // exit if ANY PRESSED
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
        put_text_at(-1,420,"PRESS A NUMBER TO CONTINUE");
        char classes[3][80] = {"1 - WARRIOR","2 - SAILOR","3 - MERCHANT"};
        for (int i=0; i<3; i++) {
            put_text_at(245,320-(4-i)*50,classes[i]);
        }
        
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
  
    }

    
    
    return 0;
}
