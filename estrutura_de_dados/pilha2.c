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

typedef struct{
    No *topo;
    int tam;
}Pilha;

void criar_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

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
void empilhar (Pilha *p){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    } else   
        printf("Erro ao alocar memoria...\n");
}

// operacao top
No* desempilhar(Pilha *p){
    if(p->topo){
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    } else
        printf("\nPilha vazia!\n");
    return NULL;
}

void imprimir_pilha(Pilha *p){
    No *aux = p->topo;
    printf("\n---------- Pilha Tam: %d -----------\n", p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("\n---------- Fim da Pilha ------------\n");
}

int main(){
    No *remover;
    Pilha p;
    int opcao;

    criar_pilha(&p);

    do{
        printf("\n\t0 - Sair\n\t1 - Empilhar\n\t2 - Desempilhar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            empilhar(&p);
            break;
        case 2:
            remover = desempilhar(&p);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);

                free(remover);
            } else
                printf("Sem no a remover.\n");
            break;
        case 3:
            imprimir_pilha(&p);
            break;        
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}