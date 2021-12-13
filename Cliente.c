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

///////////////////////////////////////
////// Funções do Módulo Cliente //////
///////////////////////////////////////

void moduloCliente(void) {
    char opc;
    do {
        opc = telaCliente();
        switch(opc) {
            case '1': 	telaCadastrar();
                        break;
            case '2': 	telaPesquisar();
                        break;
            case '3': 	telaAtualizar();
                        break;
            case '4': 	telaExcluir();
                        break;
        } 		
    } while (opc != '0');
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

void telaCadastrar(void) {
    char nome[61];
    char cpf[14];
    char nasc[11];
    char email[61];
    char fone[12];
    char veic[30];
    char placa[10];
    char cor[15];

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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();

    printf("///          CPF:                                                                     ///\n");
    scanf("%[0-9].", cpf);
    getchar();

    printf("///          Data de nascimento:                                                      ///\n");
    scanf("%[0-9]/", nasc);


    printf("///          Email:                                                                   ///\n");
    scanf("%[A-Za-z@._]", email);
    getchar();

    printf("///          Telefone:                                                                ///\n");
    scanf("%[0-9]", fone);
    getchar();

    printf("///          Veículo:                                                                 ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", veic);
    getchar();

    printf("///          Placa do veículo:                                                        ///\n");
    scanf("%[A-Za-z0-9]", placa);
    getchar();

    printf("///          Cor do veículo:                                                          ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cor);
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
