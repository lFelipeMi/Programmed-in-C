#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int inicio = 1; // Valor inicial para a primeira posição da linha
    int sm_centro1 = 0; // Soma dos valores da primeira linha central
    int sm_centro2 = 0; // Soma dos valores da segunda linha central //linha caso a % 2 != 0
    int pares = 0; // Contador para números pares
    
    // Loop para imprimir as linhas de números
    for (int i = 1; i <= a; i++) {
        int atual = inicio; // Valor atual para a posição na linha
        int sm_linha = 0; // Soma dos valores da linha
        
        // Loop para imprimir os números na linha
        for (int j = 1; j <= b; j++) {
            printf("%3.d ", atual);
            
            // Verifica se o número é par
            if (atual % 2 == 0) {
                pares++;
            }
            
            // Atualiza a soma dos valores da linha
            sm_linha += atual;
            
            // Atualiza a soma dos valores das linhas centrais
            if ((a % 2 == 0 && i == a / 2) || i == a / 2 + 1) {
                if (i == a / 2) {
                    sm_centro1 += atual;
                } else {
                    sm_centro2 += atual;
                }
            }
            
            atual++; // Incrementa o valor atual para a próxima posição na linha
        }
        
        printf("\n"); // Quebra de linha entre as linhas
        
        inicio = atual; // Atualiza o valor inicial para a próxima linha

    }
    
    // Se a for ímpar, imprime a soma das linhas centrais separadamente
    if (a % 2 != 0) {
        printf("%d\n", sm_centro2);
    } else {
        printf("%d\n", sm_centro1);
        printf("%d\n", sm_centro2);
    }
    
    // Exibe o total de números pares exibidos nas a linhas
    printf("%d\n", pares);
    
    return 0;
}
