typedef struct funcionarios Funcionarios;
#include <stdio.h>

/*Funcao que copia os dados do arquivo*/
void copia_dados(FILE*fl,int n,Funcionarios**pessoal);

/*Funcao que imprime os valores e pessoas dos departamentos*/
void imprime_folha_pagamento(int n,Funcionarios**pessoal,char depto);
