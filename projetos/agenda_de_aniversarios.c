#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    printf("\n\t-------------------------------");
    for(int i = 0; i < quant; i++)
        printf("\n\t%d: %02d/%02d/%04d - %s", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    printf("\n\t-------------------------------\n");
}

//0 = ERRO //1 = Cadastro realizado
int cadastrar_contato(Contato **c, int id, int tam){
    if(id < tam){
        Contato *novo = calloc(1, sizeof(Contato));
        printf("Digite o nome do aniversariante: ");
        //fgets(novo->nome, 50, stdin);
        scanf(" %49[^\n]", novo->nome);
        printf("\nDigite a data de nascimento DD/MM/AAAA: ");
        scanf(" %d %d %d", &novo->dia, &novo->mes, &novo->ano);

        c[id] = novo;
        return 1;
    }

    printf("Erro ao cadastrar contato, quantidade excedida.\n");
    return 0;
}

void alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("Insira o indice do contato que deseja alterar: ");
    scanf(" %d", &id);
    if(id > quant || id < 1){
        printf("Contato inexistente, impossivel alterar.\n");
        return;
    }
    id--;
    Contato *novo = calloc(1, sizeof(Contato));
    printf("Digite o nome do aniversariante: ");
    //fgets(novo->nome, 50, stdin);
    scanf(" %49[^\n]", novo->nome);
    printf("\nDigite a data de nascimento DD/MM/AAAA: ");
    scanf(" %d %d %d", &novo->dia, &novo->mes, &novo->ano);
    c[id] = novo;
}

int ler_arquivo(Contato **c, char arq[]){
    FILE *file = fopen(arq, "r");
    int quant = 0;
    Contato *novo = calloc(1, sizeof(Contato));

    if(file){
        fscanf(file, "%d ", &quant);
        for(int i = 0; i < quant; i++){
            //fgets(novo->nome, 50, file);
            fscanf(file, "%49[^\n]", novo->nome);
            fscanf(file, "%d %d %d\n", &novo->dia, &novo->mes, &novo->ano);
            c[i] = novo;
            novo = calloc(1, sizeof(Contato));
        }
        fclose(file);
    } else
        printf("Impossivel ler arquivo.");
}

void salvar_arquivo(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "w");

    if(file){
        fprintf(file, "%d\n", quant);
        for(int i = 0; i < quant; i++){
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    } else
        printf("Erro ao abrir arquivo.\n");
}

void alterarB(char arq[]){
    FILE *file = fopen(arq, "rb+");
    Contato c;
    int id, i = 1;

    if(file){
        printf("\n\tLista de contatos:\n");
        printf("\t--------------------------------\n");
        while(fread(&c, sizeof(Contato), 1, file)){
            printf("\t%d - %02d/%02d/%04d\t%s\n", i, c.dia, c.mes, c.ano, c.nome);
            i++;
        }
        printf("\t--------------------------------\n");
        
        printf("\n\tDigite o indice do contatoo que deseja alterar: ");
        scanf("%d ", &id);
        id--;

        if(id >= 0 && id < i - 1){
            printf("\tDigite nome e data de nascimento DD MM AAAA: ");
            scanf("%49[^\n] %d %d %d", c.nome, &c.dia, &c.mes, &c.ano);
            fseek(file, id * sizeof(Contato), SEEK_SET); 
            fwrite(&c, sizeof(Contato), 1, file);
        }

    } else
        printf("\nErro ao abrir arquivo!\n");
}

int lerB(Contato **c, char arq[]){
    int quant = 0;
    Contato *novo = calloc(1, sizeof(Contato));
    FILE *file = fopen(arq, "rb");

    if(file){
        while(fread(novo, sizeof(Contato), 1, file)){
            c[quant] = novo;
            quant++;
            novo = calloc(1, sizeof(Contato));
        }
        fclose(file);
    } else
        printf("Erro ao abrir arquivo.\n");

    return quant;
}

void salvarB(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "wb");

    if(file){
        for(int i =  0; i < quant; i++)
            fwrite(c[i], sizeof(Contato), 1, file);
        fclose(file);
    } else 
        printf("Erro ao ler arquivo.\n");
}

int main(){
    Contato *contatos[100];
    char arquivo[] = {"agenda.txt"};
    char arquivo2[]  = {"agenda.dat"};
    int opcao, quant = 0, tam = 100;

    do{
        printf("\n\t0 - Sair\n\t1 - Imprimir\n\t2 - Cadastrar\n\t3 - Alterar\n\t"
            "4 - Ler um arquivo\n\t5 - Salvar alterações\n\t6 - Salvar alterações em Binario"
            "\n\t7 - Ler arquivo Binario\n8 - Alterar arquivo binario\n");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            imprimir(contatos, quant);
            break;
        case 2:
            quant += cadastrar_contato(contatos, quant, tam);
            break;
        case 3:
            alterar_contato(contatos, quant);
            break;
        case 4:
            ler_arquivo(contatos, arquivo);
            break;
        case 5:
            salvar_arquivo(contatos, quant, arquivo);
            break;
        case 6:
            salvarB(contatos, quant, arquivo2);
            break;
        case 7:
            quant = lerB(contatos, arquivo2);
            break;
        case 8:
            alterarB(arquivo2);
            break; 
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);
    
    return 0;
}