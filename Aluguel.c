
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
#include "Aluguel.h"
#include "Validar.h"

typedef struct aluguel Aluguel;

///////////////////////////////////////
////// Funções do Módulo Aluguel //////
///////////////////////////////////////

void moduloAluguel(void) {
  char opc;
  do {
    opc = telaAluguel();
    switch(opc) {
      case '1': 	telaVagas();
        break;
      case '2': 	cadastrarAluguel();
        break;
      case '3': 	pesquisarAluguel();
        break;
      case '4': 	atualizarAluguel();
        break;
      case '5': 	excluirAluguel();
        break;
      case '6': 	listarAluguel();
        break;
      case '7': 	listaAlugueisPorTipo();
        break;
      case '8':   telaValores();
        break;
    } 		
  } while (opc != '0');
}

void cadastrarAluguel(void) {
  Aluguel *alg;

	alg = telaAlugando();
  salvarAluguel(alg);
	free(alg);
}

void pesquisarAluguel(void) {
  Aluguel* alg;
	char* rg;

	rg = telaPesquisarAluguel();
	alg = buscarAluguel(rg);
	exibirAluguel(alg);
	free(alg); 
	free(rg);
}

void atualizarAluguel(void) {
  Aluguel* alg;
	char* rg;

	rg = telaAtualizarAluguel();
	alg = buscarAluguel(rg);
	if (alg == NULL) {
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              =============== Aluguel não encontrado! ===============              ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  } else {
    alg = telaAlugando();
		strcpy(alg->rg, rg);
    excluirAluguel();
    cadastrarAluguel();
		free(alg);
	}
	free(rg);
}

void excluirAluguel(void) {
  Aluguel* alg;
	char *rg;

	rg = telaExcluirAluguel();
	alg = (Aluguel*) malloc(sizeof(Aluguel));
	alg = buscarAluguel(rg);
	if (alg == NULL) {
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              =============== Aluguel não encontrado! ===============              ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  } else {
		alg->status = False;
		regravarAluguel(alg);
		free(alg);
	}
	free(rg);
}

void listarAluguel(void) {
  FILE* fp;
  Aluguel* alg;
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ================== Lista de Alugueis ==================              ///\n");
  printf("///                                                                                   ///\n");
  alg = (Aluguel*) malloc(sizeof(Aluguel));
  fp = fopen("aluguel.dat", "rb");
  if (fp == NULL) {
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ======= Ocorreu um erro na abertura do arquivo! =======              ///\n");
    printf("///              ======= Não é possível continuar este programa! =======              ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    exit(1);
  }
  while(fread(alg, sizeof(Aluguel), 1, fp)) {
    if (alg->status != 0) {
      exibirAluguel(alg);
    }
  }
  fclose(fp);
}

void listaAlugueisPorTipo(void) {
  FILE* fp;
  char tipo[10];
  Aluguel* alg;
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ============== Lista de Alugueis por Tipo ==============             ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ==================== Buscar Aluguel ====================             ///\n");
  printf("///                                                                                   ///\n");
  printf("///              Informe o Tipo de Aluguel(D,S,M): ");
  scanf(" %50[^\n]", tipo);
  alg = (Aluguel*) malloc(sizeof(Aluguel));
  fp = fopen("aluguel.dat", "rb");
  if (fp == NULL) {
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ======= Ocorreu um erro na abertura do arquivo! =======              ///\n");
    printf("///              ======= Não é possível continuar este programa! =======              ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    exit(1);
  }
  while(fread(alg, sizeof(Aluguel), 1, fp)) {
    if ((strcmp(alg->tipo, tipo) == 0) && (alg->status != 0)) {
      exibirAluguel(alg);
    }
  }
  fclose(fp);
}

char telaAluguel(void) {
  char opc;

  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ===================  Menu de Aluguel ===================             ///\n");
  printf("///                                                                                   ///\n");
  printf("///               1 -  Vagas                                                          ///\n");
  printf("///               2 -  Cadastrar Aluguel                                              ///\n");
  printf("///               3 -  Pesquisar Aluguel                                              ///\n");
  printf("///               4 -  Atualizar Aluguel                                              ///\n");
  printf("///               5 -  Excluir Aluguel                                                ///\n");
  printf("///               6 -  Listar Aluguel                                                 ///\n");
  printf("///               7 -  Listar Aluguel por Tipo                                        ///\n");
  printf("///               8 -  Tabela de Valores                                              ///\n");
  printf("///               0 -  Voltar para meunu principal                                    ///\n");
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

void telaErroArquivoAluguel(void) {
	
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
	printf("///                          informações sobre os alugueis.                           ///\n");
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

void telaVagas(void) {
    
  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              =================== Tabela de Vagas ===================              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                         Quantidade de Vagas                       ///\n");
  printf("///         Motocicletas             |               x                                ///\n");
  printf("///         Carros de pequeno porte  |               y                                ///\n");
  printf("///         Carros de grande porte   |               z                                ///\n");
  printf("///         Vagas Totais             |             x+y+z                              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  getchar();
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

Aluguel* telaAlugando(void) {
  Aluguel *alg;
  alg = (Aluguel*) malloc(sizeof(Aluguel));

  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              =================== Menu para Alugar ==================              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");

  getchar();
  printf("///          Nome do cliente: ");
  scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", alg->nome);
  getchar();

  printf("///          Tipo de Aluguel (Dia: D ; Semana: S ; Mês: M): ");
  scanf("%[A-Z]", alg->tipo);
  getchar();

  do {
    printf("///          CPF (apenas número): ");
    scanf("%[0-9]", alg->cpf);
    getchar();
  } while (!validarCPF(alg->cpf));

  do {
    printf("///          RG (apenas números): ");
    scanf("%[0-9]", alg->rg);
    getchar();
  } while (!validarRG(alg->rg));

  do{
    printf("///          Data de entrada (ddmmaaaa): ");
    scanf("%[0-9/]", alg->dte);
    getchar();
  } while (!validarData(alg->dte));

  do {
    printf("///          Data de saída (ddmmaaaa): ");
    scanf("%[0-9/]", alg->dts);
    getchar();
  } while (!validarData(alg->dts));

  do {
    printf("///          Tipo do veículo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", alg->tpvei);
    getchar();
  } while (!validarNome(alg->tpvei));

  printf("///          Placa do veículo (ABC12D3): ");
  scanf("%[A-Za-z0-9]", alg->placa);
  getchar();

  alg->status = True;

  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///       Valor total do aluguel: R$ ");
  scanf("%[0-9,.]", alg->valor);
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  return alg;
}

char* telaPesquisarAluguel(void) {
  char* rg;
  rg = (char*) malloc(14*sizeof(char));

  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ================== Pesquisar Aluguel ==================              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  do {
    getchar();
    printf("///          Informe o RG: ");
    scanf("%[0-9].", rg);
    getchar();
  } while (!validarRG(rg));

  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  return rg;
}

char* telaAtualizarAluguel(void) {
  char* rg;
  rg = (char*) malloc(14*sizeof(char));

  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ================== Atualizar Aluguel ==================              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  do {
    getchar();
    printf("///          Informe o RG: ");
    scanf("%[0-9].", rg);
    getchar();
  } while (!validarRG(rg));

  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  return rg;
}

char* telaExcluirAluguel(void) {
  char* rg;
  rg = (char*) malloc(14*sizeof(char));

  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              =================== Excluir Aluguel ===================              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  do {
    getchar();
    printf("///          Informe o RG: ");
    scanf("%[0-9].", rg);
    getchar();
  } while (!validarRG(rg));

  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  return rg;
}

void telaValores(void) {
    
  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ================== Tabela de Valores ==================              ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                            Dia        Semana        Mês           ///\n");
  printf("///         Motocicletas             |R$      10,00       30,00        100,00         ///\n");
  printf("///         Carros de pequeno porte  |R$      20,00       60,00        200,00         ///\n");
  printf("///         Carros de grande porte   |R$      30,00       90,00        300,00         ///\n");
  printf("///                                                                                   ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  getchar();
  printf("\t\t\t>>>  Aguarde um momento...\n");
  sleep(2);
  getchar();
}

void salvarAluguel(Aluguel* alg) {
  FILE* fp;

  fp = fopen("aluguel.dat", "ab");
  if (fp == NULL){
    telaErroArquivoAluguel(); 
  }
  fwrite(alg, sizeof(Aluguel), 1, fp);
  fclose(fp);
}

Aluguel* buscarAluguel(char* rg) {
  FILE* fp;
	Aluguel* alg;

	alg = (Aluguel*) malloc(sizeof(Aluguel));
	fp = fopen("aluguel.dat", "rb");
	if (fp == NULL) {
    telaErroArquivoAluguel();
	}
	while(fread(alg, sizeof(Aluguel), 1, fp)) {
    if ((strcmp(alg->rg, rg) == 0) && (alg->status == True)) {
      fclose(fp);
		  return alg;
		}
	}
	fclose(fp);
	return NULL;
}

void exibirAluguel(Aluguel* alg) {
    
if (alg == NULL) {
	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                                   ///\n");
	printf("///              ================= Aluguel Inexistente =================              ///\n");
	printf("///                                                                                   ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
} else {
	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                                   ///\n");
	printf("///              ================== Aluguel Cadastrado =================              ///\n");
	printf("///                                                                                   ///\n");
	printf("///              Nome do cliente: %s\n", alg->nome);
	printf("///              CPF: %s\n", alg->cpf);
	printf("///              RG: %s\n", alg->rg);
	printf("///              Tipo de Aluguel: %s\n", alg->tipo);
	printf("///              Data de entrada: %s\n", alg->dte);
	printf("///              Data de saída: %s\n", alg->dts);
	printf("///              Veículo: %s\n", alg->tpvei);
	printf("///              Placa do veículo: %s\n", alg->placa);
	printf("///              Valor do Aluguel: R$ %s\n", alg->valor);
	printf("///              Status: %d\n", alg->status);
	printf("///                                                                                   ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  }
  getchar();
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}

void regravarAluguel(Aluguel* alg) {
  int achou;
	FILE* fp;
	Aluguel* algLido;

	algLido = (Aluguel*) malloc(sizeof(Aluguel));
	fp = fopen("aluguel.dat", "r+b");
	if (fp == NULL) {
    telaErroArquivoAluguel();
	}
	achou = False;
	while(fread(algLido, sizeof(Aluguel), 1, fp) && !achou) {
    if (strcmp(algLido->rg, alg->rg) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Aluguel), SEEK_CUR);
      fwrite(alg, sizeof(Aluguel), 1, fp);
		}
	}
	fclose(fp);
	free(algLido);
}
