#include <stdio.h>

int main()
{
    int n1 = 0;
    printf("Digite um numero: ");
    scanf("%d", &n1);
    if(n1 % 2 == 0)
        printf("O numero %d eh Par\n", n1);
    else   
        printf("O numero %d eh Impar\n", n1);

    return 0;
}