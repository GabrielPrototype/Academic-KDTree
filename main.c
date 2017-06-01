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
    int num = 0;
    int i;

    Dot kddot;
    KDTreeNode *root = NULL;

    cliTextHead();
    printf("\nCMD>");
    fgetsplus(cmd_line, CMD_LINE_MAX, stdin);
    strToUpper(cmd_line, sizeof (cmd_line));

    while (strncmp(cmd_line, "EXIT", CMD_LINE_MAX) != 0) {

        if (strncmp(cmd_line, "INSERT INTO TREE ", 17) == 0) {

            strncpy(cmd_line, &cmd_line[17], CMD_LINE_MAX);
            cmd_aux_ptr = strtok(cmd_line, ";");

            if (sscanf(cmd_aux_ptr, "%lf", &kddot.xcoord) != 0) {
                cmd_aux_ptr = strtok(NULL, ";");

                if (sscanf(cmd_aux_ptr, "%lf", &kddot.ycoord) != 0) {

                    if (kddot.ycoord >= 0 && kddot.ycoord <= 90 && kddot.xcoord >= 0 && kddot.xcoord <= 180) {
                        //printf("---> ok");
                        strncpy(kddot.tag, " ", TAGLEN);
                        kdtreeInsert(&root, kddot);
                        printf("\n---> Inserted (%3.3f, %2.3f) successfully\n", kddot.xcoord, kddot.ycoord);

                        cmd_ok = !NULL;
                    } else {
                        printf("\n--->Coordinates out of range (x: 0 to 180, y: 0 to 90)\n");

                    }
                }
            }

        } else if (strncmp(cmd_line, "SHOW TREE", CMD_LINE_MAX) == 0) {
            printf("\n");
            treePrinter(root);
            printf("\n");

            cmd_ok = !NULL;

        } else if (strncmp(cmd_line, "SHOW TREE PRE ORDER", CMD_LINE_MAX) == 0) {
            printf("\n");
            preOrden(root);
            printf("\n");

            cmd_ok = !NULL;

        } else if (strncmp(cmd_line, "SEARCH IN TREE AT POINT ", 24) == 0) {
            printf("\n3\n");

            cmd_ok = !NULL;

        } else if (strncmp(cmd_line, "INSERT AUTO ", 12) == 0) {

            strncpy(cmd_line, &cmd_line[12], CMD_LINE_MAX);
            if (sscanf(cmd_line, "%d", &num) != 0 && num > 0 && num < 5999) {
                
                printf("\n");
                for (i = 0; i < num; i++) {
                    kddot.xcoord = randFrom(-99.0, 99.0);
                    kddot.ycoord = randFrom(-99.0, 99.0);
                    strncpy(kddot.tag, " ", TAGLEN);
                    kdtreeInsert(&root, kddot);
                    printf("---> Inserted (%3.3f, %2.3f) successfully\n", kddot.xcoord, kddot.ycoord);
                }
            } else {
                printf("\n--->Error in argument\n");
            }

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
            "*  INSERT INTO TREE [xcoord];[ycoord]\n"
            "*  SHOW TREE\n"
            "*  SHOW TREE PRE ODER\N"
            "*  SEARCH IN TREE AT POINT [xcoord];[ycoord] WITH RADIUS [radius]\n"
            "*  INSERT AUTO [number of random points]\n"
            "* \n"
            "*  EXIT\n"
            "*********\n");

}

