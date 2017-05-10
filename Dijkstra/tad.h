/*Este programa necessita de dois arquivos: o capitais.txt, contendo na primeira linha a quantidade de capitais em ordem de insercao
e nas proximas as capitais em si (as quais podem mudar de nome. Note que inicialmente as strings aceitam apenas 50 caracteres, podendo
este ser alterado no cabecalho.
O arquivo dijkstra.txt deve conter a quantidade de n arestas a serem criadas na primeira linha, e nas proximas n linhas,
o vertice inicial, final e seu peso.
*/
#ifndef _TAD_H
#define _TAD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define VERTICES 100 //quantidade maxima de vertices
#define LENGHT 50 //tamanho maximo das strings no arquivo

#define INPUT "dijkstra.txt" //arquivo contendo os caminhos
#define INPUT2 "capitais.txt" //arquivo contendo as cidades

typedef struct
{
    int distancia; //distancia do node ate a origem
    int existe; //se ainda esta no grafo ou nao
    int anterior; //anterior no caminho
} grafo;

int acha_menor();
void carrega_grafo();
void imprime(char **, int);
void dijkstra();

int arestas;
int source, dest;

grafo G[VERTICES];

int MPeso[VERTICES][VERTICES];
/*Matriz de pesos: a posicao [i][j] indica que existe uma aresta entre o vertice [i][j] e o valor do seu peso
*/

#endif // _TAD_H
