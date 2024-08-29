#include <stdio.h>

int main(){
    char a, b;
    a = getchar();
    getchar();
    b = getchar();

    printf("A: %c\nB: %c\n", a, b);

    char troca = a;
    a = b;
    b = troca;

    printf("A: %c\nB: %c\n", a, b);

    return 0;
}