// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @Title Funções - Maior, Menor, Média e Moda
//
#include <stdio.h>

float media(int vector[10]){
    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += vector[i];
    }

    return sum / 10.0;
}

int max(int vector[10]){
    int maxi = vector[0];

    for(int i = 0; i < 10; i++){
        if(maxi < vector[i]){
            maxi = vector[i];
        }
    }
    return maxi;
}

int min(int vector[10]){
    int mini = vector[0];

    for(int i = 0; i < 10; i++){
        if(mini > vector[i]){
            mini = vector[i];
        }
    }
    return mini;
}

int mode(int vector[10]){
    int value = vector[0];
    int cont = 0, contAux = 0;
    
    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            if(vector[i] == vector[j]){
                contAux++;
            }
        }
        if(contAux > cont){
            cont = contAux;
            value = vector[i];
        }
        contAux = 0;
    }
    return value;
}

int main(){
    int vector[10];

    for(int  i = 0; i < 10; i++){
        scanf("%d", &vector[i]);
    }

    printf("%d %d %.2f %d", max(vector), min(vector), media(vector), mode(vector));
    return 0;

}
