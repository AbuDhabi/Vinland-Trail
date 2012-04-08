#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

extern int MAXX;
extern int MAXY;
extern SDL_Surface* BITMAPS[255];
extern Mix_Chunk* SOUNDS[255];
extern TTF_Font* FONT_GEORGIA;
extern SDL_Surface* MAIN_SCREEN;
extern bool END_PROGRAM;
extern int state;
extern SDL_Color DEFAULT_COLOR;
extern PartyMember PARTY[5];
extern int CLASS;
extern Equipment INVENTORY;
extern bool END_PROGRAM;
extern int state;
extern int DISTANCE;
extern int DAYS;
extern int SCORE;
extern int PACE;
extern int RATIONS;
extern bool PAUSED;
extern int LANDMARKS;

#endif // GLOBALS_H_INCLUDED
