#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0;
    scanf(" %d %d", &n1, &n2);
    int mmc = n1 * n2;

    for(int i = 1; i < n1; i++){
        int teste = n2 * i;

        if(teste % n1 == 0){
            mmc = teste;
            break;
        }    
    }
    printf("O MMC de %d e %d eh %d", n1, n2, mmc);

    printf("\n");
    return 0;
}