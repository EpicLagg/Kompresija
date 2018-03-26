#include "filip.h"

void upis2dint(int n, int m, int (*matrica)[n], char *ime)
{
    for(int i = 0; i < n; i++) {
        for(int ii = 00; ii < m; ii++) {
            printf("%s[%d][%d] = ", ime, i, ii);
            scanf("%d", &matrica[i][ii]);
        }
    }
}

void ispis2dint(int n, int m, int (*matrica)[n])
{
    for(int i = 0; i < m; i++) {
        printf("\t[%d]", i);
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("[%d]\t", i);
        for(int ii = 0; ii < m; ii++) {
            printf("%d\t", matrica[i][ii]);
        }
        printf("\n");
    }
}

double filiplog(double baza, double broj)
{
    return log(broj)/log(baza);
}

int intunos(char *tekst)
{
    int temp;
    puts(tekst);
    scanf("%d", &temp);
    return temp;
}

char charunos(char *tekst)
{
    char temp;
    puts(tekst);
    scanf(" %c", &temp);
    return temp;
}

void chrrmv(char *recenica, char znak, int redni_broj)
{
    char *p = recenica;
    for(int i = 0; i < redni_broj; i++) {
        p = strchr(p, znak) + 1;
    }
    memmove(p - 1, p, strlen(p) + 1);
}

void strrmv(char *haystack, char *needle)
{
    int n = strlen(haystack), m = strlen(needle) - 1, brojac;
    char *p;
    for(int i = 0; i < n - m; i++) {
        brojac = 0;
        for(int ii = 0; ii < m; ii++) {
            if(*(haystack + i + ii) != *(needle + ii))
                brojac++;
        }
        if(brojac == 0) {
            p = haystack + i;
            break;
        }
    }
    memmove(p, p + m, m + 2);
    *(haystack + n - m - 1) = '\0';
}

char *strfnd(char *haystack, char *needle)
{
    int n = strlen(haystack), m = strlen(needle) - 1, brojac;
    char *p;
    for(int i = 0; i < n - m; i++) {
        brojac = 0;
        for(int ii = 0; ii < m; ii++) {
            if(*(haystack + i + ii) != *(needle + ii))
                brojac++;
        }
        if(brojac == 0) {
            p = haystack + i;
            break;
        }
    }
    return p;
}

void fgetline(char *niz, int broj, size_t arraysize, FILE *f)
{
    for(int i = 0; fgets(niz, arraysize, f) != NULL; i++) {
        if(i == broj)
            break;
    }
}

int longestline(FILE *f)
{
    int max = 0;
    char temp[1048576];
    for(int i = 0; fgets(temp, 1048576, f) != NULL; i++) {
        if((int)strlen(temp) > max)
            max = strlen(temp);
    }
    return max;
}
