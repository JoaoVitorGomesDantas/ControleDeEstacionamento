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
#include "Funcionarios.h"

void moduloFuncionarios(void) {
    char opc;

    do {
        opc = telaFuncionarios();
        switch(opc) {
            case '1': 	telaCadastrarFunc();
                        break;
            case '2': 	telaPesquisarFunc();
                        break;
            case '3': 	telaAtualizarFunc();
                        break;
            case '4': 	telaExcluirFunc();
                        break;
        } 		
    } while (opc != '0');
}

char telaFuncionarios(void) {
    char opc;

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
    printf("///            Escolha a opção que você deseja:                                       ///\n");
    scanf("%c", &opc);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return opc;
}

void telaCadastrarFunc(void) {
    char nome[61];
    char cpf[14];
    char rg[14];
    char nasc[11];
    char end[61];
    char email[61];
    char fone[12];
    char idenf[14];

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
    printf("///          Nome:                                                                    ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    printf("///          CPF:                                                                     ///\n");
    scanf("%[0-9]", cpf);
    printf("///          RG:                                                                      ///\n");
    scanf("%[0-9]", rg);
    printf("///          Data de nascimento:                                                      ///\n");
    scanf("%[0-9]/", nasc);
    printf("///          Endereço:                                                                ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", end);
    printf("///          Email:                                                                   ///\n");
    scanf("%[A-Za-z@._]", email);
    printf("///          Telefone:                                                                ///\n");
    scanf("%[0-9- ]", fone);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///       Número de identificação do funcionário:                                     ///\n");
    scanf("%[0-9]", idenf);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaPesquisarFunc(void) {
    char idenf;

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
    printf("///          Informe o número de idenfiticação:                                       ///\n");
    scanf("%[0-9]", &idenf);
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

void telaAtualizarFunc(void) {
    char idenf;

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
    printf("///          Informe o número de idenfiticação:                                       ///\n");
    scanf("%[0-9]", &idenf);
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

void telaExcluirFunc(void) {
    char idenf;

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
    printf("///          Informe o número de identificação:                                       ///\n");
    scanf("%[0-9]", &idenf);
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

