typedef enum { // Definindo uma enumeração de códigos de erro para ficar mais
               // legível de identificar o que cada código significa
  OK,          // Código de sucesso de execução
  ABRIR,          // Código de não foi possível abrir o arquivo
  FECHAR,         // Código de não foi possível fechar o arquivo
  ESCREVER,       // Código de não foi possível escrever no arquivo
  LER             // Código de não foi possível ler o arquivo
} ERROS;          // Definindo o nome da enumeração como ERROS

typedef ERROS (*funcao)(); // Definindo um tipo de função que recebe um array de
                      // tarefas e um ponteiro para a posição atual das tarefas,
                      // e retorna um código de erro

ERROS soma_elementos(); // Assinatura da função de somar elementos em um array
ERROS manipulacao_strings(); // Assinatura da função de manipular strings
ERROS cadastro_struct(); // Assinatura da função de cadastrar produtos usando struct
ERROS operacoes_matriciais(); // Assinatura da função de operações matriciais
ERROS manipulacao_ponteiros_strings(); // Assinatura da função de manipular ponteiros em strings
ERROS leitura_escrita_binario(); // Assinatura da função de leitura e escrita de registros em arquivos binários
ERROS ordenacao_structs(); // Assinatura da função de ordenação de structs
ERROS manipulacao_ponteiros(); // Assinatura da função de manipulação de ponteiros
ERROS calculo_estatisticas(); // Assinatura da função de cálculo de estatísticas em um array
ERROS manipulacao_tempo(); // Assinatura da função de manipulação de tempo

void clearBuffer(); // Assinatura da função de limpar buffer



// Itens necessários para o exercício 3
#define MAX_PRODUTOS 50

typedef struct Cadastro_Produto {
  char nome[50];
  float preco;
  int quant;
} Produto;

int criar(Produto produtos[], int *pos);
int listar(Produto produtos[], int pos);
int calcular(Produto produtos[], int pos);