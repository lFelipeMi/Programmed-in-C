#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void escrever(char f[]){
    FILE *file = fopen(f, "w");
    char letra;

    if(file){
        printf("\nDigite um texto e pressione ENTER ao finalizar!\n");
        scanf("%c", &letra);
        while(letra != '\n'){
            fputc(letra, file);
            scanf("%c", &letra);
        }
        fclose(file);
    } else   
        printf("\nERRO ao abrir o arquivo!\n");
}

void escrever2(char f[]){
    FILE *file = fopen(f, "w");
    char texto[500];

    if(file){
        printf("\nDigite uma frase ou 1 caractere para finalizar:\n");
        scanf("%499[^\n]", texto);
        
        while(strlen(texto) > 1){
            fputs(texto, file);
            fputc('\n', file);
            scanf(" %499[^\n]", texto);
            //printf("\n --> dentro do while...");
        }
        fclose(file);
    } else   
        printf("\nERRO ao abrir o arquivo!\n");    
}

void escrever3(char f[]){
    FILE *file = fopen(f, "w");
    char nome[100];
    int idade, opcao;
    float altura;

    if(file){
        do{
            printf("\nDigite nome, idade e altura: \n");
            scanf(" %s %d %f", nome, &idade, &altura);
            fprintf(file, "%s %d %.2f\n", nome, idade, altura);
            scanf(" %d", &opcao);
        }while(opcao == 1);
        fclose(file);
    } else   
        printf("\nERRO ao abrir o arquivo!\n");       
}

void escrever_bin(char f[]){
    Contato c;
    FILE *file = fopen(f, "ab");

    if(file){
        printf("Digite o nome e a data de nascimento DD MM AAAA: ");
        scanf("%49[^\n] %d %d %d", c.nome, &c.dia, &c.mes, &c.ano);
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
        printf("Lido com sucesso!");
    } else
        printf("\nErro ao abrir o arquivo!\n");
}

void ler_bin(char f[]){
    Contato c;
    FILE *file = fopen(f, "rb");

    if(file){
        while(feof(file)){
            if(freaf(&c, sizeof(Contato), 1, file))
                printf("\nNome: %s\nData: %02d/%02d/%04d", c.nome, c.dia, c.mes, c.ano);
        }
        fclose(file);
    }
}

void ler(char f[]){
    FILE *file = fopen(f, "r");
    char letra;

    if(file){
        printf("\n\tTexto lido do arquivo:\n");
        while(!feof(file)){
            letra = fgetc(file);
            printf("%c", letra);
        }
        fclose(file);
    } else   
        printf("\nERRO ao abrir o arquivo!\n");


}

void ler2(char f[]){
    FILE *file = fopen(f, "r");
    char texto[500];

    if(file){
        printf("\n\tTexto lido do arquivo:\n");
        while(!feof(file)){
            if(fgets(texto, 499, file))
                printf("\n--> %s\n", texto);
        }
        fclose(file);
    } else   
        printf("\nERRO ao abrir o arquivo!\n");
}

void ler3(char f[]){
    FILE *file = fopen(f, "r");
    char nome[100];
    int idade, opcao;
    float altura;

    if(file){
        printf("\n\tTexto lido do arquivo:\n");
        while(!feof(file)){
            if(fscanf(file, "%s %d %f", nome, &idade, &altura) != -1)
                printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n\n", nome, idade, altura);
        }
        fclose(file);
    } else   
        printf("\nERRO ao abrir o arquivo!\n");
}

int main(){
    char nome[] = {"arquivo.txt"};
    char nomebin[] = {"arquivo.dat"};
    //escrever3(nome);
    escrever_bin(nomebin);
    ler_bin(nomebin);

    return 0;
}