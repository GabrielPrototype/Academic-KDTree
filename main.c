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
    char cmd_aux[CMD_LINE_MAX];
    char *cmd_aux_ptr = NULL;
    char cmd_ok = '\0';
    double radius = 0;
    int num = 0;
    int i;

    Dot kddot;
    KDTreeNode *root = NULL;
    KDTreeNode *resultNode = NULL;
    KDStack *kdstck = NULL;

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
                        strncpy(kddot.tag, " ", TAGLEN);
                        kdtreeInsert(&root, kddot);
                        printf("\n---> Inserted (%7.3f, %7.3f) successfully\n", kddot.xcoord, kddot.ycoord);

                        cmd_ok = !NULL;
                    } else {
                        printf("\n--->Coordinates out of range (x: 0 to 180, y: 0 to 90)\n");

                    }
                } else {
                    printf("\n--->Error in argument\n");
                }
            } else {
                printf("\n--->Error in argument\n");
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
            strncpy(cmd_line, &cmd_line[24], CMD_LINE_MAX);
            strncpy(cmd_aux, cmd_line, CMD_LINE_MAX);
            cmd_ok = !NULL;

            if (sscanf(cmd_aux, "%lf", &kddot.xcoord) != 0) {

                if (sscanf(cmd_aux, "%*f;%lf", &kddot.ycoord) != 0) {

                    if (sscanf(cmd_aux, "%*f;%*f WITH RADIUS %lf", &radius) != 0) {
                        kdtreeSearchNearestInRadius(&resultNode, root, kddot, radius);
                        printf("---- Nearest point of %.2f;%.2f in a radius %.2f:\n", kddot.xcoord, kddot.ycoord, radius);
                        printf("---- (%03.2f;%03.2f)\n", resultNode->dotinfo.xcoord, resultNode->dotinfo.ycoord);

                    } else {
                        printf("\n---> Error in argument\n");
                    }
                } else {
                    printf("\n---> Error in argument\n");
                }

            } else {
                printf("\n---> Error in argument\n");
            }
        } else if (strncmp(cmd_line, "SEARCH ALL IN TREE AT POINT ", 28) == 0) {
            strncpy(cmd_line, &cmd_line[28], CMD_LINE_MAX);
            strncpy(cmd_aux, cmd_line, CMD_LINE_MAX);
            cmd_ok = !NULL;

            if (sscanf(cmd_aux, "%lf", &kddot.xcoord) != 0) {

                if (sscanf(cmd_aux, "%*f;%lf", &kddot.ycoord) != 0) {

                    if (sscanf(cmd_aux, "%*f;%*f WITH RADIUS %lf", &radius) != 0) {
                        kdtreeSearchInRadius(&kdstck, root, kddot, radius);
                        printf("---- All points within a radius %.2f with center at %.2f;%.2f:\n", radius, kddot.xcoord, kddot.ycoord);
                        while (kdstck) {
                            resultNode = kdstackPop(&kdstck);
                            if (resultNode)
                                printf("---- (%07.2f;%07.2f)\n", resultNode->dotinfo.xcoord, resultNode->dotinfo.ycoord);
                        }

                    } else {
                        printf("\n---> Error in argument\n");
                    }
                } else {
                    printf("\n---> Error in argument\n");
                }

            } else {
                printf("\n---> Error in argument\n");
            }
        } else if (strncmp(cmd_line, "INSERT AUTO ", 12) == 0) {

            strncpy(cmd_line, &cmd_line[12], CMD_LINE_MAX);
            if (sscanf(cmd_line, "%d", &num) != 0 && num > 0 && num < 5999) {

                printf("\n");
                for (i = 0; i < num; i++) {
                    kddot.xcoord = randFrom(0.0, 180.0);
                    kddot.ycoord = randFrom(0.0, 99.0);
                    strncpy(kddot.tag, " ", TAGLEN);
                    kdtreeInsert(&root, kddot);
                    printf("---> Inserted (%7.3f, %7.3f) successfully\n", kddot.xcoord, kddot.ycoord);
                }
            } else {
                printf("\n--->Error in argument\n");
            }

            cmd_ok = !NULL;
        } else if (strncmp(cmd_line, "CLEAR", 5) == 0) {
            system("clear");
            cmd_ok = !NULL;
        }
        if (strncmp(cmd_line, "HELP", 5) == 0) {
            printf("\n");
            cliTextHead();
            cmd_ok = !NULL;
        }

        if (!cmd_ok) {
            printf("\nInvalid Command\n");

        }

        cmd_line[0] = '\0';
        printf("\nCMD>");
        fgetsplus(cmd_line, CMD_LINE_MAX, stdin);
        strToUpper(cmd_line, sizeof (cmd_line));
        cmd_ok = '\0';
    }
    return (EXIT_SUCCESS);
}

int cliTextHead() {

    printf("K-D Tree App, Gabriel L. P. Abreu\n"
            "*********\n"
            "* Commands:\n"
            "*  INSERT INTO TREE [xcoord];[ycoord]\n"
            "*  SHOW TREE\n"
            "*  SHOW TREE PRE ODER\n"
            "*  SEARCH IN TREE AT POINT [xcoord];[ycoord] WITH RADIUS [radius]\n"
            "*  SEARCH ALL IN TREE AT POINT [xcoord];[ycoord] WITH RADIUS [radius]\n"
            "*  INSERT AUTO [number of random points]\n"
            "*  \n"
            "*  HELP (Print this text)\n"
            "*  EXIT\n"
            "*********\n");

}

