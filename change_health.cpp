#include "header.h"
#include "globals.h"

int change_health(int partymember, int change) {
    
    if (PARTY[partymember].health <= 0) return 0; // he's dead, jim
    
    PARTY[partymember].health += change;
    if (PARTY[partymember].health <= 0) PARTY[partymember].health = 0;
    if (PARTY[partymember].health >= 100) PARTY[partymember].health = 100;
    return 0;
}
