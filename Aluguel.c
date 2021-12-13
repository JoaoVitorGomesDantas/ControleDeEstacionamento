
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
#include "Aluguel.h"

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
            case '2': 	telaAlugando();
                        break;
        } 		
    } while (opc != '0');
}

char telaAluguel(void) {
    char opc;

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
    scanf("%c", &opc);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return opc;
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
    getchar();

    printf("///          CPF:                                                                     ///\n");
    scanf("%[0-9]", cpf);
    getchar();

    printf("///          Data de entrada:                                                         ///\n");
    scanf("%[0-9]/", dte);
    getchar();

    printf("///          Data de saída:                                                           ///\n");
    scanf("%[0-9]/", dts);
    getchar();

    printf("///          Tipo do veículo:                                                         ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", tpvei);
    getchar();

    printf("///          Modelo do veículo:                                                       ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", mdvei);
    getchar();

    printf("///          Placa do veículo:                                                        ///\n");
    scanf("%[A-Za-z0-9]", placa);
    getchar();

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

