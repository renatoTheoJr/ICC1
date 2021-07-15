#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Introdução a leitura e escrita em arquivos de texto
	- Memória Principal RAM (Memória Stack e Memória Heap): muito rápida, cara, difícil de escalar, volátil
	- Memória Secundária (HDD, SSD): mais "lento", mais "baratos", mais fácil de escalar, persistente
	
	- RAM (Random Access Memory)
	- ROM (Read Only Memory)
	
	- A manipulação de arquivos é realizada por meio de um canal de comunicação com uma interface de disco
	- Em C, esta interface é direta independente do sistema de arquivos da máquina (FAT32, NTFS, e outros)
	- O acesso é realizado por meio de ponteiros (o endereço aponta diretamente para o arquivo)
	
	- Tipos de arquivos:
	--- Codificados com caracteres (texto)
	--- Codificados em binários (não tem interpretação direta para leitura)
	
	- Arquivos (pacote de bytes armazenados e organizados na memória secundária)
	--- nome (identifica o arquivo)
	--- extensão (identifica o formato do arquivo): txt, c, pdf
*/

int main(){
	//tipo de dado (* para endereço)
	FILE *arquivo = NULL;
	
	//abertura do arquivo (caminho, modo de abertura)
	//Modos de abertura para arquivos com caracteres:
	//	"w": write (escrita) -> cria um arquivo novo. Se já existir, o conteúdo anterior será destruído.
	//	"r": read (leitura) -> abre um arquivo já existente. O arquivo deve existir antes de ser aberto.
	//	"a": append (adição) -> adiciona conteúdo ao final do arquivo se ele já existir
	//	"w+": Cria um arquivo texto para leitura e gravação. 
	//		  Se o arquivo existir, o conteúdo anterior será destruído. Se não existir, será criado.
	//	"r+": Abre um arquivo texto para leitura e gravação (o arquivo deve existir). 
	//		  O arquivo deve existir e pode ser modificado. Permite leitura e escrita (após conteúdo)
	//	"a+": Abre um arquivo texto para gravação e leitura. 
	//		  Os dados serão adicionados no fim do arquivo se ele já existir, 
	//		  ou um novo arquivo será criado, no caso de arquivo não existir anteriormente.
	
	//fopen(nome_do_arquivo, modo_de_abertura);
	arquivo = fopen("arquivo.txt","w");
	
	//if (arquivo == NULL)
	if (!arquivo){//se abrir com "r" e deu erro, posso abrir com modo "w"
		printf("Erro na abertura do arquivo");
		exit(1);//aborta a execução do programa: 0 - finalizou normal; outros valores depende do significado associado
	}
	
	//escrevendo no arquivo
	//fprintf(ponteiro_arquivo, informacao);
	fprintf(arquivo, "Ola, bom dia\n");
	fprintf(arquivo, "ICC I - ");
	fprintf(arquivo, "Aula sobre arquivos\n");
	
	//se não fechar pode ser que a escrita não seja realizada de forma correta
	//stdout: saída padrão de dados (monitor)
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
  	
  	//estruturação do exemplo de jogos com arquivos:
  	//ação N (novo jogo): 
	//	- criar um arquivo ("w"), escrever os dados da struct 
  	//	- nome do arquivo: jogo(codigo).txt -> função concatenação (string.h)
	//ação V (baixar estoque):
	//	Primeira abordagem:
	//	- ler o arquivo ("r"), lendo os dados para a struct; fechar o arquivo
	//	- se for baixar o estoque: acessar o arquivo ("w") e escrever os dados (o conteúdo anterior será substituido) 
  	//	Segunda abordagem:
  	//	- ler o arquivo ("w+"), ler os dados para a struct
  	//	- se for baixar o estoque: reescrevo os dados
	//ação I (imprimir lista com estoque > 0)
  	//ação F (finalizar)
  	
  	//w+ é equivalente (r com w)
  	//r+ é equivalente (r com a)
  	
  	//eu sei que um arquivo existe (r) eu consigo validar a sua existencia
  	//se eu abrir com (w), o arquivo será criado
  	
	fclose(arquivoLeitura);
	
	return 0;
}
