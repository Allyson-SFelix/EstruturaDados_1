#include "contabancaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Contas * criarConta(int numCliente,char titular[100],float saldo){
    Contas *conta=(Contas*)malloc(sizeof(Contas));
    strcpy(conta->titular,titular);
    conta->saldo=0.0;
    conta->numero=numCliente;
    return conta;   
}

void deposita(Contas * conta,float valor){
    conta->saldo+=valor;
}

void sacar(Contas*conta,float valor){
    if(conta->saldo<valor){
        printf("\nSaldo insuficiente\n");
    }else{
        conta->saldo-=valor;
    }
}

void transfere(Contas*contaOrigem,Contas*contaDestino,float valor){
    if(contaOrigem->saldo<valor){
        printf("\nSaldo insuficiente\n");
    }else{
        contaOrigem->saldo-=valor;
        contaDestino->saldo+=valor;
    }
}

float saldo(Contas*conta){
    return conta->saldo;
}

void excluiConta(Contas**conta,int *numeroContas,int indiceApagar){
    numeroContas[indiceApagar-1]=0;
    free(conta[indiceApagar-1]);
}

void liberarMemoria(Contas**conta, int quantidade, int*numeroContas){
    int contador=0;
    for(contador=0;contador<quantidade;contador++){
        if(numeroContas[contador]!=0){
            free(conta[contador]);
        }
    }
    free(conta);
}