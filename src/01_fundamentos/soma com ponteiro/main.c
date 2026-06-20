#include <stdio.h>

void soma(int *a, int *b){
        int soma = *a + *b;
    printf("Soma: %d\n", soma);  // Mostra

}

int main()
{
    int a = 7;
    int b = 3;

    soma(&a, &b);
    
    return 0;
}