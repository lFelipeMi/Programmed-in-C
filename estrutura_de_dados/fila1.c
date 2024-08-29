#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int sla;
    struct no *proximo;
}No;

void adicionar_na_fila(No **fila, int num){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->sla = num;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else {
            No *temp = *fila;
            while(temp->proximo)
                temp = temp->proximo;
            temp->proximo = novo;
        }
    } else  
        printf("Erro ao alocar memoria!\n");
}

No* remover_da_fila(No **fila){
    No *remover = NULL;
    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
        return remover;
    } else
        printf("A fila esta vazia!\n");
    return NULL;
}

void imprimir(No *fila){
    printf("\n\t----------- INICIO -----------\n\t");
    while(fila){
        printf("%d ", fila->sla);
        fila = fila->proximo;
    }
    printf("\n\t------------ FIM -------------\n\t");
}

int main(){
    int num, opcao;
    No *fila = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir na fila\n\t2 - Remover da fila\n\t3 - Imprimir fila\n\t--> ");
        scanf(" %d", &opcao);
        
        switch (opcao)
        {
        case 1:
            printf("Digite o numero a ser adicionado a fila: ", &num);
            scanf(" %d", &num);
            adicionar_na_fila(&fila, num);
            break;
        case 2:
            No *remover = remover_da_fila(&fila);
            if(remover){
                printf("Valor removido: %d\n", remover->sla);
                free(remover);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);
    return 0;
}