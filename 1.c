#include <stdio.h>

void main(){

    int taxa = 0, tres = 0, cinco = 0;
    scanf("%d", &taxa);

    //verificamos o resto da divisão e adicionamos o valor 3 até o resto da divisão ser igual a zero
    if(taxa % 5 == 1){ 
        tres = 2;
        cinco = (taxa - 6)/ 5;
    }
    //////////////////////////////////////////////////////////
    if(taxa % 5 == 3){
        tres = 1;
        cinco = (taxa - 3)/ 5;
    }
    //////////////////////////////////////////////////////////
    if(taxa % 5 == 4){
        tres = 3;
        cinco = (taxa - 9)/ 5;
    }
    //////////////////////////////////////////////////////////
    if(taxa % 5 == 2){
        tres = 4;
        cinco = (taxa - 12)/ 5;
    }
    //////////////////////////////////////////////////////////

    return;
}