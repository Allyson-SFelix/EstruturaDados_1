#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

struct aluno{
  char nome[100];
  int matricula;
  float IRA;
};

Aluno * receberDados(){
  // alocando memoria para o struct Aluno
  Aluno * estudante=(Aluno*)malloc(sizeof(Aluno));
  if(estudante==NULL){
    exit(1);
  }
  //
  printf("\n-----MATRICULA-----\n");
  printf("\nDigite o seu nome: ");
  scanf(" %[^\n]",estudante->nome);
  printf("\nDigite o numero da matricula: ");
  scanf("%d",&estudante->matricula);
  printf("\nDigite o seu IRA(Indice de rentimento academico): ");
  scanf("%f",&estudante->IRA);
  printf("\n-------------------\n");
  return estudante;
}

void mostrarTela(Aluno * aluno){
  printf("\n-----ALUNO MATRICULADO-----\n");
  printf("\nNome: %s",aluno->nome);
  printf("\nMatricula: %d",aluno->matricula);
  printf("\nIRA: %.2f\n\n",aluno->IRA);
}

void liberarMemoria(Aluno ** aluno, int *numeroAlunos){
  int i=0;
  for(i=0;i<(*numeroAlunos);i++){
    free(aluno[i]);
  }
  free(aluno);
}

Aluno ** matricularAlunos(int *numeroAlunos){
  //
  Aluno **estudante=(Aluno**)malloc(sizeof(Aluno*));
   if(estudante==NULL){
    exit(1);
  }
  //
  char saida;
  int i=0;
  // cadastrar todos de uma vez
  do{
    estudante = (Aluno **)realloc(estudante,((*numeroAlunos) + 1)*sizeof(Aluno *));
    estudante[*numeroAlunos]=receberDados();
    printf("\nDigite para sair\t(1-Sair)");
    scanf(" %c",&saida);
    (*numeroAlunos)++;
  }while(saida!='1');
  // mostrar todos de uma vez
  for(i=0;i<(*numeroAlunos);i++){
    mostrarTela(estudante[i]);
  }
  return estudante;
}