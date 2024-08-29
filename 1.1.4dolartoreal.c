#include <stdio.h>

void main(){
    float cotacao = 0, dolar = 0;
    scanf("%f %f", &cotacao, &dolar);
    printf("Voce pode converter %.2f$ em %.2fR$", dolar, dolar*cotacao);

}