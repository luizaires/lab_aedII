/*Etapas:
1-Implementação da lógica sem se preocupar, inicialmente, se as funções possuem o retorno desejado,
apenas se elas não possuem erros de compilação, como por exemplo, erros de tipagem
2-Rodar o código, corrigindo os bugs na ordem que vão aparecendo de modo a liberar a pilha de execução, averiguando os retornos das funções.*/
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
  struct contato *agenda[size];
  int opt;
  do {
    opt = exibirMenu();
    executarMenu(agenda, opt);
  } while (opt != 1);
  return 0;
}

//Criação de um menu que executará a função desejada, de acordo com a opção escolhida
//A sua principal vantagem é que essa execução é executada em loop.
//Assim, não é necessário testar todas as implementações na função main
//Podemos escolher quais executar, ou mesmo fazer isso mais de uma vez
//Sem necessidade de rodar o código novamente
int exibirMenu() {
  int opcao;

  printf("\nMenu de opções\n");
  printf("1. Sair\n");
  printf("2. Inserir novo contato\n");
  printf("3. Remover contato da lista\n");
  printf("4. Buscar contato na agenda\n");
  printf("5. Exportar agenda de contatos para arquivo\n");
  printf("6. Exibir lista telefônica\n");
  printf("Digite o número corresponde a opcão que deseja executar: ");
  scanf("%d", &opcao);

  return opcao;
}

void executarMenu(struct contato *ptrAgenda[], int opcao) {
  //???É msm necessário
  struct contato *c;
  char filename[15];

  switch (opcao) {
    case 1:
      break;
  
    case 2:
      inserirContato(ptrAgenda);
      break;
  
    case 3:
      printf("\nInforme o contato que deseja remover:");
      scanf("%[^\n]%*c", c->nome);
      removerContato(ptrAgenda, c->nome);
      break;
  
    case 4:
      printf("\nInforme o contato que deseja buscar:");
      scanf("%[^\n]%*c", c->nome);
      buscarContato(ptrAgenda, c->nome);
      break;
  
    case 5:
      printf("\nInforme o nome do arquivo par o qual os dados de contato serao exportados");
      scanf("%[^\n]%*c", filename);
      exportarAgenda(ptrAgenda, filename);
      break;
  
    case 6:
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
  printf("\nNome: %s\nTelefone:%s\nE-mail: %s\n", novo->nome, novo->tel,
         novo->email);
  return novo;
}

void inserirContato(agenda lista) {
  printf("\nPonteiro agenda: %p\n", lista);
  struct contato *ptrContato = criarContato();
  printf("\nPonteiro struct: %p\n", ptrContato);
  int key = calcularChave(ptrContato->nome);
  printf("\nChave: %d\n", key);
  int hashIndex = hashFunc(key);
  //Desafio!Para evitar que o valor do indice da tabela hash fosse atualizado a cada laço de repetição
  //foi necessario armazená-lo em uma variável temporária
  int temp = hashIndex;
  printf("Index: %d\n", hashIndex);
  while (lista[temp] != NULL && temp < size) {
    lista[temp] = ptrContato;
    temp++;
  }
  if(lista[temp] == NULL){
    hashIndex = temp;
  }
  //Teste
  printf("\nContato inserido\n");
  printf("Nome: %s\nTelefone:%s\nE-mail: %s\n", lista[hashIndex]->nome,
         lista[hashIndex]->tel, lista[hashIndex]->email);
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
  /*DIFICULDADES!! VERIFICAR se essa função libera o endereço da lista, mas não libera os espaços de memória alocados com os dados da struct de contato*/
  free(contato);
}

/* DIFICULDADES! 
Essa função deverá abir um arquivo para escrita e então 
os dados de contatos contidos na lista telefônica deverão ser copiados,
usando uma função da biblioteca string.h 
O problema é como realizar essa implementação usando lógica de ponteiros??*/
/*SOLUÇÃO ENCONTRDADA
A biblioteca stdio.h possui a função fwrite que permite escrever
os elementos da struct para um arquivo*/
void exportarAgenda(agenda lista, char arq[]) {
  //Declarando ponteiro para o arquivo
  FILE* fp;
  char c;
  int i = 0;
  //Abertura de uma arquivo no modo escrita
  fp = fopen(arq, "w");
  /* Verificando se não houve algum erro durante esse processo, o que é feito averiguando se a função fopen retorna um valor não-nulo*/
  if (fp == NULL) {
    printf("Não foi possível abrir arquivo!");
    exit(1);

  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }
  //Percorrendo a lista telefônica (tabela Hash)
  while (i < size) {
    /*Encontrado um endereço armazendo na lista, escrevemos o contato alocado nesse endereço no arquivo. Para isso utilizamos a função fwrite. O primeiro argumento é o endereço que indica o contato, o segundo é tamanho da struct que indica esse dado. O terceiro argumento indica o número structs que se deseja. Aqui, optou-se por escrever apenas 1 struct, quando há um endereço presente no índice do array. No entanto, poderiamos passar o tamanho do array para escrever todas as structs alocadas nos ponteiros contidas nesse array, o que incluiria os valores NULL. O quarto argumento é o ponteiro para o arquivo.*/
    if(lista[i] != NULL){
      fwrite(lista[i],sizeof(struct contato), 1, fp);
    }
    i++;
  }
  
  fclose(fp);
}

void exibirAgenda(agenda lista){
  printf("****Lista Telefônica****");
  for(int i = 0; i < size; i++){
    printf("      Hash Index: %d", i);
    printf("Nome: %s\nTelefone:%s\nE-mail: %s\n", lista[i]->nome,
         lista[i]->tel, lista[i]->tel);
  }
}