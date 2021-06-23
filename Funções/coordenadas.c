//Renato Tadeu Theodoro Junior - 11796750
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double metodoEuclides(int x1, int x2, int y1, int y2){
    double result = (double) (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    return sqrt(result);
}

double metodoHermann(int x1, int x2, int y1, int y2){
    double result = (double) abs(x2 - x1) + abs(y2 - y1);
    return result;
}

int main(){
    int n; 
    scanf("%d", &n);

    if(n<1){
        printf("Falha no processamento dos dados.\n");
        return 0;
    }

    int coordenadas[n][3]; //n - Número de estabelecimentos / 3 - x, y, i(tipo de quadra)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &coordenadas[i][j]);
        }
        if(coordenadas[i][2] < -1 || coordenadas[i][2] > 1){
            printf("Falha no processamento dos dados.\n");
            return 0;
        }
    }

    int parque = 0, baldio = 0, residencial = 0;
    double distanciaHermann = 0, distanciaEuclides = 0;

    for(int i = 0; i < n; i++){
        double dist = 0.0;
        int next = i+1;
    
        if(i == n-1){ // Para a volta 
            next = 0;
        }

        if(coordenadas[i][2] == -1){
            baldio++;
            dist = metodoEuclides(coordenadas[i][0], coordenadas[next][0], coordenadas[i][1], coordenadas[next][1]);
            distanciaHermann += dist;
            distanciaEuclides += dist;
        }else if(coordenadas[i][2] == 0){
            residencial++;
            dist = metodoHermann(coordenadas[i][0], coordenadas[next][0], coordenadas[i][1], coordenadas[next][1]);
            distanciaHermann += dist;
            distanciaEuclides += dist;

        }else{
            parque++;
            distanciaHermann += metodoHermann(coordenadas[i][0], coordenadas[next][0], coordenadas[i][1], coordenadas[next][1]);
            distanciaEuclides += metodoEuclides(coordenadas[i][0], coordenadas[next][0], coordenadas[i][1], coordenadas[next][1]);
        }
    }
    double dist = 0.0;

  
    dist = fabs(distanciaHermann - distanciaEuclides);
    
    
    printf("Ao todo, foi passado por %d terrenos baldios, %d terrenos residenciais e %d parques.\nA diferenca total de distancia percorrida foi de %.2lf metros.", baldio, residencial, parque, dist);


}