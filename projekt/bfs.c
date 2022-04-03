#include "struktury.h"
#include "bfs.h"
#include <stdlib.h>

int bfs(list_s_t list_s) {
    int start = list_s->start;
    int ik = list_s->ilosc_kolumn, iw = list_s->ilosc_wierszy;
    int ilosc_wierzcholkow = ik*iw;
    int zwiedzone[ilosc_wierzcholkow][2];
    for (int i = 0; i < ilosc_wierzcholkow; i++) {
        zwiedzone[i][0] = i;
        zwiedzone[i][1] = 0;
    }
    zwiedzone[start][1] = 1;
    int nrw;
	int v[ilosc_wierzcholkow];
	int vs = 1, vz = 0;
	v[0] = start;
	while(vz < vs) {
		list_t iterator = list_s->wierzcholki[v[vz]];
		while(iterator != NULL) {
		    nrw = iterator->x;
			if(zwiedzone[nrw][1] == 0) {
				v[vs++] = nrw;
				zwiedzone[nrw][1] = 1;
			}
		    iterator = iterator->next;
    	}
		vz++;
	}
    printf("KONIEC BFS\n");

	int wynik = 0;
	for (int koniec = 0; koniec < ilosc_wierzcholkow; koniec++) {
		if (zwiedzone[koniec][1] == 1)
			wynik++;
	}
	if (wynik == ilosc_wierzcholkow) {
		printf("zwracam zero\n");
		return 0;
	}
	else 
		return 1;
}