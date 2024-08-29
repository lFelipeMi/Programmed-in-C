#include <stdio.h>

int main(){
    int dias;
    scanf("%d", &dias);

    printf("O trabalhador devera receber: %.2f\n", (dias * 45.0) - (dias * 45.0 * 0.08));

    return 0;
}