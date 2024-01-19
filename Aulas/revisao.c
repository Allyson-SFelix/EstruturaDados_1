//02. Escreva uma função que receba duas strings como entrada e retorne uma nova string que seja a concatenação das duas. 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Disciplina{
    char nome[20];
    int codMateria;
}Disciplina;

typedef struct Aluno{
    char nome[15];
    int idade;
    Disciplina *materias;
}Aluno;

struct Puta{
    int idade;
};

int main(){ 
    struct Puta * puta=(struct Puta*)malloc(sizeof(struct Puta));

    int i=0;
    int linha=4,coluna=4;
    int **matriz=(int **)calloc(linha,sizeof(int *));
    for(i=0;i<linha;i++){
        matriz[i]=(int *)calloc(coluna,sizeof(int));
    }
    
    printf("Digite o valor ");
    scanf("%d",*(*(matriz+3)+2));
    scanf("%d",matriz[3][2]);

    Aluno *aluno=(Aluno *)malloc(sizeof(Aluno));   
    if(aluno==NULL){
        exit(1);
    }
    aluno->materias=(Disciplina*)malloc(7*sizeof(Disciplina));
    
    if(aluno->materias==NULL){
        exit(1);
    }


    for(i=0;i<linha;i++){
        free(matriz[i]);
    }
    free(aluno->materias);
    free(aluno);
    free(matriz);
   return 0;
}