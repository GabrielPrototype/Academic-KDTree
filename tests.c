/* 
 * File:   tests.c
 * Author: Titan
 */

#include <stdio.h>

#include "headers/kdtree.h"


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

int _print_t(KDTreeNode *subroot, int is_left, int offset, int depth, char s[30][255])
{
    char b[40];
    int width = 16;

    if (!subroot) return 0;

    sprintf(b,"(%03.2f;%03.2f)",subroot->dotinfo.xcord,subroot->dotinfo.ycord);

    int left  = _print_t(subroot->left,  1, offset,                depth + 1, s);
    int right = _print_t(subroot->right, 0, offset + left + width, depth + 1, s);
    

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {
        
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }

    return left + width + right;
}

void print_t(KDTreeNode *root)
{
    int lines = 30;
    char s[lines][255];
    for (int i = 0; i < lines; i++)
        sprintf(s[i], "%120s", " ");

    _print_t(root, 0, 0, 0, s);

    for (int i = 0; i < lines; i++)
        printf("%s\n", s[i]);
}