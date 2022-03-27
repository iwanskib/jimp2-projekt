#include "struktury.h"


list_t wstaw_na_poczatek ( list_t l, int x, double w) {
	elem_t *nw = malloc(sizeof*nw);
	nw->next = l;
	nw->x = x;
	nw->waga = w;
	return nw;
}

pq_t initialize_pq ( int s ) {
	pq_t pq = malloc (sizeof * pq);
	pq->q = malloc ( s*sizeof*(pq->q));
	pq->hq = malloc ( s*sizeof*(pq->hq));
	pq->n = 0;
	pq->size = s;
	return pq;
}

list_s_t initialize_lista ( int ilosc_kolumn, int ilosc_wierszy, int start, int end) {
	list_s_t list_s = malloc (sizeof * list_s);
	list_s->start = start;
	list_s->ilosc_wierszy = ilosc_wierszy;
	list_s->ilosc_kolumn = ilosc_kolumn;
	list_s->end = end;
	list_s->wierzcholki = malloc ( ilosc_kolumn*ilosc_wierszy*sizeof*(list_s->wierzcholki));
	int i;
	for ( i = 0; i < ilosc_kolumn*ilosc_wierszy; i++ ) 
		list_s->wierzcholki[i] = NULL;
	return list_s;
}


/*int  pq_add( pq_t pq,int x,double wg) {
	pq->q[pq->n] = x;
	pq->d[pq->n] = wg;
	pq->n++;
	return 0;
}

int pop_from_pq( pq_t pq ) {
	int i,x = 0;
	for ( i = 1; i < pq->n; i++){
		if ( pq->d[x] > pq->d[i] ) 
			x = i;
	}

	for ( i = x; i <pq->n; i++) {
		
	}
	return pq->q[x];
}
*/
void pq_free( pq_t pq) {
	free(pq->q);
	free(pq);
}
void lista_free ( list_s_t list_s ) {
	free(list_s->wierzcholki);
	free(list_s);
}
