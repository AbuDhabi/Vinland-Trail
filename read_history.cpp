//Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur tristique augue nec neque pellentesque sagittis. Nullam diam turpis, blandit et tincidunt at, consequat eu elit. Nulla venenatis imperdiet nunc id condimentum. Praesent placerat ultrices suscipit. Quisque eget lectus nec massa tincidunt congue ut vel justo. Nulla gravida ante in turpis consectetur sed venenatis diam dictum. Nunc lacinia, nibh venenatis gravida iaculis, sapien libero porta metus, ac egestas justo dui eget ante. Pellentesque condimentum mauris eget quam bibendum tincidunt tincidunt justo iaculis. Nam varius cursus malesuada. Vivamus consectetur, felis et eleifend lacinia, erat nisl gravida tellus, non sodales leo nisl sed felis. Duis magna turpis, laoreet vel suscipit eget, viverra eget sem. Donec felis dolor, feugiat quis luctus eu, porta a leo. Phasellus sagittis rutrum eros, convallis commodo ante placerat sed.
#include "header.h"
#include "globals.h"

int read_history() {

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
                    return 0;
                    break;
                }
            } // end switch
        } // end of message processing

        
        print_full_picture(BITMAPS[IMG_HISTORY]);
        boxRGBA(MAIN_SCREEN,100,50,560,320,0xFF,0xFF,0xFF,0xFF);
        put_text_at(-1,48,"VIKING HISTORICAL TEXT");
        put_text_at(120,80,"Vikings were North Europeans who went raiding and trading");
        put_text_at(120,100,"across most of Europe around 800-1050. The name comes");
        put_text_at(120,120,"from the phrase \"to go viking\", originally meaning to set");
        put_text_at(120,140,"out on a journey. Vikings sailed to Greenland and built");
        put_text_at(120,160,"colonies, sailed to England and looted monasteries, sailed");
        put_text_at(120,180,"to Constantinople and became mercenaries, sailed to Russia");
        put_text_at(120,200,"and captured slaves, sailed to France and settled down,");
        put_text_at(120,220,"and the most important Vikings were buried in boats. In");
        put_text_at(120,240,"this game, you play Vikings trying to sail to Vinland (North");
        put_text_at(120,260,"America) to establish a settlement there and live off");
        put_text_at(120,280,"the fat of the land, far away from the bitter snows of");
        put_text_at(120,300,"Norway.");
        
        if (Mix_Playing(-1) == 0) Mix_PlayChannel(-1, SOUNDS[SND_MAIN_MENU], 0);
        SDL_Flip(MAIN_SCREEN);
        SDL_Delay(100);
        
  
    }
    
    return 0;
}
