// Renato Tadeu Theodoro Junior - 11796750
#include <stdio.h>

int main(){
    char tabuleiro[3][3];
    int flagNaoPrenchido =0; // Para saber se há um espaço sem preencher
    int flagGanhador = 0; // Para saber se há um ganhador
    char ganhador = ' ';
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%c", &tabuleiro[i][j]);
            if(tabuleiro[i][j] == ' ' || tabuleiro[i][j] == '\n'){
                j--;
            }
            if(tabuleiro[i][j] == '-'){
                flagNaoPrenchido = 1;
            }
        }
    }

    for(int i=0; i<3; i++){ // Verificar se alguém ganhou nas linhas /colubas
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0]== tabuleiro[i][2] && tabuleiro[i][0] !='-'){
            flagGanhador = 1;
            ganhador = tabuleiro[i][0];
        }else if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i]== tabuleiro[2][i] && tabuleiro[0][i] !='-'){
            flagGanhador = 1;
            ganhador = tabuleiro[i][0];
        }
    }
    if(tabuleiro[0][0] == tabuleiro [1][1] && tabuleiro[0][0] == tabuleiro[2][2] && tabuleiro[0][0] !='-'){ //verificando diagonais
        flagGanhador = 1;
        ganhador = tabuleiro[0][0];
    }else if(tabuleiro[0][2] == tabuleiro [1][1] && tabuleiro[0][2] ==tabuleiro[2][0] && tabuleiro[0][2] !='-'){ // verificando diagonais
        flagGanhador = 1;
        ganhador = tabuleiro[0][2];

    }


    if(flagGanhador){
        printf("%c ganhou", ganhador);
    }else if(flagNaoPrenchido){ //Caso ainda tenha jogadas a ser feitas
        printf("em jogo");
    }else{
        printf("empate");
    }
    return 0;
    

}