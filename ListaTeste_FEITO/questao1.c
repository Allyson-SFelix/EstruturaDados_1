#include <stdio.h>
#include <stdlib.h>

void criacaoArray(int vetor[],int num){
    for(int i=0;i<num;i++){
        vetor[i]=i;
    }
    
}
void invertendoArray(int vetor[],int num){
    int valorComparacao = (num/2);
    int copiaN=num-1;
    for(int i=0;i<valorComparacao;i++){
        int auxiliar=vetor[i];
        vetor[i]=vetor[copiaN];
        vetor[copiaN]=auxiliar;
        copiaN--;
    }
}
void mostrar(int vetor[],int num){
    for(int i=0;i<num;i++){
        printf("%d\n",vetor[i]);
    }
}
int main(){
    printf("Escreva a quantidade de numeros para o vetor\n");
    int n=0;
    scanf("%d",&n);
    int array[n];
    criacaoArray(array,n);
    invertendoArray(array,n);
    mostrar(array,n);
    return 0;
}