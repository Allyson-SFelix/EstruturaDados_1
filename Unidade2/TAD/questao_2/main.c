#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"

int main(){
    Disciplina**disciplina= (Disciplina**) malloc(sizeof(Disciplina*)); //estrutura de disciplinas
    Aluno**aluno= (Aluno**) malloc(sizeof(Aluno*));  //estruturas de aluno
    int codMenu=1;  // codigo de menu
    int quantidadeAluno=0;
    int quantidadeMateria=0;
    int *quantMaterias=&quantidadeMateria;  //ponteiro da quantidade de materia
    int *quantAlunos=&quantidadeAluno;      // ponteiro da quantidade de aluno
    int *matriculas=malloc(sizeof(int));    // cada array é um aluno e contem o seu codigo
    int *codigoDisciplina=malloc(sizeof(int)); // cada array é uma disciplina e contem o seu codigo
    while(codMenu!=0){  
        printf("\n mat=%d\taluno=%d",*quantMaterias,*quantAlunos);
        printf("\nBem vindo ao banco\n");
        printf("\nDigite 1 - - Cadastrar Disciplina");
        printf("\nDigite 2 - - Cadastrar Aluno");
        printf("\nDigite 3 - - Matricular Aluno");
        printf("\nDigite 4 - - Apagar Disciplina");
        printf("\nDigite 5 - - Excluir Aluno");
        printf("\nDigite 6 - - Ver Alunos");
        printf("\nDigite 7 - - Ver Disciplinas");
        printf("\nDigite 0 - - Sair\n");
        scanf("%d",&codMenu);
        if(codMenu==1){
            // cadastrar disciplina
            char nomeTemp[100];
            printf("\nDigite o nome: ");
            scanf(" %[^\n]s",nomeTemp);
            (*quantMaterias)++;
            disciplina=(Disciplina**)realloc(disciplina,(*quantMaterias)*sizeof(Disciplina*));
            disciplina[(*quantMaterias)-1]=cria_disciplina(nomeTemp,*quantMaterias);
            codigoDisciplina=realloc(codigoDisciplina,(*quantMaterias)*sizeof(int));
            codigoDisciplina[(*quantMaterias)-1]=(*quantMaterias);
        }else if(codMenu==2){
            // cadastrar aluno
            char nomeTemp[100];
            printf("\nDigite o nome: ");
            scanf(" %[^\n]s",nomeTemp);
            (*quantAlunos)++;
            aluno=(Aluno**)realloc(aluno,(*quantAlunos)*sizeof(Aluno*));
            aluno[(*quantAlunos)-1]=cria_aluno(nomeTemp,*quantAlunos);
            matriculas=realloc(matriculas,(*quantAlunos)*sizeof(int));
            matriculas[(*quantAlunos)-1]=(*quantAlunos);

        }else if(codMenu==3){
            if(quantidadeAluno==0 || quantidadeMateria==0){
                printf("\nNao existe Aluno ou Materias");
            }else{
                int matriculaTemp=0;
                int contador=0,codDisciplinaTemp=0;
                printAlunos(aluno,(*quantAlunos),matriculas);
                printDisciplinas(disciplina,(*quantMaterias),codigoDisciplina);
                
                printf("\nDigite a matricula do aluno: ");
                scanf("%d",&matriculaTemp);
                printf("Digite o codigo da disciplina: ");
                scanf("%d",&codDisciplinaTemp); 
                if(codDisciplinaTemp<=0 || codDisciplinaTemp>codigoDisciplina[quantidadeMateria-1] || matriculaTemp<=0 || matriculaTemp>matriculas[quantidadeAluno-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(codigoDisciplina[codDisciplinaTemp-1]!=0 || matriculas[matriculaTemp-1]!=0){
                        matricula_disciplina(aluno[matriculaTemp-1],disciplina[codDisciplinaTemp-1]);
                    }else{
                        printf("\nNAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==4){
            if(quantidadeMateria==0){
                printf("\nNao existe  Materias");
            }else{
                printDisciplinas(disciplina,(quantidadeMateria),codigoDisciplina);
                int codDisciplinaTemp=0;
                printf("\nDigite o codigo da Disciplina: ");
                scanf("%d",&codDisciplinaTemp);
                  if(codDisciplinaTemp<=0 || codDisciplinaTemp>codigoDisciplina[quantidadeMateria-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(codigoDisciplina[codDisciplinaTemp-1]!=0){
                        exclui_disciplina(disciplina[codDisciplinaTemp-1]);
                        codigoDisciplina[codDisciplinaTemp-1]=0;
                    }else{
                        printf("\nNAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==5){
            if(quantidadeAluno==0){
                printf("\nNao existe Aluno ");
            }else{
                printAlunos(aluno,(quantidadeAluno),matriculas);
                int matriculaTemp=0;
                printf("\nDigite o codigo da Disciplina: ");
                scanf("%d",&matriculaTemp);
                  if(matriculaTemp<=0 || matriculaTemp>codigoDisciplina[matriculaTemp-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(codigoDisciplina[matriculaTemp-1]!=0){
                        exclui_aluno(aluno[matriculaTemp-1]);
                        matriculas[matriculaTemp-1]=0;
                    }else{
                        printf("\nNAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==6){
            if(quantidadeAluno==0){
                printf("\nNao existe Aluno ");
            }else{
                printAlunos(aluno,(quantidadeAluno),matriculas);
            }
        }else if(codMenu==7){
            if(quantidadeMateria==0){
                printf("\nNao existe Materias");
            }else{
                printDisciplinas(disciplina,(quantidadeMateria),codigoDisciplina);
            }
        }else if(codMenu==0){
            printf("\n\tFechando programa\n");
            liberarMemoriaAlunos(aluno,quantidadeAluno,matriculas);
            liberarMemoriaDisciplinas(disciplina,quantidadeMateria,codigoDisciplina);
        }else{
            printf("\n\tCodigo nao encontrado\n");
        }
    }
}