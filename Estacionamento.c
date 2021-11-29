
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
#include "Funcionarios.h"

////////////////////////////
// Assinatura das funções //
////////////////////////////

char telaInicio(void);
void telaValores(void);
void moduloAluguel(void);
char telaAluguel(void);
void telaVagas(void);
void telaAlugando(void);
void moduloGestao(void);
char telaGestao(void);
char telaFluxoFinanceiro(void);
void telaAnexarReceita(void);
void telaAnexarVagas(void);
void telaRelatorioSemanal(void);
void telaRelatorioMensal(void);
void telaControleVagas(void);
void telaInfo(void);
void telaCriacao(void);

////////////////////////
// Programa principal //
////////////////////////

int main(void) {
    char menu;

    do {
        menu = telaInicio();
        switch(menu) {
            case '1':   moduloCliente();
                        break;
            case '2':   telaValores();
                        break;
            case '3':   moduloAluguel();
                        break;
            case '4':   moduloGestao();
                        break;
            case '5':   telaInfo();
                        telaCriacao();
                        break;

        } 	
    } while (menu != '0');

    ///telaInicio();
    ///telaCliente();
    ///telaCadastrar();
    ///telaPesquisar();
    ///telaAtualizar();
    ///telaExcluir();
    ///telaValores();
    ///telaAluguel();
    ///telaVagas();
    ///telaAlugando();
    ///telaGestao();
    ///telaFuncionarios();
    ///telaCadastrarFunc();
    ///telaPesquisarFunc();
    ///telaAtualizarFunc();
    ///telaExcluirFunc();
    ///telaFluxoFinanceiro();
    telaAnexarReceita();
    ///telaControleVagas();
    telaRelatorioSemanal();
    telaRelatorioMensal();
    ///telaInfo();
    ///telaCriacao();

    return 0;
}

/////////////
// Funções //
/////////////

char telaInicio(void) {
    char menu;
    
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ========================  Menu  =======================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///               1 -  Clientes                                                       ///\n");
    printf("///               2 -  Tabela de Valores                                              ///\n");
    printf("///               3 -  Aluguel                                                        ///\n");
    printf("///               4 -  Gestão                                                         ///\n");
    printf("///               5 -  Sobre                                                          ///\n");
    printf("///               0 -  Sair                                                           ///\n");
    printf("///                                                                                   ///\n");
    printf("///            Escolha a opção que você deseja:                                       ///\n");
    scanf("%c", &menu);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return menu;
}

void telaValores(void) {
    
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================== Tabela de Valores ==================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                        Hora     Dia     Semana     Mês            ///\n");
    printf("///         Motocicletas             |R$   2,50     10,00   30,00      100,00         ///\n");
    printf("///         Carros de pequeno porte  |R$   5,00     20,00   60,00      200,00         ///\n");
    printf("///         Carros de grande porte   |R$   7,50     30,00   90,00      300,00         ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

///////////////////////////////////////
////// Funções do Módulo Aluguel //////
///////////////////////////////////////

void moduloAluguel(void) {
    char alug;
    char menu;
    do {
        menu = telaInicio();
        alug = telaAluguel();
        switch(alug) {
            case '1': 	telaVagas();
                        break;
            case '2': 	telaAlugando();
                        break;
        } 		
    } while (menu != '0');
}

char telaAluguel(void) {
    char alug;

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
    printf("///               2 -  Aluguel                                                        ///\n");
    printf("///               0 -  Voltar para meunu principal                                    ///\n");
    printf("///                                                                                   ///\n");
    printf("///            Escolha a opção que você deseja:                                       ///\n");
    scanf("%c", &alug);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return alug;
}

void telaVagas(void) {

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
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAlugando(void) {
    char nome[61];
    char cpf[14];
    char dte[11];
    char dts[11];
    char tpvei[40];
    char mdvei[40];
    char placa[12];
    char valor[12];


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
    printf("///          Nome do cliente:                                                         ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    printf("///          CPF:                                                                     ///\n");
    scanf("%[0-9]", cpf);
    printf("///          Data de entrada:                                                         ///\n");
    scanf("%[0-9]/", dte);
    printf("///          Data de saída:                                                           ///\n");
    scanf("%[0-9]/", dts);
    printf("///          Tipo do veículo:                                                         ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", tpvei);
    printf("///          Modelo do veículo:                                                       ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", mdvei);
    printf("///          Placa do veículo:                                                        ///\n");
    scanf("%[A-Za-z0-9]", placa);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///       Valor total do aluguel: R$                                                  ///\n");
    scanf("%[0-9],.", valor);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

//////////////////////////////////////
////// Funções do Módulo Gestão //////
//////////////////////////////////////

void moduloGestao(void) {
    char gest;
    char menu;

    do {
        gest = telaGestao();
        menu = telaInicio();
        switch(gest) {
            case '1': 	telaFuncionarios();
                        break;
            case '2': 	telaFluxoFinanceiro();
                        break;
            case '3': 	telaControleVagas();
                        break;
        } 		
    } while (menu != '0');
}

char telaGestao(void) {
    char gest;

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
    scanf("%c", &gest);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return gest;
}

char telaFluxoFinanceiro(void) {
    char flux;

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
    scanf("%c", &flux);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return flux;
}

void telaAnexarReceita(void) {

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


void telaInfo(void) {
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                    Universidade Federal do Rio Grande do Norte                    ///\n");
    printf("///                        Centro de Ensino Superior do Seridó                        ///\n");
    printf("///                      Departamento de Computação e Tecnologia                      ///\n");
    printf("///                         Disciplina DCT1106 -- Programação                         ///\n");
    printf("///                   Projeto Sistema de Controle de Estacionamento                   ///\n");
    printf("///                       Developed by @joaovitorgd - Out, 2021                       ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ======== Sistema de Controle de Estacionamento ========              ///\n");
    printf("///                                                                                   ///\n");
    printf("///      Projeto da disciplina DCT1106 - Programação, para criação de um sistema      ///\n");
    printf("///      de controle de estacionamentos ao qual tem por objetivos desenvolver um      ///\n");
    printf("///      programa de computador que possibilite aos administradores de uma empre-     ///\n");
    printf("///      sa controlar a entrada e saída de veículos, além de registrar o fluxo        ///\n");
    printf("///      financeiro dessa empresa, facilitando a gestão do negócio.                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaCriacao(void) {
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                    Universidade Federal do Rio Grande do Norte                    ///\n");
    printf("///                        Centro de Ensino Superior do Seridó                        ///\n");
    printf("///                      Departamento de Computação e Tecnologia                      ///\n");
    printf("///                         Disciplina DCT1106 -- Programação                         ///\n");
    printf("///                   Projeto Sistema de Controle de Estacionamento                   ///\n");
    printf("///                       Developed by @joaovitorgd - Out, 2021                       ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///             ========= Sistema de Controle de Estacionamento =========             ///\n");
    printf("///                                                                                   ///\n");
    printf("///    Este projeto exemplo foi desenvolvido por:                                     ///\n");
    printf("///                                                                                   ///\n");
    printf("///    Aluno: João Vitor Gomes Dantas                                                 ///\n");
    printf("///    E-mail: joao.vitor.dantas.085@ufrn.edu.br                                      ///\n");
    printf("///    Redes sociais: @joaovitorgd                                                    ///\n");
    printf("///    Repositório: https://github.com/JoaoVitorGomesDantas/ControleDeEstacionamento  ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
