#include "disciplina.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct disciplina{
    char nome[100];
    int codigo;
};

Disciplina*cria_disciplina(char nome[],int codigo){
    Disciplina*disciplinas=(Disciplina*)malloc(sizeof(Disciplina));
    if(disciplinas==NULL){
        printf("\nErro na alocacao\n");
    }
    strcpy(disciplinas->nome,nome);
    disciplinas->codigo=codigo;
    return disciplinas;
}


void exclui_disciplina(Disciplina* disciplina){
    free(disciplina);
}

void printDisciplinas(Disciplina**mat, int max, int *codigoDisciplina){
    int contador=0;
    for(contador=0;contador<max;contador++){
        if(codigoDisciplina[contador]!=0){
         printf("\nNome:%s\tCodDisciplina:%d\n",mat[contador]->nome,codigoDisciplina[contador]);
        }
    }
}


void liberarMemoriaDisciplinas(Disciplina**disciplina,int max, int*codigoDisciplina){
    int contador=0;
    for(contador=0;contador<max;contador++){
        if(codigoDisciplina[contador]!=0)
        free(disciplina[contador]);
    }
    free(disciplina);
}