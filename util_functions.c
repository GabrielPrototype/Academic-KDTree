/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

char* fgetsplus(char str[], int count, FILE * restrict stream) {

    __fpurge(stdin);
    fgets(str, count, stream);
    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';
    return str;
}

double randFrom(double min, double max) {
    double f = (double) rand() / RAND_MAX;
    return min + f * (max - min);
}

void strToUpper(char s[], size_t maxsize) {
    int i;
    for (i = 0; i < maxsize && s[i] != '\0'; i++) {

        s[i] = toupper(s[i]);
    }
}