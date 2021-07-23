/* @author Renato Tadeu Theodoro Junior
   @USP  11796750
   @Title [5 - Alocação Dinâmica] Retirar Palavra Tabu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char tabu[20];
    scanf("%s\n", tabu);
    int sizeTabu = strlen(tabu);

    char *phrase = malloc(sizeof(char ));
    int sizePhrase = 1;

    int indexTabu = 0;
    int totalTabu = 0;
    char caracter = getchar();

    while ((int) caracter != 36){
        phrase[sizePhrase - 1] = caracter;

        if(caracter == tabu[indexTabu]){
            if(indexTabu == sizeTabu - 1){
                totalTabu++;
                sizePhrase -= indexTabu + 1;
                indexTabu = 0;
            }else{
                indexTabu++;
            }
        }else{
            indexTabu = 0;
        }
        caracter = getchar();
        sizePhrase++;
        phrase = (char*) realloc(phrase, sizePhrase * sizeof(char));
    }
    phrase[sizePhrase - 1] = '\0'; 

    printf("A palavra tabu foi encontrada %d vezes\n", totalTabu);
    printf("Frase: %s\n", phrase);
    free(phrase);

    return 0;
}
