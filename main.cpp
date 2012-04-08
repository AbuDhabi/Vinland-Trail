#include "header.h"
#include "globals.h"

int MAXX = 640;
int MAXY = 480;
SDL_Surface* BITMAPS[255]; //255 is more than I'll need
Mix_Chunk* SOUNDS[255];
TTF_Font* FONT_GEORGIA;
SDL_Surface* MAIN_SCREEN;
SDL_Color DEFAULT_COLOR = {0x00,0x00,0x00,0xFF};
PartyMember PARTY[5];
int CLASS;
Equipment INVENTORY = {0,0,0,100,0}; // nothing but the boat is okay
bool END_PROGRAM = false;
int state =  0; // -1 - exit, 0 - go to main menu, 1 - start new game/naming, 2 - read history, 3 - choose class,
               // 4 - purchase stuff/new game, 5 - the actual game screen, finally! 6 - game over
               // 7 - vinland reached!, 8 - random event, 9 - whaling, 10 - go fishing
               // 11 - bergen, 12 - reykyavik, 13 - greenland
int DISTANCE = 0; // distance traveled
int DAYS = 0; // total days taken
int SCORE = 0;
int PACE = 0;
int RATIONS = 0;
bool PAUSED = true;
int LANDMARKS = 0; // which landmarks were already reached

int main ( int argc, char** argv )
{
    srand((unsigned)time(0)); // IT'S RANDOM TIME
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO&SDL_INIT_AUDIO&SDL_INIT_TIMER ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    // initialize SDL sound
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 4096;
    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
        fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
        exit(1);
    }
    if (TTF_Init() < 0) {
        fprintf(stderr, "Unable to initialize TTF: %s\n", TTF_GetError());
        exit(1);
    }
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if(initted&flags != flags) {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        // handle error
    }
    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    atexit(TTF_Quit);
    atexit(IMG_Quit);

    // create a new window
    MAIN_SCREEN = SDL_SetVideoMode(MAXX, MAXY, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !MAIN_SCREEN )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    SDL_WM_SetCaption("Viking Trail","Viking Trail");
    
    
    // LOAD MEDIA
    if (!load_media()) {
        // errors! could not load media for whatever reason
        
    };
    
    if (!show_intro()) {
        // something went wrong!
    }
    
    while (state != -1) {
        if (state == 0) { state = main_menu(); }
        if (state == 1) { state = name_party_members(); } // start the game
        if (state == 2) { state = read_history(); } // read history
        if (state == 3) { state = choose_class(); } // class selection
        if (state == 4) { state = buy_stuff(); } // the initial buying scene
        if (state == 5) { state = high_seas(); } // main game screen
        if (state == 6) { state = game_over(); } // game over mon
        if (state == 7) { state = vinland_reached(); } // game over in a good way!
        if (state == 8) { state = random_event(); } // some random event!
        if (state == 9) { state = go_fishing_or_whaling(1); } // whaling
        if (state == 10) { state = go_fishing_or_whaling(2); } // fishing
        if (state == 11) { state = landmark_reached(1); } // bergen
        if (state == 12) { state = landmark_reached(2); } // reykyavik
        if (state == 13) { state = landmark_reached(3); } // greenland
    }
    

    
    clean_up();

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
