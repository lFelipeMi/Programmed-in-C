#include <stdio.h>

int main(){
    char nome[10] = {'\0'};
    int tam = 0, i = 0;
    fgets(nome, 10, stdin);
    /*while(nome[i] != '\0'){
        if(nome[i] == '\n'){
            nome[i] = '\0';
        }
        i++;
    }*/

    tam = printf("%s", nome);
    printf("%d", tam);

    printf("\n");
    return 0;
}