#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"
#include <string.h>

struct aluno{
    char nome[100];
    int matricula;
    Disciplina*disciplinas[10];
    int num_disciplinas;
};

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
    int contador;
    for (contador = 0; contador < aluno->num_disciplinas; contador++) {
        if (aluno->disciplinas[contador] == disciplina) {
            printf("O aluno já está matriculado nesta disciplina.\n");
        }
    }
    if (aluno->num_disciplinas < 10) { 
        aluno->disciplinas[aluno->num_disciplinas] = disciplina;
        aluno->num_disciplinas+=1;
        printf("Aluno matriculado com sucesso na disciplina.\n");
    } else {
        printf("O aluno atingiu o limite de disciplinas.\n");
    }
}

void exclui_aluno(Aluno* aluno){
    free(aluno);
}

void printAlunos(Aluno**aluno,int max,int *matriculas){
    int contador=0;
    for(contador=0;contador<max;contador++){
        if(matriculas[contador]!=0){
                printf("\nNome:%s\tMatricula:%d\n",aluno[contador]->nome,matriculas[contador]);
            }
    }
}


void liberarMemoriaAlunos(Aluno**aluno,int max, int *matriculas){
    int contador=0;
    for(contador=0;contador<max;contador++){
        if(matriculas[contador]!=0)
        free(aluno[contador]);
    }
    free(aluno);
}