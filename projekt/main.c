#include "struktury.h"
#include "read_write.h"
#include "generator.h"
#include "bfs.h"
#include <getopt.h> // dodac do specyfikacji 

char* usage = 
	"Pomoc: %s [-k ilosc kolumn -k ilosc wierszy] [-s punkt poczatkowy -e punkt koncowy] [-f waga poczatkowa -t waga koncowa] -i plik wejsciowy -o plik wyjsciowy -x true/false\n"
	"	Jeżeli podamy plik wejściowy to\n"
	"		nie podajemy ilosci kolumn, wierszy wagi początkowej,koncowej i nie zmieniamy wartosci zmiennej x\n"
	"		program czyta graf z pliku i rozwiazuje go na podstawie podanych punktów lub ich wartosci domyslnych\n"
	"	W przeciwnym wypadku\n"
	"		nie jest konieczne podanie parametrow, poniewaz program ma przyjete wartosci domyslne\n";

int main ( int argc, char**argv) {


	int opt;
	int k = 3;
	int w = 3;
	int s = 0; //zmienic w specyfikacji 
	int e = k*w-1;
	double f = 0;
	double t = 1;
	char *inp = NULL;
	char *out = NULL;
	int x = 0;
	char *progname = argv[0];
	list_s_t list_s;
	
	while (( opt = getopt (argc,argv, "k:w:s:e:f:t:i:o:x")) != -1) { // dodac x do specyfikacji i pozmieniac flagi
		switch (opt) {
		case 'k':
			k = atoi(optarg);
			break;
		case 'w':
			w = atoi(optarg);
			break;
		case 's':
			s = atoi(optarg);
			break;
		case 'e':
			e = atoi(optarg);
			break;
		case 'f':
			f = atof(optarg);
			break;
		case 't':
			t = atof(optarg);
			break;
		case 'i':
			inp = optarg;
			break;
		case 'o': 
			out = optarg;
			break;
		case 'x':
			x = atoi(optarg);
			break;
		default:
		fprintf(stderr,usage,progname);
		return -1;
		}
	}
	fprintf( stderr,"\n\n%d\n\n",optind);
	if ( optind < argc ) {
		fprintf(stderr, "\nBad parameters!\n");
		for (; optind < argc; optind++ ) 
			fprintf(stderr, "\t\"%s\"\n", argv[optind] );
			fprintf(stderr, "\n");
			fprintf (stderr,usage,progname);
			return -2;	
	}
	// Jeżeli podany został plik wejściowy 
	if ( inp != NULL ) {
		FILE *inf = fopen (inp, "r");
		if ( inf == NULL) {
			fprintf( stderr, "%s: Nie mozna przeczytac pliku wejsciowego: %s\n\n",argv[0],inp);
			return -3;
		}
		if ((list_s = read_file(inf)) == NULL ) { //zmiana
			fprintf(stderr, "%s: Zla tresc pliku wejsciowego: %s \n\n",argv[0],inp);
			return -4;
		}
		else fclose (inf);
	} else {
		list_s = initialize_lista( k,w, s,e);
		generator(list_s, 1, 0, 1);

			
		if ( out != NULL  ) {
			FILE *ouf = NULL;
			ouf = fopen ( out, "w");
			if ( ouf == NULL ) {
				fprintf( stderr, "%s: Nie mozna wypisac do podanego pliku: %s \n\n",argv[0],out);
				return -5;
			}
			if ( write_file ( ouf, list_s ) == 1 ) {
				fprintf (stderr, "%s: Wykryto zly format pliku wyjsciowego: %s \n\n", argv[0],out);
				return -6;
			}
			else fclose(ouf);
		}
		else {
			FILE *ouf = stdout;
			if ( write_file ( ouf, list_s ) == 1 ) {
				fprintf (stderr, "%s: Wykryto zly format pliku wyjsciowego: %s \n\n", argv[0],out);
				return -6;
			}
		}
	}
	int czyspojny = bfs(list_s);
	if (czyspojny == 0)
		printf("Graf jest spójny (BFS)\n");
	if (czyspojny == 1)
		printf("Graf NIE jest spójny (BFS)\n");
/*	int * wynik = dijkstra( list_s );
	int i ;
	for ( i = list_s->wynik-1; i >=0; i-- ) {
		fprintf(stderr,"%d - > ",wynik[i]);
	}
*/
}
