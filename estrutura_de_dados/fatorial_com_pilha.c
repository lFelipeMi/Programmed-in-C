#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* empilhar(No *pilha, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    } else
        printf("Erro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    } else
        printf("Pilha vazia\n");
    return remover;
}

void imprimir(No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%d\n", pilha->valor);
        pilha = pilha->proximo;
    }
    printf("\n");
}

int fatorial(int num){
    No *pilha = NULL, *remover;

    while(num > 1){
        pilha = empilhar(pilha, num);
        num--;
    }

    imprimir(pilha);

    while(pilha){
        remover = desempilhar(&pilha);
        num *= remover->valor;
        free(remover);
    }
    return num;
}

int main(){
    int valor;

    printf("Digite um valor maior que zero para o fatorial: ");
    scanf("%d", &valor);
    printf("\n\n\tFatorial de %d: %d\n", valor, fatorial(valor));

    return 0;
}