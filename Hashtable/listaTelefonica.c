#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 32

struct contato {
  char nome[25];
  char tel[11];
  char email[50];
};
// Um vetor que guardará os endereços na posição (índice) retornada pela função
// hashFunc
typedef struct contato *agenda[size];

void inserirContato(struct contato *agenda[]);
void removerContato(agenda, struct contato *);
void exportarAgenda(agenda);

int main(void) {
  struct contato *agenda[size];
  inserirContato(agenda);
  return 0;
}

int ExibirMenu() {
  int opcao;

  printf("\nMenu de opções\n");
  printf("1. Sair\n");
  printf("2. Inserir novo contato\n");
  printf("3. Remover contato da lista\n");
  printf("4. Buscar contato na agenda\n");
  printf("5. Exportar agenda de contatos para arquivo\n");
  printf("6. Exibir lista\n");
  printf("Digite o número corresponde a opcão que deseja executar: ");
  scanf("%d", &opcao);

  return opcao;
}

void executarMenu(struct contato *agenda[], int opcao) {
  struct contato *c;
  switch (opcao) {
  case 1:
    break;

  case 2:
    inserirContato(agenda);
    break;

  case 3:
    printf("\nInforme o contato que deseja remover:");
    scanf("%d", c);
    removerContato(agenda, c);
    break;
  }
}

// Implementa uma função que recebe uma string e calcula a soma dos valores em
// ASCII dos caracteres correspondentes
int calcularChave(char str[]) {
  int key = 0;
  for (int i = 0; i <= strlen(str); i++) {
    key += str[i];
  }
  return key;
}

// Retorna o índice que armazenará o endereço do contato inserido ao dividir o
// valor da chave calculada pelo tamanho definido para a agenda
int hashFunc(int key) { return key % size; }

// Retorna o endereço de um ponteiro onde ficará alocado o struct contendo o
// nome,o numero de telefone e o e-mail do contato
struct contato *criarContato() {
  struct contato *novo = (struct contato *)malloc(sizeof(struct contato));
  printf("Nome do contato: ");
  scanf("%s", (*novo).nome);
  printf("Numero de telefone: ");
  scanf("%s", (*novo).tel);
  printf("E-mail: ");
  scanf("%s", (*novo).email);
  return novo;
}

void inserirContato(struct contato *agenda[]) {
  struct contato *ptrContato = criarContato();
  int key = calcularChave(ptrContato->nome);
  int index = hashFunc(key);
  agenda[index] = ptrContato;
}
