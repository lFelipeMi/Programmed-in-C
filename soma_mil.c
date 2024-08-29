#include <stdio.h>

int main(){
    int soma = 0;
    for(int i = 1; i < 1000; i+=2){
        printf("%6i + %3i...\n", soma, i);
        soma += i;
    }

    printf("%d", soma);

    printf("\n");
    return 0;
}