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

int exibirMenu(void);
void executarMenu(agenda, int);
void inserirContato(struct contato *agenda[]);
struct contato *buscarContato(agenda, char[]);
void removerContato(agenda, char[]);
void exportarAgenda(agenda, char[]);
void exibirAgenda(agenda);

int main(void) {
  struct contato* agenda[size];
  int opt;
  memset(agenda, 0, size*sizeof(agenda[0]));
  do {
    opt = exibirMenu();
    executarMenu(agenda, opt);
  } while (opt != 1);

  for(int i = 0; i < size;i++){
    if(agenda[i] != NULL){
      free(agenda[i]);
    }
  }
  return 0;
}


int exibirMenu() {
  int opcao;

  printf("\nMenu de opcoes\n");
  printf("1. Sair\n");
  printf("2. Inserir novo contato\n");
  printf("3. Remover contato da lista\n");
  printf("4. Buscar contato na agenda\n");
  printf("5. Exportar agenda de contatos para arquivo\n");
  printf("6. Exibir lista telefonica\n");
  printf("Digite o numero corresponde a opcao que deseja executar: ");
  scanf("%d", &opcao);

  return opcao;
}

void executarMenu(struct contato *ptrAgenda[], int opcao) {
  char filename[15];
  char nomeContato[25];

  switch (opcao) {
  case 1:
    break;

  case 2:
    inserirContato(ptrAgenda);
    break;

  case 3:
    printf("Informe o contato que deseja remover:");
    scanf("%s", nomeContato);
    removerContato(ptrAgenda, nomeContato);
    break;

  case 4:
    printf("Informe o contato que deseja buscar:");
    scanf("%s", nomeContato);
    buscarContato(ptrAgenda, nomeContato);
    break;

  case 5:
    printf("Informe o nome do arquivo par o qual os dados de contato serao "
           "exportados");
    scanf("%s", filename);
    exportarAgenda(ptrAgenda, filename);
    break;

  case 6:
    printf("Opção: %d\nPonteiro da agenda: %p\n", opcao, ptrAgenda);
    exibirAgenda(ptrAgenda);
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
  printf("Valor da chave: %d\n", key);
  return key;
}

// Implementando método da divisão
int hashFunc(int key) { return key % size; }

// 
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

void inserirContato(agenda lista) {
  struct contato *ptrContato = criarContato();
  int key = calcularChave(ptrContato->nome);
  //Determinando a posição em que o contato será alocado
  int hashIndex = hashFunc(key);
  //Aloca caso o valor armazenado seja nulo
  if (lista[hashIndex] == NULL) {
    lista[hashIndex] = ptrContato;
  } else {
    //Na hipótese em que essa posição não esteja livre
    int temp = hashIndex+1;
    while (lista[temp] != NULL && temp < size) {
      lista[temp] = ptrContato;
      printf("Indice %d da lista ocupado\n", hashIndex);
      temp++;
      hashIndex = temp;
    }
    printf("Indice %d da lista livre\n", hashIndex);
  }
  // Teste
  for (int i = 0; i < size; i++) {
    printf("%p", lista[i]);
    printf(" ");
  }
  printf("\nContato inserido\n");
  
  printf("HashIndex: %d\nNome: %s\nTelefone:%s\nE-mail: %s\n",
        hashIndex,lista[hashIndex]->nome, lista[hashIndex]->tel,
        lista[hashIndex]->email);
}

struct contato *buscarContato(agenda lista, char nome[]) {
  // Calcula o valor da chave a a partir do nome do contato informado
  printf("%s\n", nome);
  int key = calcularChave(nome);
  // Aplica a função hash para retornar o indice de uma dada chave
  int index = hashFunc(key);
  printf("Index:%d\n", index);
  // Percorre a lista de contatos a partir desse indice
  for(int i = index; i < size; i++) {
    if (lista[i]->nome == nome) {
      printf("Valor encontrado\n: %d\nNome: %s\nTelefone:%s\nE-mail: %s\n",lista[index]->nome, lista[index]->tel,lista[index]->email);
      return lista[i];
    }
  }
  return 0;
}

void removerContato(agenda lista, char nome[]) {
  struct contato *contato = buscarContato(lista, nome);
  free(contato);
}

void exportarAgenda(agenda lista, char arq[]) {
  // Declarando ponteiro para o arquivo
  FILE *fp;
  char c;
  int i = 0;
  // Abertura de uma arquivo no modo escrita
  fp = fopen(arq, "w");
  if (fp == NULL) {
    printf("Nao foi possivel abrir arquivo!\n");
    exit(1);
  } else {
    printf("Arquivo aberto com sucesso!\n");
  }
  // Percorrendo a lista telefônica (tabela Hash)
  while (i < size) {
    if (lista[i] != NULL) {
      fwrite(lista[i], sizeof(struct contato), 1, fp);
    }
    i++;
  }
  fclose(fp);
}

void exibirAgenda(agenda lista) {
  printf("****Lista Telefonica****\n");
  for (int i = 0; i < size; i++) {
    printf("\nHash Index: %d\n", i);
    if (lista[i] == NULL) {
      printf("Espaco Vazio!\n");
    } else {
      printf("Nome: %s\nTelefone:%s\nE-mail: %s\n", lista[i]->nome,
             lista[i]->tel, lista[i]->tel);
    }
  }
}
