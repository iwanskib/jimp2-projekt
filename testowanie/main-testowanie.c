#include "../projekt/struktury.h"
#include "../projekt/dijkstra.h"
#include "../projekt/generator.h"

int main ( int argc, char **argv) {
	int i = 10000;
	int wynik = 0;
	while ( i-- ) {
		list_s_t list_s = initialize_lista(835,835,0,100*100-1);
		generator(list_s,0,0,10);
		dijkstra(list_s);
		if ( list_s->dost != 1.7976931348623157E+308 && list_s->post != -1 ) wynik++;
	}
	fprintf(stderr,"%d\n",wynik);


}
