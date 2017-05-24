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
    printf("%d %d %s\n", test->xcord, test->ycord, test->tag);
    KDTreeNode *nodetest = kdnodeInit(test, 0);
    getchar();
}