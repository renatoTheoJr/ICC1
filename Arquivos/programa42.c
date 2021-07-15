#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Manipula��o de structs em arquivos bin�rios
*/

//defini��o da estrutura de dados para manipula��o
typedef struct game{
	int codigo;
	char titulo[100];
	char plataforma[20];
	int estoque;
	float preco;
} Game;

int main(){
	//defini��o da vari�vel jogo do tipo "Game"
	Game jogo = {10, "FIFA", "PS3", 12, 45.99};
	
	//gravando toda a vari�vel em arquivo
	FILE *arquivo = fopen("structBinario.dat","wb");
	fwrite(&jogo, sizeof(Game), 1, arquivo);
	fclose(arquivo);
	
	Game jogoLeitura;
	
	//lendo os dados do arquivo diretamente para a vari�vel jogoLeitura
	FILE *arquivoLeitura = fopen("structBinario.dat","rb");
	fread(&jogoLeitura, sizeof(Game), 1, arquivoLeitura);
	fclose(arquivo);
	
	printf("*** Ficha do produto ***\n");
	printf("Codigo: %d\n", jogoLeitura.codigo);
	printf("Titulo: %s\n", jogoLeitura.titulo);
	printf("Plataforma: %s\n", jogoLeitura.plataforma);
	printf("Quantidade em estoque: %d\n", jogoLeitura.estoque);
	printf("Preco: %.2f\n\n", jogoLeitura.preco);
	
	return 0;	
}
