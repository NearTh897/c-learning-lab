#include <stdio.h>

// Função principal que inicia a execução do programa
void main()
{
    // Laço 'for' que começa com a variável 'x' igual a 11 e decrementa 2 a cada iteração
    // A condição de parada é quando 'x' se torna menor que 0
    for(int x = 100; x >= 0; x -= 10)
    {
        // A cada iteração, imprime o valor atual de 'x' seguido por uma vírgula
        printf("%d,", x);
    }
}
