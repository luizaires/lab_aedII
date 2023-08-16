#include <stdio.h>
#include <stdlib.h>

func(int m, int n){
    if (n == 1){
        return m + 1;
    } else if(m == 1){
        return n + 1;
    } else if (m > 1 && n > 1){
        return f(m, n - 1) + f(m-1, n);
    }
}


int main (){
    int m, n;
    printf("Digite um valor inteiro para m: ");
    scanf("%d", &m);
    printf("Digite um valor inteiro para n: ");
    scanf("%d", &n);
    func(m, n);

}