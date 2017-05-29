/*
 * 
 */

/* 
 * File:   kdtree.h
 * Author: Gabriel L. P. Abreu
 *
 * Created on 22 de Maio de 2017, 06:29
 */

#ifndef KDTREE_H
#define KDTREE_H

#include <string.h>
#include <math.h>

#define TAGLEN 35

typedef struct Dot {
    double xcord, ycord;
    char tag[TAGLEN];
} Dot;

typedef struct KDTreeNode {
    Dot dotinfo;
    char dif;
    struct KDTreeNode *left;
    struct KDTreeNode *right;
} KDTreeNode;

typedef struct KDStack {
    KDTreeNode *info;
    struct KDStack *next;
} KDStack;
/*      prototypes */
Dot *dotInit(double x, double y, char *info);
KDTreeNode *kdnodeInit(Dot *kddot, char dif);
/*      prototypes */
#endif /* KDTREE_H */