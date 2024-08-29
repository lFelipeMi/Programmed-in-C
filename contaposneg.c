#include <stdio.h>

int main(){
    int v[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &v[i]);
    }

    int neg = 0, pos = 0;
    for(int i = 0; i < 5; i++){
        if(v[i] < 0)
            neg++;
        if(v[i] >= 0)
            pos++;
    }

    printf("%d negativos\n%d positivos", neg, pos);

    printf("\n");
    return 0;
}

