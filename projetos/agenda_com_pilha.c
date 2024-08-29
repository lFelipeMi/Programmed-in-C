//RETOMAR.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

typedef struct no{
    Contato c;
    struct no *proximo;
}No;

void imprimir_contato(Contato c){
    printf("\t%s\t%02d/%02d/%04d\n", c.nome, c.dia, c.mes, c.ano);
}

void imprimir_agenda(No *agenda){
    int id = 1;
    printf("\n\t-------------- Contatos --------------\n");
    while(agenda){
        printf("\t%2d - %s\t%02d/%02d/%04d\n", id, agenda->c.nome, agenda->c.dia, agenda->c.mes, agenda->c.ano);
        agenda = agenda->proximo;
        id++;
    }
    printf("\t---------------- FIM! ----------------\n");
}

Contato le_contato(){
    Contato novo;

    printf("Digite o nome e a data de nascimento DD MM AAAA:\n");
    scanf(" %49[^\n] %d %d %d", novo.nome, &novo.dia, &novo.mes, &novo.ano);

    return novo;
}

//empilhar
No* adiciona_contato(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->c = le_contato();  
        novo->proximo = topo;

        return novo; 
    } else
        printf("Erro ao alocar memoria!");
    return NULL;
}

//desempilhar
No* remover_ultimo(No **topo){
    if(*topo){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else
        printf("A agenda esta vazia!");
    return NULL;
}

int main(){
    No *agenda;
    int opcao;

    do{
        printf("\n0 - Sair\n1 - Ler contato\n2 - Remover ultimo contato\n3 - Imprimir contatos\n\n");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 1:
            agenda = adiciona_contato(agenda);
            break;
        case 2:
            No *remover = remover_ultimo(&agenda);
            if(remover){
                printf("Contato removido:\n");
                imprimir_contato(remover->c);
            }
            free(remover);
            break;
        case 3:
            imprimir_agenda(agenda);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida");
            break;
        }
    }while(opcao != 0);    
}