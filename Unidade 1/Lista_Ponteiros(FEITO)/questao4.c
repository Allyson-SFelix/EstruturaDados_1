// area e perimetro de um hexagono

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro);

void calcula_hexagono(float l, float *area, float *perimetro){
    *area=(3*pow(l,2)*sqrt(3))/2;
    *perimetro=6*l;
}

int main(void) {
    float area,perimetro,lado=0;
    float *p_area=&area;
    float *p_perimetro=&perimetro;
    printf("Digite o lado(em cm): ");
    scanf("%f",&lado);
    calcula_hexagono(lado,p_area,p_perimetro);
    printf("O valor do Perimetro= %.3f \nO valor da Area= %.2f\n",*p_area,*p_perimetro);
    return 0;
}