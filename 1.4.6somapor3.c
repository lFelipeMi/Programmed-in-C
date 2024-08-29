#include <stdio.h>

void main(){
    int n = 0, soma = 0;
    scanf("%d", &n);

    for(int i = 3; i <= n; i++){
        if(i % 3 == 0){
            soma += i;
        }
    }

    printf("A soma dos numeros divisiveis por 3 no intervalo de 1 a %d eh: %d", n, soma);
    printf("\n");
}