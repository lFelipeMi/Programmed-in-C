#include <stdio.h>

void le_vetor(int *vet, int tam);
int remove_repeticao(int *vet, int tam);
void imprime_vetor(int *vet, int tam);

int main() {
    int n = 0;
    scanf("%d", &n);
    int v[n];

    le_vetor(v, n);

    n = remove_repeticao(v, n);

    imprime_vetor(v, n);
    printf("\n");

    return 0;
}

void le_vetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%d", vet + i);
    }
}

int remove_repeticao(int *vet, int tam) {
    int valido = 1, n = 0;
    int vet2[tam];
    for (int i = 0; i < tam; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (vet[i] == vet[j]) {
                valido = 0;
            }
        }
        if (valido) {
            vet2[n] = vet[i];
            n++;
        }
        valido = 1;
    }

    for (int i = 0; i < n; i++) {
        vet[i] = vet2[i];
    }

    return n;
}

void imprime_vetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
}


