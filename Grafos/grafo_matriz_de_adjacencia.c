#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo grafo;
typedef struct aresta aresta;
typedef struct vertice vertice;

struct grafo {
  int numVertices;
  int numArestas;
  vertice **vertices;
  int **matrizAdjacencia;
};

struct vertice {
  char nome[10];
};

vertice *criarVertice() {
  vertice *ptrVertice = malloc(sizeof(vertice *));
  printf("Nome: ");
  scanf("%s", ptrVertice->nome);
  return ptrVertice;
}

grafo *criarGrafo(int v) {
  grafo *ptrGrafo = malloc(sizeof(grafo));
  ptrGrafo->numVertices = v;
  ptrGrafo->numArestas = 0;
  ptrGrafo->vertices = malloc(v * sizeof(vertice *));
  printf("Informe o nome dos vertices:\n");
  for (int i = 0; i < v; i++) {
    printf("\nVertice %d\n", i);
    ptrGrafo->vertices[i] = criarVertice();
  }
  ptrGrafo->matrizAdjacencia = calloc(v, sizeof(int *));
  for (int i = 0; i < v; i++) {
    ptrGrafo->matrizAdjacencia[i] = calloc(v, sizeof(int*));
  }
  return ptrGrafo;
}

void exibirVertices(grafo *g) {
  printf("Vertices do grafo:\n");
  for (int i = 0; i < g->numVertices; i++) {
    printf("%d: %s\n", i, g->vertices[i]->nome);
  }
}

void inserirAresta(grafo *g) {
  int v1, v2, dist;
  exibirVertices(g);
  printf("Digite uma opcao(inteiro) para o vertice de origem: ");
  scanf("%d", &v1);
  printf("Digite uma opcao(inteiro) para o vertice de destino: ");
  scanf("%d", &v2);
  printf("Distancia entre os vertices informados: ");
  scanf("%d", &dist);
  g->matrizAdjacencia[v1][v2] = dist;
  g->numArestas++;
}

void exibirGrafo(grafo *g) {
  int v = g->numVertices;

  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      printf("%d ", g->matrizAdjacencia[i][j]);
    }
    printf("\n");
  }
}

void liberarGrafo(grafo* g){
  for (int i = 0; i < g->numVertices; i++) {
    free(g->vertices[i]);
  }
  for (int i = 0; i < g->numVertices; i++) {
    free(g->matrizAdjacencia[i]);
  }
  free(g);
}
void teste(grafo* g){
  if(g != NULL){
    printf("Ponteiro para o grafo foi criado: %p\n", g);
    printf("Numero de vertices: %d\n", g->numVertices);
    printf("Numero de arestas: %d\n", g->numArestas);

  }else{
    printf("Alocacao falhou!\n");
  }
}

int main(void) {
  int v;
  printf("Informe o numero de vertices do grafo: ");
  scanf("%d", &v);
  printf("V = %d\n", v);
  grafo *g = criarGrafo(v);
  teste(g);
  inserirAresta(g);
  exibirGrafo(g);
  liberarGrafo(g);
  teste(g);
  return 0;
}