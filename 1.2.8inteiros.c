#include <stdio.h>

void main (){
    int v[5];
    for(int i = 0; i < 5; i++){
        scanf("%d", &v[i]);
    }

    int maior = v[0], menor = v[0], igual = 1;
    for(int i = 1; i < 5; i++){
        if(v[i] != v[i-1] && igual){
            igual = 0;
        }
        if (maior < v[i]){
            maior = v[i];
        }
        if(menor > v[i]){
            menor = v[i];
        }
    }

    if(!igual){
        printf("Entre");
        for(int i = 0; i < 5; i++){
            printf(" %d", v[i]);
        }
        printf(" o maior elemento eh %d e o menor eh %d", maior, menor);
    } else {
        printf("Os valores são todos iguais");
    }
    printf("\n");
}