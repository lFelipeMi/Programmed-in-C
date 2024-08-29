#include <stdio.h>

void troca(float *a, float *b);
void imprime(int variavel);

int main(){
    float a = 1, b = 2;
    troca(&a, &b);
    imprime(a);
    imprime(b);

    return 0;
}

void troca(float *a, float *b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void imprime(int variavel){
    printf("%d\n", variavel);
}