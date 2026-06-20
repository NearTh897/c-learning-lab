// Basta esta função no seu código:

#include <stdio.h>

int pot(int b, int e) {
    int r = 1;
    for(int i = 0; i < e; i++) r *= b;
    return r;
}

int main() {
       int resultado = pot(4, 3);
    
    printf("4 ao cubo: %d\n", pot(4, 3));
    printf("Resultado guardado: %d\n", resultado);
    
    return 0;
}