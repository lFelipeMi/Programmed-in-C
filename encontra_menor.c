#include <stdio.h>

int main(){
    int n;
    scanf(" %d", &n);
    int menor = n;

    for(int i = 1; i < 1000; i++){
        scanf(" %d", &n);
        if(n < menor){
            menor = n;
        }
    }
    printf("%d eh o menor numero", menor);

    printf("\n");
    return 0;
}