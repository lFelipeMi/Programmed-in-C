#include <stdio.h>

void main(){
    int n = 0;
    scanf("%d", &n);
    if(n >= 0){
        printf("%d eh positivo", n);
    } else{
        printf("%d eh negativo", n);
    }
    printf("\n");
    if(n % 2 == 0){
        printf("%d eh par", n);
        if(n == 2){
            printf(" e tambem eh primo");
        }
    } else {
        printf("%d eh impar", n);
        int primo = 1;
        for(int i = 3; i < n; i++){
            if(n % i == 0){
                primo = 0;
            }
        }
        if(primo){
            printf(" e tambem eh primo");
        }
    }
    printf("\n");
}