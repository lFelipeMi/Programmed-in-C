#include <stdio.h>

int main(){
    int *p;

    printf("Espaco para um inteiro %d\n", sizeof(int));
    printf("Espaco para um ponteiro %d\n", sizeof(p));
    printf("Espaco para um caractere %d\n", sizeof(char));
    printf("Espaco para um float %d\n", sizeof(float));
    printf("Espaco para um double %d\n", sizeof(double));
    printf("Espaco para um long long int %d\n", sizeof(long long int));
    printf("Espaco para um long double %d\n", sizeof(long double));
    printf("Espaco para um short int %d\n", sizeof(short int));
}