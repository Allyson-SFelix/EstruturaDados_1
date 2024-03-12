#include "disciplina.h"
typedef struct aluno Aluno;

/*Funcao que aloca a estrutura para cadastrar o aluno e seus dados e retorna a estritura preenchida*/
Aluno* cria_aluno(char nome[], int matricula);


/*Funcao que recebe o aluno e a disciplina para matricular o aluno e atualizar o numero de disciplinas matriculado*/
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);


/*Funcao que exclui o aluno do sistema*/
void exclui_aluno(Aluno* aluno);


/*Funcao que realiza o print dos alunos cadastrados no sistema*/
void printAlunos(Aluno**aluno,int max,int *matriculas);


/*Funcao que libera memoria da estrutura de alunos */
void liberarMemoriaAlunos(Aluno**aluno,int max,int *matriculas);