#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *proximo;
}No;

typedef struct
{
    No *prim, *fim;
    int tam;
}Fila;

void iniciar_fila(Fila *f){
    f->prim = NULL;
    f->fim = NULL;
    f->tam = 0;
}

void inserir_fila(Fila *f, int num){
    No *novo  = malloc(sizeof(No));
    
    if(novo){
        novo->num = num;
        novo->proximo = NULL;
        if(f->prim == NULL){
            f->prim = novo;
            f->fim = novo;
        } else {
            f->fim->proximo = novo;
            f->fim = novo;
        }
        f->tam++;
    } else
        printf("Erro ao alocar memoria!\n");
}

No* remover_fila(Fila *f){
    if(f){
        No *remover = f->prim;
        f->prim = f->prim->proximo;
        f->tam--;
        return remover;
    } else
        printf("A fila esta vazia!\n");
    return NULL;
}

void imprimir(Fila *f){
    No *temp = f->prim;
    printf("\n\t--------- Inicio ----------\n\t");
    while(temp){
        printf("%d ", temp->num);
        temp = temp->proximo;
    }
    printf("\n\t---------- Fim ------------\n\t");
}

int main(){
    Fila fila;
    int num, opcao;

    iniciar_fila(&fila);

    do{    
        printf("\n\t0 - Sair\n\t1 - Inserir na fila\n\t2 - Remover da fila\n\t3 - Imprimir fila\n\t--> ");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o numero a ser inserido na fila: ");
            scanf(" %d", &num);
            inserir_fila(&fila, num);
            break;
        case 2:
            No *remover = remover_fila(&fila);
            if(remover){
                printf("\n\tRemovido: %d", remover->num);
                free(remover);
            }
            break;
        case 3:
            imprimir(&fila);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);

    return 0;    
}