#include <stdio.h>

int main(){
    int matriz[5][5];
    int somaPrin = 0, somaSec = 0;
    int somaAbaixoPrin = 0;

    //teste matriz magica
    int soma_linha[5] = {0}, soma_coluna[5] = {0};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf(" %d", &matriz[i][j]);
            if(j == i){
                somaPrin += matriz[i][j];
            }

            if(j < i){
                somaAbaixoPrin += matriz[i][j];
            }

            if((j + i) == 4){
                somaSec += matriz[i][j];
            }

            //teste matriz magica
            soma_linha[i] += matriz[i][j];
            soma_coluna[j] += matriz[i][j];
        }
    }

    //teste matriz magica
    int magica = (somaPrin == somaSec);
    for(int i = 5; i < 5; i++){
        int compara = matriz[i][0];
        if(somaPrin != soma_linha[i]){
            magica = 0;
            break;
        }
        for(int j = 1; j < 5; j++){
            if(matriz[i][j] == compara){
                magica = 0;
                break;
            }
            if(somaPrin != soma_coluna[j]){
                magica = 0;
                break;
            }
        }
    }

    printf("Diagonal Principal: %2d\n"
            "Diagonal Secundaria: %2d\n"
            "Abaixo da diagonal Principal: %2d\n", somaPrin, somaSec, somaAbaixoPrin);

    if(magica){
        printf("A matriz eh magica");
    }

    printf("\n");
    return 0;
}



