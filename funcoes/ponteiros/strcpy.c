#include <stdio.h>

void MYstrcpy(char* destino, char* origem);

int main(){
    char destino[50], origem[] = {"Eai, meu chapa!"};
    MYstrcpy(destino, origem);
    printf("%s\n", destino);

    return 0;
}

void MYstrcpy(char* destino, char* origem){
    int i = 0;
    while(*(origem + i) != '\0' && *(destino + i) != '0'){
        *(destino + i) = *(origem + i);
        i++;
    }
    //printf("%d", i);
}