typedef struct ingresso Ingresso;



void preenche(Ingresso* i);
void imprime(Ingresso* i); 
void imprime_menor_maior_preco(int n, Ingresso* vet);
void altera_preco(Ingresso* i, float valor);
void liberarMemoria(Ingresso**ingresso,int qtd);
Ingresso**receberDadosIniciais(Ingresso**ingresso,int *quantidadeIngressos);