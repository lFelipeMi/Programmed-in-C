#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista =  novo;
    } else
        printf("Erro ao alocar memoria!");
}

void inserir_no_final(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL)
            *lista = novo;
        else {
            No *temp = *lista;
            while(temp->proximo)
                temp = temp->proximo;
            temp->proximo = novo;
        }
    } else
        printf("Erro ao alocar memoria!\n");
}

void inserir_no_meio(No **lista, int num, int id){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            No *temp = *lista;
            while(temp->valor != id && temp->proximo)
                temp = temp->proximo;
            novo->proximo = temp->proximo;
            temp->proximo = novo;
        }
    } else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else if (novo->valor < (*lista)->valor) {
            novo->proximo = *lista;
            (*lista) = novo;
        } else {
            No *temp = *lista;
            while(temp->proximo && temp->proximo->valor < novo->valor)
                temp = temp->proximo;
            novo->proximo = temp->proximo;
            temp->proximo = novo;
        }

    } else 
        printf("Erro ao alocar memoria!\n");
}

No* remover_lista(No **lista, int num){
    No *remover =  NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = (*lista)->proximo;
        } else {
            No *temp = *lista;
            while(temp->proximo && temp->proximo->valor != num)
                temp = temp->proximo;
            if(temp->proximo){
                remover = temp->proximo;
                temp->proximo = remover->proximo;
            } else
                printf("Valor nao encontrado!\n");
        }
    } else  
        printf("A lista esta vazia!\n");
    return remover;
}

No* buscar(No **lista, int num){
    No *no = NULL;
    No *temp = *lista;
    while(temp && temp->valor !=num)
        temp = temp->proximo;
    if(temp)
        no = temp;

    return no;
}

void imprimir_lista(No *lista){
    printf("\n\t------------- LISTA -------------\n\t");
    while(lista){
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n\t----------- FIM LISTA -----------");
}

int main(){
    No *lista = NULL, *remover;
    int opcao, num, id;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t"
            "3 - Inserir no meio\n\t4 - Inserir em ordem\n\t5 - Remover\n\t"
            "6 - Buscar\n\t7 - Imprimir\n\t--> ");
        
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &num);
            inserir_no_inicio(&lista, num);
            break;
        case 2:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &num);
            inserir_no_final(&lista, num);
            break;
        case 3:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &num);
            printf("Insira após qual elemento deseja inserir esse valor: ");
            scanf(" %d", &id);
            inserir_no_meio(&lista, num, id);
            break;
        case 4:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &num); 
            inserir_ordenado(&lista, num);
            break;
        case 5:
            printf("Digite o valor que deseja remover: ");
            scanf(" %d", &num);
            No *remover = remover_lista(&lista, num);
            if(remover){
                printf("No removido: %d", remover->valor);
                free(remover);
            }
            break;
        case 6:
            printf("Digite o valor que deseja buscar: ");
            scanf(" %d", &num);
            No *busca = buscar(&lista, num);
            if(busca){
                printf("Elemento encontrado: %d\n", busca->valor);
                free(busca);
            } else  
                printf("Elemento nao encontrado!\n");
            break;
        case 7:
            imprimir_lista(lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}