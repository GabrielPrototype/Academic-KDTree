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

int cliTextHead();

/*  Prototypes */




int main(int argc, char** argv) {

    setbuf(stdin, NULL);

    char cmd_line[CMD_LINE_MAX];
    char cmd_aux[30];
    char *cmd_aux_ptr = NULL;
    char cmd_ok = NULL;

    Dot kddot;

    cliTextHead();
    printf("\nCMD>");
    fgetsplus(cmd_line, CMD_LINE_MAX, stdin);
    strToUpper(cmd_line, sizeof (cmd_line));

    while (strncmp(cmd_line, "EXIT", CMD_LINE_MAX) != 0) {

        if (strncmp(cmd_line, "INSERT INTO TREE ", 17) == 0) {
            strncpy(cmd_line, &cmd_line[17], CMD_LINE_MAX);
            cmd_aux_ptr = strtok(cmd_line, ";");
            if (sscanf(cmd_aux_ptr, "%lf", &kddot.xcord) != 0) {
                cmd_aux_ptr = strtok(NULL, ";");
                if (sscanf(cmd_aux_ptr, "%lf", &kddot.ycord) != 0) {
                    printf("ok");
                    cmd_ok = !NULL;
                }
            }

        } else if (strncmp(cmd_line, "SHOW TREE", 9) == 0) {
            printf("\n2\n");
            cmd_ok = !NULL;
        } else if (strncmp(cmd_line, "SEARCH IN TREE AT POINT ", 24) == 0) {
            printf("\n3\n");
            cmd_ok = !NULL;
        } else if (strncmp(cmd_line, "INSERT AUTO ", 24) == 0) {
            cmd_ok = !NULL;
        } else if (strncmp(cmd_line, "CLEAR", 5) == 0) {
            system("clear");
            cmd_ok = !NULL;
        }

        if (!cmd_ok) {
            printf("\nInvalid Command\n");

        }

        cmd_line[0] = "\0";
        //cliTextHead();
        printf("\nCMD>");
        fgetsplus(cmd_line, CMD_LINE_MAX, stdin);
        strToUpper(cmd_line, sizeof (cmd_line));
        cmd_ok = NULL;
    }
    return (EXIT_SUCCESS);
}

int cliTextHead() {

    printf("K-D Tree App, Gabriel L. P. Abreu\n"
            "*********\n"
            "* Commands:\n"
            "*  INSERT INTO TREE [xcord];[ycord]\n"
            "*  SHOW TREE\n"
            "*  SEARCH IN TREE AT POINT [xcord];[ycord] WITH RADIUS [radius]\n"
            "*  INSERT AUTO [number of random points]"
            "* \n"
            "*  EXIT\n"
            "*********\n");

}

