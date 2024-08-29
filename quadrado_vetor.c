#include <stdio.h>

int main(){
    int vet1[10] = {0}, vet2[10] = {0};

    for(int i = 0; i < 10; i++){
        scanf(" %d", &vet1[i]);
        vet2[i] = vet1[i] * vet1[i]; 
    }

    for(int i = 0; i < 10; i++)
        printf("%3d ", vet1[i]);

    printf("\n");

    for(int i = 0; i < 10; i++)
        printf("%3d ", vet2[i]);


    printf("\n");
    return 0;
}