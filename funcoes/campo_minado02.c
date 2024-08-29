#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Dessa vez vou fazer com struct e um jeito diferente de verificar vitoria/derrota.

typedef struct
{
    int eBomba;
    int estaAberta;
    int bombasVizinhas;
}Celula;

//Assim fica mais facil alterar o tamanho do campo.
int TAM = 10, l = 0, c = 0;
Celula jogo[10][10];

void iniciaCampo(){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            jogo[i][j].eBomba = 0;
            jogo[i][j].estaAberta = 1;
            jogo[i][j].bombasVizinhas = 0;
        }
    }
}

void sorteiaBombas(int n){
    for(int i = 0; i < n; i++){
        l = rand() % TAM;
        c = rand() % TAM;
        while(jogo[l][c].eBomba){
            l = rand() % TAM;
            c = rand() % TAM;
        }
        jogo[l][c].eBomba = 1;
    }
}

void qualDificuldade(int nivel){
    if(nivel == 1)
        sorteiaBombas(10);
    if(nivel == 2)
        sorteiaBombas(16);
    if(nivel == 3)
        sorteiaBombas(22);
}

void escolhaDificuldade(){
    int dificuldade = 0;
        do{
        printf("Selecione a dificuldade\n1 - Facil\n2 - Intermediario\n3 - Dificil\n");
        scanf(" %d", &dificuldade);
        printf("Dificuldade selecionada: ");
        switch (dificuldade){
        case 1:
            printf("Facil");
            qualDificuldade(dificuldade);
            break;
        case 2:
            printf("Intermediario");
            qualDificuldade(dificuldade);
            break;
        case 3:
            printf("Dificil");
            qualDificuldade(dificuldade);
            break;
        default:
            printf("Dificuldade invalida\n");
            break;
        }

    }while(dificuldade <= 0 || dificuldade > 3);
}

int posicaoEhValida(int linha, int coluna){
    if(linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM)
        return 1;
    else
        return 0;
}

void contaBombasVizinhas(int linha, int coluna){
    if(posicaoEhValida(linha - 1, coluna) && jogo[linha - 1][coluna].eBomba)
        jogo[linha][coluna].bombasVizinhas += 1;
    if(posicaoEhValida(linha + 1, coluna) && jogo[linha + 1][coluna].eBomba)
        jogo[linha][coluna].bombasVizinhas += 1;
    if(posicaoEhValida(linha, coluna - 1) && jogo[linha][coluna - 1].eBomba)
        jogo[linha][coluna].bombasVizinhas += 1;
    if(posicaoEhValida(linha, coluna + 1) && jogo[linha][coluna + 1].eBomba)
        jogo[linha][coluna].bombasVizinhas += 1;
}

void contaBombas(){
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            contaBombasVizinhas(i, j);
}

void imprime_campo(){
    printf("\n\t\t   ");
    for(int i = 0; i < TAM; i++)
        printf("   %d", i); //indice das colunas
    printf("\n\t\t    -----------------------------------------\n");
    for(int i = 0; i < TAM; i++){
        printf("\t\t%d   ", i); //indice das linhas
        for(int j = 0; j < TAM; j++){
            if(jogo[i][j].estaAberta && jogo[i][j].eBomba != 1)
                printf("| %d ", jogo[i][j].bombasVizinhas);
            if(jogo[i][j].estaAberta && jogo[i][j].eBomba)
                printf("| X ");
            if(jogo[i][j].estaAberta != 1)
                printf("|   ");
        }
        printf("|\n\t\t    -----------------------------------------\n");
    }
    printf("\n");
}

void abrirCelula(int linha, int coluna){
        if (!posicaoEhValida(linha, coluna) || jogo[linha][coluna].estaAberta)
            return;

    jogo[linha][coluna].estaAberta = 1;

    if(jogo[linha][coluna].bombasVizinhas == 0){
        if(posicaoEhValida(linha - 1, coluna))
            abrirCelula(linha - 1, coluna);
        if(posicaoEhValida(linha + 1, coluna))
            abrirCelula(linha + 1, coluna);
        if(posicaoEhValida(linha, coluna - 1))
            abrirCelula(linha, coluna - 1);
        if(posicaoEhValida(linha, coluna + 1))
            abrirCelula(linha, coluna + 1);
    }
}

int ganhou(){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(jogo[i][j].estaAberta != 1 && jogo[i][j].eBomba != 1)
                return 0; //ainda não ganhou
        }
    }
    return 1; //se passou pelo for, todas as posições estão abertas e o jogador ganhou.
}

void jogar(){
    int linha = 0, coluna = 0;

    iniciaCampo();
    escolhaDificuldade();
    contaBombas();
    
    printf("\n\t\t\t\t  CAMPO MINADO\n");

    do{
        imprime_campo();
        do{
            printf("\nDigite as coordenadas de linha e colunas desejadas: ");
            scanf(" %d %d", &linha, &coluna);
            if(posicaoEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta)
                printf("Posicao invalida ou ja aberta!");
        }while(posicaoEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta);
        abrirCelula(linha, coluna);

    }while(ganhou() == 0 && jogo[linha][coluna].eBomba == 0);

    imprime_campo();
    if(jogo[linha][coluna].eBomba){
        printf("UMA BOMBA!! Você perdeu!\n");
        return;
    }
    
    printf("Parabéns!! Você ganhou!\n");
}

int main(){
    srand(time(NULL));
    int opcao;

    do{
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }while(opcao == 1);
}
