//Implementação da lógica sem se preocupar, inicialmente, se as funções possuem o retorno desejado
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

int main(void) {
  struct contato *agenda[size];
  int opt;
  do {
    opt = exibirMenu();
    executarMenu(agenda, opt);
  } while (opt != 1);
  return 0;
}

int exibirMenu() {
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
  //???É msm necessário
  struct contato *c;
  char filename[15];

  switch (opcao) {
  case 1:
    break;

  case 2:
    inserirContato(agenda);
    break;

  case 3:
    printf("\nInforme o contato que deseja remover:");
    scanf("%[^\n]%*c", c->nome);
    removerContato(agenda, c->nome);
    break;

  case 4:
    printf("\nInforme o contato que deseja buscar:");
    scanf("%[^\n]%*c", c->nome);
    buscarContato(agenda, c->nome);
    break;

  case 5:
    printf("\nInforme o nome do arquivo par o qual os dados de contato serao "
           "exportados");
    scanf("%[^\n]%*c", filename);
    exportarAgenda(agenda, filename);
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
  printf("Valor da chave: %d", key);
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
  printf("Nome: %s\nTelefone:%s\nE-mail: %s\n", novo->nome, novo->tel,
         novo->tel);
  return novo;
}

void inserirContato(struct contato *agenda[]) {
  struct contato *ptrContato = criarContato();
  int key = calcularChave(ptrContato->nome);
  int index = hashFunc(key);
  while (agenda[index] != NULL && index < size) {
    index++;
    agenda[index] = ptrContato;
  }
  printf("Contato inserido\n");
  printf("Nome: %s\nTelefone:%s\nE-mail: %s\n", agenda[index]->nome,
         agenda[index]->tel, agenda[index]->tel);
}

struct contato *buscarContato(agenda lista, char nome[]) {
  // Calcula o valor da chave a a partir do nome do contato informado
  int key = calcularChave(nome);
  // Aplica a função hash para retornar o indice de uma dada chave
  int index = hashFunc(key);
  // Percorre a lista de contatos a partir desse indice
  while (lista[index] != NULL) {
    // se o nome do contato localizado no índice é o mesmo do parâmetro
    // informado na função de busca, o endereço do contato é retornado
    if (lista[index]->nome == nome) {
      return lista[index];
    }
    // Caso não o encontre inicialmente na posição indicada pelo índice, a
    // função irá verificar se o dado se encontra na posição seguinte
    index++;
  }
  // se não o contato não for encontrado, a função retorna o valor 0
  return 0;
}

void removerContato(agenda lista, char nome[]) {
  struct contato *contato = buscarContato(lista, nome);
  // VERIFICAR!!! Talvez essa função libera o endereço da lista, mas não libera
  // os espaços de memória alocados com os dados da struct de contato
  free(contato);
}

// Essa função deverá abir um arquivo para leitura e então os dados de contatos
// contidos na lista telefônica deverão ser copiados, usando uma função da
// biblioteca string.h O problema é como realizar essa implementação usando
// lógica de ponteiros??
void exportarAgenda(agenda lista, char arq[]) {}
