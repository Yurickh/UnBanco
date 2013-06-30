#include "EngineUnit.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool isNumber(string str)
{
	string::iterator it;

	for(it = str.begin(); it!=str.end(); ++it)
		if(!isdigit(*it)) return false;

	return true;
}

int Textual::menu(int nopt, string options[], string text)
{
	int opt;
	string temp;

	CLRSCR;

	while(1)
	{
		print(text);
		for(int i =0; i<nopt; ++i)
		{
			cout << i+1 << ". " << options[i] << endl;
		}

		cout << ">>> ";
		cin >> temp;
		if(isNumber(temp))
			opt =  atoi(temp.c_str());
		else
		{
			CLRSCR;
			error("Tecla Invalida");
			continue;
		}

		CLRSCR;

		if(0 > opt || nopt < opt)
			error("Tecla Invalida");
		else
			return opt -1;
	}
}

void Textual::print(string output)
{
	cout << output << endl;
}

void Textual::print(int output)
{
	cout << output << endl;
}

void Textual::read(string& input)
{
	cout << ">>> ";
	cin >> input;
}

void Textual::read(int& opt)
{
	string temp;

	cout << ">>> ";

	cin >> temp;
	if(isNumber(temp))
		opt =  atoi(temp.c_str());
	else
		opt = -1;
}

void Textual::error(string error)
{
	CLRSCR;
	cout << "Erro: ";
	print(error);
}

void Textual::success(string succ)
{
	CLRSCR;

	cout << "Sucesso! ";
	print(succ);
}

void Textual :: cont()
{
	char c;

	cout << "Pressione ENTER para continuar.";
	do {
		getchar();
		c = getchar();
	} while (c != '\n');
}
