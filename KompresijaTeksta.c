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
    int broj_rijeci = 1;
    //pronalazenje broja rijeci u tekstu
    for(int i = 0; i < duljina; i++) {
        if(tekst[i] == ' ')
            broj_rijeci++;
    }
    //pretvaranje teksta u niz rijeci
    char rijeci[broj_rijeci][32], buffer[32], *p = tekst;
    for(int i = 0; i < broj_rijeci - 1; i++) {
		size_t duljinarijeci = strlen(p) - strlen(strchr(p, ' '));
		memcpy(buffer, p, duljinarijeci);
		buffer[duljinarijeci] = '\0';
		memmove(rijeci[i], buffer, duljinarijeci + 1);
		p = strchr(p, ' ') + 1;
    }
    p = strrchr(tekst, ' ') + 1;
    memcpy(buffer, p, strlen(p));
    buffer[strlen(p)] = '\0';
	memmove(rijeci[broj_rijeci - 1], buffer, strlen(p) + 1);
	//test
	for(int i = 0; i < broj_rijeci; i++) {
		puts(rijeci[i]);
	}
	//"kodiranje"
	char kodiranerijeci[broj_rijeci][32];
	int bk = 0;
	fprintf(k, "%d\n", broj_rijeci);
	for(int i = 0; i < broj_rijeci; i++) {
		int razlika = 0;
		for(int ii = 0; ii < i; ii++) {
			if(strcmp(rijeci[i], rijeci[ii]) != 0) {
				razlika++;
			}
		}
		if(razlika == i) {
			memmove(kodiranerijeci[bk], rijeci[i], strlen(rijeci[i]) + 1);
			bk++;
			fprintf(k, "%s ", rijeci[i]);
		}
	}
	printf("%d", bk);
	/*
	for(int i = 0; i < bk; i++) {
		puts(rijeci[i]);
	}
	*/
	//output
	for(int i = 0; i < broj_rijeci; i++) {
		fprintf(o, )
	}
}
