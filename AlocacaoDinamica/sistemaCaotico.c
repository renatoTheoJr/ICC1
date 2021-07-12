// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @title [Trabalho 2] Admirável Mundo Caótico
#include <stdio.h>
#include <stdlib.h>

char lifeOrDead(int livingNeighbors, char state){
    if(livingNeighbors < 2 || livingNeighbors > 3){
        return '.';
    }else if(livingNeighbors == 3){
        return 'x';
    }else{
        return state;
    }
}

void moore(char **ceils, int line, int collum, int generations){
    char copy[line][collum + 1];

    for(int i = 0; i < line; i++){
        for(int j = 0; j <= collum; j++){
            copy[i][j] = ceils[i][j];
        }
    }

    int cont = 0;
    while(cont < generations){
        for(int i = 0; i < line; i++){
            for(int j = 0; j < collum; j++){
                int life = 0;

                for(int k = i - 1; k <= i + 1; k++){
                    for(int l = j -1; l <= j + 1; l++){
                        int auxK = k, auxL = l;

                        if(!(k == i && l == j)){
                            if(k < 0){
                                auxK = line - 1;
                            }else if(k >= line){
                                auxK = 0;
                            }

                            if(l < 0){
                                auxL = collum - 1;
                            }else if(l >= collum){
                                auxL = 0;
                            }

                            if(ceils[auxK][auxL] == 'x'){
                                life++;
                            }  
                        } 
                    }
                }
                copy[i][j] = lifeOrDead(life, ceils[i][j]);
            }
        }
        cont++;
        
        for(int i = 0; i < line; i++){
            for(int j = 0; j < collum; j++){
                ceils[i][j] = copy[i][j];
            }
        }
    }
}

void vonNeumann(char **ceils, int line, int collum, int generations){
    char copy[line][collum + 1];

    for(int i = 0; i < line; i++){
        for(int j = 0; j <= collum; j++){
            copy[i][j] = ceils[i][j];
        }
    }

    int cont = 0;
    while(cont < generations){
        for(int i = 0; i < line; i++){
            for(int j = 0; j < collum; j++){
                int life = 0;

                for(int k = i - 2; k <= i + 2; k++){
                    if(k != i){
                        int auxK;
                        if(k == -1){
                            auxK = line - 1;
                        }else if(k == -2){
                            auxK = line - 2;
                        }else if(k == line){
                            auxK = 0;
                        }else if(k == line + 1){
                            auxK = 1;
                        }else{
                            auxK = k;
                        }

                        if(ceils[auxK][j] == 'x'){
                            life++;
                        }
                    }
                }

                for(int k = j - 2; k <= j + 2; k++){
                    if( k != j){
                        int auxK;
                        if(k == -1){
                            auxK = collum - 1;
                        }else if(k == -2){
                            auxK = collum - 2;
                        }else if(k == collum){
                            auxK = 0;
                        }else if(k == collum + 1){
                            auxK = 1;
                        }else{
                            auxK = k;
                        }

                        if(ceils[i][auxK] == 'x'){
                            life++;
                        }
                    }
                }

                copy[i][j] = lifeOrDead(life, ceils[i][j]);
            }
        }
        cont++;
        
        for(int i = 0; i < line; i++){
            for(int j = 0; j < collum; j++){
                ceils[i][j] = copy[i][j];
            }
        }
    }

}


int main(){
    int line, collum, generations;
    scanf("%d %d", &line, &collum);
    scanf("%d", &generations);
    char model;
    scanf("%*[\r\n]s");
    scanf("%c", &model);
    scanf("%*[\r\n]s");


    if(line <= 0 || collum <= 0 || generations <= 0 || (model != 'N' && model != 'M')){
        printf("Dados de entrada apresentam erro.\n");
        exit(1);
    }

    char **ceils = malloc(line * sizeof(void *));

    for(int i = 0; i < line; i++){
        ceils[i] = malloc((collum + 1) * sizeof(char));
        for(int j = 0; j <= collum; j++){
            scanf("%c", &ceils[i][j]);
        }
    }
    
    if(model == 'M'){
        moore(ceils, line, collum, generations);
    }else{
        vonNeumann(ceils, line, collum, generations);
    }

    for(int i = 0; i < line; i++){
        for(int j = 0; j <= collum; j++){
            printf("%c", ceils[i][j]);
        }
        free(ceils[i]);
    }

    free(ceils);
    return 0;
}