
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

typedef struct gestao Gestao;

struct gestao {
  char id[10];
  char diaf[10];
  char mesf[10];
  char anof[10];
  char ftd[15];
  char dpd[15];
  char lcd[15];
  int status;
};

void moduloGestao(void);
char telaGestao(void);

void moduloFluxoFinanceiro(void);
void anexarFluxoDeCaixa(void);
void telaErroArquivoFluxoFinanceiro(void);
void pesquisarFluxoDeCaixa(void);
void atualizarFluxoDeCaixa(void);
void excluirFluxoDeCaixa(void);
void listarFluxoDeCaixa(void);
void listaFluxoDeCaixaPorDia(void);
void listaFluxoDeCaixaPorMes(void);

char telaFluxoFinanceiro(void);
Gestao* telaAnexarReceita(void);
char* telaPesquisarFluxoDeCaixa(void);
char* telaAtualizarFluxoDeCaixa(void);
char* telaExcluirFluxoDeCaixa(void);
void telaRelatorioDiario(Gestao*);
void telaRelatorioMensal(Gestao*);

void salvarFluxoDeCaixa(Gestao*);
Gestao* buscarFluxoDeCaixa(char*);
void exibirFluxoDeCaixa(Gestao*);
void regravarFluxoDeCaixa(Gestao*);
