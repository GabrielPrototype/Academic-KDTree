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

typedef struct {
    int xcord, ycord;
    char tag[TAGLEN];
} Dot;

typedef struct {
    Dot dotinfo;
    char dif;
    struct KDTreeNode *left;
    struct KDTreeNode *right;
} KDTreeNode;

typedef struct {
    KDTreeNode *info;
    struct KDStack *next;
} KDStack;


#endif /* KDTREE_H */