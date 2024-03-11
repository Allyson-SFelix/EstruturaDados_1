#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *arquivoPegar=fopen("dados.txt","rt");
    FILE *arquivoSaida=fopen("saida_q2.txt","wt");

    if(arquivoPegar==NULL){
        printf("Erro na abertura de arquivo1\n");
        exit(1);
    }
    if(arquivoSaida==NULL){
        printf("Erro na abertura de arquivo2\n");
        exit(1);
    }

    int vetor[10];
    int i=0;

    for(i=0;i<10;i++){
        fscanf(arquivoPegar,"%d",&vetor[i]);
    }

    int maior=0,menor=0,soma=0;
    float media;
    for(i=0;i<10;i++){
        if(vetor[i]>vetor[maior]){
            maior=i;
        }else if(vetor[i]<vetor[menor]){
            menor=i;
        }
        soma+=vetor[i];
    }

    media=soma/10.0;

    fprintf(arquivoSaida,"Menor:%d\nMaior:%d\nMedia:%.2f",vetor[menor],vetor[maior],media);

    fclose(arquivoPegar);
    fclose(arquivoSaida);

    return 0;
}
