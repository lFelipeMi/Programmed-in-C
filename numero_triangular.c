#include <stdio.h>

int main(){
    int n = 0;
    scanf(" %d", &n);

    for(int i = 1; i < (n/2) - 1; i++){
        if(i * (i+1) * (i+2)){
            printf("Este eh um numero triangular\n");
            return 0;
        }
    }
    printf("Este nao eh um numero triangular");

    printf("\n");
    return 0;
}