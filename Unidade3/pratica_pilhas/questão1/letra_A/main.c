#include "pilha.h"
#include <stdio.h>

int main(){
    float valor=0.0;
    int cont=0,numeroDados=0,contVetor=0;
    int *contadorVetor=&contVetor;
    Pilha*pilha=pilha_cria(contadorVetor);
    printf("\nDigita a quantidade de dados que voce almeja inserir : ");
    scanf("%d",&numeroDados);
    while(cont<numeroDados){
        printf("\nDigite os valores:");
        scanf("%f",&valor);
        pilha_push(pilha,valor,contadorVetor);
        cont++;
    }
    
    float valorTopo=pilha_pop(pilha,contadorVetor);

    printf("\nValor: %.2f\n",valorTopo);
    
    pilha_imprimir(pilha);
    
    pilha_libera(pilha);
    return 0;
}