#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem {
	double waga;
	int x;
	struct elem *next;
} elem_t, *list_t;


list_t wstaw_na_poczatek ( list_t l, int x, double w);


typedef struct {
	int ilosc_kolumn;
	int ilosc_wierszy;
	int start;
	int end;
	int wynik;
	list_t *wierzcholki;
} *list_s_t;

typedef struct {
	int *q;
	int *hq;
	int n;
	int size;
} *pq_t;

list_s_t initialize_lista ( int ilosc_kolumn,int ilosc_wierszy, int start, int end );
pq_t initialize_pq (int size);
int  pq_add(pq_t pq, int x, double wg);
int pq_pop(pq_t pq);
void pq_free(pq_t pq);
void lista_free ( list_s_t list_s );

#endif
