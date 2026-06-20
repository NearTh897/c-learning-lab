#include <stdio.h>
#include <string.h>

int main() {
    char palavrasecreta[5] = "CASA";
    char chutes[26];
    int tentativas = 0;
    
    while(1) {  // Loop infinito (sairá com break)
        printf("\nPalavra: ");
        
        // AQUI: mostrar palavra com underscores/letras
        // Use dois loops for aninhados
        
        palavrasecreta[0] = 'C';
        palavrasecreta[1] = 'A';
        palavrasecreta[2] = 'S';
        palavrasecreta[3] = 'A';
        palavrasecreta[4] = '\0';



        
        // AQUI: pedir nova letra
        scanf(" %c", &chutes);
        chutes[tentativas] == chutes;
        // Guardar no array chutes
        
        // AQUI: verificar se ganhou
        if (chutes == palavrasecreta);
        printf("Parabens, vc acertou! A palavra secreta era: CASA!");
        break;
        // Se sim, break;
    }
    
    printf("Parabéns! Você descobriu a palavra!\n");
    return 0;
}