#include <stdio.h>
#include <string.h>

int main() {
    char nome[50];
    char sobrenome[50];
    int idade;      
    
    printf("Digite seu nome: ");
    scanf("%49s", nome);  // Limita a 49 caracteres + \0
    
    printf("Digite seu sobrenome: ");
    scanf("%49s", sobrenome);
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    // Limpa o buffer do teclado (importante!)
    while(getchar() != '\n');
    
    printf("\nOlá %s %s, você tem %d anos!\n", nome, sobrenome, idade);
    
    if(idade >= 18) {
        printf("Você é maior de idade.\n");
    } else {
        printf("Você é menor de idade.\n");
    }
    
    return 0;
}