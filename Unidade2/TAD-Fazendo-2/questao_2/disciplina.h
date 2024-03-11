typedef struct disciplin{
    char nome[100];
    int codigo;

}disciplina;

typedef struct disciplina Disciplina;


/*Funcao que crria disciplina alocando um espaço da memoria para a estrutura e coloca os valores na estrutura*/
Disciplina*cria_disciplina(char nome[],int codigo);


/*Funcao que limpa a memoria da estrutura no parametro*/
void exclui_disciplina(Disciplina* disciplina);

