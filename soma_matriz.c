#include <stdio.h>

int main(){
    int matriz[5][7], soma = 0;
    int soma_linha[5], soma_coluna[7];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            scanf(" %d", &matriz[i][j]);
            soma+= matriz[i][j];
            soma_linha[i] += matriz[i][j];
            soma_coluna[j] += matriz[i][j];
        }
    }

    printf("Soma total: %d\n", soma);

    for(int i = 0; i < 5; i++){
        printf("Linha %d: %2d\n", i + 1, soma_linha[i]);
    }

    for(int i = 0; i < 7; i++){
        printf("Coluna %d: %2d\n", i + 1, soma_coluna[i]);
    }


    
    printf("\n");
    return 0;
}