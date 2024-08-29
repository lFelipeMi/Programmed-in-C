#include <stdio.h>

void main(){
    int d1x, d1y, d2x, d2y, dUx, dUy;

    scanf("%d %d", &d1x, &d1y);
    scanf("%d %d", &d2x, &d2y);
    scanf("%d %d", &dUx, &dUy);

    if(((d1x < dUx && d1y < dUy && d2x > dUx && d2y > dUy) && (d1x < d2x && d1y < d2y))|| ((d1x > dUx && d1y > dUy && d2x < dUx && d2y < dUy) &&(d1x > d2x && d1y > d2y)) ||
        ((d1x < dUx && d1y > dUy && d2x > dUx && d2y < dUy) && (d1x < d2x && d1y > d2y))|| ((d1x > dUx && d1y < dUy && d2x < dUx && d2y > dUy) && (d1x > d2x && d1y < d2y))){
            printf("INTERNO");
        } else {
            printf("EXTERNO");
        }
        
    return;
}