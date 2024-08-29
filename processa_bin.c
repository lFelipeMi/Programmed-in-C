#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0;
    while(n1 != -1 && n2 != -1)
    {
        scanf(" %d", &n1);
        if(n1 == -1)
        {
            break;
        }
        scanf(" %d", &n2);
        if(n2 == -1)
        {
            break;
        }

        int n1_1 = n1, n2_2 = n2;
        int binario1 = 0, binario2 = 0, binario3 = 0, base = 1;
        while(n1_1 > 0 || n2_2 > 0)
        {
                int decimo1 = n1_1 % 2, decimo2 = n2_2 % 2;

                if(decimo1 == decimo2 && decimo1 == 1){
                    binario3 += 1 * base;
                }

                binario1 += decimo1 * base;
                binario2 += decimo2 * base;
                base *= 10;
                n1_1 /= 2;
                n2_2 /= 2;
        }
        printf("%d %d %d ", binario1, binario2, binario3);

        int decimal = 0;
        n1_1 = binario3;
        base = 1;

        while(n1_1 > 0)
        {
            int bit1 = n1_1 % 10;
            decimal += bit1 * base;
            base *= 2;
            n1_1 /= 10;
        }
        printf("%d\n", decimal);
    }

    printf("\n");
    return 0;
}