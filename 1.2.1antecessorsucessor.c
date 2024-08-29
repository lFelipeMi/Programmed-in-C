#include <stdio.h>

void main(){
    int n = 0;
    //Digite um número entre 0 e 60
    scanf("%d", &n);

    if (n > 60 || n < 0){
        printf("O numero digitado nao eh valido");
    } else if (n != 0 && n != 60){
            printf("O antecessor de %d: %d\nO sucessor de %d: %d\n", n, n-1, n, n+1);
        } else if (n == 0){
            printf("O antecessor de 0 eh: 60\nO sucessor de 0 eh: 1\n");
        } else {
            printf("O antecessor de 60 eh: 59\nO sucessor de 60 eh: 0\n");
        }
}