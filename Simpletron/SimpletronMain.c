#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "SimpletronC.c"

/*
Execução do Simpletron. Estava pedindo para definir os registradores e tudo mais na Main, assim como foi feito.
Apenas foi declarado na Main "struct ope p".
*/

int main (){
setlocale(LC_ALL, "Portuguese");
    int desejo = 0;
    struct ope p;
    inicializa(&p);

    printf("Atencao!!! Fortemente recomendado em abrir toda janela do .exe para ler os textos melhor.\n");
    printf("Alem disso, o .txt esta na pasta /output. O VsCode so consegue ler se estiver dentro dela. Modifique o arquivo de la.\n");

    do{
        printf("Preparando para iniciar o Simpletron. Digite 1 se deseja testa-lo por parametro e 2 para testa-lo  de forma automatica no .exe e 3 se deseja testar no TXT: ");
        scanf("%d", &desejo);
    }while(desejo != 1 && desejo != 2 && desejo != 3);

    printf("\n\n\n");

    switch (desejo)
    {
        case 1:
            criarCodigoPassagemParametros(&p);
            break;
        
        case 2:
            criarCodigoAutomatico(&p);
            break;
        
        case 3:
            criarCodigoArquivoTexto(&p);
            break;
            
        default:
            break;
    }

    executa(&p);

system("pause");
return 0;
}