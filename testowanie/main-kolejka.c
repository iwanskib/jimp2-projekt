#include "../projekt/dijkstra.h"
#include "../projekt/struktury.h"
#include <time.h>

int main ( int argc, char ** argv ) {

	srand(1);
	pq_t pq = initialize_pq(9);	
	int i,x,y;
	for ( i = 0; i < 9; i++ ) pq->d[i] = 20*(double)rand()/RAND_MAX;

	for ( i = 0; i < 9; i++ ) {
		x = i;
		printf("%d = %f\n",x,pq->d[i]);
		pq_add(pq);
		printf("\n");
	}
	

	for ( i = 0; i < 9; i++ ) {
		printf("wierz:%d waga:%f place:%d\n",pq->q[i]->top,pq->d[pq->q[i]->top], pq->q[i]->place);
	}
	
	printf("\n++++++++++++++++++++++++++++++++++\n");
	
	for ( i = 0; i < 9; i++ ) {
		int u  = pq_pop(pq);
		printf("wierz:%d waga:%f\n",u,pq->d[u]);

	}
	printf("\n++++++++++++++++++++++++++++++++++\n");
	
}
