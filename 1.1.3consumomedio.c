#include <stdio.h> 

void main(){
    float kmrodados = 0, combustivelgasto = 0;
    scanf("%f %f", &kmrodados, &combustivelgasto);
    printf("Seu consumo médio foi: %.2fKm/L\n", kmrodados/combustivelgasto);

}