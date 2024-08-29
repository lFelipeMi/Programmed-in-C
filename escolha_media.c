#include <stdio.h>
#include <ctype.h>

void limpar_buffer();
float media_artimetica(float n1, float n2, float n3);
float media_ponderada(float n1, float n2, float n3);

int main(){
    char escolha;
    float n1, n2, n3, media;

    escolha = tolower(getchar());

    while (escolha != 'p' && escolha != 'a'){
        printf("escolha invalida\n");
        escolha = tolower(getchar());
        limpar_buffer();
    } 

    scanf(" %f %f %f", &n1, &n2, &n3);

    if (escolha == 'p'){
        printf("media ponderada: ");
        media = media_ponderada(n1, n2, n3);
    }
    else if(escolha == 'a'){
        printf("media aritimetica: ");
        media = media_artimetica(n1, n2, n3);
    }

    printf("%.2f", media);

    printf("\n");
    return 0;
}

void limpar_buffer() { 
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

float media_artimetica(float n1, float n2, float n3){
    return (n1 + n2 + n3)/3;
}

float media_ponderada(float n1, float n2, float n3){
    return (n1 * 0.3) + (n2 * 0.3) + (n3 * 0.4);
}