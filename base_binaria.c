#include <stdio.h>

int main(){
    int n = 0;
    scanf(" %d", &n);
    int binario = 0, base = 1, n2 = n;

    /*for(; n2 > 0; n2/=10){
        int bit = n2 %10;
        decimal += bit * base;
        base *= 2;
    }
    printf("%d na base decimal eh %d", n, decimal);
    */

    for(; n2> 0; n2/=2){
        int decimo = n2%2;
        binario += decimo * base;
        base *= 10;
    }
    printf("%d na base binaria eh %d", n, binario);

    printf("\n");
    return 0;
}