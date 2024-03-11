#include <stdio.h>

int main(){
    // COMPLEXIDADE
    //  Identificar os programas com menor tempo e maior eficiencia(menor memoria no computador) 
    //  Corretude    -> Para toda entrada legal(entrada de dados correta de acordo com seu tipo) ela produz uma saida correta
    //  Simplicidade -> (codigo limpo) Facil de ser entendido / Facil de implementar / Facil de manter
    //  Eficiencia   -> (em funcao do tamanho/entrada) - quanto tempo para produzir e quanto  de memória ram ele vai ocupar
    //          tempo-> parte fixa(variaveis no parametro pro exemplo) + parte variavel(instancia do problema a ser resolvido)
    //             S(p)=c+Sr;

    // Complexidade de espaço => contar as variáveis e somar seus espaços ocupado
    //      int         (4 Bytes)
    //      float       (4 Bytes)
    //      char        (1 Bytes)
    //      double      (8 Bytes)
    //      long double (10 Bytes)

    // Complexidade de tempo => tempo de execucao de uma entrada e o numero de atribuicoes,somas,condicionais...
    //                                                                   (operacoes primitivas na ULA) 
    //      Soma de codigos de linhas
    //      Olha o tempo de cada linhas e quantas vezes executadas
    //      Agrupa e deixa mais simplificado
    //      Analisar o tipo da funcao
    // 
    //      T(nome_funcao)=somas
    //
    //      Simplicar (Tira a constante, tira o menor indice)
    //
    //      Notacao do big O: T(nome_funcao)=O(o que sobrou)
    return 0;
}