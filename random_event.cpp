#include "header.h"
#include "globals.h"

int random_event() {
    int return_code = 5; // by default, back to high seas
    char temp[80]; int number;
    int random_event = rand()%3+1; 
    
    if (random_event == 1) { // becalmed
        number = rand()%6+1;
        DAYS += number;
    } else if (random_event == 2) {
        // somehow apply scurvy to Leif
        for (int i=0;i<5;i++) {
            change_health(i,rand()%20);
        }
    } else if (random_event == 3) { // BOAT FUCKING DAMAGED
        number = rand()%20+1;
        INVENTORY.boat_status -= number;
    }
    
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
        
        
        if (random_event == 1) { // becalmed
            print_full_picture(BITMAPS[IMG_BECALMED]); 
            sprintf(temp,"Lose %d days.",number);
            put_text_at(-1,400,temp);
            
        } else if (random_event == 2) { //scurvy
            print_full_picture(BITMAPS[IMG_SCURVY]); 
        } else if (random_event == 3) {
            print_full_picture(BITMAPS[IMG_BOAT_DAMAGED]); 
            sprintf(temp,"Boat takes %d%% damage.",number);
            put_text_at(-1,-1,temp);
        }
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    

    
    return return_code; // go somewhere
}
