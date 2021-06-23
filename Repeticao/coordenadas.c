#include <stdio.h>
int main(){
    int x=0, y=0;
    char direcao;

    for(int i=0; i<6; i++){
        scanf("%c", &direcao);
        switch(direcao){
            case 'W':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'A':
                x--;
                break;
            case 'D':
                x++;
                break;
            default:
                break;
        }
    }
    printf("%i %i\n", x, y);
}