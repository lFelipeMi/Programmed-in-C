#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void iniciar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_inicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    } else 
        printf("Erro ao alocar memória!\n");
}

void inserir_fim(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            No *temp = lista->inicio;
            while(temp->proximo)
                temp = temp->proximo;
            temp->proximo = novo;
        }
        lista->tam++;
    } else 
        printf("Erro ao alocar memoria!\n");
}

void inserir_meio(Lista *lista, int num, int id){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            lista->inicio = novo;
            novo->proximo = NULL;
        } else {
            No *temp = lista->inicio;
            while(temp->proximo && temp->valor != id)
                temp = temp->proximo;
            novo->proximo = temp->proximo;
            temp->proximo = novo;
        }
        lista->tam++;
    } else  
        printf("Erro ao alocar memooria!\n");
}

void inserir_ordenado(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            lista->inicio = novo;
            novo->proximo = NULL;
        } else if(novo->valor < lista->inicio->valor){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        } else {
            No *temp = lista->inicio;
            while(temp->proximo && temp->proximo->valor < novo->valor)
                temp = temp->proximo;
            novo->proximo = temp->proximo;
            temp->proximo = novo;
        }
        lista->tam++;
    } else 
        printf("Erro ao alocar memoria!\n");
}

No* remover_lista(Lista *lista, int num){
    No *remover = NULL;

    if(lista){
        if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = lista->inicio->proximo;
        } else {
            No *temp = lista->inicio;
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

No* buscar_lista(Lista *lista, int num){
    No *no = NULL;
    No *temp = lista->inicio;
    while(temp && temp->valor != num)
        temp = temp->proximo;
    if(temp)
        no = temp;
    
    return no;
}

void imprimir(Lista lista){
    No *listinha = lista.inicio;
    printf("\n\t------------ LISTA %d -----------\n\t");
    while(listinha){
        printf("%d ", listinha->valor);
        listinha = listinha->proximo;
    }
    printf("\n\t----------- FIM LISTA -----------");
}

void liberar_lista(Lista *lista) {
    No *temp = lista->inicio;
    while (temp) {
        No *remover = temp;
        temp = temp->proximo;
        free(remover);
    }
    lista->inicio = NULL;
    lista->tam = 0;
}

int main(){
    Lista lista;
    No *remover;
    int opcao, num, id;

    iniciar_lista(&lista);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t"
            "3 - Inserir no meio\n\t4 - Inserir ordenado\n\t5 - Remover\n\t"
            "6 - Buscar\n\t7 - Imprimir\n\t--> ");
        
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &num);
            inserir_inicio(&lista, num);
            break;
        case 2:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &num);
            inserir_fim(&lista, num);
            break;
        case 3:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &num);
            printf("Insira após qual elemento deseja inserir esse valor: ");
            scanf(" %d", &id);
            inserir_meio(&lista, num, id);
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
            if (remover)
            {
                printf("No removido: %d\n", remover->valor);
                free(remover);
            }
            break;
        case 6:
            printf("Digite o valor que deseja buscar: ");
            scanf(" %d", &num);
            No *busca = buscar_lista(&lista, num);
            if(busca){
                printf("Elemento encontrado: %d\n", busca->valor);
                free(busca);
            } else
                printf("Elemento nao encontrado!\n");
            break;
        case 7:
            imprimir(lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);

    liberar_lista(&lista);

    return 0;
}