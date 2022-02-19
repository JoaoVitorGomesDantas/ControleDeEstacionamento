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

typedef struct cliente Cliente;

struct cliente {
  char nome[61];
  char cpf[14];
  char nasc[11];
  char city[61];
  char email[61];
  char fone[12];
  char veic[30];
  char placa[10];
  int status;
};

void cadastrarCliente(void);
void pesquisarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);
void listarCliente(void);
void listaClientesPorCidade(void);

void moduloCliente(void);
char telaCliente(void);
Cliente* telaCadastrar(void);
char* telaPesquisar(void);
char* telaAtualizar(void);
char* telaExcluir(void);

void salvarCliente(Cliente*);
Cliente* buscarCliente(char*);
void exibirCliente(Cliente*);
void regravarCliente(Cliente*);
