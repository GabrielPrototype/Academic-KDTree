/* 
 * File:   util_functions.h
 * Author: Gabriel L. P. Abreu
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "headers/kdtree.h"

Dot *dotInit(double x, double y, char *info) {
    Dot *newdot = malloc(sizeof (Dot));
    newdot->xcoord = x;
    newdot->ycoord = y;
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

char kddotCompare(Dot *dot1, Dot *dot2, char dif) {

    if (dif == 0) /* Caso diferenciador seja 0, compara-se a dimensão 1, X no caso*/
        return (dot1->xcoord > dot2->xcoord);
    else /* Caso contrario, compara-se a dimensão 2, Y no caso*/
        return (dot1->ycoord > dot2->ycoord);
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

    double distX = dotA->xcoord - dotB->xcoord; //calculating number to square in next step
    double distY = dotA->ycoord - dotB->ycoord;
    double dist;

    dist = pow(distX, 2) + pow(distY, 2); //calculating Euclidean distance
    dist = sqrt(dist);

    return dist;
}

KDTreeNode *kdtreeSearchNearestInRadius(KDTreeNode **node, KDTreeNode *subroot, Dot center, double radius) {

    double dist;
    if (subroot) { /* root != null*/
        dist = kddotCalcDistance(&subroot->dotinfo, &center);

        if (dist <= radius) /* ponto está dentro da circunferencia*/
            *node = subroot;
        else {
            if (subroot->dif == 0) {/*dif 0, compara X*/
                if ((center.xcoord - radius) < subroot->dotinfo.xcoord)
                    kdtreeSearchNearestInRadius(&*node, subroot->left, center, radius);
                else
                    if ((center.xcoord + radius) >= subroot->dotinfo.xcoord)
                    kdtreeSearchNearestInRadius(&*node, subroot->right, center, radius);
            } else { /*caso contrario, compara y*/
                if ((center.ycoord - radius) < subroot->dotinfo.ycoord)
                    kdtreeSearchNearestInRadius(&*node, subroot->left, center, radius);
                else
                    if ((center.ycoord + radius) >= subroot->dotinfo.ycoord)
                    kdtreeSearchNearestInRadius(&*node, subroot->right, center, radius);
            }
        }
    }
}

KDTreeNode *kdtreeSearchInRadius(KDStack **stack, KDTreeNode *subroot, Dot center, double radius) {

    double dist;
    if (subroot) { /* root != null*/
        dist = kddotCalcDistance(&subroot->dotinfo, &center);

        if (dist <= radius) { /* ponto está dentro da circunferencia*/
            kdstackPush(&(*stack), subroot);

            if (subroot->dif == 0) {/*dif 0, compara X*/
                if ((center.xcoord - radius) < subroot->dotinfo.xcoord)
                    kdtreeSearchInRadius(&*stack, subroot->left, center, radius);
                else
                    if ((center.xcoord + radius) >= subroot->dotinfo.xcoord)
                    kdtreeSearchInRadius(&*stack, subroot->right, center, radius);
            } else { /*caso contrario, compara y*/
                if ((center.ycoord - radius) < subroot->dotinfo.ycoord)
                    kdtreeSearchInRadius(&*stack, subroot->left, center, radius);
                else
                    if ((center.ycoord + radius) >= subroot->dotinfo.ycoord)
                    kdtreeSearchInRadius(&*stack, subroot->right, center, radius);
            }
        }
    }
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
    printf("((%.2f,%.2f)-[%s]) ", node->dotinfo.xcoord, node->dotinfo.ycoord, node->dotinfo.tag);
}

void inOrden(KDTreeNode *subroot) {
    if (subroot != NULL) {
        printf("{");
        inOrden(subroot->left);
        kdnodePrint(subroot);
        printf(",");
        inOrden(subroot->right);
        printf("}");
    }
}

void preOrden(KDTreeNode *subroot) {
    if (subroot != NULL) {
        printf("{");
        kdnodePrint(subroot);
        preOrden(subroot->left);
        printf(",");
        preOrden(subroot->right);
        printf("}");
    }
}

char tprinter_depth[ 2056 ];
int tprinter_di;

void treePrinterPush(char c) {
    tprinter_depth[ tprinter_di++ ] = ' ';
    tprinter_depth[ tprinter_di++ ] = c;
    tprinter_depth[ tprinter_di++ ] = ' ';
    tprinter_depth[ tprinter_di++ ] = ' ';
    tprinter_depth[ tprinter_di ] = 0;
}

void TreePrinterPop() {
    tprinter_depth[ tprinter_di -= 4 ] = 0;
}

void treePrinterRec(KDTreeNode *subroot) {

    setbuf(stdout, NULL);
    printf("(%03.2f; %03.2f)\n", subroot->dotinfo.xcoord, subroot->dotinfo.ycoord);
    
    if (subroot->right) {
        printf("%s `-(RIGHT)--", tprinter_depth);
        treePrinterPush(' ');
        treePrinterRec(subroot->right);
        TreePrinterPop(tprinter_depth);
    }
    if (subroot->left) {
        printf("%s `-(LEFT )--", tprinter_depth);
        treePrinterPush('|');
        treePrinterRec(subroot->left);
        TreePrinterPop(tprinter_depth);
    }
    
}

void treePrinter(KDTreeNode *subroot) {

    if (subroot) {
        treePrinterRec(subroot);
    }
}