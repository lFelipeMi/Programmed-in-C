#include <stdio.h>

int main(){
    int n;
    scanf(" %d", &n);
    int maior = n, menor = n;

    if(n < 0){
        printf("Entrada negativa invalida...");
        return 0;
    }

    while(n >= 0){
        scanf(" %d", &n);

        if(n > maior){
            maior = n;
        }
        if(n < menor){
            menor = n;
        }
    }

    printf("O menor eh: %3.d"
           "O maior eh: %3.d", menor, maior);

    printf("\n");
    return 0;
}