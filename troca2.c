#include <stdio.h>

int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    printf("n1: %d\nn2:%d\n", n1, n2);
    n1 += n2;
    n2 = n1 - n2;
    n1 = n1 - n2;
    printf("\nn1: %d\nn2:%d\n", n1, n2);


    return 0;
}