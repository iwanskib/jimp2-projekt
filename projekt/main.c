#include "struktury.h"
#include "read_write.h"
#include "generator.h"
#include "dijkstra.h"
#include "bfs.h"
#include <getopt.h> // dodac do specyfikacji 
#include <string.h> // dodac do specyfikacji

char* usage = 
	"Pomoc: %s [-k ilosc kolumn -k ilosc wierszy] [-s punkt poczatkowy -e punkt koncowy] [-f waga poczatkowa -t waga koncowa] -i plik wejsciowy -o plik wyjsciowy -g 0/1\n"
	"	Jeżeli podamy plik wejściowy to\n"
	"		Program wczyta graf z podanego pliku, wiec nie potrzebne jest podawanie wiekszosci flag\n"
	"		mozliwe jest jednak nadal podanie wierzcholka poczatkowego i koncowego\n	"
	"	W przeciwnym wypadku\n"
	"		nie jest konieczne podanie parametrow, poniewaz program ma przyjete wartosci domyslne\n"
	"	Natomiast gdy nie podamy pliku wyjsciowego to program wypisze wygenerowany graf do utworzonego pliku graf.txt\n"
	"		jednakze zamiast pliku wyjsciowego mozemy jako argument podac napis stoud, a wtedy program wypisze graf na standardowe wyjscie\n";

int main ( int argc, char**argv) {


	int opt;
	int k = 10;
	int w = 10;
	int s = 0; //zmienic w specyfikacji 
	int e;
	double f = 0;
	double t = 1;
	char *inp = NULL;
	char *out = "graf.txt\0";
	int  g;	
	int y = -1;
	char *progname = argv[0];
	list_s_t list_s;
	
	while (( opt = getopt (argc,argv, "k:w:s:e:o:f:t:i:g:")) != -1) { // dodac x do specyfikacji i pozmieniac flagi
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
			y = 1;
			break;
		case 'g':
			g = atoi(optarg);
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
		default:
		fprintf(stderr,usage,progname);
		return -1;
		}
	}
	if ( optind < argc ) {
		fprintf(stderr, "\nBad parameters!\n");
		for (; optind < argc; optind++ ) 
			fprintf(stderr, "\t\"%s\"\n", argv[optind] );
			fprintf(stderr, "\n");
			fprintf (stderr,usage,progname);
			return -2;	
	}
	if ( k <= 1 || w <= 1 || s < 0 || s > k*w-1 || e < 0 || e > k*w-1 || f < 0 || t < 0 || ( g != 0 && g!= 1) )   { 
		fprintf(stderr,"\n%s: Nieprawdilowe dane wejsciowe!\n\n",argv[0]);
		fprintf(stderr,usage,progname);
		return -2;
	}
	if ( strcmp(out,"stdout") != 0 ) 
	if ( out[strlen(out)-1] != 't' ||  out[strlen(out)-2] != 'x' || out[strlen(out)-3] != 't'|| out[strlen(out)-4] != '.' ) {
		fprintf(stderr, "\n%s: Nieprawidłowy format pliku wyjściowego. Graf zostanie wypisany do pliku graf.txt\n",argv[0]);
		out = "graf.txt";
	}
	if ( inp != NULL )
	if ( inp[strlen(inp)-1] != 't' ||  inp[strlen(inp)-2] != 'x' || inp[strlen(inp)-3] != 't'|| inp[strlen(inp)-4] != '.' ) {
		fprintf(stderr, "\n%s: Nieprawidłowy format pliku wejściowego. Oczekiwany format .txt. Podane rozszerzenie: %c%c%c%c\n",argv[0],inp[strlen(inp)-1],inp[strlen(inp)-2],inp[strlen(inp)-3],inp[strlen(inp)-4]);	
		return -2;
	}
	if ( y == -1 ) 
	e = k*w-1;
	// Jeżeli podany został plik wejściowy 
	if ( inp != NULL ) {
		FILE *inf = fopen (inp, "r");
		if ( inf == NULL) {
			fprintf( stderr, "%s: Nie mozna przeczytac pliku wejsciowego: %s\n\n",argv[0],inp);
			return -3;
		}
		fprintf(stderr,"");
		if ((list_s = read_file(inf)) == NULL ) { //zmiana
			fprintf(stderr, "%s: Zla tresc pliku wejsciowego: %s \n\n",argv[0],inp);
			return -4;
		}
		else fclose (inf);
		if ( bfs(list_s) == 1 ) {
			fprintf(stderr,"Podany graf jest niespojny\n");
			return -1;
		}
		list_s->start = s;
		list_s->end = e;
	} else {
		list_s = initialize_lista( k,w, s,e);
		generator(list_s,g,f,t);
		if ( bfs(list_s) == 1 ) {
			fprintf(stderr,"Wygenerowany graf jest niespojny\n");
			return -1;
		}
		if (strcmp(out,"stdout") == 0 ){
			FILE *ouf = stdout;
			if ( write_file ( ouf, list_s ) == 1 ) {
				fprintf (stderr, "%s: Wykryto zly format pliku wyjsciowego: %s \n\n", argv[0],out);
				return -6;
			}
		}
		else if ( strcmp(out,"stdout") != 0 ) {
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
	}
	int* wynik = dijkstra( list_s );
	int i ;
	for ( i = list_s->wynik-1; i >=0; i-- ) {
		fprintf(stdout,"%d - > ",wynik[i]);
	}
	fprintf(stdout,"%d\n",list_s->end);
	lista_free(list_s);
	return 0;	
}
