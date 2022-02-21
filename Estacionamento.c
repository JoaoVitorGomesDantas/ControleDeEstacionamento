
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
#include "Aluguel.h"
#include "Gestao.h"
#include "Sobre.h"

/////////////////////////////
// Assinaturas das funções //
/////////////////////////////

char telaInicio(void);
void telaSistemaFinalizado(void);

////////////////////////
// Programa principal //
////////////////////////

int main(void) {
    char opc;

    do {
        opc = telaInicio();
        switch(opc) {
            case '1':   moduloCliente();
                break;
            case '2':   moduloAluguel();
                break;
            case '3':   moduloGestao();
                break;
            case '4':   moduloSobre();
                break;
        } 	
  } while (opc != '0');
  telaSistemaFinalizado();
}

/////////////
// Funções //
/////////////

char telaInicio(void) {
    char opc;

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ========================  Menu  =======================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///               1 -  Módulo Clientes                                                ///\n");
    printf("///               2 -  Módulo Aluguel                                                 ///\n");
    printf("///               3 -  Módulo Gestão                                                  ///\n");
    printf("///               4 -  Sobre                                                          ///\n");
    printf("///               0 -  Sair                                                           ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opção que você deseja: ");
    scanf("%c", &opc);
    printf("\n");
    printf("\t\t\t>>>  Aguarde um momento...\n");
    return opc;
}

void telaSistemaFinalizado(void) {
    
    system("clear||cls");
    printf("//////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                    ///\n");
    printf("///                =======================================================             ///\n");
    printf("///                ======   Sistema de Controle de Estacionamento   ======             ///\n");
    printf("///                =======================================================             ///\n");
    printf("///                                                                                    ///\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                    ///\n");
    printf("///                       Obrigado por utilizar o nosso sistema!                       ///\n");
    printf("///                          O sistema está sendo finalizado!                          ///\n");
    printf("///                                 Sistema Finalizado!                                ///\n");
    printf("///                                                                                    ///\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////\n");
    exit(1);
}
