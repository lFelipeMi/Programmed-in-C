#include <stdio.h>

int main(){
    int continuar = 1;
    do{
        char velha[3][3] =  {'_','_','_','_','_','_','_','_','_'};
        int vencedor = 0;
        int jogada = 0;

        int somaPrin = 0, somaSec = 0;
        int soma_linha[3] = {0}, soma_coluna[3] = {0};
        while(!vencedor && jogada < 9){
            int linha = -1, coluna = -1;
            printf("////////////////////////////////////\nJogo atual:\n");
            printf("0  1  2");
            for(int i = 0; i < 3; i++){
                printf("\n-------\n|");
                for(int j = 0; j < 3; j++){
                    printf("%c|", velha[i][j]);
                    if(j == 2){
                        printf(" %d", i);
                    }
                }
            }
            printf("\n-------\n");

            printf("O proximo jogador eh: ");
            if(!(jogada%2)){
                printf("Jogador 1X\nInforme a linha e a coluna que deseja jogar!\n");
                scanf(" %d %d", &linha, &coluna);
                while((velha[linha][coluna] != '_') || linha < 0 || coluna < 0){
                    printf("Coordenadas invalidas, por favor informe novamente\n"
                        "LINHA e COLUNA desejadas");
                        scanf(" %d %d", &linha, &coluna);
                }
                velha[linha][coluna] = 'X';
            } else {
                printf("Jogador 2O\n Informe a linha e a coluna que deseja jogar!\n");
                scanf(" %d %d", &linha, &coluna);
                while((velha[linha][coluna] != '_') || linha < 0 || coluna < 0){
                    printf("Coordenadas invalidas, por favor informe novamente\n"
                        "LINHA e COLUNA desejadas\n");
                        scanf(" %d %d", &linha, &coluna);
                }
                velha[linha][coluna] = 'O';            
            }

            if(coluna == linha){
                somaPrin += velha[linha][coluna];
            }
            if((coluna + linha) == 2){
                somaSec += velha[linha][coluna];
            }
            if(somaPrin == 264 || somaSec == 264){
                vencedor = 1;
                break;
            }
            if(somaPrin == 237 || somaSec == 237){
                vencedor = 2;
                break;
            }
            soma_linha[linha] += velha[linha][coluna];
            soma_coluna[linha] += velha[linha][coluna];
            if(soma_linha[linha] == 264 || soma_coluna[coluna] == 264){
                vencedor = 1;
                break;
            }
            if(soma_linha[linha] == 237 || soma_coluna[coluna] == 237){
                vencedor = 2;
                break;
            }
            jogada++;
        }
        if(vencedor == 1){
            printf("O jogador 1X venceu com %d jogadas", jogada);
        } else if(vencedor == 2){
            printf("O jogador 2O venceu com %d jogadas", jogada);
        } else if(jogada == 9){
            printf("Foram 9 jogadas e nenhum jogador venceu");
        }



        printf("\nJogo final:\n");
        printf("0  1  2");
        for(int i = 0; i < 3; i++){
            printf("\n-------\n|");
            for(int j = 0; j < 3; j++){
                printf("%c|", velha[i][j]);
                if(j == 2){
                    printf(" %d", i);
                }
            }
        }
        printf("\n-------\n");
        printf("Digite 0 se deseja parar de jogar");
        scanf(" %d", &continuar);
    }while(continuar);

    return 0;
}