#include <stdio.h>

int main(){
    char teclado[49];
    int number;

    // Os valores do teclado serão salvos
    // num array de char

    for(int i=0; i<49; i++){
        scanf(" %c", &teclado[i]);
    }
    scanf(" %d", &number);

    int listaNumber[number];

    // A lista codificada irá ficar salva num array de 
    // n dimensões

    for(int i=0; i<number; i++){
        scanf("%d", &listaNumber[i]);
    }

    // Cada item da listaNumber corresponde a um indice do teclado
    for(int i=0; i<number; i++){
        char c = teclado[listaNumber[i]];
        if(c=='E'){
            printf("\n");
        }
        else if(c=='_'){
            printf(" ");
        }else{
            printf("%c", c);
        }
    }

}