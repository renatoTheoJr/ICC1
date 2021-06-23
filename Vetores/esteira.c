// Renato Tadeu Theodoro Junior - 11796750

#include <stdio.h>

int main(){
    char esteira[32][65];
    int linha=-1, coluna=-1;
    for(int i=0; i<32; i++){
        for(int j=0; j<65; j++){
            scanf("%c", &esteira[i][j]);
            if(esteira[i][j]=='['){
                linha=i;
                coluna=j+2;
            }
        }
    }
    int flagLoop=1, flagStatus = 0;

    char caraceterAnterior = ' ';
    while (flagLoop==1)
    {
       int linhaAux = linha, colunaAux = coluna;
       int flagAnterior = 0;
       
       if(esteira[linha][coluna] == '#'){
           flagAnterior = 1;
       }

       if(esteira[linha][coluna] == '>' || (flagAnterior && caraceterAnterior == '>')){
           coluna+=2;
       }
       else if(esteira[linha][coluna] == '<' || (flagAnterior && caraceterAnterior == '<')){
           coluna-=2;

       }
         else if(esteira[linha][coluna] == '^' || (flagAnterior && caraceterAnterior == '^')){
           linha-=1;
       }
        else if(esteira[linha][coluna] == 'v' || (flagAnterior && caraceterAnterior == 'v')){
            linha+=1;           
       } else if(esteira[linha][coluna] == ']'){
           flagLoop = 0;
            flagStatus  = 1;
            break;
       }
       else if(esteira[linha][coluna] == '.'){
            flagLoop = 0;
            flagStatus  = 2;
            break;
       }else{
            flagLoop = 0;
            flagStatus  = 3;
            break;
       }
        if(flagAnterior == 0){
            caraceterAnterior = esteira[linhaAux][colunaAux];
            esteira[linhaAux][colunaAux] = '.';
        }
    }
    if(flagStatus == 1){
        printf("Ok.\n");
    }
    else if(flagStatus == 2){
        printf("Loop infinito.\n");
    }
    else if(flagStatus == 3){
        printf("Falha na esteira.\n");
    }

    for(int i=0; i<32; i++){
        for(int j=0; j<65; j++){
            printf("%c", esteira[i][j]);
        }
    }
    
}