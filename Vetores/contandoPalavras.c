// Renato Tadeu Theodoro Junior - 11796750
#include <stdio.h>

int main(){
    int numeroCaracteres = 0, numeroPalavras = 0, numeroLinhas = 0;
    
    char caracter, caracterAnterior = ' ';
    int flagCaracterAnteriorEhValido = 0;

    while (1) {
        caracter = getchar();
        if((caracter == '\n' && caracterAnterior != '\r') ||  caracter == '\r'){
            numeroLinhas++;
            if(flagCaracterAnteriorEhValido){
                numeroPalavras++;
            }
            flagCaracterAnteriorEhValido = 0;
        }else if(caracter == ' ' || caracter == '\t' || caracter == EOF) {
            if(flagCaracterAnteriorEhValido){
                numeroPalavras++;
            }
            flagCaracterAnteriorEhValido = 0;
        }else if(caracter != '\n'){ //
            flagCaracterAnteriorEhValido = 1;
        }

        if(caracter == EOF){
            break;
        }

        numeroCaracteres++;
        caracterAnterior = caracter;
    }
    
    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", numeroLinhas, numeroPalavras, numeroCaracteres);
}