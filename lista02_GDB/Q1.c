#include <stdio.h>

int main(void){
    char c;
    for(int i = 0; i <= 127; i++){
        c = i;
        printf("%c ", c);
        if(i%9 == 0){
            printf("\n");
        }
        
    }
}