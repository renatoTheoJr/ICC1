#include <stdio.h>

int main(){
    int b=0, p=0, result=0;
    scanf("%i %i", &b, &p);

    result = p*3 - b*5;

    if(result <= -30){
        printf("P\n");
    }
    else if(result <= 0){
        printf("B\n");
    }
    else{
        printf("R\n");
    }
    return 0;

}