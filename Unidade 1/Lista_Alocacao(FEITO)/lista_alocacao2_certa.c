#include <stdio.h>
#include <stdlib.h>


int main(){
    // quantidade de questoes
    int quantidadeQuestoes=0;
    printf("Digite a quantidade de questoes: ");
    scanf("%d",&quantidadeQuestoes);
    if(quantidadeQuestoes!=0){
        //
        // Gabarito
        char *gabarito = (char *)malloc(quantidadeQuestoes*sizeof(char));
        if(gabarito==NULL){
            exit(1);
        }
        //
        // PEGANDO GABARITO
        printf("\nDigite cada alternativa certa para as questoes:\n");
        int i=0;
        for(i=0;i<quantidadeQuestoes;i++){
            printf("\nResposta da %d",i+1);
            scanf(" %c",&gabarito[i]);
        }
        //
        // RESPOSTA
        char **matrizResposta=(char **)malloc(10*sizeof(char*)); 
        if(matrizResposta==NULL){
            exit(1);
        }
        int coluna=0;
        for(coluna=0;coluna<10;coluna++){
            matrizResposta[coluna]=(char *)malloc(quantidadeQuestoes*sizeof(char));
            if(matrizResposta[coluna]==NULL){
            exit(1);
            }
        }
        //
        // PEGAR RESPOSTA DE 10 ALUNOS
        int a,b=0;
        for(b=0;b<10;b++){
            for(a=0;a<quantidadeQuestoes;a++){
                printf("\nAluno %d\nDigite a resposta da questão %d\n",b+1,a+1);
                scanf(" %c",&matrizResposta[b][a]); 
            }
        }
        //
        // NOTA DOS ALUNOS
        float *notaDosAlunos=(float *)malloc(10*sizeof(float));
        if(notaDosAlunos==NULL){
            exit(1);
        }
        //
        // COMPARAR QUESTÕES / NOTAS
        int x=0;
        for(x=0;x<10;x++){
            int soma=0;
            for(i=0;i<quantidadeQuestoes;i++){    
                if(matrizResposta[x][i]==gabarito[i]){
                    soma++;
                }
            }
            notaDosAlunos[x]=soma*(10/quantidadeQuestoes);
        }
        //
        // PORCENTAGEM DE APROVAÇÃO 
        int totalAprovados=0;
        for(i=0;i<10;i++){
            printf("\nNota do Aluno %d é %.1f\n",i,notaDosAlunos[i]);
            if(notaDosAlunos[i]>=6){
                totalAprovados++;
            }
        }
        float porcAprovados=((float)totalAprovados/10.0)*100;
        printf("A porcentagem de aprovacao foi de %.2f porcento\n",porcAprovados);
        //
        //
        // free
        free(notaDosAlunos);
        free(gabarito);
        for(coluna=0;coluna<quantidadeQuestoes;coluna++){
            free(matrizResposta[coluna]);
        }
        free(matrizResposta);
    }else{
        printf("Nao existe prova");
    }
    return 0;
}