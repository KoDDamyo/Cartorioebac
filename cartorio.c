#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca reponsavel por cuidar das string

//sistema para registro de novos usuarios
int registro(){
	
	//inicio da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variáveis/string
	
	printf("Digite seu CPF: "); //coleta de informações do usuario, solicitando o cpf
	scanf("%s", cpf); //%s refere-se ao armazenamento/salvamento de string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo no bando de dados(computador)
	file = fopen(arquivo, "w"); //cria o arquivo na pasta aonde salvamos o sistema e o "w" significa escrever(write)
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fclose(file); //sempre fechar um file
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite seu nome: "); //solicitando o nome do usuario
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite seu sobrenome: "); //solicitando o sobrenome do usuario
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite seu cargo: "); //solicitando o cargo/profissão do usario
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //para o sistema para que o usuario possa ler ou fazer algo, ele fica esperando alguma ação
}

//sistema para consulta de usuarios já existentes nos arquivos
int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); //definindo a lingua
	
	char cpf[40]; //criação das variaveis
	char conteudo[200];
	
	printf("Qual CPF deseja consultar?: "); 
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //procura de arquivos nas pastas e o "r" significa leitura/ler(reading/read)
	
	if(file == NULL){ //se não encontrar nenhum arquivo que bata com o digitado
		printf("Arquivo não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //vai ficar lendo e repetindo as informações solicitadas para o usuario
		printf("\nAqui estão as informações solicitadas: ");
		printf("%s", conteudo);
		printf("\n\n");
	} 
	fclose(file);
	system("pause");
	
	
}

//sistema para exclusão de usuarios dos arquivos
int deletar(){
	
	char cpf[40]; //variavel
	
	printf("Qual CPF deseja deletar?: ");
	scanf("%s", cpf);
	
	remove(cpf); //função que deleta/remove arquivos
	
	FILE *file;
	file = fopen(cpf, "r"); //vai nos arquivos e procura se tem o arquivo
	fclose(file);
	
	if(file == NULL){
		printf("O usuário não se encontra mais no sistema!. \n"); //validação para caso não seja encontrado o arquivo pedido para exclusção
		system("pause");
	}
	
}

int main(){
	
	int opcao=0; //definindo as variaveis	
	int laco=1;
	
	for(laco=1;laco=1;){ //definindo laço de repetição
		
		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a lingua
		
		printf("### Cartório Municipal ### \n\n"); //inicio do menu
		printf("Escolha uma opção no menu: \n\n");
		printf("\t1 - Registrar nome \n");
		printf("\t2 - Consultar nome \n");
		printf("\t3 - Deletar nome \n\n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Opção: "); //final do menu
		
		scanf("%d", &opcao); //armazenando as informações/escolha do usuario
		
		system("cls"); //deletando todas as mensagens após a escolha da opção
		
		//inicio da seção porém usando switch case que é uma forma melhor de reduzir a complexidade de vários if
		switch(opcao){
			case 1:
				registro(); //chamada de funções
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			break;	
			
			default:
				printf("Opção inválida\n");
				system("pause");
			break;
		}
		//fim da seção switch case
		
		//inicio da seleção
		//if(opcao==1){
		//	printf("Registro de nome escolhido\n");
		//	system("pause");
		//}
		
		//if(opcao==2){
		//	printf("Consulta de nome escolhido\n");
		//	system("pause");
		//}
		
		//if(opcao==3){
		//	printf("Deletar nome escolhido\n");
		//	system("pause");
		//}
		
		//if(opcao>=4 || opcao<=0){
		//	printf("Opção inválida\n");
		//	system("pause");
		//}
		//fim da seleção
		
		
		//printf("Software criado por Gabriel Borges, uso livre para qualquer pessoa.");
		
	}	
	
}
