#include "dijkstra.h"

int* dijkstra(list_s_t list_s) {
	int size = list_s->ilosc_wierszy*list_s->ilosc_kolumn;
	pq_t pq = initialize_pq(size);
	int* QS = malloc ( size*sizeof*(QS) );
	int i;
	pq->d[list_s->start] = 0;
	for ( i = 0; i < size; i++ ) QS[i] = 0;		
								
	for ( i = 0; i < size; i++ ) {
		pq_add(pq);	
	}							
	
	int u;	
	for ( i = 0 ; i < size; i++ ) {
		u = pq_pop(pq);
		QS[u] = 1;					
		list_t iterator = list_s->wierzcholki[u];
		while(iterator != NULL ) {
			if( QS [ iterator->x ] == 0 && ( pq->d [ iterator->x ] > (pq->d [ u ] + iterator->waga) ) ) {
       				pq->d [ iterator->x ] = pq->d [ u ] + iterator->waga;
      				pq->p [ iterator->x ] = u;
				pq_fix(pq,iterator->x);
			}
			iterator = iterator->next;
		}
		int j = 0;
	}
	

	int* wynik = malloc(pq->size*sizeof*(wynik));
	i = list_s->end;
	int l = 0;
	while ( pq->p[i] != -1 ) {
		wynik[l++] = pq->p[i];
		i = pq->p[i];
	}
	fprintf(stderr,"wartosc najkrotszej sciezki: %lf\n",pq->d[list_s->end]);
	list_s->wynik = l;
	pq_free(pq);
	return wynik;
}



