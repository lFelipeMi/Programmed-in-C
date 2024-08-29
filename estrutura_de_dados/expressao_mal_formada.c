#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char caractere;
    struct no *proximo;
}No;

void imprimir(No *topo){
    while(topo){
        printf("\n%c", topo->caractere);
        topo = topo->proximo;
    }
    printf("\n");
}

No* empilhar(No *topo, char c){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caractere = c;
        novo->proximo = topo;
        return novo;
    } else
        printf("Erro ao alocar memoria");
    return NULL;
}

No* desempilhar(No **topo){
    if(*topo){
        No *remover = *topo;
        *topo = remover->proximo; 
        return remover;
    } else  
        printf("A pilha esta vazia!");
    return NULL;
}

int verifica_par(char c, char f){
    switch (c)
    {
    case '(':
        if(f == ')')
            return 1;
        break;
    case '[':
        if(f == ']')
            return 1;
        break;
    case '{':
        if(f == '}')
            return 1;   
        break;
    default:
        return 0;
        break;
    }
}

int verifica_formação(char c[]){
    int i = 0;
    No *topo = NULL, *remover = NULL;

    while(c[i] != '\0'){
        if(c[i] == '(' || c[i] == '[' || c[i] == '{'){
            topo = empilhar(topo, c[i]);
            imprimir(topo);
        } else if(c[i] == ')' || c[i] == ']' || c[i] == '}'){
            remover = desempilhar(&topo);
            if(remover){
                if(verifica_par(remover->caractere, c[i]) == 0){
                    printf("EXPRESSAO MAL FORMADA!\n");
                    free(remover);
                    return 1;
                }
            } else{
                printf("EXPRESSAO MAL FORMADA!\n");
                free(remover);
                return 1;
            }
        }
        i++;
    }

    imprimir(topo);
    if(topo){
        printf("Expressao mal formada!\n");
        return 1;
    }

    printf("EXPRESSAO CORRETAMENTE FORMADA!\n");
    return 0;
}

int main(){
    char teste[50];

    printf("\n\tDigite uma expressao: ");
    scanf("%49[^\n]", teste);
    printf("\nExpressao: %s\nRetorno: %d\n", teste, verifica_formação(teste));

    return 0;
}