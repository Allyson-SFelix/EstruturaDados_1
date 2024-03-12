#include <stdlib.h>
#include <stdio.h>
#include "ingresso.h"


int main(){
    int quantidadeIngresso=0;
    int *numeroIngresso=&quantidadeIngresso;
    Ingresso **ingresso=receberDadosIniciais(ingresso,numeroIngresso);
    imprime_menor_maior_preco(*numeroIngresso,ingresso);
    liberarMemoria(ingresso,*numeroIngresso);
    //
    return 0;
}