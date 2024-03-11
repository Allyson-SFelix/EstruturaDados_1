#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *arquivo=fopen("entrada.txt","w");
    if(arquivo==NULL){
        printf("Erro na abertura de arquivo\n");
        exit(1);
    }else{
        printf("\nprintou");
    }

    fputc('A',arquivo); //ESCREVER UM CARACTER ->ASPAS SIMPLES
    fputs("\nHello world",arquivo); // ESCREVER UMA STRING
    fprintf(arquivo,"\nMeu texto!"); // ESCREVER UMA STRING

    if(fclose(arquivo)){ //retorna um inteiro diferente de 0
        printf("Fechado");
    }// else retorna EOF
    
    return 0;
}
