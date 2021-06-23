#include <stdio.h>
#include <stdlib.h>

int main(){
	int La, Ca, Lb, Cb;
	scanf("%d %d", &La, &Ca);
	scanf("%d %d", &Lb, &Cb);

	if(Ca != Lb || La<=0 || Ca <=0 || Lb <=0 || Cb <=0 ){
		printf("Valores invalidos para a multiplicacao.");
		return 0;		
	}
	int semente;
	scanf("%d", &semente);
	srand(semente);
	int matrizA[La][Ca], matrizB[Lb][Cb], result[La][Cb];

	for(int i=0; i<La; i++){
		for(int j=0; j<Ca; j++){
			matrizA[i][j] = rand()%50-25;
		}
	
	}

	for(int i=0; i<Lb; i++){
		for(int j=0; j<Cb; j++){
			matrizB[i][j] = rand() %50-25;

		}
	}

	for(int i=0; i<La; i++){
		printf("Linha %d: ", i);

		for(int j=0; j<Cb; j++){
			result[i][j] = 0; // Zera para não deixar lixo

			for(int k = 0; k<Lb; k++){
					result[i][j]+= matrizA[i][k] * matrizB[k][j];
				
			}
		   printf("%d ", result[i][j]);	
		}
		printf("\n");
	}
}
