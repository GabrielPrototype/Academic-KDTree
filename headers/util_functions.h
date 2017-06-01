/*
 * 
 */

/* 
 * File:   util_functions.h
 * Author: Gabriel L. P. Abreu
 *
 */

#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H



char* fgetsplus(char *restrict str, int count, FILE *restrict stream);

double randFrom(double min, double max);

void strToUpper(char s[], size_t maxsize);
#endif /* UTIL_FUNCTIONS_H */

