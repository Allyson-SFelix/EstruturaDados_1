/*Escreva um programa que implementa uma struct Data com os campos dia, m^es e ano. O m^es deve
ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC¸O, ABRIL, MAIO,
JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
deve ler a data e imprimir a data no formato dd/mm/aaaa */

#include <stdlib.h>
#include <stdio.h>

typedef enum{
    JANEIRO=01,FEVEREIRO, MARCO, ABRIL, MAIO,
JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO,DEZEMBRO
}Mes;


typedef struct{
    int ano;
    int dia;
    Mes mes;
}Data;

void receberDados(Data * data){
    printf("\n Digite o dia: ");
    scanf("%d",&data->dia);
    printf("\n Digite o numero do MES: ");
    scanf("%d",&data->mes);
    printf("\n Digite o ano: ");
    scanf("%d",&data->ano);
}

void mostrarDados(Data * data){
    if (data->mes>=JANEIRO && data->mes<=DEZEMBRO){
        printf("\n%02d/%02d/%04d\n",data->dia,data->mes,data->ano);
    }else{
        printf("Mes invalido");
    }
}

int main(){
    Data * data=(Data*)malloc(sizeof(Data));
    if(data ==NULL){
        exit(1);
    }
    receberDados(data);
    mostrarDados(data);
    free(data);
    //
    return 0;
}
