#include <stdio.h>

int main(){
    float velocidade;
    scanf("%f", &velocidade);
    if(velocidade<=80){
        printf("Velocidade dentro do limite permitido.\n");
        return 0;
    }

    float multa = 2* (velocidade - 80.0);
    printf("Limite de velocidade excedido! Multado no valor de R$%.2f!\n", multa);
}