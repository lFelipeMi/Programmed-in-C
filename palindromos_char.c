#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char palavra[50], copia[50] = {'\0'};  //, comparar[50] = {'\0'};
    int tam = 0, palindromo = 1;
    scanf("%50[^\n]", palavra);
    //printf("%d", tam);
    //printf("%s", palavra);

    /*tam = strlen(palavra);
    for(int i = 0; i < tam; i++){
        comparar[i] = palavra [i];
        comparar[i + 1] = '\0';
    }
    //printf("\n%s", palavra);
    //printf("\n%s", copia);
   
    char *ponteiro;
    ponteiro = strtok(comparar, "!?., ");
    while(ponteiro){
        strcat(copia, ponteiro);
        ponteiro = strtok(NULL, " !?.,"); 
    }
    printf("\n%s", copia);

    int i = 0;
    while(copia[i] != '\0'){
        copia[i] = tolower(copia[i]);
        i++;
    }*/
    int i = 0, j = 0;
    tam = strlen(palavra);
    for(i = 0; i < tam; i++){
        int letra =  palavra[i];
        if(letra != '!' && letra != '?' && letra != ' ' && letra != '.' && letra != ',')
            copia[j++] = palavra[i];
    }
    copia[j] = '\0';


    while(copia[i] != '\0'){
        copia[i] = tolower(copia[i]);
        i++;
    }
    printf("\n%s", copia);

    tam = strlen(copia);
    for(i = 0; i < tam/2; i++){
        if(copia[i] != copia[tam - 1 - i]){
            palindromo = 0;
            break;
        }
    }
    
    if(palindromo)
        printf("\n%s eh um palindromo", palavra);
    else    
        printf("\n%s nao eh um palindromo", palavra);

    printf("\n");
    return 0;
}