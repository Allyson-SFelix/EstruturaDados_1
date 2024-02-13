#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef union{
    char TipoAlimento[20];
    char TipoBebida[20];
    char TipoEletronico[20];
}Tipo;

typedef struct{
    char nome[30];
    float preco;
    Tipo tipo;
}Produto;

void receberDados(Produto *produto){
    printf("\n Digite o nome do produto: \n");
    scanf(" %[^\n]",produto->nome);
    printf("\n Digite o preco: \n");
    scanf("%f",&produto->preco);
    printf("Digite o tipo do produto: \nAlimento - - 1\nBebida - - 2\nEletronico - - 3\n");

    int temp=0;
    scanf("%d",&temp);

    switch(temp){
    case 1:
        strcpy(produto->tipo.TipoAlimento,"Alimento");
    break;
    case 2:
        strcpy(produto->tipo.TipoBebida,"Bebida");
    break;
    case 3:
        strcpy(produto->tipo.TipoEletronico,"Eletronico");
    break;
    default:
        printf("\nOPCAO INVALIDA\n");
    }

}

void mostrarDados(Produto *produto){
    printf("\nProduto: %s\n",produto->nome);
    printf("\nValor: %.2f\n",produto->preco);
    printf("\nTipo: %s \n",produto->tipo.TipoBebida);

}

int main(){
    Produto *produto=(Produto*)malloc(sizeof(Produto));
    if(produto ==NULL){
        exit(1);
    }
    receberDados(produto);
    mostrarDados(produto);
    free(produto);
    //
    return 0;
}
