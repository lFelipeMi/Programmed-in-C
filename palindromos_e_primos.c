#include <stdio.h>

int main(){
    int n = 0, soma = 0;

    do
    {
        scanf(" %d", &n);

        int inverso = 0, n2 = n;

        while(n2 > 0)
        {
            int dig = n2 % 10;
            inverso = inverso * 10 + dig;
            n2/=10;
        }
        if(n == inverso && n != 0)
        {
            int primo = 1; //se primo passar pelo seguinte laço for sem ter seu valor alterado, então ele é primo
            int i = 2;
            while(i * i <= n && primo == 1){
                if (n % i == 0) {
                    primo = 0;
                    }
                i++;
            }
        
            if (primo) 
            { 
                printf("%d\n", n);
            }
        }

        int i = 1;
        do
        {
        n2 = n;

            while(n2 > 0)
            {
                int digito = n2 % 10;
                n2 /= 10;

                if(digito == i)
                {
                    soma += i;

                }      
            }
            i++;
        }
        while(i < 9);
    }
    while(n > 0);
    
    printf("%d", soma);

    printf("\n");
    return 0;
}