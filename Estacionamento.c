
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

/////
// Assinatura das funções
void telaInfo(void);
void telaCriacao(void);
void telaInicio(void);
void telaCliente(void);

/////
// Programa principal
int main(void) {
    telaInfo();
    telaCriacao();
    telaInicio();
    telaCliente();
    return 0;
}

/////
// Funções

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
    printf("///             ========= Sistema de Controle de Estacionamento =========             ///\n");
    printf("///                                                                                   ///\n");
    printf("///      Projeto da disciplina DCT1106 - Programação, para criação de um sistema      ///\n");
    printf("///      de controle de estacionamentos ao qual tem por objetivos desenvolver um      ///\n");
    printf("///      programa de computador que possibilite aos administradores de uma empre-     ///\n");
    printf("///      sa controlar a entrada e saída de veículos, além de registrar o fluxo        ///\n");
    printf("///      financeiro dessa empresa, facilitando a gestão do negócio.                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
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
}

void telaInicio(void) {
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                                ======  Menu  ======                               ///\n");
    printf("///                                                                                   ///\n");
    printf("///               1 -  Cliente                                                        ///\n");
    printf("///               2 -  Valores                                                        ///\n");
    printf("///               3 -  Vagas                                                          ///\n");
    printf("///               4 -  Agendamento                                                    ///\n");
    printf("///               5 -  Sobre o Sistema                                                ///\n");
    printf("///               6 -  Sair                                                           ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaCliente(void) {
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                          ======  Menu dos Cliente ======                          ///\n");
    printf("///                                                                                   ///\n");
    printf("///               1 -  Cadastrar cliente                                              ///\n");
    printf("///               2 -  Pesquisar dados do cliente                                     ///\n");
    printf("///               3 -  Atualizar dados do cliente                                     ///\n");
    printf("///               4 -  Excluir cliente do sistema                                     ///\n");
    printf("///               5 -  Voltar ao Menu                                                 ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
