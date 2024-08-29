#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vet[100] = {0};

    srand(time(NULL));
    vet[0] = 0;
    for(int i = 1; i < 100; i++){
        vet[i] = 10 + rand() % 90;
    }

    for(int i = 0; i < 100; i++){
        printf("%d ", vet[i]);
        if((i + 1) / 5.0  == 0){
            printf("\n");
        }
    }
    printf("\n///////////////////////////////////////////////\n");

    for(int i = 0; i < 100; i++){
        int para = 1;
        for(int j = i + 1; j < 100; j++){  
            if(vet[j] < vet[i]){
                vet[i] += vet[j];
                vet[j] = vet[i] - vet[j];
                vet[i] -= vet[j];
            }
            if(vet[j] > vet[j+1] && j != 99)
                para = 0;
        }
        if(para)
            break;
    }

    for(int i = 0; i < 100; i++){
        printf("%d ", vet[i]);
        if((i + 1) / 5.0 == 0){
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}