#include <stdio.h> 

void main(){
    int n = 0;
    scanf("%d", &n);
    if(n >= 0){
        printf("O quadrado de %d eh: %d", n, n*n);
    } else {
        printf("O cudo de %d eh: %d", n, n*n*n);
    }
    
    printf("\n");
}