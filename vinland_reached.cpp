#include "header.h"
#include "globals.h"

int vinland_reached() {
    // also displays score
    SCORE = calculate_score();
    
    Mix_PlayChannel(-1, SOUNDS[SND_VICTORY],0);
    
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
        
        char temp[80];
        sprintf(temp,"Your score: %d.",SCORE);
        
        print_full_picture(BITMAPS[IMG_VINLAND_REACHED]);
        put_text_at(-1,300,temp);
        
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    
    Mix_HaltChannel(-1);
    return 0; // return to main menu after this
}
