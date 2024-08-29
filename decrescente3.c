#include <stdio.h>

void main(){

    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    //vamos considerar n1 = menor, n2 = meio e n3 = maior;
    int troca = 0;

    if (n1 > n2 || n1 > n3){ //verifica se n1 eh maior que algum  numero
        troca = n1;

        //proximo objetivoo eh, sefor, verificar qual dos outros dois eh o menor
        if (n2 < n3){
            n1 = n2;
            n2 = troca;
        } else {
            n1 = n3;
            n3 = troca;
        }
    }
    //verifica se n2 eh maior que n3m se for, efetua a troca
    if (n2 > n3){
        troca = n2;
        n2 = n3;
        n3 = troca;
    }

    printf("%d\n%d\n%d\n", n1, n2, n3);

    return;
}