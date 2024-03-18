#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int quantidadeElementos; // quantidade atual de elementos da pilha
    float* vetorArmazena; // vetor que armazena os dados da pilha
};

Pilha*pilha_cria(int *contador){
    Pilha*p=(Pilha*)malloc(sizeof(Pilha));
    if(p==NULL){
        printf("\nERRO NA ALOCACO DA PILHA\n");
        exit(1);
    }
    p->vetorArmazena=(float*)malloc(sizeof(float));
    if(p->vetorArmazena==NULL){
        printf("\nERRO NA ALOCACAO\n");
        exit(1);
    }
    p->quantidadeElementos=0;
    (*contador)++;
    return p;
}


void pilha_push(Pilha*p,float v,int *contador){
     if(p->quantidadeElementos >= *contador){
        p->vetorArmazena=(float *)realloc(p->vetorArmazena,(p->quantidadeElementos*2)*sizeof(float));
        p->vetorArmazena[p->quantidadeElementos] = v; // acessando o topo
        p->quantidadeElementos++;
        (*contador)*=2;
    }else{
        p->vetorArmazena[p->quantidadeElementos] = v; // acessando o topo
        p->quantidadeElementos++;
    }
}

int pilha_vazia(Pilha*p){
    return (p->quantidadeElementos==0); //retorna 0 para falso e diferente de 0 para verdade
}

float pilha_pop(Pilha*p, int *contador){
    float v;
    if(pilha_vazia(p)){
        printf("\nPilha Vazia\n");
        exit(1);
    }

    v=p->vetorArmazena[(p->quantidadeElementos -1)];
    p->vetorArmazena=(float*)realloc(p->vetorArmazena,(p->quantidadeElementos-1)*sizeof(float)); 
    (*contador)--;
    p->quantidadeElementos--; // reduzo a quantidade de elementos
    return v;
}

void pilha_imprimir(Pilha*p){
    int cont=0;
    for(cont=(p->quantidadeElementos-1);cont>=0;cont--){
        printf("\nValor:%.1f \n",p->vetorArmazena[cont]);
    }
}

void pilha_libera(Pilha*p){
    free(p);
}
