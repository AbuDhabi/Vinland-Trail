#include "header.h"
#include "globals.h"

int how_many_alive() {
    int alive=0;
    for (int i=0;i<5;i++) if (PARTY[i].health > 0) alive++;
    return alive;
}
