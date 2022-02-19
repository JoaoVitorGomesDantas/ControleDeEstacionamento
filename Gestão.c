
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
#include "Gestao.h"
#include "Validar.h"

/////////////////////////////////////
///// Funções do Módulo Gestão //////
/////////////////////////////////////

typedef struct gestao Gestao;

void moduloGestao(void) {
    char opc;

    do {
        opc = telaGestao();
        switch(opc) {
            case '1': 	moduloFuncionarios();
                break;
            case '2': 	moduloFluxoFinanceiro();
                break;
        } 		
    } while (opc != '0');
}

char telaGestao(void) {
    char opc;

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ===================  Menu de Gestão ===================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///               1 -  Módulo Funcionários                                            ///\n");
    printf("///               2 -  Fluxo financeiro                                               ///\n");
    printf("///               0 -  Voltar para o menu principal                                   ///\n");
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

void moduloFluxoFinanceiro(void) {
    char opc;

    do {
        opc = telaFluxoFinanceiro();
        switch(opc) {
            case '1': 	anexarFluxoDeCaixa();
                break;
            case '2': 	pesquisarFluxoDeCaixa();
                break;
            case '3': 	atualizarFluxoDeCaixa();
                break;
            case '4': 	excluirFluxoDeCaixa();
                break;
            case '5': 	listarFluxoDeCaixa();
                break;
            case '6': 	listaFluxoDeCaixaPorDia();
                break;
            case '7': 	listaFluxoDeCaixaPorMes();
                break;
        } 		
    } while (opc != '0');
}

void anexarFluxoDeCaixa(void) {
    Gestao *gest;

	gest = telaAnexarReceita();
    salvarFluxoDeCaixa(gest);
	free(gest);
}

void pesquisarFluxoDeCaixa(void) {
	Gestao* gest;
	char* id;

	id = telaPesquisarFluxoDeCaixa();
	gest = buscarFluxoDeCaixa(id);
	exibirFluxoDeCaixa(gest);
	free(gest); 
	free(id);
}

void atualizarFluxoDeCaixa(void) {
	Gestao* gest;
	char* id;

	id = telaAtualizarFluxoDeCaixa();
	gest = buscarFluxoDeCaixa(id);
	if (gest == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ============ Fluxo de Caixa não encontrado! ============             ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  	} else {
        gest = telaAnexarReceita();
        strcpy(gest->id, id);
        excluirFluxoDeCaixa();
        anexarFluxoDeCaixa();
        free(gest);
	}
	free(id);
}

void excluirFluxoDeCaixa(void) {
	Gestao* gest;
	char *id;

	id = telaExcluirFluxoDeCaixa();
	gest = (Gestao*) malloc(sizeof(Gestao));
	gest = buscarFluxoDeCaixa(id);
	if (gest == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ============ Fluxo de Caixa não encontrado! ============             ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    } else {
        gest->status = False;
		regravarFluxoDeCaixa(gest);
		free(gest);
	}
    free(id);
}

void listarFluxoDeCaixa(void) {
    FILE* fp;
    Gestao* gest;
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              =============== Lista do Fluxo de Caixa ===============              ///\n");
    printf("///                                                                                   ///\n");
    gest = (Gestao*) malloc(sizeof(Gestao));
    fp = fopen("gestao.dat", "rb");
    if (fp == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ======= Ocorreu um erro na abertura do arquivo! =======              ///\n");
        printf("///              ======= Não é possível continuar este programa! =======              ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if (gest->status != 0) {
            exibirFluxoDeCaixa(gest);
        }
    }
    fclose(fp);
}

void listaFluxoDeCaixaPorDia(void) {
    FILE* fp;
    char diaf[10];
    Gestao* gest;
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              =========== Lista do Fluxo de Caixa por mês ===========              ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================= Buscar Fluxo de Caixa ================             ///\n");
    printf("///                                                                                   ///\n");
    printf("///              Informe o Dia: ");
    scanf(" %50[^\n]", diaf);
    gest = (Gestao*) malloc(sizeof(Gestao));
    fp = fopen("gestao.dat", "rb");
    if (fp == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ======= Ocorreu um erro na abertura do arquivo! =======              ///\n");
        printf("///              ======= Não é possível continuar este programa! =======              ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if ((strcmp(gest->diaf, diaf) == 0) && (gest->status != 0)) {
            telaRelatorioDiario(gest);
        }
    }
    fclose(fp);
}

void listaFluxoDeCaixaPorMes(void) {
    FILE* fp;
    char mesf[10];
    Gestao* gest;
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              =========== Lista do Fluxo de Caixa por mês ===========              ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================= Buscar Fluxo de Caixa ================             ///\n");
    printf("///                                                                                   ///\n");
    printf("///              Informe o Mês: ");
    scanf(" %50[^\n]", mesf);
    gest = (Gestao*) malloc(sizeof(Gestao));
    fp = fopen("gestao.dat", "rb");
    if (fp == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ======= Ocorreu um erro na abertura do arquivo! =======              ///\n");
        printf("///              ======= Não é possível continuar este programa! =======              ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if ((strcmp(gest->mesf, mesf) == 0) && (gest->status != 0)) {
            telaRelatorioMensal(gest);
        }
    }
    fclose(fp);
}

char telaFluxoFinanceiro(void) {
    char opc;

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ==============  Menu do Fluxo Financeiro ==============              ///\n");
    printf("///                                                                                   ///\n");
    printf("///               1 -  Anexar fluxo de caixa                                          ///\n");
    printf("///               2 -  Pesquisar fluxo de caixa                                       ///\n");
    printf("///               3 -  Atualizar fluxo de caixa                                       ///\n");
    printf("///               4 -  Excluir fluxo de caixa                                         ///\n");
    printf("///               5 -  Listar fluxo de caixa                                          ///\n");
    printf("///               6 -  Relatório diário                                               ///\n");
    printf("///               7 -  Relatório mensal                                               ///\n");
    printf("///               0 -  Voltar ao menu principal                                       ///\n");
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

void telaErroArquivoFluxoFinanceiro(void) {
    
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
	printf("///                       informações sobre o fluxo financeiro.                       ///\n");
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

Gestao* telaAnexarReceita(void) {
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              =================== Fluxo Financeiro ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    getchar();
    printf("///          ID do Cadastro: ");
    scanf("%[0-9].", gest->id);
    getchar();

    printf("///          Data do Cadastro (dd/mm/aaaa):                                           ///\n");
    printf("///          Informe o Dia:");
    scanf("%[0-9]", gest->diaf);
    getchar();

    printf("///          Informe o Mês:");
    scanf("%[0-9]", gest->mesf);
    getchar();

    printf("///          Informe o Ano:");
    scanf("%[0-9]", gest->anof);
    getchar();
  
    printf("///          Faturamento diário: ");
    scanf("%[0-9].", gest->ftd);
    getchar();

    printf("///          Daspesas diária: ");
    scanf("%[0-9].", gest->dpd);
    getchar();

    printf("///          Lucro diário: ");
    scanf("%[0-9].", gest->lcd);
    getchar();

    gest->status = True;

    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return gest;
}

char* telaPesquisarFluxoDeCaixa(void) {
    char* id;
    id = (char*) malloc(14*sizeof(id));

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

    getchar();
    printf("///          Informe o ID do Cadastro: ");
    scanf("%[0-9].", id);
    getchar();

    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return id;
}

char* telaAtualizarFluxoDeCaixa(void) {
    char* id;
    id = (char*) malloc(14*sizeof(id));

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

    getchar();
    printf("///          Informe o ID do Cadastro: ");
    scanf("%[0-9].", id);
    getchar();

    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return id;
}

char* telaExcluirFluxoDeCaixa(void) {
    char* id;
    id = (char*) malloc(14*sizeof(id));

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

    getchar();
    printf("///          Informe o ID do Cadastro: ");
    scanf("%[0-9].", id);
    getchar();
   
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return id;
}

void telaRelatorioDiario(Gestao* gest) {
    
    if (gest == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ============== Fluxo de Caixa Inexistente ==============             ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	} else {
        printf("\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///              =======================================================              ///\n");
        printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
        printf("///              =======================================================              ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ================== Relatório Diário ==================               ///\n");
        printf("///                                                                                   ///\n");
        printf("///                                                                                   ///\n");
        printf("///              ID do Cadastro: %s\n", gest->id);
        printf("///              Dia do Cadastro (dd): %s\n", gest->diaf);
        printf("///              Mês do Cadastro (mm): %s\n", gest->mesf);
        printf("///              Ano do Cadastro (aaaa): %s\n", gest->anof);
	    printf("///              Faturamento diário: %s\n", gest->ftd);
        printf("///              Daspesas diária: %s\n", gest->dpd);
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        getchar();
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaRelatorioMensal(Gestao* gest) {
    
    if (gest == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ============== Fluxo de Caixa Inexistente ==============             ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	} else {
        printf("\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///              =======================================================              ///\n");
        printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
        printf("///              =======================================================              ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ================== Relatório Mensal ===================              ///\n");
        printf("///                                                                                   ///\n");
        printf("///                                                                                   ///\n");
        printf("///              ID do Cadastro: %s\n", gest->id);
	    printf("///              Dia do Cadastro (dd): %s\n", gest->diaf);
        printf("///              Mês do Cadastro (mm): %s\n", gest->mesf);
        printf("///              Ano do Cadastro (aaaa): %s\n", gest->anof);
	    printf("///              Faturamento diário: %s\n", gest->ftd);
        printf("///              Daspesas diária: %s\n", gest->dpd);
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void salvarFluxoDeCaixa(Gestao* gest) {
    FILE* fp;

    fp = fopen("gestao.dat", "ab");
    if (fp == NULL){
        telaErroArquivoFluxoFinanceiro(); 
    }
    fwrite(gest, sizeof(Gestao), 1, fp);
    fclose(fp);
}

Gestao* buscarFluxoDeCaixa(char* id) {
	FILE* fp;
	Gestao* gest;

	gest = (Gestao*) malloc(sizeof(Gestao));
	fp = fopen("gestao.dat", "rb");
	if (fp == NULL) {
		telaErroArquivoFluxoFinanceiro();
	}
	while(fread(gest, sizeof(Gestao), 1, fp)) {
        if ((strcmp(gest->id, id) == 0) && (gest->status == True)) {
            fclose(fp);
		    return gest;
        }
	}
	fclose(fp);
	return NULL;
}

void exibirFluxoDeCaixa(Gestao* gest) {
    
    if (gest == NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
        printf("///              ============== Fluxo de Caixa Inexistente ==============             ///\n");
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	} else {
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                                   ///\n");
		printf("///              ============== Fluxo De Caixa Cadastrado ==============              ///\n");
        printf("///                                                                                   ///\n");
		printf("///              ID do Cadastro: %s\n", gest->id);
		printf("///              Dia do Cadastro (dd): %s\n", gest->diaf);
        printf("///              Mês do Cadastro (mm): %s\n", gest->mesf);
        printf("///              Ano do Cadastro (aaaa): %s\n", gest->anof);
		printf("///              Faturamento diário: %s\n", gest->ftd);
        printf("///              Daspesas diária: %s\n", gest->dpd);
		printf("///              Lucro diário: %s\n", gest->lcd);
        printf("///                                                                                   ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
        getchar();
    }
	printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
}

void regravarFluxoDeCaixa(Gestao* gest) {
    int achou;
	FILE* fp;
	Gestao* gestLido;

	gestLido = (Gestao*) malloc(sizeof(Gestao));
	fp = fopen("gestao.dat", "r+b");
	if (fp == NULL) {
        telaErroArquivoFluxoFinanceiro();
	}
	achou = False;
	while(fread(gestLido, sizeof(Gestao), 1, fp) && !achou) {
        if (strcmp(gestLido->id, gest->id) == 0) {
            achou = True;
			fseek(fp, -1*sizeof(Gestao), SEEK_CUR);
            fwrite(gest, sizeof(Gestao), 1, fp);
		}
	}
	fclose(fp);
	free(gestLido);
}
