#include <stdio.h>

int exponencial(int x, int n);

void main(){
    int x = 0, n = 0;
    scanf("%d %d", &x, &n);

    printf("O produto dessa equacao eh: %d\n", exponencial(x, n));

}

int exponencial(int x, int n){
    int produto = 1;
    for(int i = 1; i <= n; i++){
        produto *= x;
    }

    return produto;
}