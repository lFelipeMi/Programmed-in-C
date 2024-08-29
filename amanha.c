#include <stdio.h>

int main(){
    float objeto[10], objeto_total[10], total = 0;
    int vendas_objeto[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o valor do objeto %2d: ", i+1);
        scanf(" %f", &objeto[i]);
    }

    for(int i = 0; i < 10; i++){
        printf("Objeto: %2d - Valor: %7.2f - Vendas: ", i + 1, objeto[i]);
        scanf(" %d", &vendas_objeto[i]);
        objeto_total[i] = objeto[i] * vendas_objeto[i];
        total += objeto_total[i];
    }
    //////////////////////////////////////////////////////////////////////////////
    int mais_vendido = 0;
    for(int i = 1; i < 10; i++){
        if(vendas_objeto[i] > vendas_objeto[mais_vendido])
            mais_vendido = i;
    }
    //////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < 10; i++){
        printf("Objeto: %2d - Valor: %7.2f - Vendas: %3d - Total: %7.2f\n"
                , i + 1, objeto[i], vendas_objeto[i], objeto_total[i]);
    }
    printf("Os objetos mais vendidos foram:\n");
    for(int i = 0; i < 10; i++){
        if(vendas_objeto[i] == vendas_objeto[mais_vendido])
           printf("Objeto: %2d - Valor: %7.2f - Vendas: %3d - Total: %7.2f\n"
                    , i + 1, objeto[i], vendas_objeto[i], objeto_total[i]);
    
    }
    printf("Total vendido: %.2f - Comissao: %.2f", total, total * (5.0/100));

    printf("\n");
    return 0;
}