#include <stdio.h>
#include <stdlib.h>

//2 * 15 = 30
#define TAM 31

void inicializarT(int t[]){
    for(int i = 0; i < TAM; i++)
        t[i] = 0;
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != 0)
        id = funcaoHash(id + 1);
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    while(t[id] != 0){
        if(t[id] == chave)
            return t[id];
        else
            id = funcaoHash(id + 1);
    }
    return 0;
}

void imprimir(int t[]){
    for(int i = 0; i < TAM; i++)
        printf("%02d = %d\n", i, t[i]);
}

int main(){
    int tabela[TAM], opcao, valor, retorno;

    inicializarT(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Busca\n\t3- Imprimir\n\t--> ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("Digite o numero que deseja buscar: ");
            scanf(" %d", &valor);
            retorno = busca(tabela, valor);
            if(retorno != 0)
                printf("Elemento encontrado: %d\n", retorno);
            else    
                printf("Elemento nao encontrado!\n");
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}