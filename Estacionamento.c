
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
#include "Gestão.h"
#include "Sobre.h"

/////////////////////////////
// Assinaturas das funções //
/////////////////////////////

char telaInicio(void);
void telaValores(void);

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

    telaAnexarReceita();
    telaRelatorioSemanal();
    telaRelatorioMensal();
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
