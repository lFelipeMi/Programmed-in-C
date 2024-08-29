/*
Penso que é muito chato ver pessoas chegando depois e sendo atendidas antes
Pior ainda é quando isso se repete durante horas,
Pensei que seria legal programar uma solução para isso, afinal
em uma fila hospitalar, um caso medio pode se tornar grave se não for atendido em um tempo correspondente.

EM PROCESSO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#include <stdio.h>
#include <stdlib.h>

#define GRAVE 50
#define MEDIO 30
#define LEVE 5

typedef struct{
    int dia, mes, ano;
}Data;

Data dataHoje;

typedef struct{
    char nome[50];
    Data nas;
    int caso;
}Pessoa;

typedef struct no{
    Pessoa paciente;
    struct no *proximo;
}No;

void adicionar_na_fila(No **fila, int prioridade){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->paciente.caso = prioridade;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else {
            if(prioridade > 49){
                if((*fila)->paciente.caso < 50){
                    novo->proximo = *fila;
                    *fila = novo;
                } else {
                    No *temp = *fila;
                    while(temp->proximo && temp->proximo->paciente.caso > 49)
                        temp = temp->proximo;
                    novo->proximo = temp->proximo;
                    temp->proximo = novo;            
                }
            } else if(prioridade > 29){
                if((*fila)->paciente.caso < 30){
                    novo->proximo = *fila;
                    *fila = novo;
                } else {
                    No *temp = *fila;
                    while(temp->proximo && temp->proximo->paciente.caso > 29)
                        temp = temp->proximo;
                    novo->proximo = temp->proximo;
                    temp->proximo = novo;
                }

            } else {
                No *temp = *fila;
                while(temp->proximo)
                    temp = temp->proximo;
                temp->proximo = novo;
            }

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

int calcula_idade(Data *data){
    int idade = (dataHoje.dia + (dataHoje.mes * 30) + (dataHoje.ano * 365)) - (data->dia + (data->mes * 30) + (data->ano *365));
    return idade / 365;
}

void imprime_paciente(No *paci){
    printf("\tNome: %s\n\tAniversario: %02d/%02d/%04d", paci->paciente.nome, &paci->paciente.nas.dia, &paci->paciente.nas.mes, &paci->paciente.nas.ano);
    printf("\n\tIdade: %d", calcula_idade(&paci->paciente.nas));

    if(paci->paciente.caso > 49){
        printf("Prioridade maxima!");
    } else if(paci->paciente.caso > 29){
        printf("Prioridade media!");
    } else 
        printf("Priridade minima.");
}

void imprimir(No *fila){
    printf("\n\t----------- INICIO -----------\n\t");
    while(fila){
        
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
                printf("Valor removido: %d\n", remover->paciente.caso);
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