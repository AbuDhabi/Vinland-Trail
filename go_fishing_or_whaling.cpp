#include "header.h"
#include "globals.h"

int go_fishing_or_whaling(int choice) {
    char temp[80];
    int boat_dmg, ration_bonus, days_taken;
    
    if (choice == 1) { // whaling
        if (CLASS == SAILOR) days_taken = rand()%3+1;
        else days_taken = rand()%6+1;
        if (CLASS == SAILOR) ration_bonus = rand()%100+21;
        else ration_bonus = rand()%200+41;
        DAYS += days_taken;
        INVENTORY.food += ration_bonus;
        if ((rand()%2 == 0 && CLASS != SAILOR) || (rand()%4 == 0 && CLASS == SAILOR)) {
            boat_dmg = rand()%20+1;
            INVENTORY.boat_status -= boat_dmg;
            sprintf(temp,"This takes %d days, earning you %d rations, but damages your boat for %d%%.",days_taken,ration_bonus,boat_dmg);
        } else {
            sprintf(temp,"This takes %d days, earning you %d rations.",days_taken,ration_bonus);
        }
        
    } else if (choice == 2) { // fishing
        if (CLASS == SAILOR) days_taken = rand()%6+2;
        else days_taken = rand()%12+4;
        if (CLASS == SAILOR) ration_bonus = rand()%40+20;
        else ration_bonus = rand()%20+10;
        DAYS += days_taken;
        INVENTORY.food += ration_bonus;
        sprintf(temp,"This takes %d days, earning you %d rations.",days_taken,ration_bonus);
    }
    
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
                return -1;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ANY PRESSED
                    return 5;
                    break;
                }
            } // end switch
        } // end of message processing

        
        if (choice == 1) {
            print_full_picture(BITMAPS[IMG_WHALING]);
            put_text_at(-1,400,"You go whaling.");
        } else if (choice == 2) {
            print_full_picture(BITMAPS[IMG_FISHING]);
            put_text_at(-1,400,"You go fishing.");
        }
        put_text_at(-1,420,temp);
        
        
        
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
        
  
    }
    
    return 5;// going back to high seas
}
