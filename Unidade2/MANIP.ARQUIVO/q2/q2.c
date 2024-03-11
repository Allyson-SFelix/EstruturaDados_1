#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *arquivoPegar,*arquivoSaida;
    arquivoPegar=fopen("banco_q2.txt","r");

    arquivoSaida=fopen("saida_q2.txt","w");

    if(arquivoPegar==NULL){
        printf("Erro na abartura de arquivo\n");
        exit(1);
    }
    if(arquivoSaida==NULL){
         printf("Erro na abartura de arquivo\n");
        exit(1);
    }

    char linhas[50];
    int vetor[10];
    int i=0;

    while(fgets(linhas,50,arquivoPegar)!=NULL){
        fscanf(arquivoPegar,"%d\n",vetor[i]);

        fprintf(arquivoSaida,"%d\n",vetor[i]);
        i++;
    }


    fclose(arquivoPegar);
    fclose(arquivoSaida);
}
