#include <stdio.h>

int main(){
    int n = 0;
    do{
        scanf(" %d", &n);
    }while(n < 1 && n > 10);

    for(int i = 1; i <= 10; i++){
        printf("%2i * %2i = %3i\n",n, i, n * i);
    }

    return 0;
}