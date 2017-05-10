#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct bloco
{
    int x;
    int y;
    struct bloco *prox;
} no;

typedef struct
{
    no *inicio, *fim;
} Lista;

int* retornaLista(Lista*);
void cria(Lista*);
void finaliza(Lista*);
void inserir(Lista*,int,int);
void inserirT(Lista*,int);
void eliminar(Lista*, int);
int tamanho(Lista*);
int esta_na_lista(Lista*,int);
void imprimir(Lista*);

#endif // _LISTA_H_
