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

char kddotCompare(Dot *dot1, Dot *dot2, char dif);

void kdtreeInsert(KDTreeNode **root, Dot kddot);

double kddotCalcDistance(Dot *dotA, Dot *dotB);

KDTreeNode *kdtreeSearchNearestInRadius(KDTreeNode **node, KDTreeNode *subroot, Dot center, double radius);

KDTreeNode *kdtreeSearchInRadius(KDStack **stack, KDTreeNode *subroot, Dot center, double radius);

void kdstackPush(KDStack **stack, KDTreeNode *node);

void kdstackPopV2(KDStack **stack, KDTreeNode **node);

KDTreeNode * kdstackPop(KDStack **stack);

void kdnodePrint(KDTreeNode *node);

void inOrden(KDTreeNode *subroot);

void preOrden(KDTreeNode *subroot);

void treePrinter(KDTreeNode *subroot);
/*      prototypes */
#endif /* KDTREE_H */