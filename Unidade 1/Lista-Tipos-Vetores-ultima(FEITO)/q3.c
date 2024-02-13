/*3)  Defina estruturas para representar retângulos (dadas a base e a altura) e círculos (dado o raio), e
implemente as funções a seguir:

b) Dado um retângulo, crie e retorne o maior círculo interno ao retângulo.
Protótipo: Circ* circ_interno(Ret* r);*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define pi 3.14

typedef struct ret{
    float base;
    float altura;
}Ret;

typedef struct circ{
    float raio;
}Circ;


Ret* ret_circunscrito(Circ* c, float h);
Circ* circ_interno(Ret* r);

Circ* circ_interno(Ret* r){
    Circ *circulo=(Circ*)malloc(sizeof(Circ));
    if(circulo==NULL){
        exit(1);
    }
    //
    if(r->altura < r->base){
        circulo->raio=r->altura/2.0;
    }else if(r->altura > r->base){
        circulo->raio=r->base/2.0;
    }
    return(circulo);
}


Ret* ret_circunscrito(Circ* c, float h){
    Ret *retangulo=(Ret*)malloc(sizeof(Ret));
    if(retangulo==NULL){
        exit(1);
    }
    else{
        retangulo->base = 2 * sqrt(pow(c->raio, 2) - pow((h / 2), 2));
        retangulo->altura=h;
    }
    return(retangulo);
}

int main(){
    Ret * retanguloPrincipal=(Ret*)malloc(sizeof(Ret));
    if(retanguloPrincipal==NULL){
        exit(1);
    }
    Circ * circuloPrincipal=(Circ*)malloc(sizeof(Circ));
    if(circuloPrincipal==NULL){
        exit(1);
    }
    //
    printf("Digite a altura do retangulo: ");
    scanf("%f",&retanguloPrincipal->altura);
    printf("Digite o raio do circulo: ");
    scanf("%f",&circuloPrincipal->raio);
    //
    if(retanguloPrincipal->altura>=(circuloPrincipal->raio*2)){
        printf("\nValores invalidos\n");
    }else{
        retanguloPrincipal=ret_circunscrito(circuloPrincipal,retanguloPrincipal->altura);
        printf("\nA Altura e: %.2f\nA Base e: %.2f\n",retanguloPrincipal->altura,retanguloPrincipal->base);
        printf("\nDigite a altura do retangulo: ");
        scanf("%f",&retanguloPrincipal->altura);
        printf("\nDigite a base do retangulo: ");
        scanf("%f",&retanguloPrincipal->base);
        circuloPrincipal=circ_interno(retanguloPrincipal);
        printf("\nO raio do maior circulo e: %.2f\n",circuloPrincipal->raio);
    }
    //
    free(retanguloPrincipal);
    free(circuloPrincipal);
    return 0;
}
