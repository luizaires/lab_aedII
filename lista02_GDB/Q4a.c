#include <stdio.h>
#include <stdlib.h>
// Função para verificar se um número é perfeito e retornar a soma de seus divisores próprios.
int isPerfect(int n){
    int soma = 0, i;
// Loop para iterar através dos possíveis divisores próprios do número.
    for (i = 1; i < n; i++){
        if( n % i == 0){
            soma+= i; // Adiciona o divisor à soma se for um divisor próprio.
        }
    }
// Verifica se a soma dos divisores próprios é igual ao número original.
    if(soma == n){
        return soma; // Retorna a soma se o número for perfeito.
    } 
    
}

int main(){
int k, r;

printf("\nInsira um número: ");
scanf("%i", &k);

r = isPerfect(k);  // Chama a função isPerfect para verificar se o número é perfeito.

if(r == k){
    printf("\n%i é um número perfeito", k);
} else {
     printf("\n%i não é um número perfeito", k);
}


}