struct ContaBancaria{
    char titular[100];
    int numero;
    float saldo;
};

typedef struct ContaBancaria Contas;

/*A funcao recebe como parametro o numero da conta, o nome do titular e o saldo (mas nao ha nada)
retorna uma estrutura de conta preenchida e alocada*/
Contas * criarConta(int numCliente,char titular[100],float saldo);


/*A funcao recebe como parametro a estrutura da conta pra depositar e o valor 
e atualiza o valor na conta*/
void deposita(Contas * conta,float valor); 

/*A funcao recebe como parametro a estrutura da conta para sacar e o valor para sacar
 verifica se tem saldo suficiente e atualiza o valor na conta*/
void sacar(Contas*conta,float valor);


/*A funcao recebe como parametro a estrutura da conta de origem e a estrutura da conta de destino
 verifica o saldo e atualiza o valor nas contas*/
void transfere(Contas*contaOrigem,Contas*contaDestino,float valor);

/*A funcao que recebe o endereço de uma estrutura da conta e retorna seu saldo;
*/
float saldo(Contas*conta);

/*A funcao libera o espaço alocado dinamicamente para a estrutura*/
void excluiConta(Contas**conta,int *numeroContas,int indiceApagar);

/*A funcao libera as memorias alocadas recebendo a estrutura e a quantidade de estrutura alocadas durante o uso do programa no parametro*/
void liberarMemoria(Contas**conta,int quantidade,int*numeroContas);