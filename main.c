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

void tests();

int main(int argc, char** argv) {
    
    insertTest();
    //tests();
    return (EXIT_SUCCESS);
}


void insertTest(){
    
    double xcord, ycord;
    char str[TAGLEN];
    
    KDTreeNode *root = NULL; 
    Dot testdot;
    
    printf("Insira a descrição:");
    fgetsplus(str,TAGLEN, stdin);
    
    while(strcmp(str,"exit")){
        printf("insira os pontos: ");
        scanf(" %lf %lf",&xcord, &ycord);
        testdot.xcord = xcord;
        testdot.ycord = ycord;
        strncpy(testdot.tag,str,TAGLEN);
        kdtreeInsert(&root, testdot);
        printf("Insira a descrição:");
        fgetsplus(str,TAGLEN, stdin);
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


