#include <stdlib.h>
#include <stdio.h>

//alinhamento de estrutura -> strcut com outro struct dentro

//-> toda vez que for declarar um ponteiro para struct tem de alocar a memoria

// unsigned -> pesquisar

typedef struct disciplina{
    char nome[20];
    float nota;
    int codigo;
}Disciplina;

typedef struct aluno{
    char nome[20];
    int idade;
    int matricula;
    Disciplina * materia; //(aninhamento da estrutura disciplina na estrutura aluno)
}Aluno;

int main(){
    /*
    Aluno aluno;
    aluno.idade=18;
    aluno.matricula=2023011215;
    aluno.materia[0].codigo=1234;
    printf("%d\n%d\n%d",aluno.idade,aluno.matricula,aluno.materia[0].codigo);
    */
    Aluno * aluno=(Aluno *)malloc(sizeof(Aluno));
    if(aluno==NULL){
        printf("erro alocacao\n");
        exit(1);
    }
    //
    aluno->materia=(Disciplina *)malloc(2*sizeof(Disciplina)); //alocando a struct dentro da struct com 2 de vetor
    if(aluno->materia==NULL){
        printf("erro alocacao\n");
        exit(1);
    }
    //
    printf("Digite nome\nmatricula\nidade\n");
    scanf("%[^\n]",aluno->nome);
    scanf("%d \n %d",aluno->idade,aluno->matricula);
    //
    int i;
    for(i=0;i<2;i++){
        printf("Disciplinas na posicao %d",i+1);
        scanf("%[^\n]",aluno->materia[i].nome);
        scanf("%d",&aluno->materia[i].codigo);
        scanf("%d",aluno->materia[i].nota);
    }
    //
    free(aluno->materia);
    free(aluno);
    //
    return 0;
}