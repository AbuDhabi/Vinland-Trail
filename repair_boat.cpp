#include "header.h"
#include "globals.h"

int repair_boat() {
    
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
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ENTER
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        done = true;
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_r) {
                        if (INVENTORY.money > 0 && INVENTORY.boat_status < 100) {
                            INVENTORY.money--;
                            INVENTORY.boat_status++;
                        }
                    }
                }
            } // end switch
        } // end of message processing
        
        print_full_picture(BITMAPS[IMG_REPAIR]);
        char temp[80];
        sprintf(temp,"Current boat status: %d%%",INVENTORY.boat_status);
        put_text_at(-1,200,temp);
        sprintf(temp,"Money left: %dkr",INVENTORY.money);
        put_text_at(-1,220,temp);
        put_text_at(-1,260,"Press R to repair 1% for 1kr.");
        
        put_text_at(-1,400,"Press ENTER to return to town.");
        
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    


    return 11; // go back to landmark
}
