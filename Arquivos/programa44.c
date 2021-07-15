#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/*
	Sistema de controle de jogos:
	-	Cadastrar um novo jogo (ler as informações do teclado; gravar as informações em arquivo)
	- 	Vender um jogo (ler as informações em arquivo, controle do estoque, gravar as info em arquivo)
	-	Imprimir lista de estoque (ler as informações em arquivo, verificar se o estoque > 0)
	
	Possíveis funções:
	- CadastroJogo (retiro o código de gravação para uma nova função e faço chamadas para ela)
	- VenderJogo
	- GravarArquivo (está sendo chamada por CadastroJogo e VenderJogo)
	
*/

//definição de valores constantes para melhorar a manutenção do código
#define tamanhoTitulo 100
#define tamanhoPlataforma 20

//criação de um tipo de dado com nome mais significativo para a programação
typedef unsigned short int inteiroCurto;

//definição da estrutura de dados para manipulação
typedef struct game{
	int codigo;
	char titulo[tamanhoTitulo];
	char plataforma[tamanhoPlataforma];
	inteiroCurto estoque;
	float preco;
} Game;

//funções de sistema e acesso a arquivos
int inicializandoSistema();
int gravarJogoArquivo(Game *jogo, int codigo);
Game lerJogoArquivo(int codigo);

//funções para manipulação de dados
int preencherFicha(Game *jogo, int codigo);
void imprimirFicha(Game jogo);
void imprimirProdutosEstoque(int qtdadeArquivos);

//void venderProduto(){
	//ler a ficha do produto
	//calculos estoque (validar se tenho a quantidade vendida, verificar o código do produto)
	//chamar a função gravarJogoArquivo(Game, int)
//}

int main(){
	Game jogo;
	char acao;
	
	int contArquivos = inicializandoSistema();
	do {
		//menu de leitura das opções disponiveis
		printf("Digite a opcao desejada (N - novo; V - vender; I - imprimir; F - fim): ");
		scanf("%c", &acao);
		fflush(stdin);
		printf("\n");
		
		//Sugestão de melhorias:
		// - incorporar um cadastro de cliente
		// - no momento de uma venda reduzir o estoque e associar a um cliente
		// - manter registros de clientes, produtos e vendas
		
		// - modificar a estrutura de produtos para armazenar tudo em apenas um arquivo
		// - isso pode ser realizado por meio de arquivos binários em que a leitura ocorre por blocos
		// - calcular a quantidade de bytes a serem "pulados" antes da leitura (fseek)
		
		switch(acao){
			case 'N': if (preencherFicha(&jogo, contArquivos+1)){
						printf("Jogo cadastrado com sucesso\n\n");
						imprimirFicha(jogo);
						contArquivos++;
					  } 
					  else
						printf("Erro na gravacao do jogo\n\n");
					break;
			case 'I': imprimirProdutosEstoque(contArquivos);
					  break;
			case 'F': printf("O programa sera encerrado\n\n");
					  break;
			default: printf("Opcao inexistente\n\n");
					 break;
		}
		fflush(stdin);
	}while (acao != 'F');
	return 0;
}

int inicializandoSistema(){
	printf("Inicializando o programa. Por favor, aguarde ...\n");
	int contArquivos = -2;
	
	DIR *dir = opendir("./Produtos/");// o ponto significa diretório raiz (origem)
    struct dirent *lsdir;

    while ((lsdir = readdir(dir)) != NULL){
        printf("%s\n", lsdir->d_name);
        contArquivos++;
    }

    closedir(dir);
    printf("Quantidade de jogos cadastrados: %d\n\n", contArquivos);
	return contArquivos;	
}

int gravarJogoArquivo(Game *jogo, int codigo){
	char nomeArquivo[20];
	sprintf(nomeArquivo, "%s%d.%s", "Produtos/jogo", codigo, "txt");//ao invés de strcat()
	
	FILE *arquivo = fopen(nomeArquivo,"w");
	if (arquivo != NULL){
		fprintf(arquivo, "%i\n", jogo->codigo);
		fprintf(arquivo, "%s\n", jogo->titulo);
		fprintf(arquivo, "%s\n", jogo->plataforma);
		fprintf(arquivo, "%i\n", jogo->estoque);
		fprintf(arquivo, "%f\n", jogo->preco);
		fclose(arquivo);
		return 1; 
	}
	return 0;
}

Game lerJogoArquivo(int codigo){
	Game jogo;
	char nomeArquivo[20];
	sprintf(nomeArquivo, "%s%d.%s", "Produtos/jogo", codigo, "txt");
	
	FILE *arquivo = fopen(nomeArquivo,"r");
	if (arquivo != NULL){
		fscanf(arquivo, "%i", &jogo.codigo);
		fscanf(arquivo, "%s", &jogo.titulo);
		fscanf(arquivo, "%s", &jogo.plataforma);
		fscanf(arquivo, "%i", &jogo.estoque);
		fscanf(arquivo, "%f", &jogo.preco);
		fclose(arquivo);
	}
	
	return jogo;
}

//função que recebe dados referentes a um produto e o armazena em uma instancia da struct
int preencherFicha(Game *jogo, int codigo){
	//o atributo codigo é um valor incremental
	printf("*** Cadastro de um novo jogo ***\n");
	jogo->codigo = codigo;
	
	//a função fgets ler caracteres até o valor máximo possível
	printf("Digite o titulo do jogo: ");
	fgets(jogo->titulo, tamanhoTitulo, stdin);//stdin (standard input -> teclado)
	int len = strlen(jogo->titulo); //verifica o tamanho da string digitada
	jogo->titulo[len - 1] = '\0'; //coloca marcador de final de string no ultimo caractere
	
	printf("Digite a plataforma do jogo: ");
	fgets(jogo->plataforma, tamanhoPlataforma, stdin);
	len = strlen(jogo->plataforma);
	jogo->plataforma[len - 1] = '\0';
	
	printf("Digite a quantidade em estoque: ");
	scanf("%d", &jogo->estoque);
	
	printf("Digite o preco do jogo: ");
	scanf("%f", &jogo->preco);
	
	printf("\n");
	return gravarJogoArquivo(jogo, codigo);
}

//função para imprimir a ficha completa de um jogo
void imprimirFicha(Game jogo){
	printf("*** Ficha do produto ***\n");
	printf("Codigo: %d\n", jogo.codigo);
	printf("Titulo: %s\n", jogo.titulo);
	printf("Plataforma: %s\n", jogo.plataforma);
	printf("Quantidade em estoque: %d\n", jogo.estoque);
	printf("Preco: %.2f\n\n", jogo.preco);
}

void imprimirProdutosEstoque(int qtdadeArquivos){
	int i;
	for (i=1; i<=qtdadeArquivos; i++){
		Game jogo;
		jogo = lerJogoArquivo(i);
		if (jogo.estoque > 0)
			printf("%i - %s. Em estoque: %d\n", jogo.codigo, jogo.titulo, jogo.estoque);
	}
	printf("\n");
}
