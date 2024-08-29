#include <stdio.h>

int main(){
    int n, maior;
    scanf("%d ", &n);
    maior = n;
    for(int i = 0; i < 4; i++){
        scanf(" %d", &n);
        if(n > maior){
            maior = n;
        }
    }
    printf("%d eh o maior numero", maior);

    printf("\n");
    return 0;
}