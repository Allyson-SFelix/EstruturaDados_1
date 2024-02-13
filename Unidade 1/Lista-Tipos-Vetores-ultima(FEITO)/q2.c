#include <stdlib.h>
#include <stdio.h>

typedef struct aluno
{
    int matricula;
    char nome[80];
    char turma;
    float notas[3];
    float media;
} Aluno;

void matricula(int n, Aluno **alunos);
void lanca_notas(int n, Aluno **alunos);
void imprime_tudo(int n, Aluno **alunos);
void imprime_turma(int n, Aluno **alunos, char turma);
void imprime_turma_aprovados(int n, Aluno **alunos, char turma);

void imprime_turma_aprovados(int n, Aluno **alunos, char turma)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (turma == alunos[i]->turma)
        {
            if (alunos[i]->media >= 7.0)
            {
                printf("\nMatricula: %d\nNome: %s\nTurma: %c\nNota-1: %.2f\nNota-2: %.2f\nNota-3: %.2f\nMedia: %.2f\n\n", alunos[i]->matricula, alunos[i]->nome, alunos[i]->turma, alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2], alunos[i]->media);
            }
        }
    }
}

void imprime_turma(int n, Aluno **alunos, char turma)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (turma == alunos[i]->turma)
        {
            printf("\nMatricula: %d\nNome: %s\nTurma: %c\nNota-1: %.2f\nNota-2: %.2f\nNota-3: %.2f\nMedia: %.2f\n\n", alunos[i]->matricula, alunos[i]->nome, alunos[i]->turma, alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2], alunos[i]->media);
        }
    }
}

void imprime_tudo(int n, Aluno **alunos)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("\nMatricula: %d\nNome: %s\nTurma: %c\nNota-1: %.2f\nNota-2: %.2f\nNota-3: %.2f\nMedia: %.2f\n", alunos[i]->matricula, alunos[i]->nome, alunos[i]->turma, alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2], alunos[i]->media);
    }
}

void lanca_notas(int n, Aluno **alunos)
{
    int i = 0, x = 0;
    for (x = 0; x < n; x++)
    {
        for (i = 0; i < 3; i++)
        {
            printf("\nDigite a %d* nota do aluno(%s):", i + 1, alunos[x]->nome);
            scanf("%f", &alunos[x]->notas[i]);
        }
    }
    //
    float soma = 0;
    for (x = 0; x < n; x++)
    {
        soma = 0;
        for (i = 0; i < 3; i++)
        {
            soma += alunos[x]->notas[i];
        }
        alunos[x]->media = soma / 3;
    }
}

void matricula(int n, Aluno **alunos)
{
    printf("\nDigite o numero da matricula :");
    scanf("%d", &alunos[n]->matricula);
    printf("\nDigite o nome do aluno :");
    scanf(" %[^\n]", alunos[n]->nome);
    printf("\nDigite a letra da sua turma :");
    scanf(" %c", &alunos[n]->turma);

    printf("\nVOCE FOI MATRICULADO\n");
}

int main()
{
    // pegar o numero de vagas max para a disciplina
    printf("\nDigite o numero maximo de vagas para a disciplina: ");
    int numeroVagas = 0;
    scanf("%d", &numeroVagas);

    // alocando ponteiros para vetores da estrutura
    Aluno **aluno = (Aluno **)calloc(numeroVagas, sizeof(Aluno *));
    if (aluno == NULL)
    {
        exit(1);
    }

    // alocando que cada vetor tenha um ponteiro de estrutura
    int i = 0;
    for (i = 0; i < numeroVagas; i++)
    {
        aluno[i] = (Aluno *)malloc(sizeof(Aluno));
    }

    //
    // LETRA A)
    int vagasOcupadas = 0;
    do
    {
        if (vagasOcupadas < numeroVagas)
        {
            matricula(vagasOcupadas, aluno);
            vagasOcupadas++;
            //
        }
        else
        {
            printf("\nNao existem vagas livres para essa disciplina\n");
        }
    } while (vagasOcupadas < numeroVagas);
    //

    if (numeroVagas != 0)
    {
        // LETRA B)
        lanca_notas(numeroVagas, aluno);
        // LETRA C)
        imprime_tudo(numeroVagas, aluno);
        // LETRA D)
        char turmaReceber;
        printf("\nDigite a turma que voce procura: ");
        scanf(" %c", &turmaReceber);
        imprime_turma(numeroVagas, aluno, turmaReceber);
        // LETRA E)
        printf("\nDigite a turma que voce quer os aprovados: ");
        scanf(" %c", &turmaReceber);
        imprime_turma_aprovados(numeroVagas, aluno, turmaReceber);
    }

    //
    // free´s
    for (i = 0; i < numeroVagas; i++)
    {
        free(aluno[i]);
    }
    free(aluno);
    //
    return 0;
}