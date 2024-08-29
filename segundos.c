#include <stdio.h>

int main(){
    int segundos, horas;
    short int minutos;

    scanf("%u", &segundos);
    horas = (segundos / 60) / 60;
    minutos = (segundos % 3600) / 60;
    segundos = (segundos % 3600) % 60;

    printf("%u:%hi:%d\n", horas, minutos, segundos);
    
    return 0;
}