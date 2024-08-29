#include <stdio.h>

int main(){
    int n, nn = 0;
    scanf(" %d", &n);

    for(int i = 1; i < n *2; i+=2){
        nn += i;
    }
    printf("%d", nn);

    printf("\n");
    return 0;
}