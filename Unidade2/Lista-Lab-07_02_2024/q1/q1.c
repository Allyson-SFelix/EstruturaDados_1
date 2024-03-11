#include <stdlib.h>
#include <stdio.h>
#include "ingresso.h"


int main(){
    int quantidadeIngresso=0;
    Ingresso **ingresso=receberDadosIniciais(ingresso,&quantidadeIngresso);
    liberarMemoria(ingresso,quantidadeIngresso);
    //
    return 0;
}