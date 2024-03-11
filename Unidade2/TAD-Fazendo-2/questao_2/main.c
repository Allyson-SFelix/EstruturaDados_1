/*

Certifique-se de verificar os limites de matrícula e disciplinas conforme necessário.
Implemente verificações adequadas para evitar duplicação de disciplinas no array de 
disciplinas do aluno.
Garanta que todos os recursos alocados dinamicamente sejam devidamente liberados 
para evitar vazamentos de memória.
Você pode usar as funções e estruturas da linguagem C para implementar esses TADs e 
o programa de exemplo.
*/


#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"

int main(){
    /*Seu programa deve permitir a criação 
de disciplinas e alunos, a matrícula de alunos em disciplinas, e a exibição das informações dos 
alunos e das disciplinas em que estão matriculados.*/
    Disciplina**disciplina;
    Aluno**aluno;
    int codMenu=0;
    int quantidadeAluno=0;
    int quantidadeMateria=0;
    int *quantMaterias=&quantidadeMateria;
    int *quantAlunos=&quantidadeAluno;
    int *matriculas=malloc(sizeof(int));    // cada array é um aluno e contem o seu codigo
    int *codigoDisciplina=malloc(sizeof(int)); // cada array é uma disciplina e contem o seu codigo
    while(codMenu!=0){
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
            Disciplina**disciplina=(Aluno**)realloc(disciplina,(*quantMaterias)*sizeof(Aluno*));
            disciplina[(*quantMaterias)-1]=cria_disciplina(nomeTemp,*quantMaterias);
            codigoDisciplina=realloc(codigoDisciplina,(*quantMaterias)*sizeof(int));
            codigoDisciplina[(*quantMaterias)-1]=(*quantMaterias);
        }else if(codMenu==2){
            // cadastrar aluno
            char nomeTemp[100];
            printf("\nDigite o nome: ");
            scanf(" %[^\n]s",nomeTemp);
            (*quantAlunos)++;
            Aluno**aluno=(Aluno**)realloc(aluno,(*quantAlunos)*sizeof(Aluno*));
            aluno=cria_aluno(nomeTemp,*quantAlunos);
            matriculas=realloc(matriculas,(*quantAlunos)*sizeof(int));
            matriculas[(*quantAlunos)-1]=(*quantAlunos);
        }else if(codMenu==3){
            if(quantidadeAluno==0 || quantidadeMateria==0){
                printf("\nNao existe Aluno ou Materias");
            }else{
                int matriculaTemp=0;
                int contador=0,codDisciplinaTemp=0;
                for(contador=0;contador<(quantidadeAluno);contador++){
                    if(matriculas[contador]!=0){
                        printf("\nNome:%s\tMatricula:%d\n",aluno[contador]->nome,matriculas[contador]);
                    }
                }
                for(contador=0;contador<(quantidadeMateria);contador++){
                    if(codigoDisciplina[contador]!=0){
                        printf("\nNome:%s\tCodDisciplina:%d\n",aluno[contador]->nome,codigoDisciplina[contador]);
                    }
                }
                
                printf("\nDigite a matricula do aluno: ");
                scanf("%d",&matriculaTemp);
                printf("Digite o codigo da disciplina: ");
                scanf("%d",&codDisciplinaTemp); 
                 if(codDisciplinaTemp<=0 || codDisciplinaTemp>codigoDisciplina[quantidadeMateria-1] || matriculaTemp<=0 || matriculaTemp>matriculas[quantidadeAluno-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(codigoDisciplina[contador]!=0 || matriculas[contador]!=0){
                        matricula_disciplina(aluno[matriculaTemp],disciplina[codDisciplinaTemp]);
                    }else{
                        printf("\nNAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==4){
            if(quantidadeMateria==0){
                printf("\nNao existe  Materias");
            }else{
                
            }
        }else if(codMenu==5){
            if(quantidadeAluno==0){
                printf("\nNao existe Aluno ");
            }else{
                
            }
        }else if(codMenu==6){
            if(quantidadeAluno==0){
                printf("\nNao existe Aluno ");
            }else{
                
            }
        }else if(codMenu==7){
            if(quantidadeMateria==0){
                printf("\nNao existe Materias");
            }else{
                
            }
        }else if(codMenu==0){
            
        }else{
            printf("\n\tCodigo nao encontrado\n");
        }
    }
}