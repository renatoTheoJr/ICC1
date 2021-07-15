#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Introdu��o a leitura e escrita em arquivos de texto
	- Mem�ria Principal RAM (Mem�ria Stack e Mem�ria Heap): muito r�pida, cara, dif�cil de escalar, vol�til
	- Mem�ria Secund�ria (HDD, SSD): mais "lento", mais "baratos", mais f�cil de escalar, persistente
	
	- RAM (Random Access Memory)
	- ROM (Read Only Memory)
	
	- A manipula��o de arquivos � realizada por meio de um canal de comunica��o com uma interface de disco
	- Em C, esta interface � direta independente do sistema de arquivos da m�quina (FAT32, NTFS, e outros)
	- O acesso � realizado por meio de ponteiros (o endere�o aponta diretamente para o arquivo)
	
	- Tipos de arquivos:
	--- Codificados com caracteres (texto)
	--- Codificados em bin�rios (n�o tem interpreta��o direta para leitura)
	
	- Arquivos (pacote de bytes armazenados e organizados na mem�ria secund�ria)
	--- nome (identifica o arquivo)
	--- extens�o (identifica o formato do arquivo): txt, c, pdf
*/

int main(){
	//tipo de dado (* para endere�o)
	FILE *arquivo = NULL;
	
	//abertura do arquivo (caminho, modo de abertura)
	//Modos de abertura para arquivos com caracteres:
	//	"w": write (escrita) -> cria um arquivo novo. Se j� existir, o conte�do anterior ser� destru�do.
	//	"r": read (leitura) -> abre um arquivo j� existente. O arquivo deve existir antes de ser aberto.
	//	"a": append (adi��o) -> adiciona conte�do ao final do arquivo se ele j� existir
	//	"w+": Cria um arquivo texto para leitura e grava��o. 
	//		  Se o arquivo existir, o conte�do anterior ser� destru�do. Se n�o existir, ser� criado.
	//	"r+": Abre um arquivo texto para leitura e grava��o (o arquivo deve existir). 
	//		  O arquivo deve existir e pode ser modificado. Permite leitura e escrita (ap�s conte�do)
	//	"a+": Abre um arquivo texto para grava��o e leitura. 
	//		  Os dados ser�o adicionados no fim do arquivo se ele j� existir, 
	//		  ou um novo arquivo ser� criado, no caso de arquivo n�o existir anteriormente.
	
	//fopen(nome_do_arquivo, modo_de_abertura);
	arquivo = fopen("arquivo.txt","w");
	
	//if (arquivo == NULL)
	if (!arquivo){//se abrir com "r" e deu erro, posso abrir com modo "w"
		printf("Erro na abertura do arquivo");
		exit(1);//aborta a execu��o do programa: 0 - finalizou normal; outros valores depende do significado associado
	}
	
	//escrevendo no arquivo
	//fprintf(ponteiro_arquivo, informacao);
	fprintf(arquivo, "Ola, bom dia\n");
	fprintf(arquivo, "ICC I - ");
	fprintf(arquivo, "Aula sobre arquivos\n");
	
	//se n�o fechar pode ser que a escrita n�o seja realizada de forma correta
	//stdout: sa�da padr�o de dados (monitor)
	fprintf(stdout, "Gravando dados no arquivo.\n");
	fclose(arquivo);
	
	//abrindo arquivo em modo de leitura
	FILE *arquivoLeitura = fopen("arquivo.txt","r");
	char texto[50];
	
	printf("\nLendo os dados do arquivo:\n");
	while(fgets(texto, 50, arquivoLeitura) != NULL)
  		printf("%s", texto);
  		
  	//ler a primeira frase e mostrar
  	//ler a segunda frase e mostrar
  	
  	//exemplo da struct de jogos (jogo1.txt)
  	//1\n (int)
  	//FIFA\n (char de 100)
  	//PS3\n (char de 20)
  	//10\n (unsgined short int)
  	//99.99\n (float)
  	
  	//exemplo da struct de jogos (jogo2.txt)
  	//2
  	//NBA
  	//PS4
  	//12
  	//115.99
  	
  	//estrutura��o do exemplo de jogos com arquivos:
  	//a��o N (novo jogo): 
	//	- criar um arquivo ("w"), escrever os dados da struct 
  	//	- nome do arquivo: jogo(codigo).txt -> fun��o concatena��o (string.h)
	//a��o V (baixar estoque):
	//	Primeira abordagem:
	//	- ler o arquivo ("r"), lendo os dados para a struct; fechar o arquivo
	//	- se for baixar o estoque: acessar o arquivo ("w") e escrever os dados (o conte�do anterior ser� substituido) 
  	//	Segunda abordagem:
  	//	- ler o arquivo ("w+"), ler os dados para a struct
  	//	- se for baixar o estoque: reescrevo os dados
	//a��o I (imprimir lista com estoque > 0)
  	//a��o F (finalizar)
  	
  	//w+ � equivalente (r com w)
  	//r+ � equivalente (r com a)
  	
  	//eu sei que um arquivo existe (r) eu consigo validar a sua existencia
  	//se eu abrir com (w), o arquivo ser� criado
  	
	fclose(arquivoLeitura);
	
	return 0;
}
