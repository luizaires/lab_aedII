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
  printf(">>Ponteiro para o grafo: %p\n", g);
  printf(">>Numero de vertices: %d\n", g->numVertices);
  printf(">>Numero de arestas: %d\n", g->numArestas);
  printf(">>Vertices = {\n");
  for (int i = 0; i < v; i++) {
    printf("\tv%d = %s,\n",i, g->vertices[i]->nome);
  }
  printf("}\n");

  printf(">>Matriz de Adjacencia:\n");
  for (int i = 0; i < v; i++) {
    printf("\t%s",g->vertices[i]->nome);
  }
  printf("\n");
  for (int i = 0; i < v; i++) {
    printf("%s",g->vertices[i]->nome);
    for (int j = 0; j < v; j++) {
      printf("\t%d", g->matrizAdjacencia[i][j]);
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

int testarAlocacao(grafo* g){
  if(g != NULL){
    printf("Grafo alocado com sucesso!\n");
    return 0;
  }else{
    printf("Alocacao falhou!\n");
    return 1;
  }
}


int exibirMenu() {
  int opcao;

  printf("\nMenu de opcoes\n");
  printf("1. Sair\n");
  printf("2. Inserir nova Aresta\n");
  printf("Digite o numero correspondente a opcao que deseja executar: ");
  scanf("%d", &opcao);

  return opcao;
}

void executarMenu(grafo* ptrGrafo, int opcao) {
  switch (opcao) {
  case 1:
    break;

  case 2:
    inserirAresta(ptrGrafo);
    exibirGrafo(ptrGrafo);
    break;
  }
}

int main(void) {
  int v;
  int opt;
  printf("Informe o numero de vertices do grafo: ");
  scanf("%d", &v);
  printf("V = %d\n", v);
  grafo *g = criarGrafo(v);
  testarAlocacao(g);
  do {
    opt = exibirMenu();
    executarMenu(g, opt);
  } while (opt != 1);
  liberarGrafo(g);
  return 0;
}