#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Funções para arquivos: binários
	fopen(ponteiro, arquivo)
	fclose(ponteiro)
	fwrite(buffer, tamanho, quantidade, ponteiro)
	fread(buffer, tamanho, quantidade, ponteiro)

	Funções complementares para arquivos:
	- feof(ponteiro): 
	* não verifica efetivamente se chegou ao final do arquivo
	* apenas indica uma tentativa de leitura mal sucedida 
	
	- fseek(ponteiro, offset, origem):
	----- offset: quantidade de bytes a pular ou voltar
	----- origem (SEEK_SET: início de arquivo;
				  SEEK_CUR: posição atual do ponteiro;
				  SEEK_END: fim do arquivo)
	* Exemplo: fseek(arquivo, 0, SEEK_SET): ir para o início do arquivo
			   fseek(arquivo, 0, SEEK_END): ir para o final do arquivo
			   fseek(arquivo, 128, SEEK_CUR): avançar 128 bytes a partir da posição atual
			   fseek(arquivo, -4, SEEK_CUR): retroceder 4 bytes a partir da posição atual
			   
	- outras funções para complementar:
	* remove: remover um arquivo
	* rename: renomear um arquivo
	* ferror: verificar erro na leitura de um arquivo
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
	
	fprintf(stdout, "Gravando dados no arquivo.\n");
	fclose(arquivoBinario); 
	
	//abrindo arquivo em modo de leitura
	FILE *arquivoLeitura = fopen("binario.dat","rb");
	vetor[0] = 0;
	vetor[1] = 0;
	numero = 0;
	char palavra2[10] = "";
	
	printf("\nLendo os dados do arquivo:\n");
	fread(&vetor[0], sizeof(int), 1, arquivoLeitura);
	
	//avançando 4 bytes, ou seja, vamos pular o valor referente a vetor[1]
	fseek(arquivoLeitura, -4, SEEK_CUR);
	
	fread(&numero, sizeof(float), 1, arquivoLeitura);
	fread(&palavra2, sizeof(char), 10, arquivoLeitura);
	
	printf("Vetor[0]: %i\n", vetor[0]);
	printf("Vetor[1]: %i\n", vetor[1]);
	printf("Numero: %f\n", numero);
	printf("Palavra: %s\n", palavra);
	
	fclose(arquivoLeitura);
	
	return 0;
}
