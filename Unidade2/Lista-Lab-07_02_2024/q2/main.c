#include "funcionarios.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *arquivo=fopen("funcionarios.txt","r");
    if(arquivo==NULL){
        exit(1);
    }
    char linha[100];
    int contador=0;
    fscanf(arquivo,"%d",&contador);
    Funcionarios**funcionarios=(Funcionarios**)malloc(contador*sizeof(Funcionarios*));
    if(funcionarios==NULL){
        exit(1);
    }
    
    for(contador=0;contador<10;contador++){
            funcionarios[contador]=(Funcionarios*)malloc(sizeof(Funcionarios));
            copia_dados(arquivo,contador,funcionarios);
    }
    printf("\nDigite o departamento: (A)(B)(C)");
    char dept;
    scanf(" %c",&dept);
    imprime_folha_pagamento(contador,funcionarios,dept);

    liberarMemoria(funcionarios,contador);
    return 0;
}