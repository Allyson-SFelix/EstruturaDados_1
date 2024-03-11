#include <stdlib.h>
#include <stdio.h>
#include "ingresso.h"

struct ingresso{
    float preco;
    char local[30];
    char atracao[20];
};

void preenche(Ingresso* i){
    
    // LETRA A
    printf("\nDigite o preco do ingresso: ");
    scanf("%f",&i->preco);
    printf("\nDigite o local da atracao: ");
    scanf(" %[^\n]",i->local);
    printf("\nDigite a atracao: ");
    scanf(" %[^\n]",i->atracao);
}

void imprime(Ingresso* i){
    // LETRA B
    printf("\nLocal:%s\nAtracao: %s\nPreco do ingresso: RS%.2f\n",i->local,i->atracao,i->preco);
}

void altera_preco(Ingresso* i, float valor){
   // LETRA C
    i->preco=valor;
}

void imprime_menor_maior_preco(int n, Ingresso *vet){
/*Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
n, Ingresso* vet);*/
    int i=0;
    int maiorId=0;
    int menorId=0;
    for(i=0;i<n;i++){
        if(vet[i].preco>vet[maiorId].preco){
            maiorId=i;
        }
        if(vet[i].preco<vet[menorId].preco){
            menorId=i;
        }
    }
    printf("\nO ingresso mais barato-\nvalor do ingresso: RS%.2f\nlocal:%s\natracao: %s\n",vet[menorId].preco,vet[menorId].local,vet[menorId].atracao);
    
    printf("\nO ingresso mais caro -\nvalor do ingresso: RS%.2f\nlocal:%s\natracao: %s\n",vet[maiorId].preco,vet[maiorId].local,vet[maiorId].atracao);
}

void liberarMemoria(Ingresso**ingresso,int qtd){
    int i =0;
    for(i=0;i<qtd;i++){
        free(ingresso[i]);
    }
    free(ingresso);
}

Ingresso**receberDadosIniciais(Ingresso**ingresso,int *quantidadeIngressos){
    printf("\nDigite a quantidade de ingressos vendidos:");
    scanf("%d",quantidadeIngressos);
    // realocando um novo espaço de memoria, criando um vetor de struct
    ingresso=(Ingresso **)malloc((*quantidadeIngressos)*sizeof(Ingresso*));
    if(ingresso==NULL){
        printf("erro alocacao\n");
        exit(1);
    }

     // como foi pedido apenas na letra anterior da letra que criou o vetor será [0]
        //
   
    // preparos para funcionar a letra d)
    int i=0;
    for(i=0;i<(*quantidadeIngressos);i++){
        ingresso[i]=(Ingresso *)malloc(sizeof(Ingresso));
        if(ingresso==NULL){
            printf("erro alocacao\n");
            exit(1);
        }
        preenche(ingresso[i]);
        imprime(ingresso[i]);        
        printf("\n Digite o novo valor do ingresso:\n");
        float novoPreco=0.0;
        scanf("%f",&novoPreco);
        altera_preco(ingresso[0], novoPreco);
    }
    for(i=0;i<(*quantidadeIngressos);i++){
        imprime_menor_maior_preco(*quantidadeIngressos, ingresso[i]);
    //
    //  
        return ingresso;
    }
}