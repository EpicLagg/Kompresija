#ifndef FILIP_H
#define FILIP_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void upis2dint(int n, int m, int (*matrica)[n], char *ime);
void ispis2dint(int n, int m, int (*matrica)[n]);
double filiplog(double baza, double broj);
int intunos(char *tekst);
char charunos(char *tekst);
void chrrmv(char *recenica, char znak, int redni_broj);
void strrmv(char *haystack, char *needle);
char *strfnd(char *haystack, char *needle);
void fgetline(char *niz, int broj, size_t arraysize, FILE *f);
int longestline(FILE *f);
int textlength(FILE *f);

#endif // FILIP_H
