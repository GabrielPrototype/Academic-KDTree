/*
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

    if (dif == 0) /* Caso diferenciador seja 0, compara-se a dimensão 1, X no caso*/
        return (dot1->xcord > dot2->xcord);
    else /* Caso contrario, compara-se a dimensão 2, Y no caso*/
        return (dot1->ycord > dot2->ycord);
}

void kdtreeInsert(KDTreeNode **root, Dot kddot) {
    KDTreeNode *nodeAux;
    KDTreeNode *nodeAnt = NULL;

    if (!*root) /* *root == null*/
        *root = kdnodeInit(&kddot, 0);
    else {
        nodeAux = *root;
        while (nodeAux) /* nodeAux != null*/ {
            nodeAnt = nodeAux;
            if (kddotCompare(&kddot, &nodeAnt->dotinfo, nodeAnt->dif))
                nodeAux = nodeAux->right;
            else
                nodeAux = nodeAux->left;
        }
        if (kddotCompare(&kddot, &nodeAnt->dotinfo, nodeAnt->dif))
            nodeAnt->right = kdnodeInit(&kddot, !nodeAnt->dif);
        else
            nodeAnt->left = kdnodeInit(&kddot, !nodeAnt->dif);
    }
}

double kddotCalcDistance(Dot *dotA, Dot *dotB) { /* Euclidian metric*/

    double distX = dotA->xcord - dotB->xcord; //calculating number to square in next step
    double distY = dotA->ycord - dotB->ycord;
    double dist;

    dist = pow(distX, 2) + pow(distY, 2); //calculating Euclidean distance
    dist = sqrt(dist);

    return dist;
}

KDTreeNode *kdtreeSearchNearestInRadius(KDTreeNode **node, KDTreeNode *subroot, Dot center, double radius) {

    double dist;
    if (subroot) { /* root != null*/
        dist = kddotCalcDistance(&subroot->dotinfo, &center);

        if (dist < radius) /* ponto está dentro da circunferencia*/
            *node = subroot;
        else {
            if (subroot->dif == 0) {/*dif 0, compara X*/
                if ((center.xcord - radius) < subroot->dotinfo.xcord)
                    kdtreeSearchNearestInRadius(&*node, subroot->left, center, radius);
                else
                    if ((center.xcord + radius) >= subroot->dotinfo.xcord)
                    kdtreeSearchNearestInRadius(&*node, subroot->right, center, radius);
            } else { /*caso contrario, compara y*/
                if ((center.ycord - radius) < subroot->dotinfo.ycord)
                    kdtreeSearchNearestInRadius(&*node, subroot->left, center, radius);
                else
                    if ((center.ycord + radius) >= subroot->dotinfo.ycord)
                    kdtreeSearchNearestInRadius(&*node, subroot->right, center, radius);
            }
        }
    }
}

KDTreeNode *kdtreeSearchInRadius(KDStack **stack, KDTreeNode *subroot, Dot center, double radius, char flag) {

//    double dist;
//    if (subroot) { /* root != null*/
//        dist = kddotCalcDistance(&subroot->dotinfo, &center);
//
//        if (dist <= radius) { /* ponto está dentro da circunferencia*/
//            kdstackPush(&(*stack), subroot);
//
//            if (flag == -1)
//                flag = 0;
//
//            if (subroot->dif == 0) {/*dif 0, compara X*/
//                if ((center.xcord - radius) < subroot->dotinfo.xcord)
//                    kdtreeSearchInRadius(&*stack, subroot->left, center, radius);
//                else
//                    if ((center.xcord + radius) >= subroot->dotinfo.xcord)
//                    kdtreeSearchInRadius(&*stack, subroot->right, center, radius);
//            } else { /*caso contrario, compara y*/
//                if ((center.ycord - radius) < subroot->dotinfo.ycord)
//                    kdtreeSearchInRadius(&*stack, subroot->left, center, radius);
//                else
//                    if ((center.ycord + radius) >= subroot->dotinfo.ycord)
//                    kdtreeSearchInRadius(&*stack, subroot->right, center, radius);
//            }
//        } else {
//            if (flag == 0)
//                flag = 1; /*quando a busca já se distanciou.*/
//        }
//    }
}

void kdstackPush(KDStack **stack, KDTreeNode *node) {

    if (node) {
        KDStack *newstk = malloc(sizeof (KDStack));
        newstk->info = node;
        (*stack)->next = (*stack) ? *stack : NULL;
        *stack = newstk;
    }
}

void kdstackPopV2(KDStack **stack, KDTreeNode **node) {
    *node = *stack ? (*stack)->info : NULL;
    *stack = (*stack)->next;
}

KDTreeNode * kdstackPop(KDStack **stack) {

    KDTreeNode *aux;
    aux = *stack ? (*stack)->info : NULL;
    *stack = (*stack)->next;
    return aux;
}

void kdnodePrint(KDTreeNode *node) {
    printf("(%.2f,%.2f) -[%s]", node->dotinfo.xcord, node->dotinfo.ycord, node->dotinfo.tag);
}

void inOrden(KDTreeNode *subroot) {
    if (subroot != NULL) {
        inOrden(subroot->left);
        kdnodePrint(subroot);
        inOrden(subroot->right);
    }
}

void preOrden(KDTreeNode *subroot) {
    if (subroot != NULL) {
        kdnodePrint(subroot);
        preOrden(subroot->left);
        preOrden(subroot->right);
    }
}