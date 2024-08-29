#include <stdio.h>

int main(){
    int n = 0, s = 0, s_ant = 0, seg_maior = 1, seg = 1;
    scanf(" %d", &n);
    scanf(" %d", &s_ant);

    for(int i = 1; i < n; i++){
        scanf(" %d", &s);
        if(s > s_ant){
            seg++;
        } else {
            seg = 1;
        }

        if(seg > seg_maior){
            seg_maior = seg;
        }


    }
    printf("O comprimento do maior segmento crescente eh %d", seg_maior);

    printf("\n");
    return 0;
}