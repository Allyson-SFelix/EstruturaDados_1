#include <stdlib.h>
#include <stdio.h>


//FILE fopen(char*nome_arquivo,char modo);


int main(){
    FILE *arquivo=fopen("nome.txt","r");
    if(arquivo==NULL){
        printf("Erro na abartura de arquivo\n");
        exit(1);
    }else{
        printf("printou\n");
    }

    //int lerCaracter= fgetc(arquivo); 
    //printf("%c",lerCaracter);

    char string[20];
    fgets(string,20,arquivo);
    printf("%s\n",string);

    if(fclose(arquivo)){ //retorna um inteiro diferente de 0
        printf("Fechado\n");
    }// else retorna EOF

    //  MODOS
    // leitura (r)
    // Escrever (w) 
    // Escrita no final do texto existente (append)
    // Texto (t)
    // Binario (b)

    return 0;
}
