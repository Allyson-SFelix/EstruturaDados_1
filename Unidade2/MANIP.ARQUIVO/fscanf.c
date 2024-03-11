#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *arquivo=fopen("nome.txt","r");
    if(arquivo==NULL){
        printf("Erro na abartura de arquivo\n");
        exit(1);
    }else{
        printf("printou");
    }

    char texto[20];
    fscanf(arquivo,"%s",texto);
    printf("%s",texto);

    if(fclose(arquivo)){ //retorna um inteiro diferente de 0
        printf("Fechado");
    }// else retorna EOF
    
    return 0;
}
