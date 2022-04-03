#include "read_write.h"

list_s_t read_file ( FILE* inf) {
	int k,w;
	if ( fscanf(inf,"%d %d", &w,&k) != 2 ) return NULL;
	list_s_t list_s = initialize_lista(k,w,0,0);
	int x,c;
	double y,z;
	int size = 4*2+(2*(k-2)+2*(w-2))*3+((k-2)*(w-2))*4;
	int wierz;
	while (size--) {
		if ( fscanf(inf,"%d",&x) == 1 ) {
		while ((c = fgetc(inf)) != ':') {
		;}
		fscanf(inf,"%lg",&y);
		list_s->wierzcholki[wierz] = wstaw_na_poczatek(list_s->wierzcholki[wierz],x,y);
		if ( ( c = fgetc(inf) ) == 10 ) {
			wierz++;
		}
		}
	}
	return list_s;
}

int write_file ( FILE* out, list_s_t list_s ) {
	fprintf(out,"%d %d\n",list_s->ilosc_wierszy,list_s->ilosc_kolumn);
	int i;
	for( i = 0; i < list_s->ilosc_kolumn*list_s->ilosc_wierszy; i++ ) {
		list_t iterator = list_s->wierzcholki[i];
		while ( iterator != NULL ) {
			fprintf(out," %d :%lf", iterator->x,iterator->waga);
			iterator = iterator->next;
		}
		fprintf(out,"\n");
	}
	return 0;
}
