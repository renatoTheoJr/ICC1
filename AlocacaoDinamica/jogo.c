/* @author Renato Tadeu Theodoro Junior
   @USP  11796750
   @Title [5 - Alocação Dinâmica] Ataques e Tipos
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int numberTypes;
    scanf("%d", &numberTypes);
    float **tableAtacks;
    tableAtacks = malloc(numberTypes * sizeof(float *));
    
    for(int i = 0; i < numberTypes; i++){
        tableAtacks[i] = malloc(numberTypes * sizeof(float));
        for(int j = 0; j < numberTypes; j++){
            scanf("%f", &tableAtacks[i][j]);
        }
    }

    int indexAtacks = 0;
    int **listAtacks = malloc(sizeof(void * ));
    listAtacks[indexAtacks] = malloc(2 * sizeof(int));

    int flagRead  = 1;
    while (flagRead){
        scanf("%d", &listAtacks[indexAtacks][0]);
    
        if(listAtacks[indexAtacks][0] != -1){
            scanf("%d", &listAtacks[indexAtacks][1]);
            indexAtacks++;
            listAtacks = realloc(listAtacks, (indexAtacks + 1) * sizeof(void *));
            listAtacks[indexAtacks] = malloc(2 * sizeof(int));
        }else{
            flagRead = 0;
            indexAtacks--;
        }
    }

    int typeEnemy;
    scanf("%d", &typeEnemy);
    
    int bestIndex = -1;
    float bestAtack = -1.0;
    for(int i = 0; i <= indexAtacks; i++){
        float atack = listAtacks[i][0] * (tableAtacks[listAtacks[i][1]][typeEnemy]);
        if(atack > bestAtack){
            bestAtack = atack;
            bestIndex = i;
        }
        free(listAtacks[i]);
    }

    free(listAtacks[indexAtacks+1]); // Have the -1 value
    free(listAtacks);

    for(int i = 0; i < numberTypes; i++){
        free(tableAtacks[i]);
    }
    free(tableAtacks);

    printf("O melhor ataque possui indice %d e dano %.2f", bestIndex, bestAtack);
    return 0;
}