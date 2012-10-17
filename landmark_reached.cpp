#include "header.h"
#include "globals.h"

int landmark_reached(int which) {
    
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
                    if (event.key.keysym.sym == SDLK_p) {
                        return 14; // pillage
                    }
                    if (event.key.keysym.sym == SDLK_b) {
                        return 15; // buy
                    }
                    if (event.key.keysym.sym == SDLK_r) {
                        return 16; // repair
                    }
                }
            } // end switch
        } // end of message processing
        
        if (which == 1) {
            print_full_picture(BITMAPS[IMG_BERGEN]);
            put_text_at(-1,400,"Welcome to Bergen, gate to the fjords!");
        } else if (which == 2) {
            print_full_picture(BITMAPS[IMG_REYKYAVIK]);
            put_text_at(-1,400,"Welcome to Reykyavik, land of glaciers and volcanoes!");
        } else if (which == 3) {
            print_full_picture(BITMAPS[IMG_GREENLAND]);
            put_text_at(-1,400,"Welcome to Greenland, which isn't green at all!");
        }
        put_text_at(20,100,"What shall we do here?");
        put_text_at(20,120,"P - Pillage");
        put_text_at(20,140,"R - Repair boat");
        put_text_at(20,160,"B - Buy stuff");
        put_text_at(20,180,"ENTER - Leave");
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    


    return 5; // go somewhere, like the high seas
}
