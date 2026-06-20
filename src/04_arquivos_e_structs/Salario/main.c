#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[100];
    float salario;
} Funcionario;

int main() {
    FILE *arquivo;
    int quantidade;
    int codigo;
    char nome[100];
    float salario;
    int i;
    float soma = 0;
    float media;
    
    arquivo = fopen("dados.txt", "r");
    
    if (arquivo == NULL) {
        printf("Nao consegui abrir o arquivo!\n");
        return 1;
    }
    
    fscanf(arquivo, "%d", &quantidade);
    printf("Quantidade de funcionarios: %d\n\n", quantidade);
    
    // Cria o vetor com a quantidade certa
    Funcionario funcionarios[quantidade];
    
    // Primeiro loop: ler e guardar
    for (i = 0; i < quantidade; i++) {
        fscanf(arquivo, "%d", &codigo);
        fgetc(arquivo);
        fgets(nome, 100, arquivo);
        nome[strcspn(nome, "\n")] = '\0';
        fscanf(arquivo, "%f", &salario);
        
        // GUARDA no vetor
        funcionarios[i].codigo = codigo;
        strcpy(funcionarios[i].nome, nome);
        funcionarios[i].salario = salario;
        
        // ACUMULA para a média
        soma = soma + salario;
        
        // MOSTRA na tela
        printf("Funcionario %d:\n", i+1);
        printf("  Codigo: %d\n", funcionarios[i].codigo);
        printf("  Nome: %s\n", funcionarios[i].nome);
        printf("  Salario: %.2f\n\n", funcionarios[i].salario);
    }
    
    fclose(arquivo);
    
    // Calcula a média
    media = soma / quantidade;
    printf("Soma total dos salarios: %.2f\n", soma);
    printf("Media salarial: %.2f\n\n", media);
    
    // Segundo loop: mostra quem está acima da média
    printf("=== Funcionarios com salario acima da media ===\n");
    for (i = 0; i < quantidade; i++) {
        if (funcionarios[i].salario > media) {
            printf("  %s (Cod: %d) - R$ %.2f\n", 
                   funcionarios[i].nome, 
                   funcionarios[i].codigo, 
                   funcionarios[i].salario);
        }
    }
    
    return 0;
}