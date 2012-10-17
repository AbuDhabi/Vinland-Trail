#include "header.h"
#include "globals.h"

int buy_at_landmark() {
    
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
                    if (event.key.keysym.sym == SDLK_1) {
                        if (INVENTORY.money >= 10) {
                            INVENTORY.axes++;
                            INVENTORY.money -= 10;
                        }

                    }
                    if (event.key.keysym.sym == SDLK_2) {
                        if (INVENTORY.money >= 10) {
                            INVENTORY.food += 10;
                            INVENTORY.money -= 10;
                        } else if (INVENTORY.money >= 1) {
                            INVENTORY.food += 1;
                            INVENTORY.money -= 1;
                        }

                    }
                    if (event.key.keysym.sym == SDLK_3) {
                        if (INVENTORY.money >= 50) {
                            INVENTORY.settlers++;
                            INVENTORY.money -= 50;
                        }
                    }
                }
            } // end switch
        } // end of message processing
        
        print_full_picture(BITMAPS[IMG_BUYING]);
        put_text_at(-1,48,"BUY STUFF");
        put_text_at(-1,400, "PRESS NUMBERS, RECEIVE BACON, ENTER GOES BACK TO TOWN");
        
        char stuff[3][80] = {"1 - AXES, 10kr: ","2 - FOOD, 1kr: ","3 - SETTLERS, 50kr: "};
        char temp[80], temp2[80]; int number;
        for (int i=0; i<3; i++) {
            strcpy(temp,""); strcpy(temp2,"");
            strcpy(temp,stuff[i]);
            if (i==0) number = INVENTORY.axes;
            else if (i==1) number = INVENTORY.food;
            else if (i==2) number = INVENTORY.settlers;
            sprintf(temp2,"%d",number);
            strcat(temp,temp2);
            put_text_at(245,320-(4-i)*50,temp);
        }
        char temp3[80];
        sprintf(temp3,"MONEY LEFT: %dkr",INVENTORY.money);
        put_text_at(-1,340,temp3);
        
        
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    


    return 11; // go back to landmark
}
