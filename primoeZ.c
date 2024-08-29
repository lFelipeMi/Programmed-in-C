#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) { // for(condição de inicio; condição de parada; incremento);
        scanf("%d", &k); //faz a leitura de uma sequencia K de n numeros.
        
        // Verifica se k é primo
        int primo = 1; //se primo passar pelo seguinte laço for sem ter seu valor alterado, então ele é primo
        for (int j = 2; j * j <= k; j++) {
            if (k % j == 0) {
                primo = 0;
                break; // Se encontrar um divisor, não é primo, o valor da variavel é alterado e o for é encerrado.
            }
        }
        
        if (primo) { // 1 = verdadeiro e 0 = falso
            printf("%d eh primo.\n", k);
        } else { //se não for primo então temos que encontrar numero primo mais proximo do numero analisado, sendo ele maior.
            // Encontra o maior primo anterior a k
            int primoAnt = 2;
            for (int j = k - 1; j >= 2; j--) { //for(condição de inicio; condição de para; decremento)
                primo = 1; 

                for (int l = 2; l * l <= j; l++) {
                    if (j % l == 0) {
                        primo = 0;
                        break; // Se encontrar um divisor, não é primo, a variavel é alterada e o for é encerrado
                    }
                }
                if (primo) {
                    primoAnt = j;
                    break; // Encontrou o maior primo anterior, sai do loop
                }
            }
            printf("%d nao eh primo, o primo anterior eh %d.\n", k, primoAnt);
        }
    }
    
    printf("\n");
    return 0;
}
