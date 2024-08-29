#include <stdio.h>

void maiorEmenor(int vet[], int TAM, int* maior, int* menor);
void imprime(int variavel);

int main(){
    int v[10] = {98,13,33,46,78,12,11,5,43,10};
    int maior = 0, menor = 0;

    maiorEmenor(v, 10, &maior, &menor);
    imprime(maior);
    imprime(menor);

    return 0;
}


void maiorEmenor(int vet[], int TAM, int* maior, int* menor){
    *maior = vet[0];
    *menor = vet[0];
    for(int i = 1; i < TAM; i++){
        if(vet[i] > *maior)
            *maior = vet[i];
        if(vet[i] < *menor)
            *menor = vet[i];
    }
}

void imprime(int variavel){
    printf("%d\n", variavel);
}