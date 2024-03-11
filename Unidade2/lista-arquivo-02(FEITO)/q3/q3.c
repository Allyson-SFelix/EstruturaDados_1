/*Vocˆe foi contratado para desenvolver um programa em C que permita o cadastro de frutas e seus
pre ̧cos em um arquivo de dados. 



O usu ́ario poder ́a cadastrar m ́ultiplas frutas em uma  ́unica execu ̧c ̃ao do programa.

Ap ́os inserir os dados de cada fruta, o programa deve salvar as informa ̧c ̃oes no arquivo ”frutas.txt”.
Cada linha do arquivo deve conter o nome da fruta e seu pre ̧co, separados por v ́ırgula.
O programa deve continuar solicitando os dados das frutas at ́e que o usu ́ario decida parar.
Quando o usu ́ario decidir parar de cadastrar frutas, o programa deve exibir uma mensagem de encer-
ramento e fechar o arquivo.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    float valor;
}Frutas;

Frutas **cadastrarFrutas(Frutas**frutas,int contador){
    frutas[contador]= (Frutas*)malloc(sizeof(Frutas));
    printf("\n----CADASTRANDO FRUTA----\n");
    printf("\nDigite o nome da fruta: ");
    scanf(" %[^\n]s",frutas[contador]->nome);
    printf("\nDigite o valor da fruta: ");
    scanf("%f",&frutas[contador]->valor);
    return frutas;
}

void liberarMemoria(Frutas**fruta,int contador){
    int i=0;
    for(i=0;i<contador;i++){
        free(fruta[i]);
    }
    free(fruta);
}

int main(){
    FILE *frutaArquivo=fopen("frutas.txt","wt");
    if(frutaArquivo==NULL)
        exit(1);
    
    Frutas ** fruta=(Frutas**)malloc(sizeof(Frutas*));
    if(fruta==NULL)
        exit(1);
    
    char manter;
    int contador=0;
    do{
        fruta = (Frutas**)realloc(fruta,(contador + 1)* sizeof(Frutas*));
        fruta =cadastrarFrutas(fruta,contador);
        printf("Deseja continuar\t(1--Sair)");
        scanf(" %c",&manter);
        if(manter!=1){
            contador++;
        }
    }while(manter!='1');
    int i=0;
    for(i=0;i<contador;i++){
        fprintf(frutaArquivo,"Nome:%s,Preco:RS%.2f\n",fruta[i]->nome,fruta[i]->valor);
    }
    fclose(frutaArquivo);
    liberarMemoria(fruta,contador);
    return 0;
}