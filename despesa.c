#include <stdio.h>

int main(){
    float despesa, gorjeta, total_pagar;
    int num_pessoas;
    scanf("%f %f %d", &despesa, &gorjeta, &num_pessoas);

    total_pagar = (despesa + (despesa * (gorjeta/100))) / num_pessoas; 

    printf("Cada pessoa devera pagar: %.2f\n", total_pagar);

    return 0;
}