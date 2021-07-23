// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @Title  Sistema de Gerenciamento de Músicas

#include<stdio.h>
#include <stdlib.h>

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
    int musicPlayIndex;
    Music *musics;
}Playlist;

char *readLine(){
    char* line;
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
    playlist1.name = readLine();
    playlist1.total = 0;
    playlist1.musicPlayIndex = 0;
    playlist1.musics = NULL;
    int comand;
    do{
        scanf("%d", &comand);

        if(comand == 1){
            scanf("%*[\r\n]s");
            if(playlist1.total == 15){
                printf("Playlist cheia!\n");
            }else{
                playlist1.total++;
                playlist1.musics = realloc(playlist1.musics, playlist1.total * sizeof(Music));
                playlist1.musics[playlist1.total - 1].name = readLine();
                playlist1.musics[playlist1.total - 1].artist = readLine();
                scanf("%d", &playlist1.musics[playlist1.total - 1].second);
                printf("Musica %s de %s adicionada com sucesso.\n", playlist1.musics[playlist1.total - 1].name, playlist1.musics[playlist1.total - 1].artist); 
                scanf("%*[\r\n]s");
            }
        }else if(comand == 2){
            printf("---- Playlist: %s ----\n", playlist1.name);
            printf("Total de musicas: %d\n\n", playlist1.total);
            for(int i = 0; i < playlist1.total; i++){
                if(i == playlist1.musicPlayIndex){
                    printf("=== NOW PLAYING ===\n");
                }
                printf("(%d). '%s'\n", i + 1, playlist1.musics[i].name);
                printf("Artista: %s\n", playlist1.musics[i].artist);
                printf("Duracao: %d segundos\n\n", playlist1.musics[i].second);
            }
        }else if(comand == 3){
            playlist1.musicPlayIndex++;
            
            if(playlist1.musicPlayIndex == playlist1.total){ // Total de Musicas > Total de Index
                playlist1.musicPlayIndex = 0;
            } 
        }else if(comand == 4){
            playlist1.musicPlayIndex--;
            if(playlist1.musicPlayIndex < 0){
                playlist1.musicPlayIndex = playlist1.total - 1;
            }
        }

    }while (comand != 5);
    for(int i = 0; i < playlist1.total; i++){
        free(playlist1.musics[i].artist);
        free(playlist1.musics[i].name);
    }
    free(playlist1.musics);
    free(playlist1.name);

    return 0;
}

