#include <stdio.h>
#include <ctype.h>

int main(){
    char letra;
    letra = toupper(getchar());

    if(letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
        printf("Eh uma vogal");
    } else {
        printf("Eh uma consoante");
    }

    printf("\n");
    return 0;
}