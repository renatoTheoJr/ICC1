#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Substituição de valores podemos escrever novos dados na mesma estrutura
	Exemplo:
	-	Anteriormente no arquivo: 1000 -30  10.99 fernando
	-	Ao escrever novos dados:  1000 -30 100.88 fernando (** o 10.99 foi substituido por 100.88)
	-	Reparem que os dois valores possuem o mesmo tamanho e tipo de dado (float)
	
	Exemplo 2 (Incluir um terceiro valor do vetor - incluir o número 20): vetor(1000 -30 20), 10.99, fernando
	-	Anteriormente no arquivo: 1000 -30  10.99 fernando
	-	Ao escrever novos dados:  1000 -30  20    fernando	
	-	Alternativa mais viável:  1000 -30  10.99 fernando 20	
	-	Cuidado!!!
	
	- Imagina que escreveu isso: 1000 -30 20 10.99 fernando
	- Mas, na verdade o arquivo: 1000 -30 20       fernando
	- Na leitura, você espera:   int int int float char[10]
	- O que realmente lê:        int int int       char[10]
	
	Escrevendo no meio do arquivo:
	- substituindo bytes (ok)
	- incluir novos dados antes do final do arquivo:
	-	reescrever todos os dados após o cursor (não pode escrever somente o 20) -> r+b
		- o cursor não "empurra" os bytes
		-	(colocar o curso na posição (1000 -30)
			(reescreve todos os valores após (20 10.99 fernando)
	-	ou incluir este novo dado no final do arquivo (1000 -30  10.99 fernando 20) -> append (ab)
*/

int main(){
	FILE *arquivoBinario = fopen("binario.dat","wb");
	
	if (!arquivoBinario){
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	
	int vetor[2] = {1000, -30};
	float numero = 10.99;
	char palavra[10] = "fernando";
	
	//escrevendo no arquivo
	fwrite(vetor, sizeof(int), 2, arquivoBinario);
	fwrite(&numero, sizeof(float), 1, arquivoBinario);
	fwrite(palavra, sizeof(char), 10, arquivoBinario);
	fclose(arquivoBinario); 
	
	//abrindo arquivo em modo de leitura
	FILE *arquivoLeitura = fopen("binario.dat","rb");
	vetor[0] = 0;
	vetor[1] = 0;
	numero = 0;
	char palavra2[10] = "";
	
	printf("\nLendo os dados do arquivo:\n");
	fread(&vetor[0], sizeof(int), 1, arquivoLeitura);
	fread(&vetor[1], sizeof(int), 1, arquivoLeitura);
	fread(&numero, sizeof(float), 1, arquivoLeitura);
	fread(palavra2, sizeof(char), 10, arquivoLeitura);
	fclose(arquivoLeitura);
	
	printf("Vetor[0]: %i\n", vetor[0]);
	printf("Vetor[1]: %i\n", vetor[1]);
	printf("Numero: %f\n", numero);
	printf("Palavra: %s\n", palavra);
	
	printf("****************************\n\n\n");
	//abrindo arquivo em modo de leitura
	FILE *arquivoEscrita = fopen("binario.dat","r+b");//abrindo para leitura e escrita (arquivo existe)
	numero = 100.88;
	
	//avançando 8 bytes, ou seja, vamos pular os valores referentes ao vetor
	fseek(arquivoLeitura, 8, SEEK_CUR);
	fwrite(&numero, sizeof(float), 1, arquivoEscrita);
	fclose(arquivoBinario); 
	
	//abrindo arquivo em modo de leitura
	arquivoLeitura = fopen("binario.dat","rb");
	
	vetor[0] = 0;
	vetor[1] = 0;
	numero = 0;
	strcmp(palavra2, "");
	
	printf("\nLendo os dados do arquivo novamente:\n");
	fread(vetor, sizeof(int), 2, arquivoLeitura);
	fread(&numero, sizeof(float), 1, arquivoLeitura);
	fread(palavra2, sizeof(char), 10, arquivoLeitura);
	fclose(arquivoLeitura);
	
	printf("Vetor[0]: %i\n", vetor[0]);
	printf("Vetor[1]: %i\n", vetor[1]);
	printf("Numero: %.2f\n", numero);
	printf("Palavra: %s\n", palavra);
	
	return 0;
}
