#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime_vetor(int *v, int n);

int main(){
    int v1[25], v2[25];
    srand(time(NULL));

    for(int i = 0; i < 25; i++){
        v1[i] = rand() % 50;
        v2[i] = rand() % 99;
    }

    int v3[25];
    for(int i = 0; i < 25; i++){
        v3[i] = v1[i] + v2[i];
    }

    imprime_vetor(v1, 25);
    imprime_vetor(v2, 25);
    imprime_vetor(v3, 25);
    


    return 0;
}

void imprime_vetor(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *(v + i));
    }
    printf("\n");
}