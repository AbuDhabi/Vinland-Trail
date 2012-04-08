#include "header.h"
#include "globals.h"

int generate_party() {
    //char fnames[14][80] = {"Sven","Erik","Jens","Bjorn","Ulf","Leif","Olaf","Ragnar","Knut","Godfrid","Harald","Ivar","Rorik","Thorfin"};
    char fnames[80][80] = {"Olav","Harald","Sigurd","Rane","Ottar", "Sote","Sigvat","Yngve","Torkjell","Svein","Ulvkjell","Gisle","Vilhjalm", 
                           "Gunnvald","Geirfinn","Rikard","Edmund","Edvard","Edvig","Edgeir","Rolv","Eirik","Einar","Haakon","Erling", 
                           "Tryggve","Ragnvald","Aslak","Skjalg","Lodin","Tore","Torberg","Knut","Tord","Halvdan","Guttorm","Roerek","Ring",
                           "Gudroed","Baard","Karl","Berse","Kalv","Torgeir","Arnljot","Avrafaste","Torfinn","Gissur","Hovgarda","Dag", 
                           "Arnfinn","Armod","Bjoern","Torstein","Finn","Erlend","Haarek","Kimbe","Grim","Torgil","Alfrin","Torarin", 
                           "Grimkjell","Magnus","Jarisleiv","Torgrim","Grimnir","Bruse","Glum","Oeyvind","Grjotgard","Gamle","Ossur","Gandalf", 
                           "Hysing","Helsing","Haki","Snorre","Arnor","Tjodolv"};
    char lnames[32][80] = {"Bloodaxe", "the Red", "the Black", "Niceguy", "Hound", "the Holy", "the Big",
                           "the Mouth", "Goldeneyes", "Bard", "Pilgrim", "Crusader", "Bowbreaker", "Tambourine-Shaker",
                           "the Good", "Fairhair", "Greycloak", "Barefoot", "the Hunchback", "Broad-Shouldered",
                           "Lawmender", "Ironhand", "Skull", "Hairy-Breeches", "Ironside", "the Boneless", "Snake-Eye",
                           "Forkbeard", "Bluetooth", "Gold", "Tiller", "Crow"};
    
    char temp[80];
    for (int i=0;i<5;i++) {
        strcpy(temp,"");
        strcat(temp,fnames[rand()%80]);
        strcat(temp," ");
        if (rand()%2 == 0) 
            strcat(temp,lnames[rand()%32]);
        else {
            strcat(temp,fnames[rand()%80]);
            strcat(temp,"sson");
        }
        strcpy(PARTY[i].name,temp);
        PARTY[i].health = 100;
    }
    return 0; // maybe it'll need to return something
}

int name_party_members() {
    // let's clear stuff
    DISTANCE = 0;
    INVENTORY = {0,0,0,100,500};
    SCORE = 0;
    DAYS = 0;
    PACE = 1;
    RATIONS = 2;
    
    generate_party();

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
                //done = true;
                return -1;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ANY PRESSED
                    if (event.key.keysym.sym == SDLK_r) {
                        generate_party();
                    }
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        //Mix_HaltChannel(-1);
                        return 3; // go to class choice screen
                        //done = true;
                    }
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        //Mix_HaltChannel(-1);
                        return 0; // go to main menu
                        //done = true;
                    }
                    break;
                }
            } // end switch
        } // end of message processing
     
        
        print_full_picture(BITMAPS[IMG_NAMING]);
        
        for (int i=0;i<5;i++) {
            put_text_at(245,320-(4-i)*50, PARTY[i].name);
        }
        put_text_at(-1, 400,"PRESS R TO REGENERATE NAMES, PRESS ENTER TO CONTINUE");
        put_text_at(-1,48,"PARTY MEMBER NAMES");
        
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
  
    }

    
    return 0;
}

