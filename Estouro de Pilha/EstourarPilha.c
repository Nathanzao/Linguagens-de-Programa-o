#include <stdio.h>

void recursaoInfinita(int valor){
    printf("%d", valor);
    recursaoInfinita(valor + 1);
}

void main(){
    recursaoInfinita(0);
    return 0;
}