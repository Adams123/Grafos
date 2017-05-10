#include "tad.h"

/*Funcao que executa o dijkstra a partir de source
*/
void dijkstra()
{
    int interacao;
    for(interacao=0; interacao<arestas; interacao++) //enquanto existirem arestas a serem percorridas
    {
        int i;
        int v = acha_menor(); //v eh a menor aresta vizinha a source
        G[v].existe = 0; //Remove a menor aresta de G
        for (i = 0; i < arestas; i++){
            if (G[i].existe)//vertice deve estar no grafo
                if(MPeso[v][i] != 0)//a aresta entre o menor e o atual deve existir
                    if((G[v].distancia + MPeso[v][i] < G[i].distancia || G[i].distancia == 0))
                    {
                        //caso a distancia do menor + distancia entre o atual e o menor
                        //seja menor que a distancia do no sendo visitado ou caso ela nao tenha sido inicializada
                        /*----RELAXAMENTO DE [V][I]----*/
                        G[i].distancia = G[v].distancia + MPeso[v][i]; //vertice sendo visitado recebe peso do menor + distancia entre menor e sendo visitado
                        G[i].anterior = v; //caminho mais proximo eh salvo
                    }
        }
        if(v==dest) {
                return;
        }
    }
}

void imprime(char **capitais, int n)   //imprime o caminho de source a dest
{
    int i = dest; //inicia a lista no ultimo no (no caso, o no dest)
    printf("Distancia de %s ate %s: %d\n", capitais[source], capitais[dest], G[dest].distancia);
    printf("Caminho:\n");
    int caminho[n], cont=0;
    while(i != source)   //enquanto nao chegar ao vertice de origem
    {
        caminho[cont]=G[i].anterior; //como ao percorrermos o vetor, o caminho vai estar na ordem inversa
        cont++;  //o colocamos em um vetor de caminho em ordem crescente
        i = G[i].anterior; //avanca para o vertice pai
    }
    cont--;
    for(cont; cont>0; cont--)
        printf("%s ->", capitais[caminho[cont]]);
    printf("%s ->%s\n", capitais[caminho[cont]], capitais[dest]);
}

int acha_menor()   //acha menor aresta da vizinhanca do source
//note que a vizinhanca do source eh modificada a acada interacao do djikstra, pois os vertices ja visitados sao removidos
{
    int minimo = INT_MAX;
    int i, indice = source; //procura sempre relativo a source, ou seja, a menor distancia na vizinhanca de source
    //como as arestas ja visitadas sao removidas, eh garantido que um caminho nao vai ser percorrido duas vezes
    for (i = 0; i < arestas; i++)
        if (G[i].existe)
            if(G[i].distancia != 0)
                if(G[i].distancia < minimo)
                    minimo = G[indice = i].distancia;
    return indice;
}

void carrega_grafo() //monta o grafo a partir dos arquivos de entrada
{
    int i = 0;
    FILE *f = fopen(INPUT, "r");
    int tmp_source, tmp_dest, a;
    fscanf(f, "%d\n", &arestas);
    printf("Digite a cidade origem:\n");
    scanf("%d", &tmp_source);
    printf("Digite a cidade destino:\n");
    scanf("%d", &tmp_dest);

    tmp_source--;
    tmp_dest--; //decrementa a origem e o destino, pois a cidade 1, por exemplo, eh representada por 0 no grafo
    source = tmp_source; //origem
    dest = tmp_dest; //destino
    i=0;
    while(i<arestas)  //percorrendo todas as arestas
    {
        int source, dest; //source e dest usados apenas dentro do for
        int val;
        G[i].existe = 1; //vertice esta no grafo
        G[i].distancia = 0; //distancia do no 'i' ate o source eh 0
        G[i].anterior = -1; //nao ha caminhos setados ainda
        fscanf(f, "%d %d %d", &source, &dest, &val);
        source--;
        dest--;
        MPeso[source][dest] = val; //representa se source eh adjacente a dest
        MPeso[dest][source] = val; //caso 0 nao eh, caso 1 eh
        i++;
    }
    fclose(f);
}
