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
    
    
    Dot *test = dotInit(2,4,"TESTE");
    
    printf("%d %d %s", test->xcord, test->ycord, test->tag);
    return (EXIT_SUCCESS);
}

