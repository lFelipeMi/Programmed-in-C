#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_arvore(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *novo = malloc(sizeof(NoArv));

        if(novo){
            novo->valor = num;
            novo->direita = NULL;
            novo->esquerda = NULL;
            return novo;
        } else
            printf("Erro ao alocar memoria!\n");
    } else {
        if(num < raiz->valor)
            raiz->esquerda = inserir_arvore(raiz->esquerda, num);
        else 
            raiz->direita = inserir_arvore(raiz->direita, num);
    }
    return raiz;
}

void inserir_arvore2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if(num < (*raiz)->valor)
            inserir_arvore2(&((*raiz)->esquerda), num);
        else
            inserir_arvore2(&((*raiz)->direita), num);
    }
}

void inserir_arvoreI(NoArv **raiz, int num){
    NoArv *temp = *raiz;
    while(temp){
        //A chave pra entender isso é que não estamos alterando o endereço
        //Mas sim alterando PARA QUAL endereço
        if(num < temp->valor)
            raiz = &temp->esquerda;
        else    
            raiz = &temp->direita;
        temp = *raiz;
    }
    temp = malloc(sizeof(NoArv));
    temp->valor = num;
    temp->esquerda = NULL;
    temp->direita = NULL;
    *raiz = temp;
    //"*raiz" já não aponta mais para o endereç que recebemos no inicio
}

NoArv* BuscarRec(NoArv *raiz, int num){
    if(raiz){
        if(num){
            if(num == raiz->valor)
                return raiz;
            else if(num < raiz->valor)
                return BuscarRec(raiz->esquerda, num);
            else
                return BuscarRec(raiz->direita, num);
        }
    } else
        return NULL;
}

NoArv* BuscarIt(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}


//Pretendo melhorar essa função
NoArv *remover(NoArv *raiz, int chave){
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else {
        if(raiz->valor == chave){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                printf("Elemento follha removido: %d!\n", chave);
                return NULL;
            } else{
                if(raiz->esquerda && raiz->direita){
                    NoArv *temp = raiz->esquerda;
                    while(temp->direita != NULL)
                        temp = temp->direita;
                    raiz->valor += temp->valor;
                    temp->valor = raiz->valor - temp->valor;
                    raiz->valor -= temp->valor;
                    printf("Elemento trocado: %d!\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                } else{
                    NoArv *temp;
                    if(raiz->esquerda)
                        temp = raiz->esquerda;
                    else
                        temp = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d!\n", chave);
                    return temp;
                }

            }
        } else {
             if (chave < raiz->valor)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else 
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else    
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    /*if(raiz == NULL)
        return 0;
    else    
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
    */
    return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->direita == NULL && raiz->direita == NULL)
        return 1;
    else 
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

void imprimir_arvore(NoArv *raiz){
    if(raiz){
        imprimir_arvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_arvore(raiz->direita);
    }
}

int main(){
    NoArv *raiz = NULL, *busca;
    int opcao, num;

    inserir_arvoreI(&raiz, 500);
    inserir_arvoreI(&raiz, 250);
    inserir_arvoreI(&raiz, 300);
    inserir_arvoreI(&raiz, 100);
    inserir_arvoreI(&raiz, 750);
    inserir_arvoreI(&raiz, 900); 

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Remover No\n\t"
            "4 - Dados da arvore\n\t5 - Imprimir\n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o numero que deseja inserir: ");
            scanf(" %d", &num); 
            inserir_arvoreI(&raiz, num);
            break;
        case 2:
            printf("Digite o valor que deseja buscar: ");
            scanf(" %d", &num);
            busca = BuscarIt(raiz, num);
            if(busca)
                printf("\nValor encontrado: %d", busca->valor);
            else    
                printf("Valor nao encontrado!\n");
            break;
        case 3:
            printf("Digite o valor que deseja remover: ");
            scanf(" %d", &num);
            remover(raiz, num);
            break;
        case 4:
            if(raiz == NULL)
                printf("A arvore esta vazia!\n");
            else {
                printf("A arvore tem altura: %d.\n", altura(raiz));
                printf("A arvore contem %d nos.\n", quantidade_nos(raiz));
                printf("A arvore contem %d folhas.\n", quantidade_folhas(raiz));
            }
            break;
        case 5:
            imprimir_arvore(raiz);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);


    return 0;
}