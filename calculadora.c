#include <stdio.h>

int main(){
    int opcao = -1;
    do{
        printf("Selecione a opcao desejada:\n1 – Somar\n2 – Subtrair\n3 – Multiplicar\n4 – Dividir\n0 – Sair");
        scanf("%d", opcao);

        int n1 = 0, n2 = 0;
        scanf(" %d %d", &n1, &n2);

        switch (opcao)
        {
        case 1:
            printf("%d + %d = %d", n1, n2, n1+n2);
            break;

        case 2: 
            printf("%d - %d = %d", n1, n2, n1-n2);
            break;

        case 3:
            printf("%d * %d = %d", n1, n2, n1*n2);
            break;

        case 4:
            while(n2 == 0){
                printf("O dividendo nao pode ser zero, digite outro numero.\n");
                scanf(" %d", &n2);
            }
            printf("%d / %d = %d", n1, n2, n1/n2);
            break;

        case 0:
            printf("Saindo...");
            break;
        }
        printf("\n");
    }while(opcao != 0);

    printf("\n");
    return 0;
}