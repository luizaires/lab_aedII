#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool ehPrimo(int);
int contePrimos(int n);
void fatoresPrimos(int n);

int main(void){
    int num;
    printf("Digite um inteiro: ");
    scanf("%d", num);
    printf("/nDecomposição em fatores primos: ");
    fatoresPrimos(num);
    return 0;
}

bool ehPrimo(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            count++;
        }
        if(count > 2){
            return false;
        }
    }
    if(count == 2){
        return true;
    }

}

int contePrimos(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0 && ehPrimo(i)){
            count++;
        }
    }
    return count;
}

void fatoresPrimos(int n){
    int* ptr;
    int nPrimos = contePrimos(n);
    int count = 0;
    int n1 = n;
    ptr = (int*) malloc(nPrimos*sizeof(int));
    if(ptr != 0){
        for(int i = 2; i <= n; i++){
            if(ehPrimo(i)){
                while(n%i == 0){
                    ptr[count] = i;
                    n /= i;
                    count++;
                }
            }
        }
    }else{
        printf("Memória não alocada!");
    }
    printf("%d = 1*", n);
    for(int i = 0; i < count; i++){
        printf("%d*", *(ptr+i));
    }
}