
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
            case '2': 	telaAlugando();
                        break;
            case '3': 	telaValores();
                        break;
        } 		
    } while (opc != '0');
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
    printf("///               2 -  Aluguel                                                        ///\n");
    printf("///               3 -  Tabela de Valores                                              ///\n");
    printf("///               0 -  Voltar para meunu principal                                    ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opção que você deseja:                                          \n");
    scanf("%c", &opc);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return opc;
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
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAlugando(void) {
    Aluguel* alg;
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
    do {
    printf("///          Nome do cliente:                                                         ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ] ", alg->nome);
    getchar();
    } while (!validarNome(alg->nome));

    do {
    printf("///          CPF (apenas número):                                                     ///\n");
    scanf("%[0-9]", alg->cpf);
    getchar();
    } while (!validarCPF(alg->cpf));

    do{
    printf("///          Data de entrada (dd/mm/aaaa):                                            ///\n");
    scanf("%[0-9]/", alg->dte);
    getchar();
    } while (!validarData(alg->dte));

    do {
    printf("///          Data de saída (dd/mm/aaaa):                                              ///\n");
    scanf("%[0-9]/", alg->dts);
    getchar();
    } while (!validarData(alg->dts));

    do {
    printf("///          Tipo do veículo:                                                         ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", alg->tpvei);
    getchar();
    } while (!validarNome(alg->tpvei));

    do {
    printf("///          Modelo do veículo:                                                       ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", alg->mdvei);
    getchar();
    } while (!validarNome(alg->mdvei));

    printf("///          Placa do veículo:                                                        ///\n");
    scanf("%[A-Za-z0-9]", alg->placa);
    getchar();

    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///       Valor total do aluguel: R$                                                  ///\n");
    scanf("%[0-9],.", alg->valor);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
    printf("///                                        Hora     Dia     Semana     Mês            ///\n");
    printf("///         Motocicletas             |R$   2,50     10,00   30,00      100,00         ///\n");
    printf("///         Carros de pequeno porte  |R$   5,00     20,00   60,00      200,00         ///\n");
    printf("///         Carros de grande porte   |R$   7,50     30,00   90,00      300,00         ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>>  Aguarde um momento...\n");
    sleep(2);
    getchar();
}
