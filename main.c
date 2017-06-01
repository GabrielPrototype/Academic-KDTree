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
#include "headers/util_functions.h"

#define CMD_LINE_MAX 255
/*
 * 
 */

/*  Prototypes */


/*  Prototypes */




int main(int argc, char** argv) {

    setbuf(stdin, NULL);
    
    char cmd_line[CMD_LINE_MAX];

    printf("K-D Tree App, Gabriel L. P. Abreu\n"
            "*********\n"
            "* Commands:\n"
            "*  INSERT INTO TREE [xcord];[ycord]\n"
            "*  SHOW TREE\n"
            "*  SEARCH IN TREE AT POINT [xcord];[ycord] WITH RADIUS [radius]\n"
            "*********");
    printf("\nCMD>");
    fgetsplus(cmd_line, CMD_LINE_MAX, stdin);
    strToUpper(cmd_line, sizeof (cmd_line));
    return (EXIT_SUCCESS);
}




