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
	double dost;
	int post;
	list_t *wierzcholki;
} *list_s_t;

typedef struct {
	int place;
	int top;
} *elem;

typedef struct {
	elem *q;
	int n;
	int size;
	double *d;
	int *p;
} *pq_t;

list_s_t initialize_lista ( int ilosc_kolumn,int ilosc_wierszy, int start, int end );
pq_t initialize_pq (int size);
void  pq_add(pq_t pq);
int  pq_pop(pq_t pq);
void pq_fix(pq_t pq, int x);
void pq_free(pq_t pq);
void lista_free ( list_s_t list_s );

#endif
