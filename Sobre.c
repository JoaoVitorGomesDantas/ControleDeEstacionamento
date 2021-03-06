
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
#include "Sobre.h"


void moduloSobre(void) {
  char opc;
  do {
    opc = telaSobre();
    switch(opc) {
      case '1': 	telaInfo();
        break;
      case '2': 	telaCriacao();
        break;
    } 		
  } while (opc != '0');
}

char telaSobre(void) {
  char opc;

  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///              =======================================================              ///\n");
  printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
  printf("///              =======================================================              ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ========= Menu de Informações Sobre o Projeto =========              ///\n");
  printf("///                                                                                   ///\n");
  printf("///               1 -  Informações sobre o projeto                                    ///\n");
  printf("///               2 -  Informações sobre o criador do projeto                         ///\n");
  printf("///               0 -  Voltar ao Menu principal                                       ///\n");
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

void telaInfo(void) {
    
  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///                    Universidade Federal do Rio Grande do Norte                    ///\n");
  printf("///                        Centro de Ensino Superior do Seridó                        ///\n");
  printf("///                      Departamento de Computação e Tecnologia                      ///\n");
  printf("///                         Disciplina DCT1106 -- Programação                         ///\n");
  printf("///                   Projeto Sistema de Controle de Estacionamento                   ///\n");
  printf("///        Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta        ///\n");
  printf("///      Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta_2020.2   ///\n");
  printf("///                       Developed by @joaovitorgd - Out, 2021                       ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///        ============== Sistema de Controle de Estacionamento ==============        ///\n");
  printf("///                                                                                   ///\n");
  printf("///      Projeto da disciplina DCT1106 - Programação, para criação de um sistema      ///\n");
  printf("///      de controle de estacionamentos ao qual tem por objetivos desenvolver um      ///\n");
  printf("///      programa de computador que possibilite aos administradores de uma empre-     ///\n");
  printf("///      sa controlar a entrada e saída de veículos, além de registrar o fluxo        ///\n");
  printf("///      financeiro dessa empresa, facilitando a gestão do negócio.                   ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  sleep(5);
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void telaCriacao(void) {
    
  system("clear||cls");
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///                    Universidade Federal do Rio Grande do Norte                    ///\n");
  printf("///                        Centro de Ensino Superior do Seridó                        ///\n");
  printf("///                      Departamento de Computação e Tecnologia                      ///\n");
  printf("///                         Disciplina DCT1106 -- Programação                         ///\n");
  printf("///                   Projeto Sistema de Controle de Estacionamento                   ///\n");
  printf("///        Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta        ///\n");
  printf("///      Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta_2020.2   ///\n");
  printf("///                       Developed by @joaovitorgd - Out, 2021                       ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                                   ///\n");
  printf("///              ======== Sistema de Controle de Estacionamento ========              ///\n");
  printf("///                                                                                   ///\n");
  printf("///    Este projeto exemplo foi desenvolvido por:                                     ///\n");
  printf("///                                                                                   ///\n");
  printf("///    Aluno: João Vitor Gomes Dantas                                                 ///\n");
  printf("///    E-mail: joao.vitor.dantas.085@ufrn.edu.br                                      ///\n");
  printf("///    Redes sociais: @joaovitorgd                                                    ///\n");
  printf("///    Repositório: https://github.com/JoaoVitorGomesDantas/ControleDeEstacionamento  ///\n");
  printf("///    Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta            ///\n");
  printf("///    Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta_2020.2     ///\n");
  printf("///                                                                                   ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  sleep(5);
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}
