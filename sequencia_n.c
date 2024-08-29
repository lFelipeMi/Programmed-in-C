#include <stdio.h>

int main(){
    int n, S, soma = 0;

    for(int i = 0; i < n; i++){
        scanf(" %d", &S);
        soma += S;
    }
    printf("A soma da sequencia eh: %d", soma);

    printf("\n");
    return 0;
}