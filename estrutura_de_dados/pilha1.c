#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa(){
    Pessoa p;

    printf("\nDigite nome e data de nascimento DD MM AAAA:\n");
    scanf(" %49[^\n] %d %d %d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);

    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s - %02d/%02d/%04d", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

// operacao push
No* empilhar (No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    } else   
        printf("Erro ao alocar memoria...\n");
    return NULL;
}

// operacao top
No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else
        printf("\nPilha vazia!\n");
    return NULL;
}

void imprimir_pilha(No *topo){
    printf("\n-------------- Pilha ---------------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n---------- Fim da Pilha ------------\n");
}

int main(){
    No *topo = NULL, *remover;
    int opcao;

    do{
        printf("\n\t0 - Sair\n\t1 - Empilhar\n\t2 - Desempilhar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);

                free(remover);
            } else
                printf("Sem no a remover.\n");
            break;
        case 3:
            imprimir_pilha(topo);
            break;        
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}