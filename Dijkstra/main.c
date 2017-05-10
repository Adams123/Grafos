#include "tad.h"


int main()
{

    char **capitais; //vetor contendo as capitais
    FILE *f;
    f=fopen(INPUT2, "r"); //o arquivo contem, na primeira, a quantidade de capitais a ser lida
    int num_c;
    fscanf(f,"%d", &num_c);
    capitais=(char**)malloc(sizeof(char*)*num_c);
    int i;
    for(i=0; i<num_c; i++)
    {
        capitais[i]=(char*)malloc(sizeof(char)*LENGHT);
        fscanf(f,"%s",capitais[i]); //nas proximas linhas, contem as capitais em ordem de insercao no grafo
    }
    fclose(f);

    carrega_grafo();
    dijkstra();
    imprime(capitais, num_c);
    return 0;

}
