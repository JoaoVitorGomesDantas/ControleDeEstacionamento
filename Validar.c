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

int validarCPF (char* cpf) {
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

/// Validar RG

int validarRG (char* rg) {
	int tam;
  	tam = strlen(rg);
  	if(tam != 7) {
		return 0;
  	}
  	for (int i = 0; i < tam; i++) {
    		if (!validaNumero(rg[i])) {
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

// Retirado de https://github.com/flgorgonio/linguasolta_2020.2 do professor @flgorgonio
// Validação de data 

int ehBissexto(int aa) {
	if ((aa % 4 == 0) && (aa % 100 != 0)) {
    		return 1;
  	} else if (aa % 400 == 0) {
    		return 1;
  	} else {
    		return 0;
  	}
}

int ehData(int dd, int mm, int aa) {
	int maiorDia;
  	if (aa < 0 || mm < 1 || mm > 12) {
		return 0;
	}
  	if (mm == 2) {
    		if (ehBissexto(aa)) { 
      			maiorDia = 29;
		} else {
     		 	maiorDia = 28;
		}
  	} else {
		if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    		maiorDia = 30;
  		} else {
    		maiorDia = 31;
		}
	}
  	if (dd < 1 || dd > maiorDia) {
    		return 0;
	}
  	return 1;
}

int validarData(char* data) {
	int tam, dia, mes, ano;
  	tam = strlen(data);
  	if (tam != 8) {
    		return 0;
  	}
  	for (int i = 0; i < tam; i++) {
    		if (!validaNumero(data[i])) {
      			return 0;
    		}
  	}
  	dia = (data[0] - '0') * 10 + (data[1] - '0');
  	mes = (data[2] - '0') * 10 + (data[3] - '0');
  	ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + (data[7] - '0');
  	if (!ehData(dia, mes, ano)) {
    		return 0;
  	}
  	return 1;
}
