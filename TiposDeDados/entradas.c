#include <stdio.h>

int main(){
    int n1, n2;

    printf("Digite o primeiro numero");
    scanf("%i", &n1);

    printf("Digite o primeiro e o segundo numero"); //Usuário fica perdido

    scanf("%i %i", &n1, &n2); //Não tão usual

    printf("Primeiro numero: %i\n", n1);
    printf("Primeiro numero: %i e o segundo numero: %i\n", n1, n2);
}