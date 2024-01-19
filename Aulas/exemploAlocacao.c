#include <stdlib.h> //biblioteca de alocacao dinamica(malloc,calloc,free,exit)
#include <stdio.h>
#include <string.h> //biblioteca de manipualcao de string 


int main(){
    char *nome = (char *) malloc(50*sizeof(char));
    if(nome==NULL){
        exit(1);
    }
    printf("Digite o seu nome: ");
    scanf("%[^\n]",nome); // ->[^\n] -> enquanto tiver espacamento continua armazenando

    int tamanho=strlen(nome);

    nome = (char *) realloc(nome,tamanho*sizeof(char));
    if(nome==NULL){
        exit(1);
    }
    printf("Seu nome completo: %s",nome);

    free(nome);
    return 0;
}