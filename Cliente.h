///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                   Centro de Ensino Superior do Seridó                   ///
///                 Departamento de Computação e Tecnologia                 ///
///                    Disciplina DCT1106 -- Programação                    ///
///              Projeto Sistema de Controle de Estacionamento              ///
///   Inspirado em: @flgorgonio https://github.com/flgorgonio/linguasolta   ///
///                  Developed by @joaovitorgd - Out, 2021                  ///
///////////////////////////////////////////////////////////////////////////////

void cadastrarCliente(void);
void pesquisarCliente(void);

void moduloCliente(void);
char telaCliente(void);
void telaCadastrar(void);
void telaPesquisar(void);
void telaAtualizar(void);
void telaExcluir(void);

void salvarCliente(Cliente* cli);
Cliente* buscarCliente(char* cpf);
void exibirCliente(Cliente* cli);
