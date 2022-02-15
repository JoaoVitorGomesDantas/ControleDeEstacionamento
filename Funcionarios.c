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
    	printf("\n\nAluno não encontrado!\n\n");
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
    	printf("\n\nAluno não encontrado!\n\n");
  	} else {
		  func->status = False;
		  regravarFuncionario(func);
		  free(func);
	}
	free(cpf);
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
	printf("///                          informações sobre os clientes.                           ///\n");
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
    
    do {
      printf("///          Nome:                                                                    ///\n");
      scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->nome);
      getchar();
    } while (!validarNome(func->nome));

    do {
      printf("///          CPF (apenas números):                                                    ///\n");
      scanf("%[0-9].", func->cpf);
      getchar();
    } while (!validarCPF(func->cpf));
    
    do {
    printf("///          RG (apenas números):                                                       ///\n");
    scanf("%[0-9]", func->rg);
    getchar();
    } while (!validarRG(func->rg));

    do {
    printf("///          Data de nascimento:                                                      ///\n");
    scanf("%[0-9]/", func->nasc);
    getchar();
    } while (!validarData(func->nasc));

    do {
    printf("///          Endereço:                                                                ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->end);
    getchar();
    } while(!validarNome(func->end));

    printf("///          Email:                                                                   ///\n");
    scanf("%[A-Za-z@._]", func->email);

    do {
      printf("///          Telefone (apenas número com DDD):                                        ///\n");
      scanf("%[0-9]", func->fone);
      getchar();
    } while (!validaTelefone(func->fone));

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
      printf("///          Informe o CPF do funcionário:                                            ///\n");
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
      printf("///          Informe o CPF do funcionário:                                            ///\n");
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
      printf("///          Informe o CPF do funcionário:                                            ///\n");
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

  fp = fopen("funcionário.dat", "ab");
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
    		if (strcmp(func->cpf, cpf) && (func->status == True)) {
			fclose(fp);
			return func;
		}
	}
	fclose(fp);
	return func;
}

void exibirFuncionario(Funcionario* func) {

	if (func == NULL) {
		printf("\n= = = Funcionario Inexistente = = =\n");
	} else {
		printf("\n= = = Funcionario Cadastrado = = =\n");
		printf("Nome do Funcionario: %s\n", func->nome);
		printf("CPF: %s\n", func->cpf);
    		printf("RG: %s\n", func->rg);
		printf("Data de nascimento: %s\n", func->nasc);
    		printf("Endereço: %s\n", func->end);
		printf("Email: %s\n", func->email);
		printf("Telefone: %s\n", func->fone);
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
