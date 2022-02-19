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
#include "Funcionarios.h"
#include "Validar.h"

typedef struct funcionario Funcionario;

void moduloFuncionarios(void) {
	char opc;

  	do {
		opc = telaFuncionarios();
      		switch(opc) {
			case '1': 	cadastrarFuncionario();
				break;
          		case '2': 	pesquisarFuncionario();
                      		break;
          		case '3': 	atualizarFuncionario();
                      		break;
          		case '4': 	excluirFuncionario();
                      		break;
          		case '5':   listarFuncionario();
                      		break;
          		case '6':   listaFuncionarioPorTurno();
                      		break;
		} 
	} while (opc != '0');
}

void cadastrarFuncionario(void) {
	Funcionario *func;

	func = telaCadastrarFunc();
  	salvarFuncionario(func);
	free(func);
}

void pesquisarFuncionario(void) {
	Funcionario* func;
	char* cpf;

	cpf = telaPesquisarFunc();
	func = buscarFuncionario(cpf);
	exibirFuncionario(func);
	free(func); 
	free(cpf);
}

void atualizarFuncionario(void) {
	Funcionario* func;
	char* cpf;

	cpf = telaAtualizarFunc();
	func = buscarFuncionario(cpf);
	if (func == NULL) {
		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		printf("///                                                                                   ///\n");
    		printf("///              ============= Funcionário não encontrado! =============              ///\n");
    		printf("///                                                                                   ///\n");
    		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	} else {
		func = telaCadastrarFunc();
		strcpy(func->cpf, cpf);
      		excluirFuncionario();
      		cadastrarFuncionario();
		free(func);
	}
	free(cpf);
}

void excluirFuncionario(void) {
	Funcionario* func;
	char *cpf;

	cpf = telaExcluirFunc();
	func = (Funcionario*) malloc(sizeof(Funcionario));
	func = buscarFuncionario(cpf);
	if (func == NULL) {
		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		printf("///                                                                                   ///\n");
    		printf("///              ============= Funcionário não encontrado! =============              ///\n");
    		printf("///                                                                                   ///\n");
    		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	} else {
		func->status = False;
		regravarFuncionario(func);
		free(func);
	}
	free(cpf);
}

void listarFuncionario(void) {
	FILE* fp;
  	Funcionario* func;
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ================ Lista de Funcionários ================              ///\n");
  	printf("///                                                                                   ///\n");
  	func = (Funcionario*) malloc(sizeof(Funcionario));
  	fp = fopen("funcionario.dat", "rb");
  	if (fp == NULL) {
		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		printf("///                                                                                   ///\n");
    		printf("///              ======= Ocorreu um erro na abertura do arquivo! =======              ///\n");
    		printf("///              ======= Não é possível continuar este programa! =======              ///\n");
    		printf("///                                                                                   ///\n");
    		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		exit(1);
  	}
  	while(fread(func, sizeof(Funcionario), 1, fp)) {
		if (func->status != 0) {
			exibirFuncionario(func);
		}
	}
  	fclose(fp);
}

void listaFuncionarioPorTurno(void) {
	FILE* fp;
  	char trn[21];
  	Funcionario* func;
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ============ Lista de Funcionário por Turno ============             ///\n");
  	printf("///                                                                                   ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ================== Buscar Funcionario ==================             ///\n");
  	printf("///                                                                                   ///\n");
  	printf("///              Informe o Turno: ");
  	scanf(" %50[^\n]", trn);
  	func = (Funcionario*) malloc(sizeof(Funcionario));
  	fp = fopen("funcionario.dat", "rb");
  	if (fp == NULL) {
		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		printf("///                                                                                   ///\n");
    		printf("///              ======= Ocorreu um erro na abertura do arquivo! =======              ///\n");
    		printf("///              ======= Não é possível continuar este programa! =======              ///\n");
    		printf("///                                                                                   ///\n");
    		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		exit(1);
  	}
	while(fread(func, sizeof(Funcionario), 1, fp)) {
		if (strcmp(func->trn, trn) == 0 && (func->status != 0)) {
			exibirFuncionario(func);
		}
	}
  	fclose(fp);
}

char telaFuncionarios(void) {
	char opc;

  	system("clear||cls");
  	printf("\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///              =======================================================              ///\n");
  	printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  	printf("///              =======================================================              ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ================ Menu dos Funcionários ================              ///\n");
  	printf("///                                                                                   ///\n");
  	printf("///               1 -  Cadastrar funcionário                                          ///\n");
  	printf("///               2 -  Pesquisar dados do funcionário                                 ///\n");
  	printf("///               3 -  Atualizar dados do funcionário                                 ///\n");
  	printf("///               4 -  Excluir funcionário do sistema                                 ///\n");
  	printf("///               5 -  Listar funcionários do sistema                                 ///\n");
  	printf("///               6 -  Listar funcionários por turno                                  ///\n");
  	printf("///               0 -  Voltar ao Menu principal                                       ///\n");
  	printf("///                                                                                   ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
 	printf("\n");
  	printf("               Escolha a opção que você deseja: ");
  	scanf("%c", &opc);
  	printf("\n");
  	printf("\t\t\t>>>  Aguarde um momento...\n");
  	sleep(1);
  	return opc;
}

void telaErroArquivoFuncionario(void) {
	
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
	printf("///                        informações sobre os funcionários.                         ///\n");
	printf("///                                                                                   ///\n");
	printf("///                      Pedimos desculpas pelos inconvenientes                       ///\n");
	printf("///                        mas este programa será finalizado!                         ///\n");
	printf("///                                                                                   ///\n");
	printf("///                                                                                   ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
}

Funcionario* telaCadastrarFunc(void) {
	Funcionario* func;
  	func = (Funcionario*) malloc(sizeof(Funcionario));

  	system("clear||cls");
  	printf("\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///              =======================================================              ///\n");
  	printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  	printf("///              =======================================================              ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ================ Cadastrar Funcionário ================              ///\n");
  	printf("///                                                                                   ///\n");
  	printf("///                                                                                   ///\n");
	
  	getchar();
  	printf("///          Nome: ");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->nome);
  	getchar();


  	do {
		printf("///          CPF (apenas números): ");
    		scanf("%[0-9].", func->cpf);
    		getchar();
  	} while (!validarCPF(func->cpf));
    
  	do {
    		printf("///          RG (apenas números): ");
    		scanf("%[0-9]", func->rg);
    		getchar();
  	} while (!validarRG(func->rg));

  	do {
    		printf("///          Data de nascimento: ");
    		scanf("%[0-9]/", func->nasc);
    		getchar();
  	} while (!validarData(func->nasc));

  	printf("///          Cidade: ");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->city);
  	getchar();

  	printf("///          Endereço: ");
  	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->end);
  	getchar();

  	printf("///          Email: ");
  	scanf("%[A-Za-z@._]", func->email);
  	getchar();

  	do {
    		printf("///          Telefone (apenas número com DDD): ");
    		scanf("%[0-9]", func->fone);
    		getchar();
  	} while (!validaTelefone(func->fone));

  	printf("///          Turno (Manhã: M ;Tarde: T ; Noite:  N) : ");
  	scanf("%[A-Za-z]", func->trn);
  	getchar();

  	func->status = True;

  	printf("///                                                                                   ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("\n");
  	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  	getchar();
  	return func;
}

char* telaPesquisarFunc(void) {
	char* cpf;
  	cpf = (char*) malloc(14*sizeof(cpf));

  	system("clear||cls");
  	printf("\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///              =======================================================              ///\n");
  	printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  	printf("///              =======================================================              ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ================ Pesquisar Funcionário ================              ///\n");
  	printf("///                                                                                   ///\n");
  	printf("///                                                                                   ///\n");
  	do {
		getchar();
    		printf("///          Informe o CPF do funcionário: ");
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

char* telaAtualizarFunc(void) {
	char* cpf;
  	cpf = (char*) malloc(14*sizeof(cpf));

  	system("clear||cls");
  	printf("\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///              =======================================================              ///\n");
  	printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  	printf("///              =======================================================              ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ================ Atualizar Funcionário ================              ///\n");
  	printf("///                                                                                   ///\n");
  	printf("///                                                                                   ///\n");
  	do {
		getchar();
    		printf("///          Informe o CPF do funcionário: ");
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

char* telaExcluirFunc(void) {
	char* cpf;
  	cpf = (char*) malloc(14*sizeof(cpf));

  	system("clear||cls");
  	printf("\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///              =======================================================              ///\n");
  	printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  	printf("///              =======================================================              ///\n");
  	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	printf("///                                                                                   ///\n");
  	printf("///              ================= Excluir Funcionário =================              ///\n");
  	printf("///                                                                                   ///\n");
  	printf("///                                                                                   ///\n");
  	do {
		getchar();
    		printf("///          Informe o CPF do funcionário: ");
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

void salvarFuncionario(Funcionario* func) {
	FILE* fp;

  	fp = fopen("funcionario.dat", "ab");
  	if (fp == NULL){
		telaErroArquivoFuncionario(); 
  	}
	fwrite(func, sizeof(Funcionario), 1, fp);
  	fclose(fp);
}

Funcionario* buscarFuncionario(char* cpf) {
	FILE* fp;
	Funcionario* func;

	func = (Funcionario*) malloc(sizeof(Funcionario));
	fp = fopen("funcionario.dat", "rb");
	if (fp == NULL) {
		telaErroArquivoFuncionario();
	}
	while(fread(func, sizeof(Funcionario), 1, fp)) {
		if ((strcmp(func->cpf, cpf) == 0) && (func->status == True)) {
			fclose(fp);
			return func;
		}
	}
	fclose(fp);
	return NULL;
}

void exibirFuncionario(Funcionario* func) {
	
	if (func == NULL) {
		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		printf("///                                                                                   ///\n");
    		printf("///              =============== Funcionario Inexistente ===============              ///\n");
    		printf("///                                                                                   ///\n");
    		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	} else {
		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		printf("///              =======================================================              ///\n");
    		printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    		printf("///              =======================================================              ///\n");
    		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		printf("///                                                                                   ///\n");
		printf("///              ============== Funcionario Cadastrado =================              ///\n");
    		printf("///                                                                                   ///\n");
		printf("///              Nome do Funcionario: %s\n", func->nome);
		printf("///              CPF: %s\n", func->cpf);
    		printf("///              RG: %s\n", func->rg);
		printf("///              Data de nascimento: %s\n", func->nasc);
    		printf("///              Cidade: %s\n", func->city);
    		printf("///              Endereço: %s\n", func->end);
		printf("///              Email: %s\n", func->email);
		printf("///              Telefone: %s\n", func->fone);
    		printf("///              Turno: %s\n", func->trn);
    		printf("///              Status: %d\n", func->status);
    		printf("///                                                                                   ///\n");
    		printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    		getchar();
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}

void regravarFuncionario(Funcionario* func) {
	int achou;
	FILE* fp;
	Funcionario* funcLido;

	funcLido = (Funcionario*) malloc(sizeof(Funcionario));
	fp = fopen("funcionario.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivoFuncionario();
	}
	achou = False;
	while(fread(funcLido, sizeof(Funcionario), 1, fp) && !achou) {
		if (strcmp(funcLido->cpf, func->cpf) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Funcionario), SEEK_CUR);
      			fwrite(func, sizeof(Funcionario), 1, fp);
		}
	}
	fclose(fp);
	free(funcLido);
}
