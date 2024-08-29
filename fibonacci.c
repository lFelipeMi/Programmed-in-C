#include <stdio.h>

int main(){
    int n;
    scanf(" %d", &n);
    int anterior = 1, anterior_sub = 0;

    for(int i = 1; i <= n; i++){
        printf("%6.d ", anterior);
        anterior += anterior_sub;
        anterior_sub = anterior - anterior_sub;
        
        if(i % 4 == 0)
            printf("\n");
    }

    printf("\n");
    return 0;
}