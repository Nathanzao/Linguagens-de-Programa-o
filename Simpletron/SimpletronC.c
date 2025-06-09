#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "SimpletronH.h"


void inicializa(struct ope *Operacoes){
    Operacoes->acumulador = 0;
    Operacoes->codigoOperacao = 0;
    Operacoes->operandos = 0;
    Operacoes->posicMemoria = 0;
    Operacoes->registradorDeInstrucao = 0;
    Operacoes->contadorInstrucao = 0;

    for(int i = 0; i < TamanhoMemoria; i++){
        memoria[i] = 0;
    }
}

void criarCodigoArquivoTexto(){
    printf("Bem vindo ao Simpletron!\n");
    printf("Daremos inicio ao programa. O Simpletron ira ler os inteiros no arquivo de texto. Note que precisa estar no formato de 1 inteiro por linha (sem mais nenhum caracter), caso o programa precise iniciar alguma memoria so coloque 0000 ate chegar na posicao e colocar -9999 ao fim:\n\n");

    FILE *nome = fopen("input.txt", "r");

    if(nome == NULL){
        printf("Erro.");
    }else{
        printf("Arquivo aberto com sucesso.");
    }

    int inst = 0;
    int i = 0;

    while(fscanf(nome, "%d", &inst) != EOF){
        if(i == 0 && inst == -9999){
            printf("Nenhum código será colocado, portanto programa encerrado.\n");
            fclose(nome);
            return;
        }

        if(inst == -9999){
            fclose(nome);
            return;
        }

        if (i < TamanhoMemoria) {
            memoria[i] = inst;
            i++;
        } else {
            printf("\nErro: Memoria cheia. Instrucao ignorada.\n");
            break;
        }
        
    }

printf("Programa ja escrito com sucesso.\nDando continuidade...\n\n");
fclose(nome);
}

void criarCodigoAutomatico(){
    
    printf("Bem vindo ao Simpletron!\n");
    printf("Daremos inicio ao programa. Usamos preenchimento automatico. Caso nao deseje, selecione a outra opcao ao fim do programa.\n");
    printf("O codigo a seguir simulara uma tentativa de encontrar o maior valor entre dois numeros, 13 e 12, (exemplo esta no livro): \n\n");

    
    
    memoria[0] = +1009;
    memoria[1] = +1010;
    memoria[2] = +2009;
    memoria[3] = +3110;
    memoria[4] = +4104;
    memoria[5] = +1109;
    memoria[6] = +4300;
    memoria[7] = +1110;
    memoria[8] = +4300;
    memoria[9] = 0;
    memoria[10] = 0;


    printf("Programa ja escrito com sucesso.\nDando continuidade...\n\n");

}

void criarCodigoPassagemParametros(){
    printf("Bem vindo ao Simpletron!\n");
    printf("Digite -9999 para encerrar o programa, quando quiser!\n");
    printf("Daremos inicio ao programa. Primeiro, preencha o codigo e logo apos ele sera executado:\n\n");

    printf("\n\nPrograma:\n\n");
    int instrucao = 0;
    int i = 0;
    
    do{
        printf("0%d ? ", i);
        scanf("%d", &instrucao);

        if(i == 0 && instrucao == -9999){
            printf("Nenhum código será colocado, portanto programa encerrado.\n");
            return;
        }

        if(instrucao < -9999 || instrucao > 9999){
            printf("Erro. Overflow.\n");
            continue;
        }

        memoria[i++] = instrucao; /* Armazena a instrucao na memoria. */

    }while(instrucao != -9999);


    printf("Programa ja escrito com sucesso.\nDando continuidade...\n\n");

}

void read(struct ope *p){
    printf("Digite um valor para ser colocado no endereco %d: ", p->operandos);
    scanf("%d", &memoria[p->operandos]);
    
    return;
}

void write(struct ope *p){
    printf("Valor no endereco de memoria %d: %d.\n", p->operandos, memoria[p->operandos]);
    return;
}

void load(struct ope *p){
    p->acumulador = memoria[p->operandos];
    return;
}

void store(struct ope *p){
    memoria[p->operandos] = p->acumulador;
    return;
}

void add(struct ope *p){
    if(p->acumulador > 9999 || p->acumulador < -9999){
        printf("Erro. Overflow do acumulador.\n");
        return;
    }
    
    p->acumulador += memoria[p->operandos];
    return;
}

void sub(struct ope *p){
    if(p->acumulador > 9999 || p->acumulador < -9999){
        printf("Erro. Overflow do acumulador.\n");
        return;
    }
    
    p->acumulador -= memoria[p->operandos];
    return;
}

void divi(struct ope *p){
    if(p->acumulador > 9999 || p->acumulador < -9999){
        printf("Erro. Overflow do acumulador.\n");
        return;
    }

    if(memoria[p->operandos] == 0){
        printf("Erro. Tentiva de divisao por zero.\n");
    }else{
        p->acumulador = p->acumulador / memoria[p->operandos];
    }

    return;
}

void mul(struct ope *p){
    if(p->acumulador > 9999 || p->acumulador < -9999){
        printf("Erro. Overflow do acumulador.\n");
        return;
    }

    p->acumulador *= memoria[p->operandos];
}

void exibir(struct ope *p){
    printf("\n\nExibindo os dados do Simpletron. Comecaremos com os registradores: \n");
    printf("Acumulador: %d.\n", p->acumulador);
    printf("Codigo operacao: %d.\n", p->codigoOperacao);
    printf("Contador de instrucao: %d.\n", p->contadorInstrucao);
    printf("Operandos: %d.\n", p->operandos);
    printf("Posicao na memoria: %d.\n", p->posicMemoria);
    printf("Registrador de instrucao: %d.\n", p->registradorDeInstrucao);

    printf("\nMemoria:\n");


    for (int i = 0; i < 10; i++) {
        printf("%6d", i);
    }

    for (int linha = 0; linha < 10; linha++) {
        printf("\n%2d  ", linha * 10);

        for (int coluna = 0; coluna < 10; coluna++) {
            int pos = linha * 10 + coluna;
            int valor = memoria[pos];

            printf(" %+05d", valor);
        }
    }

    printf("\n");
}

void executa(struct ope *p){
    printf("\n\nComecando a execucao do programa...\n\n");

    do{
        p->registradorDeInstrucao = memoria[p->contadorInstrucao];
        p->posicMemoria = p->contadorInstrucao;
        p->codigoOperacao = p->registradorDeInstrucao / 100; /* Primeiros dois digitos. */
        p->operandos = p->registradorDeInstrucao % 100; /* Ultimos dois digitos. */

        switch(p->codigoOperacao){
            case READ:
                read(p);
                p->contadorInstrucao++;
                break;
            
            case WRITE:
                write(p);
                p->contadorInstrucao++;
                break;

            case LOAD:
                load(p);
                p->contadorInstrucao++;
                break;

            case STORE: /* Pensei que era um endereço declarado. Parece que não. */
                store(p);
                p->contadorInstrucao++;
                break;

            case ADD:
                add(p);
                p->contadorInstrucao++;
                break;

            case SUBTRACT:
                sub(p);
                p->contadorInstrucao++;
                break;

            case DIVIDE:
                divi(p);
                p->contadorInstrucao++;
                break;

            case MULTIPLY:
                mul(p);
                p->contadorInstrucao++;
                break;

            case BRANCH:
                p->contadorInstrucao = p->operandos;
                break;

            case BRANCHNEG:
                if(p->acumulador < 0){
                    p->contadorInstrucao = p->operandos;
                }else{
                    printf("Acumulador nao esta negativo!\n");
                    p->contadorInstrucao++;
                }

                break;

            case BRANCHZERO:
                if(p->acumulador == 0){
                    p->contadorInstrucao = p->operandos;
                }else{
                    printf("Acumulador nao esta zerado!\n");
                    p->contadorInstrucao++;
                }

                break;

            case HALT:
                printf("\n\nPrograma finalizado.\n\n");
                p->registradorDeInstrucao = -9999;
                p->contadorInstrucao++;
                break;

            default:
                printf("Codigo cancelado. Por erro ou pela insercao de -9999 no inicio.\n");
                p->contadorInstrucao++;
                return;
        }

    
    }while(p->registradorDeInstrucao != -9999);

    exibir(p);

}