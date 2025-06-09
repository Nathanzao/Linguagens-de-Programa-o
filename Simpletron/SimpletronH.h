/* Operações de entrada e saída: */

#define READ 10 /* Ler uma WORD do teclado em uma região específica da memória. */
#define WRITE 11 /* Escrever uma WORD de uma região específica da memória na tela. */

/* Operações de carregamento e armazenamento: */

#define LOAD 20 /* Carregar uma WORD de um local específico da memória para o acumulador. */
#define STORE 21 /* Armazenar uma WORD do acumulador para uma região específica da memória. */

/* Operações aritméticas: */

#define ADD 30 /* Somar uma WORD de um local da memória com a WORD no acumulador (o resultado permanece no acumulador). */
#define SUBTRACT 31 /* Subtrair uma WORD de um local da memória com a WORD no acumulador (o resultado permanece no acumulador). */ 
#define DIVIDE 32 /* Dividir uma WORD de um local da memória com a WORD no acumulador (o resultado permanece no acumulador). */
#define MULTIPLY 33 /* Multiplicar uma WORD de um local da memória com a WORD no acumulador (o resultado permanece no acumulador). */

/* Operações de controle de fluxo: */

#define BRANCH 40 /* Vai para algum local específico da memória. */
#define BRANCHNEG 41 /* Vai para algum local específico da memória, caso o acumulador esteja negativo. */
#define BRANCHZERO 42 /* Vai para algum local específico da memória, caso o acumulador esteja zerado. */
#define HALT 43 /* Parar. */

/* Definindo algumas coisas: */

#define TamanhoMemoria 100
static int memoria[TamanhoMemoria];

struct ope{
    int acumulador; /* Registrador AX; */
    int posicMemoria; /* Posição na memória da instrução sendo atualmente executada. */
    int codigoOperacao; /* Codigo da operação (dois digitos mais a esquerda). */
    int operandos; /* O valor que diz em qual endereço da memória as variáveis serão armazenadas. (dois digitos mais a direita). */
    int registradorDeInstrucao; /* É onde estarão as instruções e operandos, sempre pegando a próxima. */
    int contadorInstrucao; /* Para percorrer a memoria. */
};

/* Funções de funcionamento gerais: */

void inicializa(struct ope *p);
void criarCodigoAutomatico();
void criarCodigoPassagemParametros();
void criarCodigoArquivoTexto();
void executa(struct ope *p);
void exibir(struct ope *p);

/* Funções para cada instrução (menos as de controle): */

void read(struct ope *p);
void write(struct ope *p);
void load(struct ope *p);
void store(struct ope *p);
void add(struct ope *p);
void sub(struct ope *p);
void divi(struct ope *p);
void mul(struct ope *p);