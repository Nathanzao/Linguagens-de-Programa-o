#include <stdio.h>

void heapInfinito(int *vetor){
    while(1 != 0){
        vetor = malloc(sizeof(int));
    }
}

void main(){
    int *v;
    heapInfinito(v);
    return 0;
}