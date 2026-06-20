#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float imc(float peso, float alturaM){
    float resultado = peso / (alturaM * alturaM);
    return resultado;
}

int main(){
    
    float peso;
    float alturaM;
    float resultado;
    
    printf("Coloque seu peso em Kg: ");
    scanf("%f", &peso);
        
    printf("Coloque sua altura em metros (use ponto): ");
    scanf("%f", &alturaM);
    
    resultado = imc(peso, alturaM);
    
    system("clear");
        sleep(1);
        
    printf("Seu IMC é: %.2f\n", resultado);
    if (resultado < 18.25){
        printf("\n");
        printf("ALERTA: seu peso está abaixo do normal!");
    }
    
    return 0;
}