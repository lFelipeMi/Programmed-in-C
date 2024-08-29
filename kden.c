#include <stdio.h>

int main(){
    int n = 0, k = 0, soma = 0, digito = 0, k2 = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i < 10; i++){
        k2 = k;

        for(; k2 > 0; k2 /=10){
            digito = k2 % 10;

            if(digito == i){
                soma += i;

                break;
            }      
        } 

    }

    printf("%d", soma);

    printf("\n");
    return 0;
}