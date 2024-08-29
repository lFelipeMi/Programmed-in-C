#include <stdio.h>

int fatorial(int n);

void main(){
    int n = 0;
    scanf("%d", &n);
    int fat = fatorial(n);

    printf("O fatorial de %d eh %d\n", n, fat);
}

int fatorial(int n){
    int fatorial = 1;
    for(int i = n; i > 0; i--){
        fatorial *= i;
    }
    
    return fatorial;
}