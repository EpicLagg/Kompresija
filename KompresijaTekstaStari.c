#include <stdio.h>
#include <string.h>
#include "filip.h"

int main()
{
    Izbornik:;
    int odabir;
    printf("Kompresija - 1\nDekompresija - 2\n\nUnesite odabir: ");
    scanf("%d", &odabir);
    fflush(stdin);
    switch(odabir)
    {
        case 1:
            {
                char datoteka[256], datotekakod[256], datotekaoutput[256], datotekabk[256];
                printf("Unesite ime datoteke s nastavkom: ");
                fgets(datoteka, 256, stdin);
                datoteka[(int)strlen(datoteka) - 1] = '\0';
                FILE *f, *k, *o, *fbk;
                f = fopen(datoteka, "r+");
                strcpy(datotekakod, datoteka);
                datotekakod[(int)strlen(datoteka) - 4] = '\0';
                strcpy(datotekaoutput, datotekakod);
                strcpy(datotekabk, datotekakod);
                strcat(datotekakod, "kod.txt");
                strcat(datotekaoutput, "output.txt");
                strcat(datotekabk, "bk.txt");
                k = fopen(datotekakod, "w+");
                o = fopen(datotekaoutput, "w+");
                fbk = fopen(datotekabk, "w+");
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
                fprintf(fbk, "Duljina teksta: %d\n", duljina);
                fprintf(fbk, "Broj rijeci: %d\n", broj_rijeci);
                for(int i = 0; i < broj_rijeci; i++) {
                    int razlika = 0;
                    for(int ii = 0; ii < i; ii++) {
                        if(strcmp(rijeci[i], rijeci[ii]) != 0) {
                            razlika++;
                        }
                    }
                    if(razlika == i) {
                        memmove(kodiranerijeci[bk], rijeci[i], strlen(rijeci[i]) + 1);
                        if(bk == 0) {
                            fprintf(k, "%s", rijeci[i]);
                        }
                        else
                            fprintf(k, " %s", rijeci[i]);
                        bk++;
                    }
                }
                fprintf(fbk, "Broj kodiranih rijeci: %d\n", bk);
                printf("%d", bk);
                //output
                int brojac = 0;
                for(int i = 0; i < broj_rijeci; i++) {
                    for(int ii = 0; ii < bk; ii++) {
                        if(strcmp(rijeci[i], kodiranerijeci[ii]) == 0) {
                            if(brojac == 0) {
                                fprintf(o, "%d", ii);
                            }
                            else
                                fprintf(o, " %d", ii);
                            brojac++;
                        }
                    }
                }
                fclose(f);
                fclose(k);
                fclose(o);
                fclose(fbk);
                break;
            }
        case 2:
            {
                char datoteka[256], datotekakod[256], datotekaoutput[256], datotekabk[256];
                printf("Unesite ime originalne datoteke s nastavkom (bez kod/output): ");
                fgets(datoteka, 256, stdin);
                datoteka[(int)strlen(datoteka) - 1] = '\0';
                FILE *f, *k, *o, *fbk;
                f = fopen(datoteka, "w+");
                strcpy(datotekakod, datoteka);
                datotekakod[(int)strlen(datoteka) - 4] = '\0';
                strcpy(datotekaoutput, datotekakod);
                strcpy(datotekabk, datotekakod);
                strcat(datotekakod, "kod.txt");
                strcat(datotekaoutput, "output.txt");
                strcat(datotekabk, "bk.txt");
                k = fopen(datotekakod, "r+");
                o = fopen(datotekaoutput, "r+");
                fbk = fopen(datotekabk, "r+");
                int duljina = 0, broj_rijeci = 0, bk = 0;
                char temp[64];
                fgets(temp, 64, fbk);
                sscanf(temp, "Duljina teksta: %d\n", &duljina);
                fgets(temp, 64, fbk);
                sscanf(temp, "Broj rijeci: %d\n", &broj_rijeci);
                fgets(temp, 64, fbk);
                sscanf(temp, "Broj kodiranih rijeci: %d\n", &bk);
                printf("%d, %d, %d", duljina, broj_rijeci, bk);
                char tekst[duljina];
                fgets(tekst, duljina, o);
                char brojevi[broj_rijeci][32], buffer[32], *p = tekst;
                for(int i = 0; i < broj_rijeci - 1; i++) {
                    size_t duljinarijeci = strlen(p) - strlen(strchr(p, ' '));
                    memcpy(buffer, p, duljinarijeci);
                    buffer[duljinarijeci] = '\0';
                    memmove(brojevi[i], buffer, duljinarijeci + 1);
                    p = strchr(p, ' ') + 1;
                }
                p = strrchr(tekst, ' ') + 1;
                memcpy(buffer, p, strlen(p));
                buffer[strlen(p)] = '\0';
                memmove(brojevi[broj_rijeci - 1], buffer, strlen(p) + 1);
                //test
                for(int i = 0; i < broj_rijeci; i++) {
                    puts(brojevi[i]);
                }
                fgets(tekst, duljina, k);
                char rijeci[broj_rijeci][32];
                p = tekst;
                for(int i = 0; i < bk - 1; i++) {
                    size_t duljinarijeci = strlen(p) - strlen(strchr(p, ' '));
                    memcpy(buffer, p, duljinarijeci);
                    buffer[duljinarijeci] = '\0';
                    memmove(rijeci[i], buffer, duljinarijeci + 1);
                    p = strchr(p, ' ') + 1;
                }
                p = strrchr(tekst, ' ') + 1;
                memcpy(buffer, p, strlen(p));
                buffer[strlen(p)] = '\0';
                memmove(rijeci[bk - 1], buffer, strlen(p) + 1);
                for(int i = 0; i < bk; i++) {
                    puts(rijeci[i]);
                }
                int kodnibrojevi[broj_rijeci];
                for(int i = 0; i < broj_rijeci; i++) {
                    sscanf(brojevi[i], "%d", &kodnibrojevi[i]);
                }
                for(int i = 0; i < broj_rijeci; i++) {
                    if(i == 0)
                        fprintf(f, "%s", rijeci[kodnibrojevi[i]]);
                    else
                        fprintf(f, " %s", rijeci[kodnibrojevi[i]]);
                }
                break;
            }
        default:
            {
                printf("\nTaj odabir ne postoji!\n");
                goto Izbornik;
            }
    }
}
