/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <string.h>



char* fgetsplus(char *restrict str, int count, FILE *restrict stream){

    __fpurge(stdin);
    fgets(str,count,stream);
    int len = strnlen(str, sizeof(str));
    if(str[len-1] == '\n' && str[len] == '\0' )
        str[len-1] = '\0';
    return str;
}
