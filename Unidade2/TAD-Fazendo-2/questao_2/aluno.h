#include "disciplina.h"
typedef struct aluno
{
    char nome[100];
    int matricula;
    Disciplina*disciplinas[10];
    int num_disciplinas;
}aluno;

typedef struct aluno Aluno;

/*Funcao que aloca a estrutura para cadastrar o aluno e seus dados e retorna a estritura preenchida*/
Aluno* cria_aluno(char nome[], int matricula);


/*Funcao que recebe o aluno e a disciplina para matricular o aluno e atualizar o numero de disciplinas matriculado*/
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);


/*Funcao que exclui o aluno do sistema*/
void exclui_aluno(Aluno* aluno);
