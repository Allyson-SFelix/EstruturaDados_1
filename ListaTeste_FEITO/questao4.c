// receba dois numeros de parametro e retorne a soma dos N numeros 
// inteiros existentes entre eles


# include <stdlib.h>
# include <stdio.h>
int somaDosInternos(int n1,int n2){
    int numeroInicial= (n1+1);
    int resultadoSoma=0;
    for(int i=numeroInicial;i<n2;i++){
        resultadoSoma+=i ;
    }
    return resultadoSoma;
}
int main(){
    int num1,num2=0;
    printf("Digite o primeiro numero: ");
    scanf("%d",&num1);
    printf("\nDigite o segundo numero: ");
    scanf("%d",&num2);
    int resultado=somaDosInternos(num1,num2);
    printf("O Resultado da soma dos numeros inteiros entre %d e %d = %d",num1,num2,resultado);
    return 0;
}