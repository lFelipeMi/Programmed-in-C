#include <stdio.h>

int main(){
    int n = 0;
    scanf(" %d", &n);
    int inverso = 0;

    for(int i = n; i > 0; i/=10){
        int dig = i % 10;
        inverso = inverso * 10 + dig;
    }
    if(n == inverso){
        printf("%d eh um palindromo", inverso);
    } else {
        printf("%d nao eh um palindromo", n);
    }

    printf("\n");
    return 0;
}