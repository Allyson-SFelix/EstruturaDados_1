typedef struct disciplina Disciplina;


/*Funcao que crria disciplina alocando um espaço da memoria para a estrutura e coloca os valores na estrutura*/
Disciplina*cria_disciplina(char nome[],int codigo);


/*Funcao que limpa a memoria da estrutura no parametro*/
void exclui_disciplina(Disciplina* disciplina);


/*Funcao que realiza o print das disciplinas cadastradas no sistema*/
void printDisciplinas(Disciplina**mat, int max, int *codigoDisciplina);


/*Funcao que libera a memoria da estrutura de disciplinas*/
void liberarMemoriaDisciplinas(Disciplina**disciplina,int max,int *codigoMaterias);
