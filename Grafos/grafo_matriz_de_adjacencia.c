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
}

grafo *criarGrafo(int v) {
  grafo *ptrGrafo = malloc(sizeof(grafo));
  ptrGrafo->numVertices = v;
  ptrGrafo->numArestas = 0;
  ptrGrafo->vertices = malloc(v * sizeof(vertice *));
  printf("Informe o nome dos vertices:\n");
  for (int i = 0; i < v; i++) {
    printf("Vertice %d\n", i);
    ptrGrafo->vertices[i] = criarVertice();
  }
  ptrGrafo->matrizAdjacencia = calloc(v, sizeof(int));
  return ptrGrafo;
}

void exibirVertices(grafo *g) {
  for (int i = 0; i < g->numVertices; i++) {
    printf("%d: %s", i, (*g->vertices)->nome);
  }
}

void inserirAresta(grafo *g) {
  int v1, v2, dist;
  exibirVertices(g);
  printf("Digite uma opção(inteiro) para o vertice de origem: ");
  scanf("%d", &v1);
  printf("Digite uma opção(inteiro) para o vertice de destino: ");
  scanf("%d", &v2);
  printf("Distancia entre os vertices informados: ");
  scanf("%d", &dist);
  g->matrizAdjacencia[v1][v2] = dist;
  g->matrizAdjacencia[v2][v1] = dist;
}

int main(void) { return 0; }