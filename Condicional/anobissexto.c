#include <stdio.h>

int main(){
    int ano;

    scanf("%d", &ano); //Recebe o ano
    

    if(ano%4 == 0){ //Um ano será bissexto quando for divísível por 4
        printf("SIM\n");
        return 0;
    }
    printf("NAO\n");
}