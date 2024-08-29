#include <stdio.h>
#include <ctype.h>

int main(){
    char sexo;
    int idade;
    float peso, altura;

    do{
        printf("Qual seu genêro? \nDigite M para Masculino e F para Feminino\n");
        sexo = toupper(getchar());
    }while (sexo != 'M' && sexo != 'F');

    printf("Qual a sua idade, altura(m) e peso(kg)?\n");
    scanf("%d %f %f", &idade, &altura, &peso);

    printf("Perfil do usuario:");
    switch (sexo)
    {
    case 'M':
        printf("Usuario do sexo Masculino\nIdade:   %-3d\nAltura:  %-2.1f\nPeso:    %-2.1f", idade, altura, peso);
        break;
    
    default:
        printf("Usuario do sexo Feminino\nIdade:   %-3d\nAltura:  %-2.1f\nPeso:    %-2.1f", idade, altura, peso);
        break;
    }


    return 0;
}