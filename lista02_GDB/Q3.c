#include <stdio.h>
#include <math.h>

void triploPitagorico(int);

int main(void){
    int l;
    printf("Insira um parametro limite para o triplo pitagorico\n");
    scanf("%d", &l);
    printf("Triplos pitagoricos com lados menores que %d\n", l);
    triploPitagorico(l);
    
}

void triploPitagorico(int param){
    double h;
    for(int i = 1; i < param; i++){
        for(int j= 1; j < param; j++){
            h = sqrt(i*i+j*j);
            double dec = (h- (int) h);
            if(h < param && dec == 0){
                int h_int = h;
                 printf("cateto1 = %d, cateto2 = %d, hipotenusa = %d\n", i, j, h_int);
            }
        }
    }
}