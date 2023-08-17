#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bilioteca de aloa��es de textos por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //fun��o que cadastra os usu�rios no sistema
{
	//cria��o de vari�veis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Colocando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string, o usu�rio digita o cpf
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file, cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualizar
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", nome); //O usu�rio digita o nome
	
	file = fopen(arquivo, "a");//Abre o arquivo para atualizar
	fprintf(file, nome);//Inclui a vari�vel nome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualizar
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", sobrenome); //O usu�rio digita o sobrenome
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file, sobrenome); //Inclui a vari�vel sobrenome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");  //Atualiza o arquivo
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cargo); //O usu�rio digita o cargo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file, cargo); //Inclui a vari�vel cargo 
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");  //Atualiza o arquivo
	fprintf(file, ","); //Inclui a "," no arquivo
	fclose(file); //Fecha o arquivo 
	
	system("pause");	
	
}

int consulta() //Fun��o que consulta os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Cria��o de vari�veis 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //O usu�rio digita o cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo, "r" de "read" para ler o arquivo
	
	if(file == NULL) //Fun��o para ver se o cpf digitado se encontra no arquivo
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n\n"); //Mensagem caso n�o for localizado o cpf 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nEssas s�o as informa��es do usu�rio: "); 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fecha o arquivo.
	
	system("pause");
}

int deletar() //Fun��o que deleta os usu�rios do sistema
{
	char cpf[40]; //Cria a vari�vel cpf
	
	printf("Digite o CPF a ser deletado: "); //Colotando informa��o do usu�rio
	scanf("%s",cpf); //O usu�rio digita o cpf a ser cancelado do sistema
	
	remove(cpf); //Para deletar
		
	FILE *file;
	file = fopen(cpf, "r");  // Abre o arquivo, "r" de "read" para ler o arquivo
	
	if(file == NULL) //Fun��o para ver se o cpf digitado se encontra no arquivo para ser deletado
	{
		printf("\nO usu�rio n�o se encontra no sistema!\n\n"); //Mensagem dada caso o usu�rio n�o esteja no sistema
		system("pause");
	}
	
	fclose(file); //Fecha o arquivo.
	
}

int main()
{
	int opcao=0; //Definindo vari�veis	
	int laco=1;
	
	for(laco=1;laco=1;)	//Criando la�o
	{
		
		system("cls"); //Limpando a tela
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("---- Cart�rio da EBAC ----\n\n"); //In�cio do Menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio. %d 
	
		system("cls"); //Limpando a tela
	
		switch(opcao) //In�cio da sele��o
		{
			case 1:
			registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta(); //Chamada de fun��es
			break;
			
			case 3:	
			deletar(); //Chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o existe!\n\n");
			system("pause");
			break;	
		} //Fim da sele��o
	}
}

