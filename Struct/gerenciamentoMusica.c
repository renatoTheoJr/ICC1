// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @Title  Sistema de Gerenciamento de Músicas

#include<stdio.h>

typedef struct music
{
    char *name;
    char *artist;
    int second;
}Music;

typedef struct playlist
{
    char *name;
    int total;
    Music musics[15];
}Playlist;

char *readLine(char* line){
    int contSize = 1;
    char caracter = ' ';
    line = (char*) malloc(contSize * sizeof(char));

    caracter = getchar();
    while (caracter != '\n'){
        line[contSize - 1] = caracter;
        caracter = getchar();
        contSize++;
        line = (char*) realloc(line, sizeof(char)*contSize);
    }
    line[contSize - 1] = '\0'; 
    
    return line;
}

int main(){
    Playlist playlist1;
    playlist1.name = readLine(playlist1.name);
    playlist1.total = 0;
    int comand;
    do{
        scanf("%d", &comand);

        if(comand == 1){
            if(playlist1.total == 15){
                printf("Muita música");
            }else{
                playlist1.musics[playlist1.total].name = readLine(playlist1.musics[playlist1.total].name);
                playlist1.musics[playlist1.total].artist = readLine(playlist1.musics[playlist1.total].artist);
                scanf("%d", &playlist1.musics[playlist1.total].second);
                playlist1.total++;

            }
        }

    }while (comand != 5);
    

    return 0;
}

