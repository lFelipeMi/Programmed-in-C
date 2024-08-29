#include <stdio.h>

int somatorio(int n);

int main(){
    int n = 1;
    scanf(" %d", &n);

    printf("Somatorio de %d ate 0 eh %d", n, somatorio(n));

    printf("\n");
    return 0;
}

int somatorio(int n){
    if(n == 0){
        return 0;
    }
    if(n > 0){
        return n + somatorio(n - 1);
    }
    if(n < 0){
        return n + somatorio(n + 1);
    }
}
