#include <stdio.h>

void imprimeVetor(int vet[], int TAM);

int main(){
    int vet[5] = {89,12,15,34,4};
    imprimeVetor(vet, 5);

    return 0;
}

void imprimeVetor(int vet[], int TAM){
    for(int i = 0; i < TAM; i++)
        printf("%p contem: %2d\n", &vet[i], *(vet + i));
}