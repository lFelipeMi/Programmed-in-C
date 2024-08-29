#include <stdio.h>

int main(){
    int vetN[20] = {0};

    for(int i = 0; i < 20; i++)
        scanf(" %d", &vetN[i]);
    printf("\n");
    for(int i = 0; i < 20; i++)
        printf("%3d ", vetN[i]);
    printf("\n");
    for(int i = 0; i < 10; i++){
        vetN[i] += vetN[19 - i];
        vetN[19 - i] = vetN[i] - vetN[19 - i];
        vetN[i] -= vetN[19 - i];
    }    
    
    for(int i = 0; i < 20; i++)
        printf("%3d ", vetN[i]);

    printf("\n");
    return 0;
}