#include <stdio.h>
#include <string.h>
#include "filip.h"

int main()
{
    char datoteka[256], datotekakod[256], datotekaoutput[256];
	printf("Unesite ime datoteke: ");
	fgets(datoteka, 256, stdin);
	datoteka[(int)strlen(datoteka) - 1] = '\0';
	FILE *f, *k, *o;
	f = fopen(datoteka, "r+");
	strcpy(datotekakod, datoteka);
	datotekakod[(int)strlen(datoteka) - 4] = '\0';
	strcpy(datotekaoutput, datotekakod);
	strcat(datotekakod, "kod.txt");
	strcat(datotekaoutput, "output.txt");
	k = fopen(datotekakod, "w+");
	o = fopen(datotekaoutput, "w+");
	int duljina = longestline(f) + 2;
    char tekst[duljina];
    fgets(tekst, duljina, f);
    puts(tekst);
}
