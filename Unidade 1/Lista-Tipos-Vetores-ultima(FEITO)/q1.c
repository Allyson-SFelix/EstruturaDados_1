#include <stdlib.h>
#include <stdio.h>

typedef struct{
    float preco;
    char local[30];
    char atracao[20];
}Ingresso;

void preenche(Ingresso* i);
void imprime(Ingresso* i); 
void imprime_menor_maior_preco(int n, Ingresso* vet);

void preenche(Ingresso* i){
    // LETRA A
    printf("\nDigite o preco do ingresso: ");
    scanf(" %f",&i->preco);
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


int main(){
    Ingresso * ingresso=(Ingresso *)malloc(sizeof(Ingresso));
    if(ingresso==NULL){
        exit(1);
    }
    //
    printf("\nDigite a quantidade de ingressos vendidos:");
    int quantidadeIngressos=0;
    scanf(" %d",&quantidadeIngressos);
    // realocando um novo espaço de memoria, criando um vetor de struct
    ingresso=(Ingresso *) realloc(ingresso, quantidadeIngressos*sizeof(Ingresso));
    if (ingresso == NULL) {
        exit(1);
    }
    //
    // como foi pedido apenas na letra anterior da letra que criou o vetor será [0]
        //
        preenche(&ingresso[0]);
        imprime(&ingresso[0]);
        //
        printf("\n Digite o novo valor do ingresso:\n");
        float novoPreco=0.0;
        scanf(" %f",&novoPreco);
        altera_preco(&ingresso[0], novoPreco);
    // preparos para funcionar a letra d)
        int i=0;
        for(i=1;i<quantidadeIngressos;i++){
            preenche(&ingresso[i]);
            imprime(&ingresso[i]);
        }
        //
        imprime_menor_maior_preco(quantidadeIngressos, ingresso);
    //
    free(ingresso);
    //
    return 0;
}