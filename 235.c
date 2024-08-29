#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if(n % 2 == 0)
        printf("Divisivel por dois\n");
    
    if(n % 3 == 0)
        printf("Divisivel por tres\n");
    
    if(n % 5 == 0)
        printf("Divisivel por cinco\n");
    if(!(n % 2 == 0 && n % 3 == 0 && n % 5 == 0))
        printf("Nao eh divisivel por dois nem por tres e nem por cinco");

    printf("\n");
    return 0;
}