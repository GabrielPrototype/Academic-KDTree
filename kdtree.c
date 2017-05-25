/*
 *
 */

#include <stdlib.h>

#include "headers/kdtree.h"

Dot *dotInit(double x, double y, char *info) {
    Dot *newdot = malloc(sizeof (Dot));
    newdot->xcord = x;
    newdot->ycord = y;
    strncpy(newdot->tag, info, TAGLEN);
    return newdot;
}

KDTreeNode *kdnodeInit(Dot *kddot, char dif) {

    KDTreeNode *kdnode = malloc(sizeof (KDTreeNode));
    kdnode->dif = dif;
    kdnode->left = NULL;
    kdnode->right = NULL;
    kdnode->dotinfo = *kddot;
    return kdnode;
}

//int kddotCompare(KDTreeNode node1, KDTreeNode node2, char dif) {
//    /* Caso diferenciador seja 1, compara-se a dimensão 2, Y no caso*/
//    if (dif == 1) { 
//        if (node1.pY == node2.pY)
//            return 0;
//        else {
//            return (node1.pY > node2.pY) ? 1 : -1;
//        }
//
//    }
//    /* Caso diferenciador seja 0, compara-se a dimensão 1, X no caso*/
//    if (node1.pX == node2.pX)
//        return 0;
//    else {
//        return (node1.pX > node2.pX) ? 1 : -1;
//    }
//
//}

char kddotCompare(Dot *dot1, Dot *dot2, char dif) {

    if (dif == 0)   /* Caso diferenciador seja 0, compara-se a dimensão 1, X no caso*/
        return (dot1->xcord > dot2->xcord);
    else            /* Caso contrario, compara-se a dimensão 2, Y no caso*/
        return (dot1->ycord > dot2->ycord);
}

void kdtreeInsert(KDTreeNode **root, Dot kddot) {
    KDTreeNode *nodeAux;
    KDTreeNode *nodeAnt = NULL;

    if (!*root) /* *root == null*/
        *root = kdnodeInit(kddot, 0);
    else {
        nodeAux = *root;
        while (nodeAux) /* nodeAux != null*/ {
            nodeAnt = nodeAux;
            if (kddotCompare(kddot, nodeAnt->dotinfo, nodeAnt->dif))
                nodeAux = nodeAux->right;
            else
                nodeAux = nodeAux->left;
        }
        if (kddotCompare(kddot, nodeAnt->dotinfo, nodeAnt->dif))
            nodeAnt->right = kdnodeInit(kddot, !nodeAnt->dif);
        else
            nodeAnt->left = kdnodeInit(kddot, !nodeAnt->dif);
    }
}



