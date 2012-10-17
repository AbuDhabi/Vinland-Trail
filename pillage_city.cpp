#include "header.h"
#include "globals.h"

int pillage_city() {
    
    bool done = false;
    bool runthisonce = true;
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
                }
            } // end switch
        } // end of message processing
        
        int foodstolen, cashstolen, peopledead;
        
        if (runthisonce) {
            foodstolen=0; cashstolen=0; peopledead=0;
            runthisonce = false;
            // initial combat calculation
            int combativity=0;
            combativity = INVENTORY.settlers;
            if (INVENTORY.axes >= INVENTORY.settlers) {
                combativity += INVENTORY.settlers;
            } else {
                combativity += INVENTORY.axes;
            }
            for (int i=0;i<5;i++) if (PARTY[i].health > 0) combativity += 2;
            if (CLASS == 1) { // warrior
                combativity = combativity * 2;
            }
            
            // according to landmarks
            int currentroll=0, currentvictim=5;
            if (LANDMARKS == 1) {
                while (combativity > 0) {
                    /*
                    print_full_picture(BITMAPS[IMG_PILLAGE]);
                    char tmp[80];
                    sprintf(tmp,"foodstolen %d cashstolen %d peopledead %d combativity %d currentroll %d",foodstolen,cashstolen,peopledead,combativity,currentroll);
                    put_text_at(-1,-1,tmp);
                    SDL_Flip(MAIN_SCREEN);
                    SDL_Delay(500);
                    */
                    currentroll = rand()%combativity;
                    combativity = combativity - currentroll -1;
                    if (currentroll < 10) {
                        peopledead++;
                        if (INVENTORY.settlers > 0) INVENTORY.settlers--; else {
                            for (int i=0;i<5;i++) if (PARTY[i].health >0) { currentvictim = i; }
                            PARTY[currentvictim].health = 0;
                        }
                        if (how_many_alive() == 0) { return 6; } // bad end
                        //if (how_many_alive() == 0) return 11; // debug
                    } else if (currentroll >= 10 && currentroll < 20) {
                        foodstolen += currentroll*2+rand()%10;
                        cashstolen += currentroll+rand()%5;
                    } else {
                        foodstolen += currentroll*3+rand()%10;
                        cashstolen += currentroll*2+rand()%5;
                    }
                }
            } else if (LANDMARKS == 2) {
                while (combativity > 0) {
                    currentroll = rand()%combativity;
                    combativity = combativity - currentroll -1;
                    if (currentroll < 5) {
                        peopledead++;
                        if (INVENTORY.settlers > 0) INVENTORY.settlers--; else {
                            for (int i=0;i<5;i++) if (PARTY[i].health >0) { currentvictim = i; }
                            PARTY[currentvictim].health = 0;
                        }
                        if (how_many_alive() == 0) { return 6; } // bad end
                    } else if (currentroll >= 5 && currentroll < 10) {
                        foodstolen += currentroll+rand()%10;
                        cashstolen += currentroll/2+rand()%5;
                    } else {
                        foodstolen += currentroll/2+rand()%10;
                        cashstolen += currentroll/3+rand()%3;
                    }
                }
            } else if (LANDMARKS == 3) {
                while (combativity > 0) {
                    currentroll = rand()%combativity;
                    combativity = combativity - currentroll -1;
                    if (currentroll < 2) {
                        peopledead++;
                        if (INVENTORY.settlers > 0) INVENTORY.settlers--; else {
                            for (int i=0;i<5;i++) if (PARTY[i].health >0) { currentvictim = i; }
                            PARTY[currentvictim].health = 0;
                        }
                        if (how_many_alive() == 0) { return 6; } // bad end
                    } else if (currentroll >= 2 && currentroll < 5) {
                        foodstolen += currentroll/2+rand()%5;
                        cashstolen += currentroll/3+rand()%3;
                    } else {
                        foodstolen += currentroll/3+rand()%3;
                        cashstolen += currentroll/4+rand()%2;
                    }
                }
            }
            foodstolen = foodstolen *4 + rand()%20;
            cashstolen = cashstolen *3 + rand()%10;
        }
        char temp[80];
        print_full_picture(BITMAPS[IMG_PILLAGE]);
        put_text_at(-1,380,"You brutally pillage the town!");
        sprintf(temp,"You make off with %d units of food, and %dkr of trade goods!",foodstolen,cashstolen);
        put_text_at(-1,400,temp);
        if (peopledead ==1) { 
            sprintf(temp,"In the pillaging, %d of your men dies.",peopledead);
        } else {
            sprintf(temp,"In the pillaging, %d of your men die.",peopledead);
        }
        put_text_at(-1,420,temp);
        put_text_at(-1,440,"PRESS ENTER TO CONTINUE");
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
    }
    


    return 5; // go somewhere, like the high seas
 //   return 11; // debugging to town after pillage
}
