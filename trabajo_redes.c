#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
struct arista
{
    int origen, destino, peso;
};
 
struct grafo
{
    int vertices, aristas;
    struct arista* arista;
};


 
struct grafo* crearGrafo(int vertices, int aristas)
{
    struct grafo* grafo = (struct grafo*) malloc( sizeof(struct grafo));

    grafo->vertices = vertices;
 
    grafo->aristas = aristas;
 
    grafo->arista = (struct arista*) malloc( grafo->aristas * sizeof( struct arista ) );
 
    return grafo;
}
 
void Solucion(int dist[], int n)
{
    printf("\nVertice\tDistancia del vertice origen\n");
    int i;
 
    for (i = 0; i < n; ++i){
		printf("%d \t\t %d\n", i, dist[i]);
	}
}
 
void BellmanFord(struct grafo* grafo, int origen)
{
    int vertices = grafo->vertices;
 
    int aristas = grafo->aristas;
 
    int AlmacenarDist[vertices];
 
    int i,j;
 
    for (i = 0; i < vertices; i++)




        AlmacenarDist[i] = 1000;
 
    AlmacenarDist[origen] = 0;
 
    for (i = 1; i <= vertices-1; i++)
    {
        for (j = 0; j < aristas; j++)
        {
            int u = grafo->arista[j].origen;
 
            int v = grafo->arista[j].destino;
 
            int peso = grafo->arista[j].peso;
 
            if (AlmacenarDist[u] + peso < AlmacenarDist[v])
                AlmacenarDist[v] = AlmacenarDist[u] + peso;
        }
    }
 
    for (i = 0; i < aristas; i++)
    {
        int u = grafo->arista[i].origen;
 
        int v = grafo->arista[i].destino;
 
        int peso = grafo->arista[i].peso;


 
        if (AlmacenarDist[u] + peso < AlmacenarDist[v])
            printf("Esta red tiene una arista con ciclo de peso negativo\n");
    }
 
    Solucion(AlmacenarDist, vertices);
 
    return;
}
 
int main()
{
    int V,A,O;
 
	printf("Ingrese el numero de routers de la red\n");
    scanf("%d",&V);
 
	printf("Ingrese el numero de aristas de la red\n");
    scanf("%d",&A);
 
	printf("Ingrese el numero del router de origen\n");
	scanf("%d",&O);
 
    struct grafo* grafo = crearGrafo(V, A);
 
    int i;
    for(i=0;i<A;i++){
        printf("\nIngrese las siguientes propiedades de la arista %d: Origen, destino y peso respectivamente\n",i+1);
        scanf("%d",&grafo->arista[i].origen);
        scanf("%d",&grafo->arista[i].destino);
        scanf("%d",&grafo->arista[i].peso);
    }
 
    BellmanFord(grafo, O);
 
    return 0;
}
