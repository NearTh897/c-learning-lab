#include <stdio.h>

#define MAX 5 //const MAX=5;


int vetor[MAX] = {1, 2, 3, 4, 5};

void posicao(int vetor[MAX]){
        for (int i = 0; i < 5; i++) {
        printf("Posição %d: %d\n", i, vetor[MAX]);
    }
}




int main() {
    
    posicao (vetor);


    return 0;
}