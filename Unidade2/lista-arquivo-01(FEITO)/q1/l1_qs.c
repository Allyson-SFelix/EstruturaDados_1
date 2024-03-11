#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define aprovado 7


int main(){
    FILE *arquivoPegar,*arquivoSaida;
    arquivoPegar=fopen("entrada_q3.txt","r");

    arquivoSaida=fopen("saida_q3.txt","w");

    if(arquivoPegar==NULL){
        printf("Erro na abartura de arquivo\n");
        exit(1);
    }
    if(arquivoSaida==NULL){
         printf("Erro na abartura de arquivo\n");
        exit(1);
    }

    char linha[50];
    char nome[25];
    float notas[3];
    float media;
    char situacao[20];
    // cada vez que roda o while e uma linha
    while(fgets(linha,100,arquivoPegar)!=NULL){ // pego linha por linha para quand chegar na ultima linha aparece NULL (vazio), passo para a variavel linha  os valores de cada linha, ate 100 linhas
        fscanf(arquivoPegar,"%25[^\t]\t%f\t%f\t%f",nome,&notas[0],&notas[1],&notas[2]); // pego string que mesmo com o espaco do tab ainda pego e depois as notas em floats
        // calcula media
        media=(notas[0]+notas[1]+notas[2])/3.0;
        
        // aprovado ou nao
        if(media>=aprovado){
            strcpy(situacao,"aprovado");
        }else{
            strcpy(situacao,"reprovado");
        }
        
        fprintf(arquivoSaida,"%s\t%f\t%s\n",nome,media,situacao); // escrevo os nomes, as notas e se passou ou nao
    }
    //
    fclose(arquivoSaida);
    fclose(arquivoPegar);

    return 0;

}
