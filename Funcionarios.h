///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                   Centro de Ensino Superior do Seridó                   ///
///                 Departamento de Computação e Tecnologia                 ///
///                    Disciplina DCT1106 -- Programação                    ///
///              Projeto Sistema de Controle de Estacionamento              ///
///   Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta   ///
///                  Developed by @joaovitorgd - Out, 2021                  ///
///////////////////////////////////////////////////////////////////////////////

#define True 1
#define False 0

typedef struct funcionario Funcionario;

struct funcionario {
  char nome[61];
  char cpf[14];
  char rg[14];
  char nasc[11];
  char city[61];
  char end[61];
  char email[61];
  char fone[12];
  char trn[21];
  int status;
};

void cadastrarFuncionario(void);
void pesquisarFuncionario(void);
void atualizarFuncionario(void);
void excluirFuncionario(void);
void listarFuncionario(void);
void listaFuncionarioPorTurno(void);

void moduloFuncionarios(void);
char telaFuncionarios(void);
void telaErroArquivoFuncionario(void);
Funcionario* telaCadastrarFunc(void);
char* telaPesquisarFunc(void);
char* telaAtualizarFunc(void);
char* telaExcluirFunc(void);

void salvarFuncionario(Funcionario*);
Funcionario* buscarFuncionario(char*);
void exibirFuncionario(Funcionario*);
void regravarFuncionario(Funcionario*);
