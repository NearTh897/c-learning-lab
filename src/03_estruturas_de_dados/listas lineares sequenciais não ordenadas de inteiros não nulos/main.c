#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Tamanho máximo das listas

// Protótipos das funções
void inserirSemRepetir(int v[], int valor, int *pos, int max);
void listar(int v[], int quantidade);
void intercalar(int L1[], int tam1, int L2[], int tam2, int L3[], int *tam3);
void interseccao(int L1[], int tam1, int L2[], int tam2, int L3[], int *tam3);
void uniao(int L1[], int tam1, int L2[], int tam2, int L3[], int *tam3);
void removerPeloIndice(int v[], int *quantidade, int indice);  


// Função auxiliar: verifica se valor já está no vetor
bool existe(int v[], int quant, int valor) {
    for (int i = 0; i < quant; i++)
        if (v[i] == valor) return true;
    return false;
}

// Função para inserir sem repetição (valores não nulos)
void inserirSemRepetir(int v[], int valor, int *pos, int max) {
    if (valor == 0) {
        printf("Erro: valor zero não é permitido (somente inteiros não nulos).\n");
        return;
    }
    if (*pos >= max) {
        printf("Erro: lista cheia, não é possível inserir %d.\n", valor);
        return;
    }
    if (existe(v, *pos, valor)) {
        printf("Erro: valor %d já existe na lista, não inserido.\n", valor);
        return;
    }
    v[*pos] = valor;
    (*pos)++;
    printf("Valor %d inserido com sucesso.\n", valor);
}

// Função para listar (percorrer) a lista
void listar(int v[], int quantidade) {
    if (quantidade == 0) {
        printf("Lista vazia.\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

// Intercalar duas listas (alternando elementos)
void intercalar(int L1[], int tam1, int L2[], int tam2, int L3[], int *tam3) {
    *tam3 = 0;
    int i = 0, j = 0;
    while (i < tam1 && j < tam2) {
        L3[(*tam3)++] = L1[i++];
        L3[(*tam3)++] = L2[j++];
    }
    while (i < tam1) L3[(*tam3)++] = L1[i++];
    while (j < tam2) L3[(*tam3)++] = L2[j++];
}

//  Interseção das duas listas (elementos comuns)
void interseccao(int L1[], int tam1, int L2[], int tam2, int L3[], int *tam3) {
    *tam3 = 0;
    for (int i = 0; i < tam1; i++) {
        if (existe(L2, tam2, L1[i]) && !existe(L3, *tam3, L1[i])) {
            L3[(*tam3)++] = L1[i];
        }
    }
}

//  União das duas listas (todos elementos sem repetir)
void uniao(int L1[], int tam1, int L2[], int tam2, int L3[], int *tam3) {
    *tam3 = 0;
    // Copia todos os elementos da primeira lista
    for (int i = 0; i < tam1; i++) {
        L3[(*tam3)++] = L1[i];
    }
    // Insere elementos da segunda que não estão na primeira
    for (int i = 0; i < tam2; i++) {
        if (!existe(L1, tam1, L2[i]) && !existe(L3, *tam3, L2[i])) {
            L3[(*tam3)++] = L2[i];
        }
    }
}

//  Remover elemento pelo índice
void removerPeloIndice(int v[], int *quantidade, int indice) {
    if (indice < 0 || indice >= *quantidade) {
        // A validação já será feita na main, mas a função ainda protege
        printf("Erro interno: índice inválido na função remover.\n");
        return;
    }
    for (int i = indice; i < *quantidade - 1; i++) {
        v[i] = v[i + 1];
    }
    (*quantidade)--;
    printf("Elemento do índice %d removido com sucesso.\n", indice);
}

// Função para construir uma lista interativamente (sem repetição)
void construirLista(int lista[], int *tam, const char *nome) {
    int valor;
    *tam = 0;
    printf("\n--- Construindo %s ---\n", nome);
    printf("Digite inteiros não nulos (0 para terminar):\n");
    while (*tam < MAX) {
        printf("Elemento %d: ", *tam + 1);
        scanf("%d", &valor);
        if (valor == 0) break;
        inserirSemRepetir(lista, valor, tam, MAX);
    }
    printf("%s finalizada com %d elementos.\n", nome, *tam);
    listar(lista, *tam);
}

int main() {
    int lista1[MAX], lista2[MAX];
    int tam1 = 0, tam2 = 0;
    int listaIntercalada[MAX], tamInter = 0;
    int listaIntersecao[MAX], tamIntersec = 0;
    int listaUniao[MAX], tamUniao = 0;

    //  Construir duas listas sem repetição
    construirLista(lista1, &tam1, "LISTA 1");
    construirLista(lista2, &tam2, "LISTA 2");

    //  Imprimir as listas (já impressas na construção, mas vamos reforçar)
    printf("\n=== Listas originais ===\n");
    printf("Lista 1: "); listar(lista1, tam1);
    printf("Lista 2: "); listar(lista2, tam2);

    //  Intercalar
    intercalar(lista1, tam1, lista2, tam2, listaIntercalada, &tamInter);
    printf("\n=== Lista intercalada ===\n");
    listar(listaIntercalada, tamInter);

    //  Interseção
    interseccao(lista1, tam1, lista2, tam2, listaIntersecao, &tamIntersec);
    printf("\n=== Interseção das listas ===\n");
    listar(listaIntersecao, tamIntersec);

    //  Imprimir as listas geradas (já foram impressas acima, mas repetimos por clareza)
    printf("\n=== Impressão solicitada (itens c e d) ===\n");
    printf("Intercalada: "); listar(listaIntercalada, tamInter);
    printf("Interseção:  "); listar(listaIntersecao, tamIntersec);

    //  União
    uniao(lista1, tam1, lista2, tam2, listaUniao, &tamUniao);
    printf("\n=== União das listas ===\n");
    listar(listaUniao, tamUniao);

    //  Remover elemento da lista união por índice
    if (tamUniao > 0) {
        int indice;
        printf("\n=== Remoção por índice na lista união ===\n");
        printf("Lista união atual: "); listar(listaUniao, tamUniao);
        printf("Digite o índice (0 a %d) do elemento a remover: ", tamUniao - 1);
        scanf("%d", &indice);

        if (indice < 0 || indice >= tamUniao) {
            printf("Erro: índice inválido (deve estar entre 0 e %d).\n", tamUniao - 1);
        } else {
            removerPeloIndice(listaUniao, &tamUniao, indice);
            printf("Lista união após remoção: "); listar(listaUniao, tamUniao);
        }
    } else {
        printf("\nA lista união está vazia, não é possível remover.\n");
    }

    printf("\nPrograma encerrado.\n");
    return 0;
}