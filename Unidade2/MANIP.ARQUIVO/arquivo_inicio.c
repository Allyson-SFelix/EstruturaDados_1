#include <stdlib.h>
#include <stdio.h>


//FILE fopen(char*nome_arquivo,char modo);


int main(){
    FILE *arquivo=fopen("nome.txt","wt");
    if(arquivo==NULL){
        printf("Erro na abartura de arquivo\n");
        exit(1);
    }else{
        printf("printou");
    }
    if(fclose(arquivo)){ //retorna um inteiro diferente de 0
        printf("Fechado");
    }// else retorna EOF

    // funcoes para ler dados
    //int fscanf(FILE* fp, char*formato); // pega um ponteiro de arquivo e ...
    //int fgetc(FILE* fp); // pega um caracter
    //int fgets(char *s,int n,FILE* fp); // ... , tamanho da string,ponteiro do arquivo


    //  MODOS
    // leitura (r)
    // Escrever (w)
    // Escrita no final do texto existente (append)
    // Texto (t)
    // Binario (b)

    return 0;
}
