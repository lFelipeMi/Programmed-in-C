 #include <stdio.h>
#include <stdlib.h>

//2 * 15 = 30
#define TAM 31

typedef struct no{
    int chave;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicia_lista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_lista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    } else  
        printf("Erro ao alocar memoria!\n");
}

int buscar_lista(Lista *l, int valor){
    No *temp = l->inicio;
    printf("Tam %d: ", l->tam);
    while(temp && temp->chave != valor)
        temp = temp->proximo;
    if(temp)
        return temp->chave;
    return 0;
}

void imprimir_lista(Lista *l){
    No *temp = l->inicio;
    while(temp){
        printf("%d ", temp->chave);
        temp = temp->proximo;
    }
}

void inicializarT(Lista t[]){
    for(int i = 0; i < TAM; i++)
        inicia_lista(&t[i]);
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserir_lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    printf("Indice gerado: %d\n", id);
    return buscar_lista(&t[id], chave);
}

void imprimir(Lista t[]){
    for(int i = 0; i < TAM; i++){
        printf("%02d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}

int main(){
    int opcao, valor, retorno;
    Lista tabela[TAM];

    inicializarT(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Busca\n\t3- Imprimir\n\t--> ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("Digite o numero que deseja buscar: ");
            scanf(" %d", &valor);
            retorno = busca(tabela, valor);
            if(retorno != 0)
                printf("Elemento encontrado: %d\n", retorno);
            else    
                printf("Elemento nao encontrado!\n");
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}