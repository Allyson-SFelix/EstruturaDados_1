#include "funcionarios.h"
#include <stdio.h>

struct funcionarios{
    char nome[100];
    char funcional[3];
    char departamento;
    float salario;
};

// imprima o valor gasto por cada departamento

// 

void copia_dados(FILE*fl,int n,Funcionarios**pessoal){
    if(n==0){
    fscanf(fl,"\n%s\t %s\t%c\t%f",pessoal[n]->funcional,pessoal[n]->nome,pessoal[n]->departamento,pessoal[n]->salario);
    }else{
    fscanf(fl,"%s\t %[^\n]\t%c\t%f",pessoal[n]->funcional,pessoal[n]->nome,pessoal[n]->departamento,pessoal[n]->salario);
    }
}

void imprime_folha_pagamento(int n,Funcionarios**pessoal,char depto){
    // primeira linha numero de funcionarios
    // deve ser impresso \t funcional,nome,depart,salario
    int contador=0;
    float salarioDep=0.0;
    for (int contador = 0; contador < n; contador++) {
        if (pessoal[contador]->departamento == depto) {
            salarioDep += pessoal[contador]->salario;
        }
        if(contador==0){
            printf("\nFuncional\tnome\tDepto\tSalario\n");
        }else{
            printf("%s\t%s\t%c\t%2.f",pessoal[contador]->funcional,pessoal[contador]->nome,pessoal[contador]->departamento,pessoal[contador]->salario);
        }
    }
    printf("O departamento %c recebe RS%2.f de salario no total",pessoal[n]->departamento,salarioDep);
}

