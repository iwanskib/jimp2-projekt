#include "struktury.h"
#include "bfs.h"

int bfs(list_s_t list_s) {
    printf("POCZĄTEK BFS\n");
    int start = list_s->start;
    int ik = list_s->ilosc_kolumn, iw = list_s->ilosc_wierszy;
    int ilosc_wierzcholkow = ik*iw;
    int zwiedzone[ilosc_wierzcholkow][2];
    for (int i = 0; i < ilosc_wierzcholkow; i++) {              //wypełnie tablicę numerem wierzchołka oraz informacją, czy jest zwiedony (0 - nie, 1 - tak)
        zwiedzone[i][0] = i;
        zwiedzone[i][1] = 0;
    }
    zwiedzone[start][1] = 1;
    int nrw;
	int v[1000000], vs = 1, vz = 0;
	v[0] = start;
	while(v[vz] != ilosc_wierzcholkow-1) {
		while(list_s->wierzcholki[v[vz]] != NULL) { 								// gdzieś tu trzeba if dodać bo przy niespójnym lata w kółko
		    nrw = list_s->wierzcholki[v[vz]]->x;
		    zwiedzone[nrw][1] = 1;
			v[vs] = nrw;
			vs++;
		    list_s->wierzcholki[v[vz]] = list_s->wierzcholki[v[vz]]->next;
    	}
		vz++;
	}
    for(int printujemy = 0; printujemy < ilosc_wierzcholkow; printujemy++) 
        printf("%d %d\n", zwiedzone[printujemy][0], zwiedzone[printujemy][1]);
	for(int printujemyv = 0; printujemyv < vs; printujemyv++)
		printf("\t%d\n", v[printujemyv]);

    printf("KONIEC BFS\n");

	int wynik = 0;
	for (int koniec = 0; koniec < ilosc_wierzcholkow; koniec++) {
		if (zwiedzone[koniec][1] = 1)
			wynik++;
	}
	if (wynik == ilosc_wierzcholkow)
		return 0;
	else 
		return 1;
}