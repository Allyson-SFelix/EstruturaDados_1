#include <stdlib.h>
#include <stdio.h>

void respostas(int *pergunta1,int *pergunta2,int numeroPessoa);
void calcularMostrar(int numeroPessoa,int quantidadeEntrevistas,int *pergunta1,int *pergunta2);

void calcularMostrar(int numeroPessoa,int quantidadeEntrevistas,int *pergunta1,int *pergunta2){
    int i=0,x=0;
    int quantidadeMulher=0;
    int quantidadeHomem=0;
    int mulherGosta=0;
    int homemNaoGosta=0;
    for(i=0;i<quantidadeEntrevistas;i++){
            if(pergunta1[i]==2){
                quantidadeMulher++;
                if(pergunta2[i]==3){
                    mulherGosta++;
                }
            }else if(pergunta1[i]==1){
                quantidadeHomem++;
                if(pergunta2[i]==4){
                    homemNaoGosta++;
                }
            }
    }
    float porcMulher=(mulherGosta/quantidadeMulher)*100;
    float porcHomem=(homemNaoGosta/quantidadeHomem)*100;

    printf("Mulher porcentagem que gosta= %.2f",porcMulher);
    printf("Homem porcentagem que nao gosta= %.2f",porcHomem);

}

void respostas(int *pergunta1,int *pergunta2,int numeroPessoa){
    printf("\nDigite 1 - - Para Masculino\nDigite 2 - - Para Feminino\n->");
    scanf("%d",&pergunta1[numeroPessoa]);
    if(pergunta1[numeroPessoa]==1 || pergunta1[numeroPessoa]==2){
        printf("\nDigite 3 - - Se Gostou do produto\nDigite 4 - - Se Nao ostou do produto\n->");
        scanf("%d",&pergunta2[numeroPessoa]);
        if(pergunta2[numeroPessoa]!=3 && pergunta2[numeroPessoa]!=4){
            respostas(pergunta1,pergunta2,numeroPessoa);
        }
    }else{
        respostas(pergunta1,pergunta2,numeroPessoa);
    }
}

int main(){
    printf("Digite a quantidade de entrevistas: ");
    int quantidadeEntrevistas=0;
    scanf("%d",&quantidadeEntrevistas);

    int *pergunta1=(int*)malloc(quantidadeEntrevistas*sizeof(int));
    int *pergunta2=(int*)malloc(quantidadeEntrevistas*sizeof(int));
    if(pergunta1==NULL || pergunta2==NULL){
        printf("erro na alocacao de memoria\n");
        exit(1);
    }

    int numeroPessoa=0;
    
    for(numeroPessoa=0;numeroPessoa<quantidadeEntrevistas;numeroPessoa++){
        //
        respostas(pergunta1,pergunta2,numeroPessoa);
        //
        if(numeroPessoa!=quantidadeEntrevistas-1){
            printf("Voce deseja continuar a entrevista:\nDigite 1 - - Sim\n->");
            int continuar=0;
            scanf("%d",&continuar);
            if(continuar!=1){
                numeroPessoa=quantidadeEntrevistas;
            }
        }
    }
    //
    calcularMostrar(numeroPessoa,quantidadeEntrevistas,pergunta1,pergunta2);   
    //
    free(pergunta1);
    free(pergunta2);
    //
    return 0;  
}