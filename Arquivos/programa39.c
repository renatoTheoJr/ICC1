#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Funções para manipulação do arquivo:
	- fopen(nome_arquivo, modo_de_abertura): acessar o arquivo
	- fclose(ponteiro_arquivo): desconectar o arquivo
	- feof(ponteiro_arquivo): checar se está no final do arquivo
	
	Funções para escrita:
	- fprintf(ponteiro_arquivo, formatação_tipo_dado, lista_de_valores)
	
	Funções para leitura:
	- fgets(variavel_leitura, tamanho, ponteiro_arquivo)
	- fscanf(ponteiro_arquivo, tipo_de_dado, endereco_memoria_variavel)
*/

void modoWrite(){
	FILE *arquivo = fopen("matriz.txt","w");
	int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	int i;
	for (i=0;i<3;i++){
		printf("%i - %i - %i\n", matriz[i][0], matriz[i][1], matriz[i][2]);
		fprintf(arquivo, "%i %i %i\n", matriz[i][0], matriz[i][1], matriz[i][2]);
		
		//alternativa:
		//fprintf(arquivo, "%i\n", matriz[i][0]);
		//fprintf(arquivo, "%i\n", matriz[i][1]);
		//fprintf(arquivo, "%i\n", matriz[i][2]);
		
		//segunda alternativa: acrescentar um segundo loop para controlar o "j"
		//fprintf(arquivo, "%i\n", matriz[i][j]);
	}
	fclose(arquivo);
}

void modoAppend(){
	FILE *arquivo = fopen("matriz.txt","a");
	fprintf(arquivo, "%i %i %i\n", 10, 11, 12);
	fclose(arquivo);
}

void leituraArquivo(FILE *arquivo, int linhas){
	int matrizLeitura[linhas][3];
	int i = 0;
	
	//durante o acesso ao arquivo..
	//inicialmente, o cursor começa no início do arquivo
	
	
	//usando o modo "w" ou "r":
	//o cursor começa no início do arquivo
	//o cursor percorre o arquivo, lendo ("r") ou escrevendo ("w") um certo valor....
	//em algum momento, este cursor chegará ao final do arquivo e não conseguirá mais ler
	
	//usando o modo "a":
	//o cursor começa no final do arquivo
	//o cursor percorre o arquivo escrevendo um certo valor....
	//em algum momento, este cursor chegará ao final do arquivo
	
	while(!feof(arquivo)){ //end of file
		//scanf("%i", &matrizLeitura[i][0]);//leio do teclado
		//fscanf(stdin, "%i", &matrizLeitura[i][0]);//leio do teclado
		fscanf(arquivo, "%i", &matrizLeitura[i][0]);//leio do arquivo
		fscanf(arquivo, "%i", &matrizLeitura[i][1]);
		fscanf(arquivo, "%i", &matrizLeitura[i][2]);
		i++;
		
		//exemplo para ler de dois arquivos diferentes:
		//fscanf(arquivo1, "%i", &variavel1);
		//fscanf(arquivo2, "%f", &variavel2);
	}
	
	for (i=0; i<linhas; i++)
		printf("%i - %i - %i\n", matrizLeitura[i][0], matrizLeitura[i][1], matrizLeitura[i][2]);
}

int main(){
	//modoWrite();//3 linhas
	modoAppend();//4 linhas
	
	//abrindo arquivo em modo de leitura passando arquivo como parâmetro de função
	FILE *arquivoLeitura = fopen("matriz.txt","r");
	printf("\nLendo os dados do arquivo:\n");
	leituraArquivo(arquivoLeitura, 4);
	fclose(arquivoLeitura);
	
	//exemplo da struct de jogos (jogo1.txt)
  	//1\n (int)
  	//FIFA\n (char de 100)
  	//PS3\n (char de 20)
  	//10\n (unsgined short int)
  	//99.99\n (float)
  	//ASD (char de 30)
  	
  	//novo jogo - "w"
  	//acrescentar dados - "a"
  	//lendo a ficha do jogo - "r"
  	
  	//verificar se o jogo já está cadastrado:
  	//	se sim (verdadeiro) - abertura em modo "a"
  	//	se não (falso) - abertura em modo "w"
  	
  	//em um sistema é necessário gravar informações de forma persistente (é não perder os dados)
  	//o arquivo é um repositório de dados persistente
  	
	return 0;
}
