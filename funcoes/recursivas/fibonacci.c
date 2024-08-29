//NUNCA UTILIZE ESSA FUNÇÃO

#include <stdio.h>

int fibonacci(int n);

int main(){
    int n = 0;
    scanf(" %d", &n);

    printf("O %dª de fibonacci eh: %d", n, fibonacci(n));

    printf("\n");
    return 0;
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
  
}