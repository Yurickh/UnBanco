#ifndef ENGINE_UNIT_H
#define ENGINE_UNIT_H

#ifdef _WIN16
#define CLRSCR system("cls")
#elif defined(_WIN32)
#define CLRSCR system("cls")
#else
#define CLRSCR system("clear")
#endif

#include "EntityUnit.h"
#include <string>
using namespace std;

/** Responsável pela formatação de tela, entrada e saída básica.*/
class Window
{
	public:		
		/** Mostra um menu de opções na tela.
			Recebe um inteiro, o número de opções, e um vetor de strings, um vetor com o texto de cada uma das opções. */
		virtual int menu(int nopt, string options[], string text) = 0;
		/** Mostra uma string na tela. */
		virtual void print(string) = 0;
		/** Mostra um inteiro na tela. */
		virtual void print(int) = 0;
		/** Lê uma string da entrada padrão. */
		virtual void read(string&) = 0;
		/** Lê um inteiro da entrada padrão. */
		virtual void read(int&) = 0;
		/** Mostra a mensagem de erro formatada na tela. */
		virtual void error(string)=0;
		/** Mostra a mensagem de sucesso formatada na tela. */
		virtual void success(string)=0;
};

class Textual: public Window
{
	public:
		int menu(int nopt, string options[], string text);
		void print(string);
		void print(int);
		void read(string&);
		void read(int&);
		void error(string);
		void success(string);
};

#endif
