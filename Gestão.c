
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
#include "Gestão.h"

/////////////////////////////////////
///// Funções do Módulo Gestão //////
/////////////////////////////////////

void moduloGestao(void) {
    char opc;

    do {
        opc = telaGestao();
        switch(opc) {
            case '1': 	telaFuncionarios();
                        break;
            case '2': 	telaFluxoFinanceiro();
                        break;
            case '3': 	telaControleVagas();
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
    printf("///               1 -  Funcionários                                                   ///\n");
    printf("///               2 -  Fluxo financeiro                                               ///\n");
    printf("///               3 -  Controle de vagas                                              ///\n");
    printf("///               0 -  Voltar para o menu principal                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///            Escolha a opção que você deseja:                                       ///\n");
    scanf("%c", &opc);
    getchar();

    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return opc;
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
    printf("///               2 -  Anexar fluxo de vagas                                          ///\n");
    printf("///               3 -  Relatório semanal                                              ///\n");
    printf("///               4 -  Relatório mensal                                               ///\n");
    printf("///               0 -  Voltar ao menu principal                                       ///\n");
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

void telaAnexarReceita(void) {

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
    printf("///          Faturamento diário:                                                      ///\n");
    printf("///          Daspesas diária:                                                         ///\n");
    printf("///          Lucro do dia:                                                            ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAnexarVagas(void) {

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Controle de Vagas ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///       Vagas alugadas no dia:                                                      ///\n");
    printf("///       Vagas alugadas no semana:                                                   ///\n");
    printf("///       Vagas alugadas no mês:                                                      ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaRelatorioSemanal(void) {

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Relatório Semanal ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///       Receita Semanal da Empresa:                                                 ///\n");
    printf("///       Lucro Semanal da Empresa:                                                   ///\n");
    printf("///       Despesas Semanais da Empresa:                                               ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaRelatorioMensal(void) {

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Relatório Semanal ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///       Receita Mensal da Empresa:                                                  ///\n");
    printf("///       Lucro Mensal da Empresa:                                                    ///\n");
    printf("///       Despesas Mensais da Empresa:                                                ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaControleVagas(void) {

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Controle de Vagas ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///          Vagas Totais:                                                            ///\n");
    printf("///          Vagas em Uso:                                                            ///\n");
    printf("///          Vagas Disponíveis:                                                       ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
