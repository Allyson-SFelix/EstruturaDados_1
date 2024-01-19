// dados de um funcionario
//struct -> nome,salario,identificador e cargo

//letra A 
// funcao que recebe ponteiro de struct de Funcionario
// pedir para o usuario inserir os dados

//letra B
// funcao para imprimir os dados

//letra C
// funcao para alterar salario

// letra D
// criar um vetor no struct e comparar os salarios e mostrar o menor e maior alem dos cargos

#include <stdlib.h>
#include <stdio.h>

struct Funcionario{
    char nome[50];
    float salario;
    int ident;
    char cargo[20];
};
void receberDados(struct Funcionario * funcionario,int numeroFuncionario);
void mostrarDados(struct Funcionario * funcionario,int numeroFuncionario);
void mudancaSalario(struct Funcionario* funcionario,int numeroFuncionario);
void salariosPodio(struct Funcionario * funcionario,int numeroFuncionario,int quantFuncionario);

void receberDados(struct Funcionario * funcionario,int numeroFuncionario){
    printf("Escreva o nome do Funcionario: ");
    scanf(" %[^\n]",funcionario[numeroFuncionario].nome);
    printf("Escreva o salario do Funcionario: ");
    scanf("%f",&funcionario[numeroFuncionario].salario);
    printf("Escreva a identificacao do Funcionario: ");
    scanf("%d",&funcionario[numeroFuncionario].ident);
    printf("Escreva o cargo do Funcionario: ");
    scanf(" %[^\n]",funcionario[numeroFuncionario].cargo);
}
void mostrarDados(struct Funcionario * funcionario,int numeroFuncionario){
    printf("\nMostrando os dados:\nNumero do funcionario:%d\nO nome do Funcionario: %s\nO salario do Funcionario: RS%.2f\nA identificacao do Funcionario: %d\nO cargo do Funcionario: %s\n",numeroFuncionario+1,funcionario[numeroFuncionario].nome,funcionario[numeroFuncionario].salario,funcionario[numeroFuncionario].ident,funcionario[numeroFuncionario].cargo);
}
void mudancaSalario(struct Funcionario* funcionario,int numeroFuncionario){
    printf("Digite o novo valor do salario, do funcionario de numero %d: ",numeroFuncionario+1);
    scanf("%f",&funcionario[numeroFuncionario].salario);
}

void salariosPodio(struct Funcionario * funcionario,int numeroFuncionario,int quantFuncionario){
    int i=0,x=0,indiceMaior=0,indiceMenor=0;
    // indice maior
    for(i=0;i<quantFuncionario;i++){
        if(funcionario[i].salario>funcionario[indiceMaior].salario){
            indiceMaior=i;
        }
    }
    for(i=0;i<quantFuncionario;i++){
        if(funcionario[i].salario<funcionario[indiceMenor].salario){
            indiceMenor=i;
        }
    }
    
    if(indiceMaior==indiceMenor){
        printf("Salarios Iguais");
    }else{
        printf("\nO funcionario de maior salario e do cargo %s com o salario de RS%.2f\n",funcionario[indiceMaior].cargo,funcionario[indiceMaior].salario);
        printf("\nO funcionario de menor salarioe do cargo %s com o salario de RS%.2f\n",funcionario[indiceMenor].cargo,funcionario[indiceMenor].salario);
    }
}


int main(){
    printf("Digite a quantidade de funcionarios:\n");
    int quantFuncionario=0,numeroFuncionario=0;
    scanf("%d",&quantFuncionario);
    //
    // aloca a memoria do endereco do ponteiro do struct
    struct Funcionario *funcionario=(struct Funcionario*) malloc(quantFuncionario*sizeof(struct Funcionario));
    if (funcionario==NULL){
        printf("ERRO na ALOCACAO DE MEMORIA\n");
        exit(1);
    }
    //
    for(numeroFuncionario=0;numeroFuncionario<quantFuncionario;numeroFuncionario++){
        //
        receberDados(funcionario,numeroFuncionario);
        mostrarDados(funcionario,numeroFuncionario);
        //
        printf("\nVoce deseja alterar o salario deste funcionario?\nDigite 0 - - Sim\n");
        int opcaoSalario=0;
        scanf("%d",&opcaoSalario);
        if(opcaoSalario==0){
            mudancaSalario(funcionario,numeroFuncionario);
            mostrarDados(funcionario,numeroFuncionario);
        }
        //
        if(numeroFuncionario!=quantFuncionario-1){
            printf("Deseja cadastrar outro funcionario?:\n0 - - Para sim ");
            int novoCadastro=0;
            scanf("%d",&novoCadastro);
            if(novoCadastro!=0){
               numeroFuncionario=quantFuncionario;
            }
        }
    }
    //
    salariosPodio(funcionario,numeroFuncionario,quantFuncionario);
    //
    printf("\nFINALIZANDO\n");
    //
    free(funcionario);
    //
    return 0;
}