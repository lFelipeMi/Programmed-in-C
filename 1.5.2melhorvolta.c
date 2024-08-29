#include <stdio.h>

void le_vetor(float *vet, int tam);
int bestTime(float *vet, int tam);
float media_vet(float *vet, int tam);

void main(){
    int n = 0;
    scanf("%d", &n);

    float v[n];
    le_vetor(v, n);

    int indiceBest = bestTime(v, n);
    printf("O melhor tempo foi: %.2f\n", v[indiceBest]);

    float media = media_vet(v, n);
    printf("A media de tempo por volta eh %.2f\n", media);


}

void le_vetor(float *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%f", vet + i);
    }
}

int bestTime(float *vet, int tam){
    int best = 0;
    for(int i = 1; i < tam; i++){
        if(vet[i] < vet[best]){
            best = i;
        }
    }
    return best;
}

float media_vet(float *vet, int tam){
    float media = 0;
    for(int i = 0; i < tam; i++){
        media += vet[i];
    }
    return media/tam;
}