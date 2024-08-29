#include <stdio.h>

int main(){
    int n;
    scanf(" %d", &n);
    int decimal = 0, base = 1;
    int n2 = n;
    while(n2 > 0)
    {
        int dig = n2 % 10;
        decimal += dig * base;
        base *= 8;
        n2 /= 10;
    }
    printf("%d em decimal eh: %d\n", n, decimal);

    int octal = 0;
    base = 1; 
    n2 = decimal;
    while(n2 > 0)
    {
        int dig = n2 % 8;
        octal += dig * base;
        base *= 10;
        n2 /= 8;
    }
    printf("%d", octal);


    printf("\n");
    return 0;
}