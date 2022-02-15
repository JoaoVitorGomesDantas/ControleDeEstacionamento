///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                   Centro de Ensino Superior do Seridó                   ///
///                 Departamento de Computação e Tecnologia                 ///
///                    Disciplina DCT1106 -- Programação                    ///
///              Projeto Sistema de Controle de Estacionamento              ///
///   Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta   ///
///                  Developed by @joaovitorgd - Out, 2021                  ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Cliente.h"
#include "Validar.h"

///////////////////////////////////////
////// Funções do Módulo Cliente //////
///////////////////////////////////////

typedef struct cliente Cliente;

void moduloCliente(void) {
    char opc;
    do {
        opc = telaCliente();
        switch(opc) {
            case '1': 	cadastrarCliente();
                        break;
            case '2': 	pesquisarCliente();
                        break;
            case '3': 	atualizarCliente();
                        break;
            case '4': 	excluirCliente();
                        break;
        } 		
    } while (opc != '0');
}

void cadastrarCliente(void) {
	Cliente *cli;

	cli = telaCadastrar();
  salvarCliente(cli);
	free(cli);
}

void pesquisarCliente(void) {
	Cliente* cli;
	char* cpf;

	cpf = telaPesquisar();
	cli = buscarCliente(cpf);
	exibirCliente(cli);
	free(cli); 
	free(cpf);
}

void atualizarCliente(void) {
	Cliente* cli;
	char* cpf;

	cpf = telaAtualizar();
	cli = buscarCliente(cpf);
	if (cli == NULL) {
    	printf("\n\nAluno não encontrado!\n\n");
  	} else {
		cli = telaCadastrar();
		strcpy(cli->cpf, cpf);
      		excluirCliente();
      		cadastrarCliente();
		free(cli);
	}
	free(cpf);
}

void excluirCliente(void) {
	Cliente* cli;
	char *cpf;

	cpf = telaExcluir();
	cli = (Cliente*) malloc(sizeof(Cliente));
	cli = buscarCliente(cpf);
	if (cli == NULL) {
    	printf("\n\nAluno não encontrado!\n\n");
  	} else {
		  cli->status = False;
		  regravarCliente(cli);
		  free(cli);
	}
	free(cpf);
}

char telaCliente(void) {
    char opc;

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              =================== Menu de Cliente ===================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///               1 -  Cadastrar cliente                                              ///\n");
    printf("///               2 -  Pesquisar dados do cliente                                     ///\n");
    printf("///               3 -  Atualizar dados do cliente                                     ///\n");
    printf("///               4 -  Excluir cliente do sistema                                     ///\n");
    printf("///               0 -  Voltar ao Menu principal                                       ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opção que você deseja:                                          \n");
    scanf("%c", &opc);
    printf("\n");
    printf("\t\t\t>>>  Aguarde um momento...\n");
    sleep(1);
    return opc;
}

void telaErroArquivoCliente(void) {

	system("clear||cls");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
 	printf("///              =======================================================              ///\n");
 	printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
 	printf("///              =======================================================              ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                                   ///\n");
	printf("///        ============== Sistema de Controle de Estacionamento ==============        ///\n");
  	printf("///                                                                                   ///\n");
	printf("///                                  Ocorreu um erro!                                 ///\n");
	printf("///                      Não foi possível acessar o arquivo com                       ///\n");
	printf("///                          informações sobre os clientes.                           ///\n");
	printf("///                                                                                   ///\n");
	printf("///                      Pedimos desculpas pelos inconvenientes                       ///\n");
	printf("///                        mas este programa será finalizado!                         ///\n");
	printf("///                                                                                   ///\n");
	printf("///                                                                                   ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	exit(1);
}

Cliente* telaCadastrar(void) {
    Cliente *cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Cadastrar Cliente ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    do {
      printf("///          Nome do cliente:                                                         ///\n");
      scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->nome);
      getchar();
    } while (!validarNome(cli->nome));

    do {
      printf("///          CPF (apenas números):                                                    ///\n");
      scanf("%[0-9].", cli->cpf);
      getchar();
    } while (!validarCPF(cli->cpf));

    do {
      printf("///          Data de nascimento (dd/mm/aaaa):                                         ///\n");
    scanf("%[0-9]/", cli->nasc);
    getchar();
    } while (!validarData(cli->nasc));

    printf("///          Email:                                                                     ///\n");
    scanf("%[@A-Za-z._0-9]", cli->email);
    getchar();

    do {
      printf("///          Telefone (apenas número com DDD):                                        ///\n");
      scanf("%[0-9]", cli->fone);
      getchar();
    } while (!validaTelefone(cli->fone));

    do {
    printf("///          Veículo:                                                                 ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->veic);
    getchar();
    } while (!validarNome(cli->veic));

    printf("///          Placa do veículo:                                                        ///\n");
    scanf("%[A-Za-z0-9]", cli->placa);
    getchar();

    do {
    printf("///          Cor do veículo:                                                          ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->cor);
    getchar();
    } while (!validarNome(cli->cor));

    cli->status = True;
    
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cli;
}

char* telaPesquisar(void) {
    char* cpf;
    cpf = (char*) malloc(14*sizeof(char));

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Pesquisar Cliente ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    do {
      printf("///          Informe o CPF:                                                           ///\n");
      scanf("%[0-9].", cpf);
      getchar();
    } while (!validarCPF(cpf));

    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}

char* telaAtualizar(void) {
    char* cpf;
    cpf = (char*) malloc(14*sizeof(char));

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Atualizar Cliente ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    do {
      printf("///          Informe o CPF:                                                           ///\n");
      scanf("%[0-9].", cpf);
      getchar();
    } while (!validarCPF(cpf));

    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}

char* telaExcluir(void) {
  char* cpf;
  cpf = (char*) malloc(14*sizeof(char));

  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              =================== Excluir Cliente ===================              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  do {
      printf("///          Informe o CPF:                                                           ///\n");
      scanf("%[0-9].", cpf);
      getchar();
  } while (!validarCPF(cpf));

  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  return cpf;
}


void salvarCliente(Cliente* cli) {
  FILE* fp;

  fp = fopen("cliente.dat", "ab");
  if (fp == NULL){
    telaErroArquivoCliente(); 
  }
  fwrite(cli, sizeof(Cliente), 1, fp);
  fclose(fp);
}

Cliente* buscarCliente(char* cpf) {
	FILE* fp;
	Cliente* cli;

	cli = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("cliente.dat", "rb");
	if (fp == NULL) {
		telaErroArquivoCliente();
	}
	while(fread(cli, sizeof(Cliente), 1, fp)) {
    		if (strcmp(cli->cpf, cpf) && (cli->status == True)) {
			fclose(fp);
			return cli;
		}
	}
	fclose(fp);
	return cli;
}

void exibirCliente(Cliente* cli) {

	if (cli == NULL) {
		printf("\n= = = Cliente Inexistente = = =\n");
	} else {
		printf("\n= = = Cliente Cadastrado = = =\n");
		printf("Nome do cliente: %s\n", cli->nome);
		printf("CPF: %s\n", cli->cpf);
		printf("Data de nascimento: %s\n", cli->nasc);
		printf("Email: %s\n", cli->email);
		printf("Telefone: %s\n", cli->fone);
		printf("Veículo: %s\n", cli->veic);
    		printf("Placa do veículo: %s\n", cli->placa);
    		printf("Cor do veículo: %s\n", cli->cor);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}

void regravarCliente(Cliente* cli) {
	int achou;
	FILE* fp;
	Cliente* cliLido;

	cliLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("cliente.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivoCliente();
	}
	achou = False;
	while(fread(cliLido, sizeof(Cliente), 1, fp) && !achou) {
		if (strcmp(cliLido->cpf, cli->cpf) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        	fwrite(cli, sizeof(Cliente), 1, fp);
		}
	}
	fclose(fp);
	free(cliLido);
}
