#include <stdlib.h> //biblioteca de alocacao dinamica(malloc,calloc,free,exit)
#include <stdio.h>


int main(){
    // Alocacao Dinâmica
    // malloc(); calloc(); realloc();

    //alocar memoria para pegar o seu primeiro endereço (malloc())
        int *ponteiroVetor= malloc(3*sizeof(int)); 
        //(tamanho * sizeof(int)) -> no lugar de sizeof pode ser o tamanho em bytes que quer alocar) 
        // -> 3 vezes o tamanho do tipo inteiro
        
        int *ponteiro2Vetor= (int *) malloc(3*sizeof(int)); // tipo de retorno do vetor

        //verificar se teve erro na alocacao
        if(ponteiroVetor==NULL){
            printf("ERRO na alocacao de memoria");
            exit(1);
        }
        //metodo printf e scanf
        scanf("%d",&ponteiroVetor+2); // pegar o endereço alocado no endereco inicial + 2 posições adiante
        scanf("%d",&ponteiroVetor[2]);
        printf("%d\n\n",ponteiroVetor[2]); // ARRAY NAO PRECISA DE "*"
        printf("%d\n\n",*(ponteiroVetor+2));
    //
//------------------------------------------------------------------------------------------------------
    // alocar memoria e pegar em bloco o endereco (calloc()) zerando os espacos
       // int *ponteiroVetor3=(* int) calloc(3,sizeof(int)); 
        //(tamanho * sizeof(int)) -> no lugar de sizeof pode ser o tamanho em bytes que quer alocar) 
        // -> 3 vezes o tamanho do tipo inteiro

//--------------------------------------------------------------------------------------------------------

    // alterar a alocacao da memoria (realloc(variavel, novo_tamanho *sizeof(tipoVariavel)))
        ponteiroVetor=(int *) realloc(ponteiroVetor, 5 *sizeof(int));

        scanf("%d",ponteiroVetor+4);
        printf("%d \n", *(ponteiroVetor+4));
//-------------------------------------------------------------------------------------------------------

    //Declarando uma matriz com alocacao
    // Matriz
        // -> Matriz {{linha0,linha0},{linha1,linha1}}
        // -> Matriz [2][2] -> 0 1  ->[0][0] e [0][1]
        //                     2 3  ->[1][0] e [1][1]

    // alocacao com matriz
        // aloca a linha com ponteiro do ponteiro para criar X quantidade de linhas
        // DEFINE A QUANTIDADE DE LINHAS COM PONTEIRO DO PONTEIRO
        int linhas=5,coluna=3,i;
        int **matriz= (int **) malloc(linhas*sizeof(int *));
        // para que cada matriz[numero] guarda o endereço da quantidade de coluna
        // DEFINE A QUANTIDADE DE COLUNA ATRAVES DA POSICAO DE CADA LINHA, ALOCANDO O NUMERO DE COLUNAS DENTRO
        // DO TAMANHO DA VARIÁVEL 
        for(i=0;i<linhas;i++){
            matriz[i]=(int *)malloc(coluna*sizeof(int));
        }
        // Limpa primeiro as colunas
        for(i=0;i<linhas;i++){
            free(matriz[i]);
        }
        // Limpa a parte externa, ou seja, as linhas
        free(matriz);

    // Metodos para usar scanf e printf
        //  matriz[][]
        //  *(*(matriz+i)+j); (quero a matriz na linha +i) e na coluna + j (posicao)

    // após utilizar a memoria -> free(ponteiro_alocacao) -> liberar memória
    free(ponteiroVetor);
    return 0;
}