///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                   Centro de Ensino Superior do Seridó                   ///
///                 Departamento de Computação e Tecnologia                 ///
///                    Disciplina DCT1106 -- Programação                    ///
///              Projeto Sistema de Controle de Estacionamento              ///
///   Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta   ///
///                  Developed by @joaovitorgd - Out, 2021                  ///
///////////////////////////////////////////////////////////////////////////////

typedef struct funcionario Funcionario;

struct funcionario {
    char nome[61];
    char cpf[14];
    char rg[14];
    char nasc[11];
    char end[61];
    char email[61];
    char fone[12];
    char idenf[14];
};

void moduloFuncionarios(void);
char telaFuncionarios(void);
void telaCadastrarFunc(void);
void telaPesquisarFunc(void);
void telaAtualizarFunc(void);
void telaExcluirFunc(void);
