#ifndef _GRAFOO_H_
#define _GRAFOO_H_

#include "lista.h"

typedef struct grafo{
   int valor;
   int flag;
   Lista *L;
}Grafo;


Grafo* criaGrafo(int);
void adicionaAresta(Grafo*,int,int);
void printaGrafo(Grafo*,int);
Grafo* transpoeGrafo(Grafo*,int);
void removeAresta(Grafo*,int,int);
int* dfs_visit(Grafo*,int,int*,int,int*,int*);
int* DFS_graph(Grafo*, int);
void atualizaGrafo(Grafo*,int);

#endif //_GRAFOO_H_
