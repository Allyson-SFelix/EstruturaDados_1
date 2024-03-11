#include "disciplina.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Disciplina*cria_disciplina(char nome[],int codigo){
    Disciplina*disciplinas=(Disciplina*)malloc(sizeof(Disciplina));
    if(disciplinas==NULL){
        printf("\nErro na alocacao\n");
    }
    strcpy(disciplinas->nome,nome);
    disciplinas->codigo=codigo;
}


void exclui_disciplina(Disciplina* disciplina){
    free(disciplina);
}