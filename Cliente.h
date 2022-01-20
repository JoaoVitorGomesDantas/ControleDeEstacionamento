///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                   Centro de Ensino Superior do Seridó                   ///
///                 Departamento de Computação e Tecnologia                 ///
///                    Disciplina DCT1106 -- Programação                    ///
///              Projeto Sistema de Controle de Estacionamento              ///
///   Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta   ///
///                  Developed by @joaovitorgd - Out, 2021                  ///
///////////////////////////////////////////////////////////////////////////////

typedef struct cliente Cliente;

struct cliente {
  char nome[61];
  char cpf[14];
  char nasc[11];
  char email[61];
  char fone[12];
  char veic[30];
  char placa[10];
  char cor[15];
};

void cadastrarCliente(void);
void pesquisarCliente(void);

void moduloCliente(void);
char telaCliente(void);
char telaCadastrar(void);
char* telaPesquisar(void);
char* telaAtualizar(void);
char* telaExcluir(void);

void salvarCliente(Cliente*);
Cliente* buscarCliente(char*);
void exibirCliente(Cliente*);
