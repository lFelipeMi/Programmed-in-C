#include <stdio.h>

void calcula_IMC(float altura, float massa);

int main(){
    float altura, peso;
    scanf("%f %f", &altura, &peso);

    calcula_IMC(altura, peso);


    printf("\n");
    return 0;
}

void calcula_IMC(float altura, float massa){
    float IMC = massa / (altura * altura);
    if(IMC < 18.5){
        printf("ABAIXO DO PESO");
    }
    else if(IMC < 25){
        printf("PESO NORMAL");
    }
    else if(IMC < 30){
        printf("SOBREPESO");
    }
    else if(IMC < 35){
        printf("OBESIDADE GRAU 1");
    }
    else if(IMC < 40){
        printf("OBESIDADE GRAU 2");
    }
    else {
        printf("OBESIDADE GRAU 3");
    }

}