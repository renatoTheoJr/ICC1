/* @author Renato Tadeu Theodoro Junior
   @USP  11796750
   @Title Livro Corrompido
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
    int numberLines = 0;
    scanf("%d", &numberLines);
    scanf("%*[\r\n]s"); 

	char **text = malloc(numberLines * sizeof(void *)); 
    
    for(int i = 0; i < numberLines; i++){
        text[i] = readLine(text[i]);
    }

    int validLines = 0;
    scanf("%d",&validLines);

    int indexs[validLines];

    for(int i = 0; i < validLines; i++){
        scanf("%d", &indexs[i]);
    }

    for(int i = 0; i < validLines; i++){
        printf("%s\n", text[indexs[i]]);
    }
    
    for (int i = 0; i < numberLines; i++){
        free(text[i]);
    }
    free(text);

    return 0;
}
