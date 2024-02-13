#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int numero;
}peixe;

//OU
struct aluno{
    char nome[30];
};

struct tatus{
    char nome[30];
};

void teste( struct  tatus *tatu){
    scanf(" %[^\n]",tatu->nome);
}

int main(){
    //Declaracao
    struct aluno estudante; // Quando usar struct
    peixe Peixe;        // Quando usar typedef struct
    
    //Modificacao
    Peixe.numero=12;    // metodo de chamar nos dois jeitos

    // Usando struct com ponteiro
    struct tatus * tatu=(struct tatus*)malloc(sizeof(struct tatus));
    // Acessar
    scanf("%s",tatu->nome);
    // parametro
    teste(tatu);
    printf("\n\n%s",tatu->nome);
    return 0;
}