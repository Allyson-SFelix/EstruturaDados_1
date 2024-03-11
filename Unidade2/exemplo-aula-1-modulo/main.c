#include <stdio.h>
#include "biblioteca.h"

int main(){
    float valor1,valor2;
    printf("Digite um numero: ");
    scanf("%f",&valor1);
    printf("Digite um numero: ");
    scanf("%f",&valor2);
    float resultSoma=soma(valor1,valor2);
    float resultSubt=subtracao(valor1,valor2);
    float resultMult=multiplicar(valor1,valor2);
    float resultDiv=divisao(valor1,valor2);
    printf("\nSoma: %.2f\nSubtracao: %.2f\nMultiplicar: %.2f\nDivisao: %.2f\n",resultSoma,resultSubt,resultMult,resultDiv);
    return 0;
}