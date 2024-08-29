#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    float valor;
    struct no *proximo;
}No;

No* empilhar(No *pilha, float num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
         
    } else
        printf("Falha ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    if(pilha){
        //float num;
        No *remover = *pilha;
        *pilha = remover->proximo; //fucarrrrrrrrr pilha->proximo
        //num = remover->valor;
        //free(remover);
        //return remover->valor; //BURRRROOOO
        //return num;
        //Vou fazer ate uma comentario pra quando eu ler isso de novo:
        //Primeiro eu inventei de fazer o desempilhar retornar float, quando executava o comando
        //dava uma lagada e depois de +/- 1 min aparecia "morto", caguei ai
        //depois vi que nao tava liberando a memoria, ai o cabeção fez o que? 
        //Sim. Liberei a memoria pra depois passar a mesma memoria liberada no return
        //Ai eu desisti, fiz um No* desempilhar mesmo, não quis criar outra variavel temporaria
        //Mas sei que podia resolver assim também, talvez seria mais eficaz.
        return remover;
    } else  
        printf("A pilha esta vazia!\n");
    return NULL;
}

float operacao(float n1, float n2, char c){
    switch (c)
    {
    case '+':   
        return n1 + n2;
        break;
    case '-':   
        return n1 - n2;
        //printf("n1: %d\tn2 %d", n1, n2); //erro
        break;
    case '*':
        return n1 * n2;
        break;
    case '/':
        return n1 / n2;
        //printf("n1: %d\tn2: %d", n1, n2); //erro
        break;
    default:
        return 0.0;
        break;
    }
}

float realiza_expressao(char exp[]){
    No *topo = NULL, *n1, *n2;
    char *pt;
    float num;// n1, n2;

    pt = strtok(exp, " ");
    while(pt){
        if(pt[0] == '+' || *pt == '-' || *pt == '*' || *pt == '/'){
            n2 = desempilhar(&topo);
            n1 = desempilhar(&topo);
            printf("N1: %d\nN2: %d\n", n1, n2);
            num = operacao(n1->valor, n2->valor, *pt);
            free(n1);
            free(n2);
            topo = empilhar(topo, num);
        } else{
            num = strtol(pt, NULL, 10);
            topo = empilhar(topo, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&topo);
    num = n1->valor;
    free(n1);
    return num;
}

int main(){
    char exp[] = {"5 3 + 2 4 * + 6 7 / 1 -"};
    //printf("Expressao: %s", exp);
    printf("Resultado: %f", realiza_expressao(exp));
}