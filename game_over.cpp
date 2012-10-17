#include "header.h"
#include "globals.h"

int game_over() {

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
        
        print_full_picture(BITMAPS[IMG_ENDSCREEN]);
        char temp[80];
        SCORE = calculate_score() / 2; // because you hath failed
        sprintf(temp,"SCORE: %d",SCORE);
        put_text_at(-1,360,temp);
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
  
    }
    return 0;
}
