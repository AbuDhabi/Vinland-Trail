#include "header.h"
#include "globals.h"

int high_seas() {
    int frame = 0;

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
                    if (event.key.keysym.sym == SDLK_SPACE) {
                        if (PAUSED) PAUSED = false;
                        else PAUSED = true;
                    }
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        done = true;
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_p) {
                        PACE++;
                        if (PACE > 2) PACE = 0;
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_r) {
                        RATIONS++;
                        if (RATIONS > 3) RATIONS = 0;
                        break;
                    }
                    if (!ALREADY_FISHEDORWHALED) {
                        if (event.key.keysym.sym == SDLK_w) {
                            // whaling
                            ALREADY_FISHEDORWHALED = true;
                            return 9;
                            //break;
                        }
                        if (event.key.keysym.sym == SDLK_f) {
                            // fishing
                            ALREADY_FISHEDORWHALED = true;
                            return 10;
                            //break;
                        }
                    }
                    
                }
            } // end switch
        } // end of message processing
        
        
        if (frame%2==0) {
            print_full_picture(BITMAPS[IMG_HIGH_SEAS_1]);
            if (frame<0) frame = 0;
            if (!PAUSED) frame++;
        }
        else if (frame%2==1) {
            print_full_picture(BITMAPS[IMG_HIGH_SEAS_2]);
            if (frame<0) frame = 1;
            if (!PAUSED) frame++;
        }
        char temp[80];
        sprintf(temp,"Miles sailed: %d",DISTANCE);
        put_text_at(-1,400,temp);
        sprintf(temp,"Days sailed: %d",DAYS);
        put_text_at(-1,450,temp);
        
        int skill_mod = 0; // sailors gonna sail
        if (CLASS == SAILOR) skill_mod = 10;
        float skeleton_crew_mod = 1; // not enough crew?
        if (how_many_alive()+INVENTORY.settlers < 5) skeleton_crew_mod = (how_many_alive()+INVENTORY.settlers)/5.0;
        
        if (!PAUSED && frame%5 == 0) {
            
            if (PACE == 0) {
                DISTANCE += (int)(36 + rand()%6 - rand()%6 + skill_mod/2)*(INVENTORY.boat_status/100.0)*skeleton_crew_mod;
                for (int i=0;i<5;i++) {
                    change_health(i,1);
                }
            } else if (PACE == 1) {
                DISTANCE += (int)(72 + rand()%12 - rand()%12 + skill_mod)*(INVENTORY.boat_status/100.0)*skeleton_crew_mod; // from SRD, 3mi/hr
            } else if (PACE == 2) {
                DISTANCE += (int)(108 + rand()%18 - rand()%18 + skill_mod*2)*(INVENTORY.boat_status/100.0)*skeleton_crew_mod;
                for (int i=0;i<5;i++) {
                    change_health(i,-1);
                }
            }
            if (RATIONS == 0) {
                for (int i=0;i<5;i++) {
                    change_health(i,-2);
                }
            } else if (RATIONS == 1) {
                for (int i=0;i<5;i++) {
                    if (PARTY[i].health > 0) { INVENTORY.food--; } // half rations
                    change_health(i,-1);
                }
                INVENTORY.food -= INVENTORY.settlers;
            } else if (RATIONS == 2) {
                for (int i=0;i<5;i++) {
                    if (INVENTORY.food >= 2) {
                         if (PARTY[i].health > 0) { INVENTORY.food -= 2; }
                    } else {
                        change_health(i,-1);
                    }
                }
                for (int i=0;i<INVENTORY.settlers;i++) {
                    if (INVENTORY.food >=2) {
                        INVENTORY.food -= 2;
                    } else {
                        if (rand()%100 == 0) {
                            INVENTORY.settlers--;
                        }
                    }
                }
            } else if (RATIONS == 3) {
                for (int i=0;i<5;i++) {
                    if (INVENTORY.food >= 4) {
                         if (PARTY[i].health > 0) { INVENTORY.food -= 4; }
                         change_health(i,1);
                    } else {
                        change_health(i,-1);
                    }
                }
                for (int i=0;i<INVENTORY.settlers;i++) {
                    if (INVENTORY.food >=4) {
                        INVENTORY.food -= 4;
                    } else {
                        if (rand()%100 == 0) {
                            INVENTORY.settlers--;
                        }
                    }
                }
            } 
            DAYS++;
            ALREADY_FISHEDORWHALED = false;
            
            if (rand()%10 == 0) { 
                return 8; // random event
            }
            if (DISTANCE > 6000) { 
                return 7; // reached vinland, fuckers!
            } else if (DISTANCE > 5000 && LANDMARKS == 2) { LANDMARKS++; return 11; } // greenland
            else if (DISTANCE > 3000 && LANDMARKS == 1) { LANDMARKS++; return 11; } // iceland
            else if (DISTANCE > 1000 && LANDMARKS == 0) { LANDMARKS++; return 11; } // bergen
            
        }// else { // if paused
        
        char pace[80];
        if (PACE == 0) strcpy(pace,"slow");
        else if (PACE == 1) strcpy(pace,"even");
        else strcpy(pace,"frantic"); // presumed 2
        char rations[80];
        if (RATIONS == 0) strcpy(rations,"none");
        else if (RATIONS == 1) strcpy(rations,"half");
        else if (RATIONS == 2) strcpy(rations,"full");
        else strcpy(rations,"double"); // presumed 3
        // pace and rations and whaling and fishing
        sprintf(temp,"P - SET PACE: %s.",pace);
        put_text_at(430,300,temp);
        sprintf(temp,"R - SET RATIONS: %s.",rations);
        put_text_at(430,320,temp);
        if (!ALREADY_FISHEDORWHALED) {
            sprintf(temp,"W - GO WHALING");
            put_text_at(430,360,temp);
            sprintf(temp,"F - GO FISHING");
            put_text_at(430,380,temp);
        }
         
        //display stuff
        sprintf(temp,"AXES: %d",INVENTORY.axes);
        put_text_at(250,300,temp);
        sprintf(temp,"RATIONS: %d",INVENTORY.food);
        put_text_at(250,320,temp);
        sprintf(temp,"BOAT STATUS: %d%%",INVENTORY.boat_status);
        put_text_at(250,340,temp);
        sprintf(temp,"SETTLERS: %d",INVENTORY.settlers);
        put_text_at(250,360,temp);
            
        // display stats of peeps (running out of room, though)
        sprintf(temp,"%s: %d%%",PARTY[0].name,PARTY[0].health);
        put_text_at(20,300,temp);
        sprintf(temp,"%s: %d%%",PARTY[1].name,PARTY[1].health);
        put_text_at(20,320,temp);
        sprintf(temp,"%s: %d%%",PARTY[2].name,PARTY[2].health);
        put_text_at(20,340,temp);
        sprintf(temp,"%s: %d%%",PARTY[3].name,PARTY[3].health);
        put_text_at(20,360,temp);
        sprintf(temp,"%s: %d%%",PARTY[4].name,PARTY[4].health);
        put_text_at(20,380,temp);
            
        //}
        
        
        // sanity checks
        //if (INVENTORY.food < 1) { RATIONS = 0; } // not necessary anymore
        
        // let's see those game-overs
        if (INVENTORY.boat_status <= 0) return 6; // game over, boat crashed
        int anyone_alive = false;
        for (int i=0;i<5;i++) if (PARTY[i].health > 0) anyone_alive = true;
        if (!anyone_alive) return 6; // game over, all leaders are dead
        
        if (PAUSED) put_text_at(-1,20,"-PRESS SPACE TO UNPAUSE-");
                
        
        SDL_Flip(MAIN_SCREEN);
        if (PAUSED) 
            SDL_Delay(100);
        else    
            SDL_Delay(100);  // TODO: adjust this properly, so it's not too slow and not too fast
    }
    
    return 0;
}
