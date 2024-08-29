#include <stdio.h>

int main(){
    int matriz[5][4];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            scanf(" %d", &matriz[i][j]);
        }
    }

    int matriz_trans[4][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            matriz_trans[j][i] = matriz[i][j];
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            printf("%2d ", matriz_trans[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}