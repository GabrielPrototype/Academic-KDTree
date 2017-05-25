/*
 *
 */

/* 
 * File:   main.c
 * Author: Gabriel L. P. Abreu
 *
 * Created on 21 de Maio de 2017, 20:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <gvc.h>

#include "headers/kdtree.h"

/*
 * 
 */
int main(int argc, char** argv) {

    tests();
    return (EXIT_SUCCESS);
}

void tests() {

    Dot *test = dotInit(2, 4, "TESTE");
    printf("%f %f %s\n", test->xcord, test->ycord, test->tag);
    KDTreeNode *nodetest = kdnodeInit(test, 0);
    getchar();
}

void graphvizTest() {

    Agraph_t* G;
    GVC_t* gvc;
    gvc = gvContext();
    G = createGraph();
    gvLayout(gvc, G, "dot");
    drawGraph(G);
    gvFreeLayout(gvc, g);
    agclose(G);
    gvFreeContext(gvc);

}