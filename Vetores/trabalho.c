// Author: Renato Tadeu Theodoro Junior 
// No USP: 11796750
// [Trabalho 1] Cleyton, o Punk de 2077
#include <stdio.h>

int main(){
	int lista[512];

	for(int i=0; i<512; i++){
		scanf("%d", &lista[i]);
	}

	int indice = 0;
	printf("Saida do programa:\n");

	while(indice <512 && lista[indice]!=0){ // Enquanto não chegar ao final da lista ou no código zero
		int add1, add2, dest;
		int number, ascii;
		//Para aplicar as regras será feito um switch para cada caso.
		switch(lista[indice]){
			case 0: // Operação 0 - HLT
				break;
			case 1: //Operacao 1 - ADD
				add1 = lista[indice+1];
				add2 = lista[indice+2];
				dest = lista[indice+3];
				indice+=4;
				lista[dest] = lista[add1] + lista[add2];
				break;
			case 2: // Operacao 2 - Mult
				add1 = lista[indice+1];
				add2 = lista[indice+2];
				dest = lista[indice+3];
				indice+=4;
				lista[dest] = lista[add1]*lista[add2];
				break;
			case 3: // Operacao 3 - CLT
				add1 = lista[indice+1];
				add2 = lista[indice+2];
				dest = lista[indice+3];
				indice+=4;
				lista[dest]= lista[add1]<lista[add2];
				break;
			case 4: // Operacao 4 - CEQ
				add1 = lista[indice+1];
				add2 = lista[indice+2];
				dest = lista[indice+3];
				indice+=4;
			    lista[dest]= lista[add1]==lista[add2];				
				break;
			case 5: // Operacao 5 - JMP
				add1 = lista[indice+1];
				indice = lista[add1];
				break;
			case 6: // Operacao 6 - Jeq
				add1 = lista[indice+1];
				add2 = lista[indice+2];
				if(lista[add1] !=0){
					indice = lista[add2];
				}else{
					indice ++;
				}
				break;
			case 7: //Operacao 7 - CPY
				add1 = lista[indice+1];
				dest = lista[indice+2];
				lista[dest] = lista[add1];
				indice +=3;
				break;
			case 8: //Operação 8 -PUT
				add1 = lista[indice+1];
				ascii = lista[add1];
				printf("%c", ascii);
				indice+=2;
				break;
			case 9: // Operação 9 - PTN
				add1 = lista[indice+1];
				number = lista[add1];
				printf("%d", number);
				indice+=2;
				break;
			default:
				indice++;
				break;
		}
	}

	printf("\nEstado final da fita:\n");

	

	for(int i=0; i<512; i++){
		printf("%d\n", lista[i]);
	}

	return 0;
}
