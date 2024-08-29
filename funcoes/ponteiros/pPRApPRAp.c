#include <stdio.h>

void imprime(int variavel);

int main(){
    int A = 1, *B, **C, ***D;
    B = &A;
    C = &B;
    D = &C;
    
    imprime(A);
    imprime(2 * *B);
    imprime(3 * **C);
    imprime(4 * ***D);

    return 0;
}

void imprime(int variavel){
    printf("%d\n", variavel);
}