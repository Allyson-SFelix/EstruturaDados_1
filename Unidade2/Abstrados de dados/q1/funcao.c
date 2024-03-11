/*Crie um TAD chamado ContaBancaria que possui os seguintes campos: titular,
número e saldo.


 Como operações, considere as seguintes:
Deposita:   recebe,   como   parâmetros,   o   endereço   de   uma   estrutura   do   tipo
ContaBancaria e um valor, atualizando o saldo;
Saca: recebe, como parâmetros, o endereço de uma estrutura do tipo ContaBancaria e
um valor, atualizando o saldo. Verificar se o saldo é suficiente para realizar o saque;
Transfere:   recebe,   como   parâmetros,   os   endereços   das   estruturas   do   tipo
ContaBancaria e um valor, atualizando os saldos. Verificar se o saldo é suficiente para
realizar a transferência;
Saldo: recebe o endereço de uma estrutura do tipo ContaBancaria e retorna seu saldo;
Exclui conta: libera o espaço alocado dinamicamente para a estrutura.
Faça o que se pede nos itens a seguir:
a) Crie um arquivo (contabancaria.h) com a interface do TAD.
b) Crie um arquivo (contabancaria.c) com a implementação do TAD.
c) Crie um programa que utiliza o TAD ContaBancaria.*/

#include "ContaBancaria.h"
#include <stdlib.h>
#include <stdio.h>


struct ContaBancaria{
    char titular[30];
    int numero;
    float saldo;
};

/*Cria conta: aloca dinamicamente uma estrutura do tipo ContaBancaria e retorna seu
endereço. Os campos titular, número e saldo devem ser fornecidos como parâmetros;
*/

Conta**criarConta(Conta**conta){
    Conta**conta=(Conta*)malloc(sizeof(Conta));
    if(conta==NULL)
        exit(1);


    return conta;
}