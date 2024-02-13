#include <stdio.h>
#include <stdlib.h> //Biblioteca que auxilia para manipular memoria
#include <math.h> //Biblioteca que auxilia para uso de (sqrt e pow, entre outros)

//Ponteiros
// Endereco da celula da memoria
// &variavel -> endereco na memoria 
// Um ponteiro é a variavel que armazena o endereco da memoria dessa variavel
// Serve para manipular a variavel fora do main ou fora da usa funcao atraves do endereço da memoria armazenada

int main(){
    int valor; 
    int *ponteiro;
    ponteiro= &valor; 
    // Para ponteiro -> printf("%p",ponteiro); 
    
    // Para pegar o conteudo do endereço usa 
    // *variavel


    // Inicializar o ponteiro:
    // Com o endereço da memória
    // ou
    // Com "nomePonteiro = NULL;"
    // para evitar resto da memoria
    
    // Conversao de Tipo
    // float number;
    // int * ponteiro;
    // ponteiro = &number;
    // ponteiro = (int*) &number; -> cash, força ser do outro tipo

    // ponteiro duplo -> ponteiro que armazena o ponteiro de outra variavel

    //---------------------------------------------------------------

    // Aritmetica de Ponteiros
    // ponteiro+2 (colocando o ponteiro com o endereço de outra variavel para +2 celulas a frente)
    // ponteiro-3 (colocando o ponteiro com o endereço de outra variavel para -3 celulas p/ tras)
    // ponteiro-- (decremento de celula)
    // ponteiro++ (incremento de celula)
    // ponteiro-ponteiro2 (Resultado é uma valor inteiro)

    //---------------------------------------------------------------

    // Ponteiro da Função (Endereço da função) -> metodo de funcao chamando funcao
    // int (*nomePonteiro)(int,int)=NomeFuncao; -> ponteiro da função que o retorno é inteiro e que tem 
    // 2 parametros de tipo int.
    
    //
    return 0;
}
