
///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                   Centro de Ensino Superior do Seridó                   ///
///                 Departamento de Computação e Tecnologia                 ///
///                    Disciplina DCT1106 -- Programação                    ///
///              Projeto Sistema de Controle de Estacionamento              ///
///   Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta   ///
///                  Developed by @joaovitorgd - Out, 2021                  ///
///////////////////////////////////////////////////////////////////////////////


typedef struct aluguel Aluguel;

struct aluguel {
  char nome[61];
  char cpf[14];
  char dte[11];
  char dts[11];
  char tpvei[40];
  char mdvei[40];
  char placa[12];
  char valor[12];
};

void moduloAluguel(void);
char telaAluguel(void);
void telaVagas(void);
void telaAlugando(void);
