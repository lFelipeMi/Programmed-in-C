#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0;

    do{
        scanf(" %d", &n1);
        switch (n1)
        {
        case -1:
            break;
        
        default:
            scanf(" %d", &n2);
            switch (n2)
            {
            case -1:
                break;
            
            default:
                int decimal1 = 0, decimal2 = 0, base = 1;
            int n1_1 = n1, n2_2 = n2;
            while(n1_1 > 0 || n1_1 > 0)
            {
                int dig1 = n1_1 % 10, dig2 = n2_2 %10;
                decimal1 += dig1 * base;
                decimal2 += dig2 * base;
                base *= 8;
                n1_1 /= 10;
                n2_2 /= 10;
            }
            printf("%d %d ", decimal1, decimal2);

            /////////////////////////////////////////////////////////////
            n1_1 = decimal1, n2_2 = decimal2;
            int binario1 = 0, binario2 = 0, binario3 = 0;
            base = 1;
            while(n1_1 > 0 || n2_2 > 0)
            {
                int decimo1 = n1_1 % 2, decimo2 = n2_2 % 2;
                binario1 += decimo1 * base;
                binario2 += decimo2 * base;

                if(decimo1 == 1)
                {
                    binario3 += 1 * base;
                } 
                else if(decimo2 == 1)
                {
                    binario3 += 1 * base;
                }

                base *= 10;
                n1_1 /= 2;
                n2_2 /= 2;
            }
            printf("%d %d %d ", binario1, binario2, binario3);

            /////////////////////////////////////////////////////////////
            int decimal = 0;
            n1_1 = binario3;
            base = 1;

            while(n1_1 > 0)
            {
                int bit = n1_1 % 10;
                decimal += bit * base;
                base *= 2;
                n1_1 /= 10;
            }
            printf("%d ", decimal);

            /////////////////////////////////////////////////////////////
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
            printf("%d\n", octal);
                break;
            }
            break;
        }
    }
    while(n1 > -1 && n2 > -1);

    printf("\n");
    return 0;
}

/*
#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0;

    do{
        scanf(" %d", &n1);
        if(n1 <= -1)
        {
            break;
        }
        scanf(" %d", &n2);
        if(n2 <= -1)
        {
            break;
        }

        int decimal1 = 0, decimal2 = 0, base = 1;
        int n1_1 = n1, n2_2 = n2;
        while(n1_1 > 0 || n1_1 > 0)
        {
            int dig1 = n1_1 % 10, dig2 = n2_2 %10;
            decimal1 += dig1 * base;
            decimal2 += dig2 * base;
            base *= 8;
            n1_1 /= 10;
            n2_2 /= 10;
        }
        printf("%d %d ", decimal1, decimal2);

        n1_1 = decimal1, n2_2 = decimal2;
        int binario1 = 0, binario2 = 0, binario3 = 0;
        base = 1;
        while(n1_1 > 0 || n2_2 > 0){
            int decimo1 = n1_1 % 2, decimo2 = n2_2 % 2;
            binario1 += decimo1 * base;
            binario2 += decimo2 * base;

            if(decimo1 == 1)
            {
                binario3 += 1 * base;
            } 
            else if(decimo2 == 1)
            {
                binario3 += 1 * base;
            }

            base *= 10;
            n1_1 /= 2;
            n2_2 /= 2;
        }
        printf("%d %d %d ", binario1, binario2, binario3);

        int decimal = 0;
        n1_1 = binario3;
        base = 1;

        while(n1_1 > 0){
            int bit = n1_1 % 10;
            decimal += bit * base;
            base *= 2;
            n1_1 /= 10;
        }
        printf("%d ", decimal);

        int octal = 0;
        base = 1; 
        n2 = decimal;
        while(n2 > 0){
            int dig = n2 % 8;
            octal += dig * base;
            base *= 10;
            n2 /= 8;
        }
        printf("%d\n", octal);
    }while(n1 > -1 && n2 > -1);

    printf("\n");
    return 0;
}*/