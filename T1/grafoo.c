#include"grafoo.h"
#include<stdlib.h>

int retornaMaiorTempo(Grafo * G, int *timeVetor, int tam){
    int maior = 0;
    int indice,i;
    indice = -1;
    int *v;
    for(i = 0; i < tam; i++){
        if(timeVetor[i] > maior && G[i].flag == BRANCO){
            maior = timeVetor[i];
            indice = i;
        }
    }
    if(indice != -1){
        timeVetor[indice] = 0;
        printf("indice :%d\n",indice);
        return indice;
    }

    else
        return -1;
}

Grafo* criaGrafo(int tam){
   Grafo *G;
   int i;

   G = (Grafo*)malloc(sizeof(Grafo)*tam);
   for(i = 0; i < tam; i++){
      G[i].L = (Lista*)malloc(sizeof(Lista));
      cria(G[i].L);
      G[i].flag = BRANCO;
   }
   return G;
}

void adicionaAresta(Grafo *G, int first, int second){
    inserir(G[first].L, first, second);
}

void printaGrafo(Grafo *G, int tam){
   int i;

   for(i = 0; i < tam; i++){
      printf("no :%d  ,",i);
      imprimir(G[i].L);
      printf("\n");
   }
}

void removeAresta(Grafo *G,int vertice,int adjacente){
   eliminar(G[vertice].L,adjacente);
}
