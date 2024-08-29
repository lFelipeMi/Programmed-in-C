#include <stdio.h>

int main(){
    int n;
    scanf(" %d", &n);
    float media = n;

    for(int i = 1; i < 100; i++){
        scanf(" %d", &n);
        media += n;
    }
    media /= 100;

    printf("A media eh: %.2f", media);

    printf("\n");
    return 0;
}