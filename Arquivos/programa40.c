#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Arquivos binários: caracteres codificados em binários
	
	Os arquivos em texto são mais complicados para leitura e escrita:
	- devem ter uma sequência bem definida
	- as funções de leitura devem estar preparadas (%c, %i, %f, etc)
	
	Os arquivos binários:
	- de certa forma dificulta a leitura não desejada externamente
	- a gravação pode ser realizada em blocos, sem preocupação em relação à estrutura
	- utilizamos fwrite() e fread()
*/

int main(){
	//abertura do arquivo (caminho, modo de abertura)
	//Modos de abertura para arquivos binários: "wb", "rb", "ab", "w+b", "r+b", "a+b"
	FILE *arquivoBinario = fopen("binario.dat","wb");
	
	if (!arquivoBinario){
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	
	int vetor[2] = {1000, -30};
	float numero = 10.99;
	char palavra[10] = "fernando";
	
	//escrevendo no arquivo
	//fwrite(&vetor[0], sizeof(int), 1, arquivoBinario);
	//fwrite(&vetor[1], sizeof(int), 1, arquivoBinario);
	fwrite(vetor, sizeof(int), 2, arquivoBinario); //escrita em blocos
	fwrite(&numero, sizeof(float), 1, arquivoBinario);
	fwrite(palavra, sizeof(char), 1, arquivoBinario);
	
	fprintf(stdout, "Gravando dados no arquivo.\n");
	fclose(arquivoBinario); 
	
	//abrindo arquivo em modo de leitura
	FILE *arquivoLeitura = fopen("binario.dat","rb");
	vetor[0] = 0;
	vetor[1] = 0;
	numero = 0;
	char palavra2[10] = "";
	
	printf("\nLendo os dados do arquivo:\n");
	//fread(&vetor[0], sizeof(int), 1, arquivoLeitura);
	//fread(&vetor[1], sizeof(int), 1, arquivoLeitura);
	fread(vetor, sizeof(int), 2, arquivoLeitura);
	fread(&numero, sizeof(float), 1, arquivoLeitura);
	fread(&palavra2, sizeof(char), 10, arquivoLeitura);
	
	printf("Vetor[0]: %i\n", vetor[0]);
	printf("Vetor[1]: %i\n", vetor[1]);
	printf("Numero: %f\n", numero);
	printf("Palavra: %s\n", palavra);
	
	fclose(arquivoLeitura);
	
	return 0;
}
