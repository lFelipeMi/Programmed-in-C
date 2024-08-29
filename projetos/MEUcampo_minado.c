#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char jogo[10][10];
char campo[10][10];
int posicoes_reveladas = 0;

void inicia_campo();
void inicia_jogo();
void imprime_jogo();
int ganhou();
int perdeu(int linha, int coluna);
void revela(int linha, int coluna);

int main(){
    int linha = 0, coluna = 0, opcao = 1;
    srand(time(NULL));
    printf("Digite 1 se quiser jogar: ");
    scanf(" %d", &opcao);

    do{
        inicia_campo();
        inicia_jogo();
        imprime_jogo();
        printf("Digite a posição LINHA COlUNA desejada: ");
        scanf(" %d %d", &linha, &coluna);
        revela(linha, coluna);
        imprime_jogo();

        while((ganhou() + perdeu(linha, coluna)) == 0){
            printf("Digite a posição LINHA COlUNA desejada: ");
            scanf(" %d %d", &linha, &coluna);
            if(jogo[linha][coluna] != ' '){
                printf("Ops, posição invalida\nDigite uma posição LINHA COLUNA vazia: ");
                scanf(" %d %d", &linha, &coluna);
            }
            revela(linha, coluna);
            imprime_jogo();
        }
        if(perdeu(linha, coluna))
            printf("Você perdeu!");
        if(ganhou())
            printf("Parabéns! Você ganhou!");

        printf("\nDigite 1 para jogar novamente!");
        scanf(" %d", &opcao);
    }while(opcao);

    return 0;
}

void inicia_campo(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            campo[i][j] = '0';
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int linha = rand() % 10, coluna = rand() % 10;
            while(campo[linha][coluna] == 'X'){
                linha = rand() % 10;
                coluna = rand() % 10;
            }

            campo[linha][coluna] = 'X';

            if(linha != 0 && campo[linha - 1][coluna] != 'X')
                campo[linha - 1][coluna] += 1;
            if(linha != 9 && campo[linha + 1][coluna] != 'X')
                campo[linha + 1][coluna] += 1;
            if(coluna != 0 && campo[linha][coluna - 1] != 'X')
                campo[linha][coluna - 1] += 1;
            if(coluna != 9 && campo[linha][coluna + 1] != 'X')
                campo[linha][coluna + 1] += 1;
        }
    }
}

void inicia_jogo(){
    posicoes_reveladas = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            jogo[i][j] = ' ';
        }
    }
}

void imprime_jogo(){
    printf("    0   1   2   3   4   5   6   7   8   9\n  -----------------------------------------\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0)
                printf("%d ", i);
            printf("| %c ", jogo[i][j]);
        }
        printf("|\n  -----------------------------------------\n");
    }
}

int ganhou(){
    if(posicoes_reveladas == (10 * 10) - (4 * 4))
        return 1;
    else
        return 0;
}

int perdeu(int linha, int coluna){
    if(jogo[linha][coluna] == 'X')
        return 1;
    else
        return 0;
}

void revela(int linha, int coluna){
    if(linha < 0 || linha > 9 || coluna < 0 || coluna > 9)
        return;

    if(jogo[linha][coluna] != ' ')
        return;
    
    jogo[linha][coluna] = campo[linha][coluna];
    posicoes_reveladas++;
    
    if(campo[linha][coluna] == '0'){
        if(linha != 0)
            revela(linha - 1, coluna);
        if(linha != 9)
            revela(linha + 1, coluna);
        if(coluna != 0)
            revela(linha, coluna - 1);
        if(coluna != 9)
            revela(linha, coluna + 1);
    }
}
