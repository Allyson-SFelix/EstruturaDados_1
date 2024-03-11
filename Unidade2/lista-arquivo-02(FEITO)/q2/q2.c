/*Implemente um programa em C para ler o nome e as notas de um n ́umero N de alunos e armazen ́a-los
em um arquivo.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    float notas[3];
}Aluno;


int main(){
    FILE* alunos=fopen("alunos.txt","wt");
    if(alunos==NULL){
        exit(1);
    }

    int numeroAlunos=0;
    printf("\nDigite a quantidade de alunos: ");
    scanf("%d",&numeroAlunos);

    Aluno *aluno=(Aluno*)malloc(numeroAlunos*sizeof(Aluno*));
    if(aluno==NULL)
        exit(1);
    
    int i=0,a=0;
    for(i=0;i<numeroAlunos;i++){
        printf("\nDigite o nome do aluno:");
        scanf(" %[^\n]s",aluno[i].nome);
        for(a=0;a<3;a++){
            printf("\nDigite a nota %d do(a) %s:",a+1,aluno[i].nome);
            scanf("%f",&aluno[i].notas[a]);
        }
    }

    for(i=0;i<numeroAlunos;i++){
        fprintf(alunos,"\nNome:%s",aluno[i].nome);
        for(a=0;a<3;a++)
            fprintf(alunos,"\tnota %d: %.2f",a+1,aluno[i].notas[a]);    
    }

    fclose(alunos);
    free(aluno);
    return 0;
}
