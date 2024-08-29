#include <stdio.h>

char velha[3][3];

void inicia_jogo();
void imprime_jogo();
int ganhou_linha(int linha);
int ganhou_coluna(int coluna);
int diagonal_principal();
int diagonal_secundaria();
int ganhou();
int verifica_coordenadas(int linha, int coluna);
int jogo();

int main(){
    int jogar = 1;
    printf("Digite 1 se gostaria de jogar!\n");
    scanf(" %d", &jogar);
    while(jogar){
        inicia_jogo();
        imprime_jogo();
        jogo();

        printf("Digite 1 se gostaria de jogar novamente!\n");
        scanf(" %d", &jogar);
    }
    return 0;
}

void inicia_jogo(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            velha[i][j] = ' ';
        }
    }
}

void imprime_jogo(){
    printf("  0   1   2\n");
    for(int i = 0; i < 3; i++){
        printf(" ");
        for(int j = 0;j < 3; j++){
            printf(" %c ", velha[i][j]);
            if(j < 2){
                printf("|");
            }
            if(j == 2){
                printf("   %d", i);
            }
        }
        if(i < 2){
            printf("\n -----------");
        }
        printf("\n");
    }
}

//0 não ganhou 1 ganhou
int ganhou_linha(int linha){
    if(velha[linha][0] == velha[linha][1] && velha[linha][1] == velha[linha][2] && velha[linha][0] != ' '){
        printf("O Jogador %c ganhou na linha %d! Parabéns!\n", velha[linha][0], linha);
        return 1;
    } else
        return 0;
}

int ganhou_coluna(int coluna){
    if(velha[0][coluna] == velha[1][coluna] && velha[1][coluna] == velha[2][coluna] && velha[0][coluna] != ' '){
        printf("O Jogador %c ganhou na coluna %d! Parabéns!\n", velha[coluna][0], coluna);
        return 1;
    } else
        return 0;
}

int diagonal_principal(){
    if(velha[0][0] == velha [1][1] && velha[1][1] ==velha[2][2] && velha[0][0] != ' '){
        printf("O jogador %c ganhou na diagonal principal! Parabéns!\n", velha[0][0]);
        return 1;
    } else
        return 0;
}

int diagonal_secundaria(){
    if(velha[0][2] == velha [1][1] && velha[1][1] == velha[2][0] && velha[1][1] != ' '){
        printf("O jogador %c ganhou na diagonal secundaria! Parabéns!\n", velha[0][2]);
        return 1;
    } else
        return 0;
}

int ganhou(){
    if(diagonal_principal() || diagonal_secundaria())
        return 1;

    for(int i = 0; i < 3; i++){
        if(ganhou_coluna(i) || ganhou_linha(i))
            return 1;
    }

    return 0;
}

int verifica_coordenadas(int linha, int coluna){
    if(linha < 3 && coluna < 3 && linha >= 0 && coluna >= 0 && velha[linha][coluna] == ' ')
        return 1;
    else{
        printf("Coordenadas invalidas\nEscolha outra posição: ");
        return 0;    
    }
}

int deu_velha(int jogadas){
    if(jogadas == 10){
        printf("VELHA!\n");
        return 1;
    } else
        return 0;
}

int jogo(){
    int jogadas = 1, linha = 0, coluna = 0;
    do{
        if(jogadas%2){
            printf("Eh a vez do jogador 1X\nEscolha a posição que deseja jogar: ");
            scanf("%d %d", &linha, &coluna);
            while(!verifica_coordenadas(linha, coluna))
                scanf(" %d %d", &linha, &coluna);
            velha[linha][coluna] = 'X';
            jogadas++;
        } else {
            printf("Eh a vez do jogador 2O\nEscolha a posição que deseja jogar: ");
            scanf("%d %d", &linha, &coluna);
            while(!verifica_coordenadas(linha, coluna))
                scanf(" %d %d", &linha, &coluna);
            velha[linha][coluna] = 'O';
            jogadas++;
        }
        imprime_jogo();
    }while(ganhou() == deu_velha(jogadas));
}
