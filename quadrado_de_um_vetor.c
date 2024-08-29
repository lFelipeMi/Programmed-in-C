#include <stdio.h>

int main(){
    int v1[10];
    for(int i = 0; i < 10; i++){
        scanf("%d", &v1[i]);
    }

    int v2[10];
    for(int i = 0; i < 10; i++){
        v2[i] = v1[i] * v1[i];
        printf("%d ", v1[i]);
    }
    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", v2[i]);
    }

    return 0;

}