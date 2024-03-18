/* TAD: pilha de valores reais */

typedef struct pilha Pilha;


Pilha* pilha_cria(int *contador);

void pilha_push(Pilha* p, float v,int *contador);

float pilha_pop(Pilha* p,int *contador);

int pilha_vazia(Pilha* p);

void pilha_libera(Pilha* p);

void pilha_imprimir(Pilha*p);