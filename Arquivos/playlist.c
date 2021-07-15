// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @Title  [Bloco 3 - 01] Sistema de Gerenciamento de Playlists 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void binaryToNum(char *binFilename) {
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)) {
        binValue += (double) ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}

int main(){
    Playlist playlist1;
    playlist1.name = readLine();
    playlist1.total = 0;
    playlist1.musicPlayIndex = 0;
    playlist1.musics = NULL;
    int flagError = 0;
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
        }else if(comand == 5){
            char *nameFile;
            scanf("%*[\r\n]s");
            nameFile = readLine();

            FILE *fileBin = fopen(nameFile,"wb");
	
            if (!fileBin){
                printf("Arquivo %s nao existe.", nameFile);
                flagError = 1;
                free(nameFile);
            }else{
                int sizeName = strlen(playlist1.name);
                fwrite(&sizeName, sizeof(int), 1, fileBin);
                fwrite(playlist1.name, sizeof(char), sizeName, fileBin);
                fwrite(&playlist1.total, sizeof(int), 1, fileBin);

                for(int i = 0; i < playlist1.total; i++){
                    sizeName = strlen(playlist1.musics[i].name);
                    fwrite(&sizeName, sizeof(int), 1, fileBin);
                    fwrite(playlist1.musics[i].name, sizeof(char), sizeName, fileBin);
                    sizeName = strlen(playlist1.musics[i].artist);
                    fwrite(&sizeName, sizeof(int), 1, fileBin);
                    fwrite(playlist1.musics[i].artist, sizeof(char), sizeName, fileBin);
                    fwrite(&playlist1.musics[i].second, sizeof(int), 1, fileBin); 
                }
                printf("Playlist %s salva com sucesso.\n",nameFile);
                fclose(fileBin);
                binaryToNum(nameFile);
                free(nameFile);
            }
       }else if(comand == 6){
           char *nameFile;
            scanf("%*[\r\n]s");
            nameFile = readLine();

            FILE *fileBin = fopen(nameFile,"rb");
	
            if (!fileBin){
                printf("Arquivo %s nao existe.", nameFile);
                free(nameFile);
                flagError = 1;
            }else{

                int sizeName;
                fread(&sizeName, sizeof(int), 1, fileBin);
                playlist1.name = realloc(playlist1.name, (sizeName + 1) * sizeof(char));
                fread(playlist1.name, sizeof(char), sizeName, fileBin);
                playlist1.name[sizeName] = '\0';
                fread(&playlist1.total, sizeof(int), 1, fileBin);

                playlist1.musics = realloc(playlist1.musics, playlist1.total * sizeof(Music));

                for(int i = 0; i < playlist1.total; i++){
                    fread(&sizeName, sizeof(int), 1, fileBin);
                    playlist1.musics[i].name = realloc(playlist1.musics[i].name, (sizeName + 1) * sizeof(char));
                    fread(playlist1.musics[i].name, sizeof(char), sizeName, fileBin);
                    playlist1.musics[i].name[sizeName] = '\0';
                    fread(&sizeName, sizeof(int), 1, fileBin);
                    playlist1.musics[i].artist = realloc(playlist1.musics[i].artist, (sizeName + 1) * sizeof(char));
                    fread(playlist1.musics[i].artist, sizeof(char), sizeName, fileBin);
                    playlist1.musics[i].artist[sizeName] = '\0';
                    fread(&playlist1.musics[i].second, sizeof(int), 1, fileBin); 
                }
                playlist1.musicPlayIndex = 0;
                printf("Playlist %s carregada com sucesso.\n",nameFile);
                binaryToNum(nameFile);
                free(nameFile);
                fclose(fileBin);
            }
       }    

    }while (comand != 7 && !flagError);

    for(int i = 0; i < playlist1.total; i++){
        free(playlist1.musics[i].artist);
        free(playlist1.musics[i].name);
    }
    free(playlist1.musics);
    free(playlist1.name);

    return 0;
}
