#include <stdio.h>

void main(){
    int inicio = 0, fim = 0;
    scanf("%d %d", &inicio, &fim);
    int soma = fim;
    for(int i = inicio; i < fim; i++){
        soma += i;
    }

    printf("%d\n", soma);

}