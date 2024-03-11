#include "aluno.h"
/* TAD : TIPO ABSTRATO DE DADOS

  TAD: uma nova struct com funcoes encapsuladas


  deve criar:
  1- arquivo cabecalho (arquivo.h)
  2- arquivo com as funcoes (funcos.c)
  3- arquivo main para executar as funcoes
*/
int main(){
  /* apenas chamei porque no aquivo.h criei 
    uma struct de nome Aluno que contem 3 informacoes para serem guardadas */
  Aluno **pessoa;
  //
  int numeroAlunos;
  //
  pessoa=matricularAlunos(&numeroAlunos);
  liberarMemoria(pessoa,&numeroAlunos);
  //
  return 0;
}