#include <stdio.h>
#include <stdlib.h>

/*Conteúdo: 
	- Alocação dinâmica e Memória Heap...
	- malloc()
	- free()
*/

void preencherMatrizStack(int linhas, int colunas, int matriz[][colunas]){
	int i, j;
	for(i=0;i<linhas;i++)
		for(j=0;j<colunas;j++)
			matriz[i][j] = i*j;
}

void imprimirMatrizStack(int linhas, int colunas, int matriz[][colunas]){
	int i, j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++)
			printf("%i ", matriz[i][j]);
		printf("\n");
	}
}

int somaMatrizStack(int linhas, int colunas, int matriz[][colunas]){
	int i, j, soma=0;
	for(i=0;i<linhas;i++)
		for(j=0;j<colunas;j++)
			soma = soma + matriz[i][j];
	return soma;
}

void preencherMatrizHeap(int linhas, int colunas, int **matriz);
void imprimirMatrizHeap(int linhas, int colunas, int **matriz);
int somaMatrizHeap(int linhas, int colunas, int **matriz);

int main(){
	int i, j;
	
	int linhas = 4;
	int colunas = 7;
	int matrizStack[linhas][colunas];
	
	printf("Alocacao na Memoria Stack\n");
	preencherMatrizStack(linhas, colunas, matrizStack);
	imprimirMatrizStack(linhas, colunas, matrizStack);
	printf("Soma dos valores da matriz: %i\n", somaMatrizStack(linhas, colunas, matrizStack));
	printf("***********************************\n");
	
	//criando uma variavel inteira na memoria heap
	printf("\nAlocacao na Memoria Heap com dados comuns\n");
	int *numero = malloc(sizeof(int));
	printf("Endereco na Memoria Heap: %p\n", numero);
	
	printf("Valor antes da atribuicao: %i\n", *numero);
	*numero = 111;
	printf("Valor apos atribuicao: %i\n", *numero);
	
	if (numero == NULL)//podemos verificar se teremos memoria suficiente para alocar
		printf("Memoria insuficiente");
		
	printf("Desalocar o dado comum na Memoria Heap\n");
	free(numero);
	printf("***********************************\n");
	
	//construindo um vetor de 4 posições de inteiros na memoria heap
	printf("\nAlocacao na Memoria Heap com vetor\n");
	int *vetorHeap = (int *)malloc(4 * sizeof(int));
	printf("Endereco na Memoria Heap: %p\n", vetorHeap);
	
	printf("Vetor sem atribuicao: ");
	for(i=0;i<4;i++)
		printf("%i ", *(vetorHeap+i));
	
	printf("\nVetor apos atribuicao: ");
	*vetorHeap = 10;
	*(vetorHeap+3) = 20;
	vetorHeap[2] = -9;
	for(i=0;i<4;i++)
		printf("%i ", *(vetorHeap+i)); //ou printf("%i ", vetorHeap[i]);
	printf("\n");
	
	printf("Desalocar o vetor na Memoria Heap\n");
	free(vetorHeap);
	printf("***********************************\n");
	
	//construindo uma matriz[2][3] de inteiros
	printf("\nAlocacao na Memoria Heap com matriz\n");
	int **matrizHeap = malloc(2 * sizeof(void *)); //quantidade de vetores
	for (j=0; j<3; j++)
		matrizHeap[j] = malloc(3 * sizeof(int)); //definindo o tamanho do vetor
	printf("Endereco na Memoria Heap: %p\n", matrizHeap);
	
	printf("Matriz sem atribuicao:\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
			printf("%i ", matrizHeap[i][j]);
		printf("\n");
	}
	
	printf("Matriz apos atribuicao:\n");
	matrizHeap[1][0] = -89; //coordenada (1,0)
	*(matrizHeap[1]+1) = 7; //coordenada (1,1)
	*(matrizHeap[0]+2) = -30; //coordenada (0,2)
	
	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
			printf("%i ", matrizHeap[i][j]);//ou printf("%i ", *(matrizHeap[i]+j));
		printf("\n");
	}
	
	printf("Desalocar a matriz na Memoria Heap\n");
	for (j=0; j<3; j++)
		free(matrizHeap[j]);//desaloca as linhas
	free(matrizHeap);//desaloca o todo
	printf("***********************************\n");
	
	printf("\nUtilizando as funcoes heap para a matriz heap\n");
	int **matrizHeapHeap = malloc(4 * sizeof(int *));
	for (j=0; j<3; j++)
		matrizHeapHeap[j] = malloc(3 * sizeof(int));
		
	preencherMatrizHeap(4, 3, matrizHeapHeap);
	imprimirMatrizHeap(4, 3, matrizHeapHeap);
	printf("Soma dos valores da matriz: %i\n", somaMatrizHeap(4, 3, matrizHeapHeap));
	
	printf("Desalocar a matriz na Memoria Heap\n");
	free(matrizHeapHeap);//desaloca o todo
	printf("***********************************\n");
	
	/*
	printf("\nUtilizando as mesmas funcoes stack para a matriz heap\n");
	int **matrizHeapStack = malloc(4 * sizeof(int *));
	for (j=0; j<3; j++)
		matrizHeapStack[j] = malloc(3 * sizeof(int));
	
	//por ser uma alocação dinâmica, não temos certeza se a alocação dos espaços é sequencial
	//em alguns casos, podemos até ter o resultado esperado
	//entretanto, não podemos confiar que a alocação dinâmica seguiu o padrão sequencial na alocação
	//assim, devemos sempre considerar que a alocação dinâmica é não sequencial
	preencherMatrizStack(4, 3, matrizHeapStack);
	imprimirMatrizStack(4, 3, matrizHeapStack);
	printf("Soma dos valores da matriz: %i\n", somaMatrizStack(4, 3, matrizHeapStack));
	
	printf("Desalocar a matriz na Memoria Heap\n");
	for (j=0; j<3; j++)
		free(matrizHeapStack[j]);//desaloca as linhas
	free(matrizHeapStack);//desaloca o todo
	printf("***********************************\n");
	//o ultimo printf não é impresso!!!
	//todo o endereçamento correto da matriz é alterado.
	*/
	
	
	//Comentários:
	
	//a vantagem de fazer o free() logo após o uso é reduzir a carga de memória alocada
	//se deixamos para desalocar somente no final, temos uma maior fatia da memória alocada
	
	//antes de finalizar a main() é necessário fazer todo a desalocação, pois o programa pode ser 
	//finalizado, mas o espaço de memória ainda estará reservado, sem acesso.
	
	//há rotinas nos sistemas operacionais que varrem a memória procurando por espaço alocados sem acesso
	//mas, não podemos contar com isso em tempo de execução
	
	//na memória stack:
	//	- só gastamos espaço de memória para as variáveis
	//  - não nos preocupamos com os bytes nem suas posições
	//	- não temos como modificar o que já está alocado
	// 	- possui um tamanho máximo de espaço definida pelo kernel do sistema operacional 
	//	- estamos presos às regras da linguagem
	//	- mais fácil de manipular
	
	//na memória heap:
	//	- gastamos espaço de memória para as variáveis e para os endereços
	//	- teoricamente, podemos usar toda a memória disponível
	//	- temos maior autonomia para trablhar com a memória
	//	- mais complexo de manipular
	//	- por exemplo, podemos definir uma matriz com 3 linhas com colunas de tamanho diferente
	
	//como escolher a forma de trabalho:
	//	- sempre analisando o problema a ser resolvido
	//	- idealmente a solução tem que ser a melhor possível com o menor custo
	//	- isso envolve, resolver o problema para todos os casos, com menos processamento e menos memória
	
	return 0;
}

void preencherMatrizHeap(int linhas, int colunas, int **matriz){
	int i, j;
	for(i=0;i<linhas;i++)
		for(j=0;j<colunas;j++)
			*((*matriz)+linhas*i+j) = i*j;
}

void imprimirMatrizHeap(int linhas, int colunas, int **matriz){
	int i, j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++)
			printf("%i ", *((*matriz)+linhas*i+j));
		printf("\n");
	}
}

int somaMatrizHeap(int linhas, int colunas, int **matriz){
	int i, j, soma=0;
	for(i=0;i<linhas;i++)
		for(j=0;j<colunas;j++)
			soma = soma + *((*matriz)+linhas*i+j);
	return soma;
}
