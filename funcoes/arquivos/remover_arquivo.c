#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[] = {"arquivo.txt"};

    FILE *file = fopen(nome, "r");

    if(file){
        printf("\nArquivo aberto com sucesso!\n");
        fclose(file);

        printf("\nRetorno: %d\n", remove(nome));
    } else {
        printf("\nErro ao abrir arquivo!\n");
        printf("\nRetorno: %d\n", remove(nome));
    }

    return 0;
}