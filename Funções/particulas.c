// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @title [4 - Funções] Simulação de Partículas
#include <stdio.h>

void showParticles(char particles[32][65]){
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 65; j++){
            printf("%c", particles[i][j]);
        }
    }
}

void applyPhysics(char particles[32][65]){
    char copy[33][64];
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            copy[i][j] = particles[i][j];
        }
    }

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
                char aux = copy[i][j];
                if(particles[i][j] == '#'){
                    if((particles[i +1 ][j] == '~' || particles[i + 1][j] == ' ') && (i + 1 < 32 )){
                        copy[i][j] = copy[i + 1][j];
                        copy[i + 1][j] = aux;
                    }else if((particles[i + 1][j - 1] == '~' || particles[i + 1][j - 1] == ' ') && (i + 1 < 32 ) && (j - 1 > -1 )){
                        copy[i][j] = copy[i + 1][j - 1];
                        copy[i + 1][j - 1] = aux;
                    }else if((particles[i + 1][j + 1] == '~' || particles[i + 1][j + 1] == ' ') && (i + 1 < 32 ) && (j + 1 < 64 )){
                        copy[i][j] = copy[i + 1][j + 1];
                        copy[i + 1][j + 1] = aux;
                    }
                }else if(particles[i][j] == '~'){
                    if((particles[i + 1][j] == ' ') && (i + 1 < 32 )){
                        copy[i][j] = copy[i + 1][j];
                        copy[i + 1][j] = aux;
            
                    }else if((particles[i + 1][j - 1] == ' ') && (i + 1 < 32 ) && (j - 1 > -1 )){
                        copy[i][j] = copy[i + 1][j - 1];
                        copy[i + 1][j - 1] = aux;
            
                    }else if((particles[i + 1][j + 1] == ' ') && (i + 1 < 32 ) && (j + 1 < 64 )){
                        copy[i][j] = copy[i + 1][j + 1];
                        copy[i + 1][j + 1] = aux;

                    }else if((particles[i][j - 1] == ' ') && (j - 1 > -1 )){
                        copy[i][j] = copy[i][j - 1];
                        copy[i][j - 1] = aux;

                    }else if((particles[i][j + 1] == ' ') && (j + 1 < 64 )){
                        copy[i][j] = copy[i][j + 1];
                        copy[i][j + 1] = aux;

                    }
                }
        }
    }

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            particles[i][j] = copy[i][j];
        }
    }
   
}

int main(){
    char particles[32][65];
    int numberFrames, frame, collum, line;
    char newParticle;

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            particles[i][j] = ' ';
        }
        particles[i][64] = '\n';
    }

    scanf("%d", &numberFrames);

    int cont = 0;

    while (cont < numberFrames) {
        int valueReader = scanf(" %d: %d %d %c", &frame, &collum, &line, &newParticle);

        if (valueReader == EOF) {
                frame = numberFrames;
        }

        while (cont < frame) {
                printf("frame: %d\n", cont + 1);
                showParticles(particles);
                applyPhysics(particles);
                cont++;
        }

        if (numberFrames != EOF) {
                particles[line][collum] = newParticle;
        }
    }

    return 0;
}

