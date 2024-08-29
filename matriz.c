#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int inicio = 1; // Valor inicial para a primeira posição da linha
    int sm_centro = 0; // Soma dos valores da linha central ou das duas linhas centrais
    int count_even = 0; // Contador para números pares
    
    // Loop para imprimir as linhas de números
    for (int i = 1; i <= a; i++) {
        int atual = inicio; // Valor atual para a posição na linha
        
        // Loop para imprimir os números na linha
        for (int j = 1; j <= b; j++) {
            printf("%d ", atual);
            
            // Verifica se o número é par
            if (atual % 2 == 0) {
                count_even++;
            }
            
            // Atualiza a soma dos valores da linha central ou das duas linhas centrais
            if (i == a / 2 + 1 || (a % 2 == 0 && i == a / 2)) {
                sm_centro += atual;
            }
            
            atual++; // Incrementa o valor atual para a próxima posição na linha
        }
        
        printf("\n"); // Quebra de linha entre as linhas
        
        inicio = atual; // Atualiza o valor inicial para a próxima linha
    }
    
    // Exibe a soma dos valores da linha central ou das duas linhas centrais
    printf("%d\n", sm_centro);
    
    // Exibe o total de números pares exibidos nas a linhas
    printf("%d\n", count_even);
    
    return 0;
}
