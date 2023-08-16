#include <stdio.h>
#include <stdlib.h>

int conteFatores(int);
void isPerfect(int);

int main(void){
    printf("Lista de numeros perfeitos entre 1 e 1000/n");
    for(int i = 1; i <= 10; i++){
        isPerfect(i);
    }

   return 0;
}


int conteFatores(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            count++;
        }
    }
    return count;
}



void isPerfect(int n){
    int soma = 0;
    int i = 0;
    int* ptr;
    int nFatores = conteFatores(n);
    int cont = 0;
    ptr = (int*) malloc(nFatores*sizeof(int));
    if(ptr != 0){
        for(int i = 1; i <= n; i++){
            if(n%i == 0){
                ptr[cont] = i;
                cont++;
            }
        }
    }else{
        printf("Memória não alocada!");
    }
    int j = 0;
    while((ptr+j) != NULL){
        soma += ptr[j];
        j++;
    }

    if(soma == n){
        printf("%d: ", i);
        for(int j=0; (ptr+j)!= NULL; j++){
            printf("%d ", *(ptr+j));
        }
        printf("/n");
        free(ptr);
    }
}