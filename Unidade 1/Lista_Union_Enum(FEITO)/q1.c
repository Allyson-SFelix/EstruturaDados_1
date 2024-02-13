#include <stdlib.h>
#include <stdio.h>

typedef enum{
    Masculino=1,Feminino
}genero; //Masculino=1 |Feminino= 2


typedef struct{
    char nome[30];
    int idade;
    genero gen;
}Pessoa;

void receberDados(Pessoa *pessoa){
    printf("\n Digite o nome: \n");
    scanf("%[^\n]",pessoa->nome);
    printf("\n Digite a sua idade: \n");
    scanf("%d",&pessoa->idade);
    printf("\n Digite 1 para Masculino\nDigite 2 para Feminino : \n");
    scanf("%d",&pessoa->gen);
}

void mostrarDados(Pessoa *pessoa){
    printf("\nSeu nome: %s\n",pessoa->nome);
    printf("\nSua idade: %d\n",pessoa->idade);
    printf("\nSeu genero: %s\n",pessoa->gen==Masculino?"Masculino":"Feminino"); // variavel == condição? se sim : se nao
    /*if (pessoa->gen== Masculino){
        printf("\nSeu genero e Masculino\n");
    }else if(pessoa->gen==Feminino){
        printf("\nSeu genero e Feminino\n");
    }else{
    printf("\nVOCE DIGITOU A OPCAO INCORRETA ERRADO\n");
    }
    */
}

int main(){
    Pessoa *pessoa=(Pessoa*)malloc(sizeof(Pessoa));
    if(pessoa ==NULL){
        exit(1);
    }
    receberDados(pessoa);
    mostrarDados(pessoa);
    free(pessoa);
    //
    return 0;
}
