#include <stdio.h>

int main()
{
    float Celcius = 0, Kelvin = 0, Fahrenheit = 0;
    int escolhaFK = 0;
    do{
        printf("\n\t0 - Sair\n\t1 - Kelvin\n\t2 - Fahrenheit\n\tEscolha: "); // "/t" é uma tabulação, uso por capricho só
        scanf("%d", &escolhaFK);

        if(escolhaFK == 1 || escolhaFK == 2){ //Outro capricho, apenas uma maneira diferente de fazer a leitura nesse caso
            printf("\tDigite a temperatura em Celcius: ");
            scanf("%f", &Celcius);
        }
        switch (escolhaFK)
        {
        case 1:
            Kelvin =  Celcius + 273.15;
            printf("\n\tA temperatura eh: %.2fK", Kelvin);
            break;
        case 2: 
            Fahrenheit = ((Celcius * 9) / 5) + 32;
            printf("\n\tA temperatura eh: %.2fF", Fahrenheit);
            break;        
        default: //É importante usar defalt para lidar com escolhas indejadas, pense que o usuário sempre é burro e mal educado
            if(escolhaFK != 0)
                printf("\tEscolha invalida, tente novamente!\n");
            break;
        }
    }while(escolhaFK != 0); // DO WHILE: Esse comando faz o algoritmo rodar ao menos uma vez o laço (while), 
                            // Assim podemos testar o código com uma melhor facilidade.

    return 0;
}
