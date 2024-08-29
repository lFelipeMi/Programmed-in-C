/*#include <stdio.h>

int main(){
    int n = 0;
    scanf(" %d", &n);
    int cntrl = 1, n2 = n, inverso = 0;

    /*for(int i = n; i > 0; cntrl++)
        i/=10;
    //printf("%d", cntrl);

    for(; n2 > 0; n/=10){
        int dig = 0;
        for(dig = n2/10; dig > 9; dig/=10);
        inverso += dig * cntrl;
        cntrl *= 10;
    }
    printf("O invers de %d eh %d", n, inverso);

    printf("\n");
    return 0;
}*/

#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int inverso = 0;

    for(int i = n; i > 0; i/=10) {
        int dig = i % 10;
        inverso = inverso * 10 + dig;
    }

    printf("O inverso de %d eh %d\n", n, inverso);

    return 0;
}
