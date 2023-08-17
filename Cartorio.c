#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bilioteca de aloações de textos por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()  //função que cadastra os usuários no sistema
{
	//criação de variáveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Colocando informação do usuário
	scanf("%s", cpf); //%s refere-se a string, o usuário digita o cpf
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file, cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualizar
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome); //O usuário digita o nome
	
	file = fopen(arquivo, "a");//Abre o arquivo para atualizar
	fprintf(file, nome);//Inclui a variável nome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualizar
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", sobrenome); //O usuário digita o sobrenome
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file, sobrenome); //Inclui a variável sobrenome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");  //Atualiza o arquivo
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cargo); //O usuário digita o cargo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file, cargo); //Inclui a variável cargo 
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");  //Atualiza o arquivo
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo 
	
	system("pause");	
	
}

int consulta() //Função que consulta os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Criação de variáveis 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s", cpf); //O usuário digita o cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo, "r" de "read" para ler o arquivo
	
	if(file == NULL) //Função para ver se o cpf digitado se encontra no arquivo
	{
		printf("\nNão foi possível abrir o arquivo, não localizado!\n\n"); //Mensagem caso não for localizado o cpf 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nEssas são as informações do usuário: "); 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fecha o arquivo.
	
	system("pause");
}

int deletar() //Função que deleta os usuários do sistema
{
	char cpf[40]; //Cria a variável cpf
	
	printf("Digite o CPF a ser deletado: "); //Colotando informação do usuário
	scanf("%s",cpf); //O usuário digita o cpf a ser cancelado do sistema
	
	remove(cpf); //Para deletar
		
	FILE *file;
	file = fopen(cpf, "r");  // Abre o arquivo, "r" de "read" para ler o arquivo
	
	if(file == NULL) //Função para ver se o cpf digitado se encontra no arquivo para ser deletado
	{
		printf("\nO usuário não se encontra no sistema!\n\n"); //Mensagem dada caso o usuário não esteja no sistema
		system("pause");
	}
	
	fclose(file); //Fecha o arquivo.
	
}

int main()
{
	int opcao=0; //Definindo variáveis	
	int laco=1;
	
	for(laco=1;laco=1;)	//Criando laço
	{
		
		system("cls"); //Limpando a tela
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("---- Cartório da EBAC ----\n\n"); //Início do Menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário. %d 
	
		system("cls"); //Limpando a tela
	
		switch(opcao) //Início da seleção
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta(); //Chamada de funções
			break;
			
			case 3:	
			deletar(); //Chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não existe!\n\n");
			system("pause");
			break;	
		} //Fim da seleção
	}
}

