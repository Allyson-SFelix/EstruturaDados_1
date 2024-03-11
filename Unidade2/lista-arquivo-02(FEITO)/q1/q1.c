/*Fa ̧ca um programa em C que solicita ao usuario informacoes de funcionarios via teclado. As in-
forma ̧c ̃oes digitadas pelo o usu ́ario s ̃ao: id, nome e sal ́ario do funcion ́ario. Armazene as informa ̧c ̃oes
digitadas pelo usu ́ario em um arquivo texto
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[25];
    float salario;
}Funcionario;

int main(){
    FILE *dadosFuncionario=fopen("funcionarios.txt","wt");
    if(dadosFuncionario==NULL){
        exit(1);
    }
    Funcionario funcionario;
    printf("\nDigite o nome do funcionarios: ");
    scanf(" %[^\n]",funcionario.nome);

    printf("\nDigite o ID do funcionario: ");
    scanf("%d",&funcionario.id);

    printf("\nDigite o salario do funcionarios: ");
    scanf("%f",&funcionario.salario);

    fprintf(dadosFuncionario,"Nome: %s\tId:%d\tSalario:RS%.02f",funcionario.nome,funcionario.id,funcionario.salario);

    fclose(dadosFuncionario);
    return 0;
}
