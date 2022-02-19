
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

typedef struct aluguel Aluguel;

struct aluguel {
  char nome[61];
  char tipo[10];
  char cpf[14];
  char rg[14];
  char dte[11];
  char dts[11];
  char tpvei[40];
  char placa[12];
  char valor[12];
  int status;
};

void cadastrarAluguel(void);
void pesquisarAluguel(void);
void atualizarAluguel(void);
void excluirAluguel(void);
void listarAluguel(void);
void listaAlugueisPorTipo(void);

void moduloAluguel(void);
char telaAluguel(void);
void telaErroArquivoAluguel(void);
void telaVagas(void);
Aluguel* telaAlugando(void);
char* telaPesquisarAluguel(void);
char* telaAtualizarAluguel(void);
char* telaExcluirAluguel(void);
void telaValores(void);

void salvarAluguel(Aluguel*);
Aluguel* buscarAluguel(char*);
void exibirAluguel(Aluguel*);
void regravarAluguel(Aluguel*);
