// Renato Tadeu Theodoro Junior - 11796750
#include <stdio.h>

int main(){
    int histograma[25];
    int vetorContador[5] = {0, 0, 0, 0, 0};

    for(int i = 0; i < 25; i++){
        scanf("%d", &histograma[i]);
        vetorContador[histograma[i]]++;
    }

    int maior = vetorContador[0], indiceMaior = 0;
    for(int i = 0; i < 5; i++){
        if(maior < vetorContador[i]){
            maior = vetorContador[i];
            indiceMaior = i;
        }
        printf("%d: |", i);
        for(int j = 0; j < vetorContador[i]; j++){
            printf("#");
        }
        printf("\n");
    }
    
    for(int i = 0; i < 25;  i++){
        if(histograma[i] == indiceMaior){
            printf("%d\n", i);
        }
    }

    return 0;
}