#include <stdio.h> 

void main(){
    int n = 0;
    scanf("%d", &n);

    if(n < 0){
        printf("O valor absoluto de %d eh: %d", n, n*(-1));
    } else {
        printf("O quadrado de %d eh: %d", n, n*n);
    }
    printf("\n");
}