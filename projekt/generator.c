#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struktury.h"
#include "read_write.h"
list_s_t generator (list_s_t list_s, int spojny, double wod, double wdo) {
    srand(time(NULL));
    int lw = list_s->ilosc_wierszy;
    int lk = list_s->ilosc_kolumn;
    wod = -1, wdo = 1;
    int x[lw][lk]; //tablica z numerami punktów

    //wypelnia tablice 2-wymiarowa numerami punktow
    int w=0, k=0;
    int z = 0;
    for (w = 0; w < lw; w++) {
        for (k = 0; k < lk; k++) {
            x[w][k] = z;
            z++;
        }
    }
    if (spojny == 0) {////////////////////////////////////////////////////////////////////////////////////////////////////////////////// dla spójnego
        if (lw == 1 && lk == 1)               // 1x1
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][0],0); 
        else if (lw == 1 && lk == 2) {        // 1x2
            double random[2];
            random[0] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            random[1] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][1],random[0]); 
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[0][0],random[1]);
        }
        else if (lw == 2 && lk == 1) {        // 2x1
            double random[2];
            random[0] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            random[1] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[1][0],random[0]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[0][0],random[1]);
        }
        else if (lw == 2 && lk == 2) {        // 2x2
            double random[8];
            for (int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][1],random[0]);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[1][0],random[1]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[0][0],random[2]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[1][1],random[3]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[0][0],random[4]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[1][1],random[5]);
            list_s->wierzcholki[x[1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][1]],x[1][0],random[6]);
            list_s->wierzcholki[x[1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][1]],x[0][1],random[7]);
        }
        else if (lw == 2 && lk > 2) {        // 2xn
            double random[14];
            for (int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][1],random[0]);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[1][0],random[1]);
            for (int i = 1; i <= lk-2; i++) {
                for (int randompwiersz = 8; randompwiersz < 11; randompwiersz++)
                    random[randompwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[0][i+1],random[8]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[1][i],random[9]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[0][i-1],random[10]);
            }
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[0][lk-2],random[2]);
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[1][lk-1],random[3]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[0][0],random[4]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[1][1],random[5]);
            for (int j = 1; j <= lk-2; j++) {
                for (int randomdwiersz = 11; randomdwiersz < 14; randomdwiersz++)
                    random[randomdwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][j]],x[1][j+1],random[11]);
                list_s->wierzcholki[x[1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][j]],x[0][j],random[12]);
                list_s->wierzcholki[x[1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][j]],x[1][j-1],random[13]);
            }
            list_s->wierzcholki[x[1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][lk-1]],x[0][lk-1],random[6]);
            list_s->wierzcholki[x[1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][lk-1]],x[1][lk-2],random[7]);
        }
        else if (lw > 2 && lk == 2) {        // nx2
            double random[14];
            for (int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][1],random[0]);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[1][0],random[1]);
            for (int i = 1; i <= lw-2; i++) {
                for (int randompwiersz = 8; randompwiersz < 11; randompwiersz++)
                    random[randompwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[i][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[i][0]],x[i+1][0],random[8]);
                list_s->wierzcholki[x[i][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[i][0]],x[i][1],random[9]);
                list_s->wierzcholki[x[i][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[i][0]],x[i-1][0],random[10]);
            }
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[lw-2][0],random[2]);
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[lw-1][1],random[3]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[0][0],random[4]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[1][1],random[5]);
            for (int j = 1; j <= lw-2; j++) {
                for (int randomdwiersz = 11; randomdwiersz < 14; randomdwiersz++)
                    random[randomdwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[j][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[j][1]],x[j+1][1],random[11]);
                list_s->wierzcholki[x[j][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[j][1]],x[j][0],random[12]);
                list_s->wierzcholki[x[j][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[j][1]],x[j-1][1],random[13]);
            }
            list_s->wierzcholki[x[lw-1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][1]],x[lw-2][1],random[6]);
            list_s->wierzcholki[x[lw-1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][1]],x[lw-1][0],random[7]);
        }
        else {                          // >= 3x3
            double random[24];
            for( int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            //wstaw_na_poczatek(od którego, do którego, waga)
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][1],random[0]);                       //pierwszy
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[1][0],random[1]); 
            for (int i = 1; i <= lk-2; i++) {                                                                                        //pierwszy wiersz
                for (int randompwiersz = 8; randompwiersz < 11; randompwiersz++)
                    random[randompwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[0][i+1],random[8]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[1][i],random[9]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[0][i-1],random[10]);
            }
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[0][lk-2],random[2]);              //ostatni w pierwszym wierszu
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[1][lk-1],random[3]);
            for (int ws = 1; ws <= lw-2; ws++) {                                                                                     //2 pętle na cały środek 3x pierwszy, pętla na środek, 3x ostatni
                for (int randompkolumna = 11; randompkolumna < 14; randompkolumna++)
                    random[randompkolumna] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[ws][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][0]],x[ws-1][0],random[11]);   
                list_s->wierzcholki[x[ws][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][0]],x[ws][1],random[12]);
                list_s->wierzcholki[x[ws][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][0]],x[ws+1][0],random[13]);
                for (int ks = 1; ks <= lk-2; ks++) {
                    for (int randomsrodek = 14; randomsrodek < 18; randomsrodek++)
                        random[randomsrodek] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[ws-1][ks],random[14]);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[ws][ks+1],random[15]);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[ws][ks-1],random[16]);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[ws+1][ks],random[17]);
                }
                for (int randomokolumna = 18; randomokolumna < 21; randomokolumna++)
                    random[randomokolumna] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[ws][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][lk-1]],x[ws-1][lk-1],random[18]);
                list_s->wierzcholki[x[ws][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][lk-1]],x[ws][lk-2],random[19]);
                list_s->wierzcholki[x[ws][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][lk-1]],x[ws+1][lk-1],random[20]);
            }
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[lw-2][0],random[4]);              //pierwszy w ostatnim wierszu
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[lw-1][1],random[5]); 
            for (int j = 1; j <= lk-2; j++) {                                                                                        //ostatni wiersz
                for (int randomowiersz = 21; randomowiersz < 24; randomowiersz++)
                    random[randomowiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);                                              
                list_s->wierzcholki[x[lw-1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][j]],x[lw-1][j-1],random[21]);
                list_s->wierzcholki[x[lw-1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][j]],x[lw-2][j],random[22]);
                list_s->wierzcholki[x[lw-1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][j]],x[lw-1][j+1],random[23]);
            }
            list_s->wierzcholki[x[lw-1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][lk-1]],x[lw-2][lk-1],random[6]);     //ostatni w ostatnim wierszu
            list_s->wierzcholki[x[lw-1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][lk-1]],x[lw-1][lk-2],random[7]);
        }
    }
    else { /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// jak nie spójny
        if (lw == 1 && lk == 1)               // 1x1
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][0],0); 
        else if (lw == 1 && lk == 2) {        // 1x2
            double random[2];
            random[0] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            random[1] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][0],random[0]); 
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[0][1],random[1]);
        }
        else if (lw == 2 && lk == 1) {        // 2x1
            double random[2];
            random[0] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            random[1] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[0][0],random[0]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[1][0],random[1]);
        }
        else if (lw == 2 && lk == 2) {        // 2x2
            double random[8];
            for (int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%2][rand()%2],random[0]);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%2][rand()%2],random[1]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[rand()%2][rand()%2],random[2]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[rand()%2][rand()%2],random[3]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[rand()%2][rand()%2],random[4]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[rand()%2][rand()%2],random[5]);
            list_s->wierzcholki[x[1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][1]],x[rand()%2][rand()%2],random[6]);
            list_s->wierzcholki[x[1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][1]],x[rand()%2][rand()%2],random[7]);
        }
        else if (lw == 2 && lk > 2) {        // 2xn
            double random[14];
            for (int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%2][rand()%(lk-1)],random[0]);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%2][rand()%(lk-1)],random[1]);
            for (int i = 1; i <= lk-2; i++) {
                for (int randompwiersz = 8; randompwiersz < 11; randompwiersz++)
                    random[randompwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[rand()%2][rand()%(lk-1)],random[8]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[rand()%2][rand()%(lk-1)],random[9]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[rand()%2][rand()%(lk-1)],random[10]);
            }
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[rand()%2][rand()%(lk-1)],random[2]);
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[rand()%2][rand()%(lk-1)],random[3]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[rand()%2][rand()%(lk-1)],random[4]);
            list_s->wierzcholki[x[1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][0]],x[rand()%2][rand()%(lk-1)],random[5]);
            for (int j = 1; j <= lk-2; j++) {
                for (int randomdwiersz = 11; randomdwiersz < 14; randomdwiersz++)
                    random[randomdwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][j]],x[rand()%2][rand()%(lk-1)],random[11]);
                list_s->wierzcholki[x[1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][j]],x[rand()%2][rand()%(lk-1)],random[12]);
                list_s->wierzcholki[x[1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][j]],x[rand()%2][rand()%(lk-1)],random[13]);
            }
            list_s->wierzcholki[x[1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][lk-1]],x[rand()%2][rand()%(lk-1)],random[6]);
            list_s->wierzcholki[x[1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[1][lk-1]],x[rand()%2][rand()%(lk-1)],random[7]);
        }
        else if (lw > 2 && lk == 2) {        // nx2
            double random[14];
            for (int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%(lw-1)][rand()%2],random[0]);
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%(lw-1)][rand()%2],random[1]);
            for (int i = 1; i <= lw-2; i++) {
                for (int randompwiersz = 8; randompwiersz < 11; randompwiersz++)
                    random[randompwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[i][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[i][0]],x[rand()%(lw-1)][rand()%2],random[8]);
                list_s->wierzcholki[x[i][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[i][0]],x[rand()%(lw-1)][rand()%2],random[9]);
                list_s->wierzcholki[x[i][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[i][0]],x[rand()%(lw-1)][rand()%2],random[10]);
            }
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[rand()%(lw-1)][rand()%2],random[2]);
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[rand()%(lw-1)][rand()%2],random[3]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[rand()%(lw-1)][rand()%2],random[4]);
            list_s->wierzcholki[x[0][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][1]],x[rand()%(lw-1)][rand()%2],random[5]);
            for (int j = 1; j <= lw-2; j++) {
                for (int randomdwiersz = 11; randomdwiersz < 14; randomdwiersz++)
                    random[randomdwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[j][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[j][1]],x[rand()%(lw-1)][rand()%2],random[11]);
                list_s->wierzcholki[x[j][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[j][1]],x[rand()%(lw-1)][rand()%2],random[12]);
                list_s->wierzcholki[x[j][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[j][1]],x[rand()%(lw-1)][rand()%2],random[13]);
            }
            list_s->wierzcholki[x[lw-1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][1]],x[rand()%(lw-1)][rand()%2],random[6]);
            list_s->wierzcholki[x[lw-1][1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][1]],x[rand()%(lw-1)][rand()%2],random[7]);
        }
        else {                          // >= 3x3
            double random[24];
            for( int randomrogi = 0; randomrogi < 8; randomrogi++) {   
                random[randomrogi] = wod + (double) rand() / RAND_MAX * (wdo-wod);
            }
            //wstaw_na_poczatek(od którego, do którego, waga)
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%(lw-1)][rand()%(lk-1)],random[0]);                       //pierwszy
            list_s->wierzcholki[x[0][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][0]],x[rand()%(lw-1)][rand()%(lk-1)],random[1]); 
            for (int i = 1; i <= lk-2; i++) {                                                                                        //pierwszy wiersz
                for (int randompwiersz = 8; randompwiersz < 11; randompwiersz++)
                    random[randompwiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[rand()%(lw-1)][rand()%(lk-1)],random[8]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[rand()%(lw-1)][rand()%(lk-1)],random[9]);
                list_s->wierzcholki[x[0][i]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][i]],x[rand()%(lw-1)][rand()%(lk-1)],random[10]);
            }
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[rand()%(lw-1)][rand()%(lk-1)],random[2]);              //ostatni w pierwszym wierszu
            list_s->wierzcholki[x[0][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[0][lk-1]],x[rand()%(lw-1)][rand()%(lk-1)],random[3]);
            for (int ws = 1; ws <= lw-2; ws++) {                                                                                     //2 pętle na cały środek 3x pierwszy, pętla na środek, 3x ostatni
                for (int randompkolumna = 11; randompkolumna < 14; randompkolumna++)
                    random[randompkolumna] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[ws][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][0]],x[rand()%(lw-1)][rand()%(lk-1)],random[11]);   
                list_s->wierzcholki[x[ws][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][0]],x[rand()%(lw-1)][rand()%(lk-1)],random[12]);
                list_s->wierzcholki[x[ws][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][0]],x[rand()%(lw-1)][rand()%(lk-1)],random[13]);
                for (int ks = 1; ks <= lk-2; ks++) {
                    for (int randomsrodek = 14; randomsrodek < 18; randomsrodek++)
                        random[randomsrodek] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[rand()%(lw-1)][rand()%(lk-1)],random[14]);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[rand()%(lw-1)][rand()%(lk-1)],random[15]);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[rand()%(lw-1)][rand()%(lk-1)],random[16]);
                    list_s->wierzcholki[x[ws][ks]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][ks]],x[rand()%(lw-1)][rand()%(lk-1)],random[17]);
                }
                for (int randomokolumna = 18; randomokolumna < 21; randomokolumna++)
                    random[randomokolumna] = wod + (double) rand() / RAND_MAX * (wdo-wod);
                list_s->wierzcholki[x[ws][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][lk-1]],x[rand()%(lw-1)][rand()%(lk-1)],random[18]);
                list_s->wierzcholki[x[ws][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][lk-1]],x[rand()%(lw-1)][rand()%(lk-1)],random[19]);
                list_s->wierzcholki[x[ws][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[ws][lk-1]],x[rand()%(lw-1)][rand()%(lk-1)],random[20]);
            }
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[rand()%(lw-1)][rand()%(lk-1)],random[4]);              //pierwszy w ostatnim wierszu
            list_s->wierzcholki[x[lw-1][0]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][0]],x[rand()%(lw-1)][rand()%(lk-1)],random[5]); 
            for (int j = 1; j <= lk-2; j++) {                                                                                        //ostatni wiersz
                for (int randomowiersz = 21; randomowiersz < 24; randomowiersz++)
                    random[randomowiersz] = wod + (double) rand() / RAND_MAX * (wdo-wod);                                              
                list_s->wierzcholki[x[lw-1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][j]],x[rand()%(lw-1)][rand()%(lk-1)],random[21]);
                list_s->wierzcholki[x[lw-1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][j]],x[rand()%(lw-1)][rand()%(lk-1)],random[22]);
                list_s->wierzcholki[x[lw-1][j]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][j]],x[rand()%(lw-1)][rand()%(lk-1)],random[23]);
            }
            list_s->wierzcholki[x[lw-1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][lk-1]],x[rand()%(lw-1)][rand()%(lk-1)],random[6]);     //ostatni w ostatnim wierszu
            list_s->wierzcholki[x[lw-1][lk-1]] = wstaw_na_poczatek(list_s->wierzcholki[x[lw-1][lk-1]],x[rand()%(lw-1)][rand()%(lk-1)],random[7]);
        }
    }
    return list_s;
}
