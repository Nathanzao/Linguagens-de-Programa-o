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

    do{
        printf("Preparando para iniciar o Simpletron. Digite 1 se deseja testa-lo por parametro e 2 para testa-lo  de forma automatica: ");
        scanf("%d", &desejo);
    }while(desejo != 1 && desejo != 2);

    if(desejo == 2){
        criarCodigoAutomatico(&p);
    }else{
        criarCodigoPassagemParametros();
    }

    executa(&p);

return 0;
}