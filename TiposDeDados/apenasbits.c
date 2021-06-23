#include<stdio.h>

int main(){
    int numero, value =4278190080, value2=16711680, value3=65280, value4=255;
    scanf("%i", &numero);
    int character1 = (numero&value) >> 24;
    int character2 = (numero&value2) >> 16;
    int character3 = (numero&value3) >> 8;
    int character4 = (numero&value4);

    printf("%c%c%c%c\n", character1, character2, character3, character4);
}