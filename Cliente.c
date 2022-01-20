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
            case '3': 	telaAtualizar();
                        break;
            case '4': 	telaExcluir();
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
    printf("///            Escolha a opção que você deseja:                                       ///\n");
    scanf("%c", &opc);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return opc;
}

void telaErroArquivoCliente(void) {

	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                                   ///\n");
	printf("///        ============== Sistema de Controle de Estacionamento ==============        ///\n");
    printf("///                                                                                   ///\n");
	printf("///                                  Ocorreu em erro!                                 ///\n");
	printf("///                        Não foi possível acessar o arquivo                         ///\n");
	printf("///                         com informações sobre os alunos.                          ///\n");
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

void telaCadastrar(void) {
    Cliente* cli;
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
    printf("///          Nome do cliente:                                                         ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->nome);
    getchar();

    printf("///          CPF:                                                                     ///\n");
    scanf("%[0-9].", cli->cpf);
    getchar();

    printf("///          Data de nascimento:                                                      ///\n");
    scanf("%[0-9]/", cli->nasc);


    printf("///          Email:                                                                   ///\n");
    scanf("%[A-Za-z@._]", cli->email);
    getchar();

    printf("///          Telefone:                                                                ///\n");
    scanf("%[0-9]", cli->fone);
    getchar();

    printf("///          Veículo:                                                                 ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->veic);
    getchar();

    printf("///          Placa do veículo:                                                        ///\n");
    scanf("%[A-Za-z0-9]", cli->placa);
    getchar();

    printf("///          Cor do veículo:                                                          ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->cor);
    getchar();

    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaPesquisar(void) {
    char cpf;

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
    printf("///          Informe o CPF:                                                           ///\n");
    scanf("%[0-9]", &cpf);
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAtualizar(void) {
    char cpf;

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
    printf("///          Informe o CPF:                                                           ///\n");
    scanf("%[0-9]", &cpf);
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaExcluir(void) {
    char cpf;

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
    printf("///          Informe o CPF:                                                           ///\n");
    scanf("%[0-9]", &cpf);
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void salvarCliente(Cliente* cli) {
  FILE* fp;

  fp = fopen("cliente.dat", "at");
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
	fp = fopen("cliente.dat", "rt");
	if (fp == NULL) {
		telaErroArquivoCliente();
	}
	while(fread(cli, sizeof(Cliente), 1, fp)) {
		if (cli->cpf == cpf) {
			fclose(fp);
			return cli;
		}
	}
	fclose(fp);
	return NULL;
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

