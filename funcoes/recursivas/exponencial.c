#include <stdio.h>

float fatorial(int n, int fator);

int main(){
    int n = 0, fator = 0;
    scanf(" %d %d", &n, &fator);

    printf("%d elevado a %d eh: %f", n, fator, fatorial(n, fator));

    printf("\n");
    return 0;
}

float fatorial(int n, int fator){
    if(fator == 0){
        return 1;
    }
    else if(fator > 0){
        return n * fatorial(n, fator - 1);
    }
    else{
        return 1 / (n * fatorial(n, (fator * -1) - 1));
    }
}