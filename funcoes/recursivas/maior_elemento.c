#include <stdio.h>

int maior_elemento(int vet[], int n);

int main(){
    int vet[10] = {0, 31, 53, -3, 89, 40, 42, 54, 78, 12};
    printf("O maoir elemento do vetor eh: %d", maior_elemento(vet, 10));

    printf("\n");
    return 0;
}

int maior_elemento(int vet[], int n){
    if(n - 1 <= 0)
        return vet[0];
        
    int maior = maior_elemento(vet, n -1);
    if(vet[n-1] < maior)
        return maior;
    else 
        return vet[n-1];
}