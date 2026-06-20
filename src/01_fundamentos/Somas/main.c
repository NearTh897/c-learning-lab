#include <stdio.h>

// Soma de três números

int main() {
    int a, b, c, soma; //três valores inteiros simples declarados
    
    printf ("digite três números: ");
    scanf("%d %d %d", &a,&b,&c); // o "&" é como o endereço da caixa ("valor" por exemplo)
     
    soma = a + b + c;
    printf("Soma: %d\n", soma);
      return 0;
}   