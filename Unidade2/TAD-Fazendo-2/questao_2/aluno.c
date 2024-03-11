#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"
#include <string.h>

Aluno* cria_aluno(char nome[], int matricula){
    Aluno*aluno=(Aluno*)malloc(sizeof(Aluno));
    if(aluno==NULL){
        printf("\nErro na alocacao no aluno\n");
        exit(1);
    }
    strcpy(aluno->nome,nome);
    aluno->matricula=matricula;
    return aluno;
} 

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina){
    aluno->num_disciplinas+=1;
    aluno->disciplinas[0]=disciplina;
}
void exclui_aluno(Aluno* aluno){
    free(aluno);
}