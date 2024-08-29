#include <stdio.h>

int main(){
    int n;
    scanf(" %d", &n);

    for(int i = n - 1; i > 1; i--){
        n *= i;
    }

    printf("%d", n);

    printf("\n");
    return 0;
}