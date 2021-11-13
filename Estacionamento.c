
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

/////
// Assinatura das funções
void telaInfo(void);
void telaCriacao(void);
void telaInicio(void);
void telaCliente(void);
void telaCadastrar(void);
void telaPesquisar(void);
void telaAtualizar(void);
void telaExcluir(void);
void telaValores(void);

/////
// Programa principal
int main(void) {
    telaInfo();
    telaCriacao();
    telaInicio();
    telaCliente();
    telaCadastrar();
    telaPesquisar();
    telaAtualizar();
    telaExcluir();
    telaValores();
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

void telaInicio(void) {
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
    printf("///               5 -  Sobre o Sistema                                                ///\n");
    printf("///               6 -  Sair                                                           ///\n");
    printf("///                                                                                   ///\n");
    printf("///            Escolha a opção que você deseja:                                       ///\n");
    scanf("%c", &menu);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaCliente(void) {
    char cli;
    
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
    printf("///               5 -  Voltar ao Menu                                                 ///\n");
    printf("///                                                                                   ///\n");
    printf("///            Escolha a opção que você deseja:                                       ///\n");
    scanf("%c", &cli);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaCadastrar(void) {
    char nome[61];
    char cpf[14];
    char nasc[11];
    char email[61];
    char tel[12];
    char veic[30];
    char placa[10];
    char cor[15];
    
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///              =======================================================              ///\n");
    printf("///              ======   Sistema de Controle de Estacionamento   ======              ///\n");
    printf("///              =======================================================              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///              ================= Cadastro do Cliente =================              ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///          Nome do cliente:                                                         ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    printf("///          CPF:                                                                     ///\n");
    scanf("%[0-9]", cpf);
    printf("///          Data de nascimento:                                                      ///\n");
    scanf("%[0-9]/", nasc);
    printf("///          Email:                                                                   ///\n");
    scanf("%[A-Za-z@._]", email);
    printf("///          Telefone:                                                                ///\n");
    scanf("%[0-9]", tel);
    printf("///          Veículo:                                                                 ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", veic);
    printf("///          Placa do veículo:                                                        ///\n");
    scanf("%[A-Za-z0-9]", placa);
    printf("///          Cor do veículo:                                                          ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cor);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaPesquisar(void) {
    char cpf;
    
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
