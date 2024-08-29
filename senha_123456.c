#include <stdio.h>

int main(){
    int n = 0;
    printf("Insira a senha: ");
    scanf("%d", &n);

    while(n != 123456){
        printf("\nSenha Invalida...\nDigite a senha: ");
        scanf(" %d", &n);
    }

    printf("\nAcesso permitido");

    printf("\n");
    return 0;
}