// Renato Tadeu Theodoro Junior - 11796759 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehPulaLinha(char caracter){
    if(caracter == '\n' || caracter == '\r'){
        return 1;
    }else{
        return 0;
    }
}

int ehSpam(char frase[77]){
    return (!strcmp(frase, "gratuito") || !strcmp(frase, "gratuitos") || !strcmp(frase, "atencao") || !strcmp(frase, "urgente")
        || !strcmp(frase, "imediato") || !strcmp(frase, "zoombie") || !strcmp(frase, "zoombies") || !strcmp(frase, "oferta") || !strcmp(frase, "ofertas")
        || !strcmp(frase, "dinheiro") || !strcmp(frase, "dinheiros") || !strcmp(frase, "renda") || !strcmp(frase, "fundo")
        || !strcmp(frase, "limitado") || !strcmp(frase, "ajuda") || !strcmp(frase, "SOS"));
}

int main(){
    char frase[78];
    char caracter;
    int contadorCaracter = 0;
    int flagSpam = 0;
    int contSpam = 0;
    while((caracter = getchar()) != EOF){
        frase[contadorCaracter] = caracter;
        contadorCaracter++;
        if(contadorCaracter == 77 && !ehPulaLinha(caracter)){
            flagSpam = 1;
            contadorCaracter = 0;
        }else if(ehPulaLinha(caracter) && !flagSpam){
            frase[contadorCaracter] = '\0';
            contadorCaracter = 0;
            int contadorAux = 0;
            char palavraAux[78];
            for(int i = 0; frase[i] != '\0'; i++){
                if(isalpha(frase[i])){
                    palavraAux[contadorAux] = frase[i];
                    contadorAux++;
                }else{
                    palavraAux[contadorAux] = '\0';
                    contSpam += ehSpam(palavraAux);
                    contadorAux = 0;
                    flagSpam = contSpam >=2 || flagSpam;
                }

            }
        }

    }

    if(flagSpam){
        printf("Spam");
    }else{
        printf("Inbox");
    }


    return 0;
}