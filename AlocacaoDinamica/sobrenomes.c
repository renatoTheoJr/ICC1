/* @author Renato Tadeu Theodoro Junior
   @USP  11796750
   @Title [5 - Alocação Dinâmica] Adicionando Sobrenomes
*/
#include <stdio.h>
#include <stdlib.h>

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
    char **listNames = malloc(1 * sizeof(char *));
    int flagRead = 1;
    int numberNames = 0;
    
    int sizeLastName = 1;
    char *lastName = (char*) malloc(sizeLastName * sizeof(char));

    while(flagRead){
        numberNames++;
        listNames = realloc(listNames, numberNames * sizeof(char *));

        int sizeName = 1;
        listNames[numberNames - 1] = (char*) malloc(sizeName * sizeof(char));

        char caracter = getchar();
        while (caracter != '\n' && (int) caracter != 36){
            if((numberNames - 1) % 2 == 0){
                if(caracter == ' '){
                    sizeLastName = 1;
                }else{
                    lastName[sizeLastName - 1] = caracter;
                    sizeLastName++;
                }
                lastName = (char*) realloc(lastName, sizeLastName * sizeof(char));
            }
            listNames[numberNames - 1][sizeName - 1] = caracter;
            caracter = getchar();
            sizeName++;
            listNames[numberNames - 1] = (char*) realloc(listNames[numberNames - 1], sizeof(char)*sizeName);
        }

        if((numberNames - 1) % 2 != 0 ){
            listNames[numberNames - 1][sizeName  - 1] = ' ';
            sizeName++;
            listNames[numberNames - 1] = (char*) realloc(listNames[numberNames - 1], sizeof(char)*sizeName);

            for(int i = 0; i < sizeLastName - 1; i++){
                listNames[numberNames - 1][sizeName  - 1] = lastName[i];
                sizeName++;
                listNames[numberNames - 1] = (char*) realloc(listNames[numberNames - 1], sizeof(char)*sizeName);
             }
             listNames[numberNames - 1][sizeName - 1] = '\0';
             sizeLastName = 1;
             lastName = (char*) realloc(lastName, sizeLastName * sizeof(char));
        }
        listNames[numberNames - 1][sizeName - 1] = '\0';

        if((int) caracter == 36){
            flagRead = 0;
        }
    }

    free(lastName);

    for(int i = 0; i < numberNames; i++){
        printf("%s\n", listNames[i]);
        free(listNames[i]);
    }
    free(listNames);

    return 0;
}
