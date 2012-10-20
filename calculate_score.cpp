#include "header.h"
#include "globals.h"

int calculate_score() {
    
    return ((INVENTORY.settlers + INVENTORY.money + INVENTORY.boat_status + how_many_alive()*5)*365)/DAYS;
    //return (1000-DAYS)*DISTANCE; // kludge
    // double kludge for using a global for score, but oh well
}
