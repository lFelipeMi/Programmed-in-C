#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    float v[n];
    for(int i = 0; i < n; i++){
        scanf("%f", v + i);
    }

    float maior = v[0], menor = v[0];
    for(int i = 1;  i < n; i++){
        if(maior < v[i]){
            maior = v[i];
        }
        if(menor > v[i]){
            menor = v[i];
        }
    }

    printf("%.2f eh o maior\n%.2f eh o menor", maior, menor);

    printf("\n");
    return 0;
}
