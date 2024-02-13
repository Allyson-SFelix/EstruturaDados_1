#include <stdio.h>

int soma(int n1,int n2){
    return n1+n2;
}

int subtrair(int n1,int n2){
    return n1-n2;
}
int multiplicacao(int n1,int n2){
    return n1*n2;
}
int divisao(int n1,int n2){
    return n1/n2;
}

int calcular(int n1,int n2,int (*operacao)(int,int)){
    return (*operacao)(n1,n2);
}

int main(){
    // usar char + sequencia de if
    int num1,num2=0;
    
    printf("Digite um numero: ");
    scanf("%d",&num1);
    printf("Digite outro numero: ");
    scanf("%d",&num2);
    
    int resultado= calcular(num1,num2,soma);
    printf("\nNumeros %d e %d\n\nResultado da Soma= %d\n",num1,num2,resultado);
    
    resultado= calcular(num1,num2,subtrair);
    printf("\nResultado da Subtracao= %d\n",resultado);
    
    resultado= calcular(num1,num2,multiplicacao);
    printf("\nResultado da Multiplicacao= %d\n",resultado);
    
    resultado= calcular(num1,num2,divisao);
    printf("\nResultado da Divisao= %d\n\n",resultado);

    return 0;
}