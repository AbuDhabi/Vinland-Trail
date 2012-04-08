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
                    // exit if ANY PRESSED
                    done = true;
                    break;
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
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    


    return 5; // go somewhere, like the high seas
}
