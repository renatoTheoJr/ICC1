#include <stdio.h>

int main(){
	int tamanho;
	char caracter;
	scanf("%i", &tamanho);

	if(tamanho>25 || tamanho<=0){
		printf("Altura invalida\n");
		return 0;
	}
	
	scanf(" %c", &caracter);
	for(int i=1; i<=tamanho; i++){
		for(int j=0; j<tamanho-i; j++){
			printf(" ");
		}
		for(int k=0; k<2*i-1; k++){
			printf("%c", caracter);
		}
		printf("\n");
	}
}
