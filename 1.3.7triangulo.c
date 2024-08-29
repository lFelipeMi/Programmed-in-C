#include <stdio.h>

int verifia_triangulo(float L1, float L2, float L3);
void classifica_triangulo(float L1, float L2, float L3);

void main(){
    float L1 = 0, L2 = 0, L3 = 0;
    do{
        scanf("%f %f %f", &L1, &L2, &L3);
    }while(verifia_triangulo(L1, L2, L3));

    printf("Esse triangulo se classifica como: ");
    classifica_triangulo(L1, L2, L3);
    
    printf("\n");
}

int verifia_triangulo(float L1, float L2, float L3){
    if(L1 < (L2 + L3) && L2 < (L3 + L1) && L3 < (L1 + L2)){
        printf("Esses são lados válidos de um triângulo.\n");
        return 0;
    } else {
        printf("Erro, tente novamente.\n");
        return 1;
    }
}

void classifica_triangulo(float L1, float L2, float L3){
    if(L1 == L2 && L2 == L3){
        printf("EQUILATERO");
    } else if(L1 != L2 && L2 != L3 && L3 != L1){
        printf("ESCALENO");
    } else {
        printf("ISOCELES");
    }
}