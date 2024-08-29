#include <stdio.h> 

void main(){
    float preco = 0;
    scanf("%f", &preco);

    float precofinal = preco + (preco * 0.1);
    printf("Voce pode pagar emm 5x de %.2fR$ sem juros\n", preco/5);
    printf("Caso pague a vista fazemos um desconto de %.2fR$ e voce paga apenas %.2fR$", preco*0.1, precofinal);
    printf("\n");
}