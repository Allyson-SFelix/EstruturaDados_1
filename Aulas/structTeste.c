#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[20];
    int idade;
    int matricula;
    char email[50];
};
struct professor{
    char nome[20];
    int idade;
    float salario;
    char email[50];
};
typedef struct funcPublico{
    char nome[20];
    int idade;
    float salario;
    char funcao[30];

}Funcionario;

void preencher(struct aluno *estudante,struct professor *professores, Funcionario *funcionario){    
    printf("Digite o nome do aluno: \n");
    scanf(" %[^\n]",estudante->nome);
    printf("Digite a idade do aluno: \n");
    scanf("%d",&estudante->idade);
    printf("Digite a matricula do aluno: \n");
    scanf("%d",&estudante->matricula);
    printf("Digite o email do aluno: \n");
    scanf(" %[^\n]",estudante->email);
    //
    printf("\n");
    printf("\n");
    //
    printf("Digite o nome do professor: \n");
    scanf(" %[^\n]",professores->nome);
    printf("Digite a idade do  professor: \n");
    scanf("%d",&professores->idade);
    printf("Digite o salario do  professor: \n");
    scanf("%f",&professores->salario);
    printf("Digite o email do  professor: \n");
    scanf(" %[^\n]", professores->email);
    //
    printf("\n");
    printf("\n");
    //
    printf("Digite o nome do Funcionario Publico: \n");
    scanf(" %[^\n]",funcionario->nome);
    printf("Digite a idade do Funcionario Publico: \n");
    scanf("%d",&funcionario->idade);
    printf("Digite o salario do Funcionario Publico: \n");
    scanf("%f",&funcionario->salario);
    printf("Digite a funcao do Funcionario Publico: \n");
    scanf(" %[^\n]", funcionario->funcao);
    printf("\n");

}

void imprimir(struct aluno *estudante,struct professor *professores,Funcionario * funcionario){
    printf("\nAlunos\n");
    printf("Nome: %s\nIdade: %d\nMatricula: %d\nEmail: %s",estudante->nome,estudante->idade,estudante->matricula,estudante->email);
    printf("\nProfessor");
    printf("Nome: %s\nIdade: %.2f\nSalario: %d\nEmail: %s",professores->nome,professores->idade,professores->salario,professores->email);
    printf("\nFuncionario Publico");
    printf("Nome: %s\nIdade: %.2f\nSalario: %d\nFuncao: %s",funcionario->nome,funcionario->idade,funcionario->salario,funcionario->funcao);
    
}   

int main(){
    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));
    if (estudante ==NULL){
        printf("Erros de memória");
        exit(1);
    }
    struct professor *professores = (struct professor*) malloc(sizeof(struct professor));
    if (professores ==NULL){
        printf("Erros de memória");
        exit(1);
    }
    Funcionario * funcionario =(Funcionario*)malloc(sizeof(Funcionario));
    if (funcionario ==NULL){
        printf("Erros de memória");
        exit(1);
    }
    preencher(estudante,professores,funcionario);
    imprimir(estudante,professores,funcionario);
    free(estudante);
    free(professores);
    free(funcionario);
    return 0;
}
