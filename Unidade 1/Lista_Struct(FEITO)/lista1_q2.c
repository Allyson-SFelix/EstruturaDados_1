#include <stdlib.h>
#include <stdio.h>

struct Pessoa{
    char nome[40];
    int identidade;
    int idade;
};

void receberDados(struct Pessoa * pessoa,int numeroPessoas);
void mudarIdade(struct Pessoa * pessoa,int numeroPessoas);
void mostrarDados(struct Pessoa * pessoa,int numeroPessoas);
void velhaNova(struct Pessoa*pessoa, int quantPessoas);

void receberDados(struct Pessoa * pessoa,int numeroPessoas){
    printf("\nEscreva o nome da pessoa: ");
    scanf(" %[^\n]",pessoa[numeroPessoas].nome);
    printf("\nEscreva a idade da pessoa: ");
    scanf("%d",&pessoa[numeroPessoas].idade);
    printf("\nEscreva o identidade da pessoa: ");
    scanf("%d",&pessoa[numeroPessoas].identidade);
}

void mudarIdade(struct Pessoa * pessoa,int numeroPessoas){
    printf("\nDigite a nova idade da pessoa: ");
    scanf("%d",&pessoa[numeroPessoas].idade);
}

void mostrarDados(struct Pessoa * pessoa,int numeroPessoas){
    printf("\nO nome da Pessoa de numero %d\nNome: %s\nCPF: %d\nIdade: %d\n",numeroPessoas+1,pessoa[numeroPessoas].nome,pessoa[numeroPessoas].identidade,pessoa[numeroPessoas].idade);
}

void velhaNova(struct Pessoa*pessoa, int quantPessoas){
    int i=0,velha=0,nova=0;
    for(i=0;i<quantPessoas;i++){
        if(pessoa[i].idade>pessoa[velha].idade){
            velha=i;
        }
    }
    for(i=0;i<quantPessoas;i++){
        if(pessoa[i].idade<pessoa[nova].idade){
            nova=i;
        }
    }
    if(nova==velha){
        printf("\nAs pessoas tem de idades iguais;\n");
    }else{
        printf("\nA pessoa mais velha tem %d anos\n\nA pessoa mais nova tem %d anos\n",pessoa[velha].idade,pessoa[nova].idade);
    }
}

int main(){
    //
    //pedindo quantidade de vetor
    printf("Digite a quantidade de pessoas: ");
    int quantPessoas=0,numeroPessoas=0;
    scanf("%d",&quantPessoas);
    //
    //alocando
    struct Pessoa *pessoa=(struct Pessoa*)malloc(quantPessoas*sizeof(struct Pessoa));
    if(pessoa==NULL){
        printf("Erro na alocacao da memoria");
        exit(1);
    }
    //
    //
    for(numeroPessoas=0;numeroPessoas<quantPessoas;numeroPessoas++){
        //recebendo dados
        receberDados(pessoa,numeroPessoas);
        //
        // mudar idade
        printf("\nDeseja alterar a idade dessa pessoa?\n 1 - - Sim: ");
        int idadeAlterar=0;
        scanf("%d",&idadeAlterar);
        if(idadeAlterar==1){
            mudarIdade(pessoa,numeroPessoas);
        }
        //
        //mostrando dados
        mostrarDados(pessoa,numeroPessoas);
        //    
        // deseja add mais pessoas
        if(numeroPessoas!=quantPessoas-1){
            printf("\nDeseja adicionar mais pessoas?\n1 - - Sim: ");
            int addPessoas=0;
            scanf("%d",&addPessoas);
        if(addPessoas!=1){
            numeroPessoas=quantPessoas;
        }       
        }
        
    }   
    //
    //nome da pessoa mais velha e mais nova
    velhaNova(pessoa,quantPessoas);
    //
    //
    printf("\nFinalizando\n");
    //
    //liberando memoria
    free(pessoa);
    //
    //return
    return 0;
}
