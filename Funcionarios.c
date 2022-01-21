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

typedef struct funcionario Funcionario;

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

    system("clear||cls");
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
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opção que você deseja:                                          \n");
    scanf("%c", &opc);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return opc;
}

char telaCadastrarFunc(void) {
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));

    system("clear||cls");
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
    
    do {
      printf("///          Nome:                                                                    ///\n");
      scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->nome);
      getchar();
    } while (!validarNome(func->nome));

    do {
      printf("///          CPF (apenas números):                                                    ///\n");
      scanf("%[0-9].", func->cpf);
      getchar();
    } while (!validarCPF(func->cpf));

    printf("///          RG:                                                                      ///\n");
    scanf("%[0-9]", func->rg);
    printf("///          Data de nascimento:                                                      ///\n");
    scanf("%[0-9]/", func->nasc);
    printf("///          Endereço:                                                                ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->end);
    printf("///          Email:                                                                   ///\n");
    scanf("%[A-Za-z@._]", func->email);

    do {
      printf("///          Telefone (apenas número com DDD):                                        ///\n");
      scanf("%[0-9]", func->fone);
      getchar();
    } while (!validaTelefone(func->fone));

    printf("///          Telefone:                                                                ///\n");
    scanf("%[0-9- ]", func->fone);
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    exit(1);
}

char* telaPesquisarFunc(void) {
    char* cpf;
    cpf = (char*) malloc(14*sizeof(cpf));

    system("clear||cls");
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
    printf("///          Informe o CPF do funcionário:                                            ///\n");
    scanf("%[0-9]", cpf);
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}

char* telaAtualizarFunc(void) {
    char* cpf;
    cpf = (char*) malloc(14*sizeof(cpf));

    system("clear||cls");
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
    printf("///          Informe o CPF do funcionário:                                            ///\n");
    scanf("%[0-9]", cpf);
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}

char* telaExcluirFunc(void) {
    char* cpf;
    cpf = (char*) malloc(14*sizeof(cpf));

    system("clear||cls");
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
    printf("///          Informe o CPF do funcionário:                                            ///\n");
    scanf("%[0-9]", cpf);
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}

