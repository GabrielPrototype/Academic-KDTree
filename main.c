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
#include <stdlib.h>

#include "headers/kdtree.h"
#include "headers/util_functions.h"

/*
 * 
 */

/*  Prototypes */
void tests();
void autoInsertTest();
void insertTest();
/*  Prototypes */

int main(int argc, char** argv) {

    autoInsertTest();
    //insertTest();
    //tests();
    return (EXIT_SUCCESS);
}


void autoInsertTest() {

    KDTreeNode *root = NULL;
    double xcord, ycord;
    Dot testdot;
    int i;
    for (i = 0; i < 30; i++) {
        xcord = randFrom(-99.0, 99.0);
        ycord = randFrom(-99.0, 99.0);
        testdot.xcord = xcord;
        testdot.ycord = ycord;
        strncpy(testdot.tag, " ", TAGLEN);
        kdtreeInsert(&root, testdot);
    }
    //preOrden(root);
    printf("\n\n");
    treePrinter(root);
}

void insertTest() {

    double xcord, ycord;
    char str[TAGLEN];

    KDTreeNode *root = NULL;
    Dot testdot;

    printf("Insira a descrição:");
    fgetsplus(str, TAGLEN, stdin);

    while (strcmp(str, "exit")) {
        printf("insira os pontos: ");
        scanf(" %lf %lf", &xcord, &ycord);
        testdot.xcord = xcord;
        testdot.ycord = ycord;
        strncpy(testdot.tag, str, TAGLEN);
        kdtreeInsert(&root, testdot);
        printf("Insira a descrição:");
        fgetsplus(str, TAGLEN, stdin);
    }

    preOrden(root);
    printf("\n");
    treePrinter(root);

    getchar();
};

void tests() {

    Dot *test = dotInit(2, 4, "TESTE");
    printf("%f %f %s\n", test->xcord, test->ycord, test->tag);
    KDTreeNode *nodetest = kdnodeInit(test, 0);
    getchar();
}


