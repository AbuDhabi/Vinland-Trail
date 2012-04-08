#include "header.h"
#include "globals.h"

bool show_intro() {
    Mix_PlayChannel(-1, SOUNDS[SND_OPENING], 0);

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

        print_full_picture(BITMAPS[IMG_INTRO]);
        put_text_at(-1,436,"PRESS ANY KEY TO CONTINUE");  
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
  
    }
    
    Mix_HaltChannel(-1);
    //Mix_HaltMusic();
  
    return true;
}
