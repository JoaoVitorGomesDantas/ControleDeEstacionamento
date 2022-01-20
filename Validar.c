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
#include <time.h>
#include <string.h>


/// Verifica se é número ou não
/// Número retorna 1 o resto retorna 0

int validaNumero (char n) {
    if (n >= '0' && n <= '9') {
     return 1;
    } else {
      return 0;
  }
}

/// Verifica se é letra ou não
/// Se for letra retorna 1 o resto retorna 0

char validaLetra (char nome) {
    if (nome >= 'a' && nome <= 'z') {
      return 1;
    } else if (nome >= 'A' && nome <= 'Z'){
      return 1;
    } else {
      return 0;
    }
}

/// Validar número de telefone

int validaTelefone(char* fone) {
    int tam;
    tam = strlen(fone);
    if (tam != 11) {
        return 0;
    }
    for (int i = 0; i < tam; i++) {
        if (!validaNumero(fone[i])) {
            return 0;
        }
    }
    return 1;
}

/// Validar CPF

int validaCPF (char* cpf) {
  int tam;
  tam = strlen(cpf);
  if(tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!validaNumero(cpf[i])) {
     return 0;
    }
  }
  return 1;
}

/// Validar Nome

int validarNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!validaLetra(nome[i])) {
      return 0;
    }
  }
	return 1;
}
