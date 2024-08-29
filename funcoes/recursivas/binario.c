#include <stdio.h>

void binario(int n);

int main(){
    int n = 0;
    scanf(" %d", &n);

    binario(n);
}

void binario(int n){
    if(n == 0)
        printf("0");
    else{
        binario(n/2);
        printf("%d", n%2);
    }
}