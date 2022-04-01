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
	int i;
	for ( i = 0; i < s; i++ ) {
		pq->q[i] = malloc ( sizeof*(pq->q[i]));
	}
	pq->d = malloc ( s*sizeof*(pq->d));
	for ( i = 0; i < s; i++ ) pq->d[i] = 1.7976931348623157E+308;
	pq->p = malloc ( s*sizeof*(pq->p));
	for ( i = 0; i < s; i++ ) pq->p[i] = -1;
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


void pq_add( pq_t pq)  {
	int i,j,l;
	i = pq->n;
	pq->q[i]->top = i;
	pq->q[i]->place = i;
	pq->n++;
}

int  pq_pop( pq_t pq ) {
	int ret = pq->q[0]->top;
	pq->q[0]->top = pq->q[--pq->n]->top;
	pq->q[0]->place = 0;
	int l,i,j,right = 0,left = 0;
	i = 0;
	while ( 1 ) {
		j = 2*i+1;
		l = 2*i+2;
		if ( j >= pq->n ) break;
		if ( pq->d[pq->q[j]->top] < pq->d[pq->q[l]->top] ) {
			left = 1;
		}	
		else right = 1;
		if ( right == 1 ) j++;
		if ( pq->d[pq->q[i]->top] <= pq->d[pq->q[j]->top] ) break;
		int tmp = pq->q[i]->top;
		pq->q[i]->top = pq->q[j]->top;
		pq->q[j]->top = tmp;
		pq->q[i]->place = i;
		pq->q[j]->place = j;
		i = j;
		right = 0;	
		left = 0;
	}
	return ret;
}
void pq_fix ( pq_t pq, int x) {
	int i,l,j,right = 0, left = 0;
	i = pq->q[x]->place;
	while ( i != 0 ) {
		j = (i-1)/ 2;
		if ( pq->d[pq->q[i]->top] >=  pq->d[pq->q[j]->top] ) break;
		int tmp = pq->q[j]->top;
		pq->q[j]->top = pq->q[i]->top;
		pq->q[i]->top = tmp;
		pq->q[pq->q[j]->top]->place = j;
		pq->q[pq->q[i]->top]->place = i; 
		i = j;
	}
}
void pq_free( pq_t pq) {
	free(pq->q);
	free(pq);
}
void lista_free ( list_s_t list_s ) {
	free(list_s->wierzcholki);
	free(list_s);
}
