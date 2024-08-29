#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data aniversario;
    int cpf, salario;
}Pessoa;

typedef struct no
{
    Pessoa pessoa;
    struct no *esq, *dir;
}No;


/*void ler_pessoa(Pessoa *p){
    printf("Digite nome, aniversario, cpf e salario: ");
    scanf("%49[^\n] %d %d %d", p->nome, &(p->aniversario.dia), &(p->aniversario.mes), &(p->aniversario.ano));
    scanf(" %d %d", &(p->cpf), &(p->salario));
} Vou testar ate conseguir, não sei o que deu errado nessa maneira*/

Pessoa ler_pessoa(Pessoa p){
    printf("Digite nome, aniversario, cpf e salario: ");
    scanf("%49[^\n] %d %d %d", p.nome, &(p.aniversario.dia), &(p.aniversario.mes), &(p.aniversario.ano));
    scanf(" %d %d", &(p.cpf), &(p.salario));
}

void imprimir_pessooa(Pessoa p){
    printf("\n\tNome: %s\n\tData: %02d/%02d/%04d\n\tCPF: %011d\n\tSalario: %d\n", p.nome, p.aniversario.dia, p.aniversario.mes, p.aniversario.ano, p.cpf, p.salario);
}

void inserir_na_arvore(No **raiz){
    Pessoa nova;
    ler_pessoa(nova);
    No *temp = *raiz;
    while(temp){
        if(nova.cpf >= temp->pessoa.cpf)
            raiz = &temp->dir;
        else    
            raiz = &temp->esq;
    }
    temp = malloc(sizeof(No));
    temp->pessoa = nova;
    temp->dir = NULL;
    temp->esq = NULL;
    *raiz = temp;
}

No* buscar_pessoa(No *raiz, int cpf){
    while(raiz){
        if(raiz->pessoa.cpf > cpf)
            raiz = raiz->esq;
        else if (raiz->pessoa.cpf < cpf)
            raiz = raiz->dir;
        else
            return raiz;
    }
    printf("Cpf não encontrado!\n");
    return NULL;
}

No* pessoa_morreu(No *arv, int cpf){
    if(arv == NULL){
        printf("Pessoa não encontrada!\n");
        return NULL;
    } if(arv->pessoa.cpf == cpf){
        if(arv->dir == NULL && arv->esq == NULL){
            printf("Pessoa removida: ");
            imprimir_pessooa(arv->pessoa);
            free(arv);
            return NULL;
        } else {
            No *temp;

            if(arv->dir && arv->esq){
                temp = arv->esq;
                while(temp->dir)
                    temp = temp->dir;
                Pessoa troca = arv->pessoa;
                arv->pessoa = temp->pessoa;
                temp->pessoa = troca;
                printf("Pessoas trocadas: \n");
                imprimir_pessooa(arv->pessoa);
                imprimir_pessooa(temp->pessoa);
                arv->esq = pessoa_morreu(arv->esq, cpf);
            } else {
                if(arv->esq)
                    temp = arv->esq;
                else    
                    temp = arv->dir;
                return temp;
            }
        }
    } else {
        if(cpf < arv->pessoa.cpf)
            arv->esq = pessoa_morreu(arv->esq, cpf);
        else if(cpf > arv->pessoa.cpf)
            arv->dir = pessoa_morreu(arv->dir, cpf);
        return arv;
    }
}

void imprimir_arvore(No *raiz){
    if(raiz){
        imprimir_arvore(raiz->esq);
        imprimir_pessooa(raiz->pessoa);
        imprimir_arvore(raiz->dir);
    }
}

int main(){
    No *raiz = NULL, *busca;
    int opcao, cpf;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Remover No\n\t"
            "4 - Dados da arvore\n\t5 - Imprimir\n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            inserir_na_arvore(&raiz);
            break;
        case 2:
            printf("Para realizar a busca insira o cpf: ");
            scanf(" %d", &cpf);
            busca = buscar_pessoa(raiz, cpf);
            if(busca)
                imprimir_pessooa(busca->pessoa);
            else    
                printf("Pessoa nao encontrada!\n");
            break;
        case 3:
            printf("Digite o cpf da pessoa que 'esta partindo': ");
            scanf(" %d", &cpf);
            pessoa_morreu(raiz, cpf);
            break;
        case 4:
            printf("\n    --------------- ARVORE DE PESSOAS ---------------\n");
            imprimir_arvore(raiz);
            break;
        /*    
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
            break;*/
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);


    return 0;
}