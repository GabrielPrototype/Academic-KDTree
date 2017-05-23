/*
 *
 */

#include <stdlib.h>

#include "headers/kdtree.h"


Dot *dotInit(int x, int y, char *info) {
    Dot *newdot = malloc(sizeof(Dot));
    newdot->xcord = x;
    newdot->ycord = y;
    strncpy(newdot->tag, info, TAGLEN);
    return newdot;
}