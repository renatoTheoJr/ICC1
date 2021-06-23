#include <stdio.h>
#include<stdlib.h>

int main(){
    float a=0, b=0, result=0;
    char op;
    scanf("%f %c %f", &a, &op, &b);

    switch(op){
        case '+': result = a + b;
            break;
        case '-': result= a -b;
            break;
        case '*': result= a * b;
            break;
        case '/': result = a / b;
            break;
        case '%' : result = a*100.0 / b;
            break;
        default: 
            printf("Não colocou uma opção válida");
            break;
    }
    printf("%.6f", result);

}