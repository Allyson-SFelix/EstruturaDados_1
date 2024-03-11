#include "contabancaria.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Contas**conta=NULL;
    int codMenu;
    int *numeroContas=malloc(sizeof(int));
    int quantidadeClientes=0;
    int *pontQuantidadeClientes=&quantidadeClientes;
    while(codMenu!=6){
        printf("\nBem vindo ao banco\n");
        printf("\nDigite 0 - - Criar Conta");
        printf("\nDigite 1 - - Depositar");
        printf("\nDigite 2 - - Sacar");
        printf("\nDigite 3 - - Transferir");
        printf("\nDigite 4 - - Saldo");
        printf("\nDigite 5 - - Excluir Conta");
        printf("\nDigite 6 - - Sair\n");
        scanf("%d",&codMenu);
        if(codMenu==0){
            char titularTemp[100];
            printf("\nDigite o nome do Titular da Conta: ");
            scanf(" %[^\n]s",titularTemp);
            printf("\nPARA ADICIONAR O SALDO DEVE FAZER UM DEPOSITO\n");
            (*pontQuantidadeClientes)++;
            conta=(Contas**)realloc(conta,(*pontQuantidadeClientes)*sizeof(Contas*));
            conta[(*pontQuantidadeClientes)-1]=criarConta(*pontQuantidadeClientes,titularTemp,0);
            numeroContas=realloc(numeroContas,(*pontQuantidadeClientes+1)*sizeof(int));
            numeroContas[(*pontQuantidadeClientes)-1]=*pontQuantidadeClientes;
        }
        else if(codMenu==1){
            if(quantidadeClientes==0){
                printf("\nNao ha conta nesse banco\n");
            }else{
                float saldoTemp=0.0;
                int contador=0,numeroContaTemp=0;
                for(contador=0;contador<(*pontQuantidadeClientes);contador++){
                 if(numeroContas[contador]!=0){
                        printf("\nNome:%s\tNumero Conta:%d\n",conta[contador]->titular,numeroContas[contador]);
                    }}
                printf("\nDigite o valor que almeja depositar: ");
                scanf("%f",&saldoTemp);
                printf("Digite o numero da conta que almeja depositar: ");
                scanf("%d",&numeroContaTemp); 
                if(numeroContaTemp<=0 || numeroContaTemp>numeroContas[(*pontQuantidadeClientes)-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(numeroContas[numeroContaTemp-1]!=0){
                        deposita(conta[numeroContaTemp-1],saldoTemp);
                    }else{
                        printf("\nCONTA NAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==2){
            if(quantidadeClientes==0){
                printf("\nNao ha conta nesse banco\n");
            }else{
                int contador=0;
                for(contador=0;contador<(*pontQuantidadeClientes);contador++){
                    printf("\nNome:%s\tNumero Conta:%d\n",conta[contador]->titular,numeroContas[contador]);
                }
                float saldoTemp=0.0;
                int numeroContaTemp=0;
                printf("\nDigite o valor que almeja sacar: ");
                scanf("%f",&saldoTemp);
                printf("\nDigite o numero da conta que almeja sacar: ");
                scanf("%d",&numeroContaTemp);
                if(numeroContaTemp<=0 || numeroContaTemp>numeroContas[(*pontQuantidadeClientes)-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(numeroContas[numeroContaTemp-1]!=0){
                        sacar(conta[numeroContaTemp-1],saldoTemp);
                    }else{
                        printf("\nCONTA NAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==3){
            if(quantidadeClientes==0){
                printf("\nNao ha conta nesse banco\n");
            }else{
                int contador=0;
                for(contador=0;contador<(*pontQuantidadeClientes);contador++){
                    printf("\nNome:%s\tNumero Conta:%d\n",conta[contador]->titular,numeroContas[contador]);
                }
                float saldoTemp=0.0;
                int contaOrigemTemp=0,contaDestinoTemp=0;
                printf("\nDigite o valor que almeja transferir: ");
                scanf("%f",&saldoTemp);
                printf("\nDigite o numero da conta que almeja retirar para transferir: ");
                scanf("%d",&contaOrigemTemp);
                printf("\nDigite o numero da conta que almeja receber o dinheiro na tranferencia: ");
                scanf("%d",&contaDestinoTemp);
                if(contaOrigemTemp<=0 || contaOrigemTemp>numeroContas[(*pontQuantidadeClientes)-1] || contaDestinoTemp<0 || contaDestinoTemp>numeroContas[(*pontQuantidadeClientes)-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                     if(numeroContas[contaDestinoTemp-1]!=0 || numeroContas[contaOrigemTemp-1]!=0){
                        transfere(conta[contaOrigemTemp-1],conta[contaDestinoTemp-1],saldoTemp);
                    }else{
                        printf("\nCONTA NAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==4){
            if(quantidadeClientes==0){
                printf("\nNao ha conta nesse banco\n");
            }else{
                int contador=0,numeroContaTemp=0;
                for(contador=0;contador<(*pontQuantidadeClientes);contador++){
                    if(numeroContas[contador]!=0){
                        printf("\nNome:%s\tNumero Conta:%d\n",conta[contador]->titular,numeroContas[contador]);
                    }
                }
                printf("\nDigite o numero da conta que almeja ver o saldo: ");
                scanf("%d",&numeroContaTemp);
                if(numeroContaTemp<=0 || numeroContaTemp>numeroContas[(*pontQuantidadeClientes)-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(numeroContas[numeroContaTemp-1]!=0){
                        printf("\n\tSaldo: RS%.2f",saldo(conta[numeroContaTemp-1]));
                    }else{
                        printf("\nCONTA NAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==5){
            if(quantidadeClientes==0){
                printf("\nNao ha conta nesse banco\n");

            }else{
                int contador=0,numeroContaTemp=0;
                for(contador=0;contador<(*pontQuantidadeClientes);contador++){
                    if(numeroContas[contador]!=0){
                        printf("\nNome:%s\tNumero Conta:%d\n",conta[contador]->titular,numeroContas[contador]);
                    }
                }
                printf("\nDigite o numero da conta que almeja excluir: ");
                scanf("%d",&numeroContaTemp);
                if(numeroContaTemp<=0 || numeroContaTemp>numeroContas[(*pontQuantidadeClientes)-1]){
                    printf("\nVoce digitou o numero que nao existe\n");
                }else{
                    if(numeroContas[numeroContaTemp-1]!=0){
                    excluiConta(conta,numeroContas,numeroContaTemp);
                    }else{
                        printf("\nCONTA NAO EXISTE\n");
                    }
                }
            }
        }else if(codMenu==6){
            printf("\nFechando programa\n");
            liberarMemoria(conta,(*pontQuantidadeClientes),numeroContas);
        }else{
            printf("\nOpcao invalida\n");
        }
    }
}