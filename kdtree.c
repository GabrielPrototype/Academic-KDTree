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

KDTreeNode *kdnodeInit(Dot *kddot, char dif){

    KDTreeNode *kdnode = malloc(sizeof(KDTreeNode));
    kdnode->dif = dif;
    kdnode->left = NULL;
    kdnode->right = NULL;
    kdnode->dotinfo = *kddot;
    return kdnode;
}



