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
    getchar();
};

void tests() {

    Dot *test = dotInit(2, 4, "TESTE");
    printf("%f %f %s\n", test->xcord, test->ycord, test->tag);
    KDTreeNode *nodetest = kdnodeInit(test, 0);
    getchar();
}

//void graphvizTest() {
//
//    Agraph_t* G;
//    GVC_t* gvc;
//    gvc = gvContext();
//    G = createGraph();
//    gvLayout(gvc, G, "dot");
//    drawGraph(G);
//    gvFreeLayout(gvc, g);
//    agclose(G);
//    gvFreeContext(gvc);
//
//}

//int _print_t(tnode *tree, int is_left, int offset, int depth, char s[20][255])
//{
//    char b[20];
//    int width = 5;
//
//    if (!tree) return 0;
//
//    sprintf(b, "(%03d)", tree->val);
//
//    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
//    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);
//
//#ifdef COMPACT
//    for (int i = 0; i < width; i++)
//        s[depth][offset + left + i] = b[i];
//
//    if (depth && is_left) {
//
//        for (int i = 0; i < width + right; i++)
//            s[depth - 1][offset + left + width/2 + i] = '-';
//
//        s[depth - 1][offset + left + width/2] = '.';
//
//    } else if (depth && !is_left) {
//
//        for (int i = 0; i < left + width; i++)
//            s[depth - 1][offset - width/2 + i] = '-';
//
//        s[depth - 1][offset + left + width/2] = '.';
//    }
//#else
//    for (int i = 0; i < width; i++)
//        s[2 * depth][offset + left + i] = b[i];
//
//    if (depth && is_left) {
//
//        for (int i = 0; i < width + right; i++)
//            s[2 * depth - 1][offset + left + width/2 + i] = '-';
//
//        s[2 * depth - 1][offset + left + width/2] = '+';
//        s[2 * depth - 1][offset + left + width + right + width/2] = '+';
//
//    } else if (depth && !is_left) {
//
//        for (int i = 0; i < left + width; i++)
//            s[2 * depth - 1][offset - width/2 + i] = '-';
//
//        s[2 * depth - 1][offset + left + width/2] = '+';
//        s[2 * depth - 1][offset - width/2 - 1] = '+';
//    }
//#endif
//
//    return left + width + right;
//}
//
//void print_t(tnode *tree)
//{
//    char s[20][255];
//    for (int i = 0; i < 20; i++)
//        sprintf(s[i], "%80s", " ");
//
//    _print_t(tree, 0, 0, 0, s);
//
//    for (int i = 0; i < 20; i++)
//        printf("%s\n", s[i]);
//}
