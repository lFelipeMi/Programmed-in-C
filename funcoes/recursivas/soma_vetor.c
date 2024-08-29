#include <stdio.h>

int soma_vetor(int vet[], int  n);

int main(){
    int vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, n = 0;
    scanf(" %d", &n);
    printf("A soma de %d do vetor eh: %d", n, soma_vetor(vet, n));

    printf("\n");
    return 0;
}

int soma_vetor(int vet[], int  n){
    if(n - 1 <= 0)
        return vet[0];
    else
        return vet[n - 1] + soma_vetor(vet, n - 1);
}