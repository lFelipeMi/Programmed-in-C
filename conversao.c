#include <stdio.h>

int main(){
    int escolha = 0;

    printf("0- Dolar para Real\n1- Real para Dolar\n");
    scanf("%d", &escolha);

    if(!escolha){
        float dolar;
        scanf("%f", &dolar);
        
        printf("A conversão de $%.2f para dolar eh R$%.2f",dolar, dolar * 5.3);
    } else {
        float real;
        scanf("%f", &real);

        printf("A conversão de R$%f eh de $%f", real, real / 5.30);
    }

    printf("\n");
    return 0;
}