#ifndef PERS_UNIT_H
#define PERS_UNIT_H

#include <string>
#include <sqlite3.h>

using namespace std;

#define PERS_ERROR_MSG "Ocorreu um erro ao se conectar ao database. Favor tentar novamente mais tarde."

/** Classe de exceção para falhas de conexão ao database. */
class PersError
{
	private:
		/** Armazena a infomação sobre o erro */
		string info;

	public:

		PersError();
		PersError(string);

		/** Retorna a informação sobre o erro */
		string what();
};

/** Classe que contém as informações necessárias à conexão com o database */
class Command<class ReturnClass>
{
	private:
		string dataBaseName;
		/** Objeto database */
		sqlite3 *db;
		/** Mensagem de log de conexão. */
		char *message;
		/** Código de retorno */
		int rc;

	protected:
		/** Lista que contém as informações de retorno */
		static list<ReturnClass> returnList;
		/** Código SQL */
		string sqlCode;


	private:
		/** Conecta ao database */
		void connect() throw (PersError);
		/** Desconecta do database */
		void disconnect() throw (PersError);
		static int callback (void*, int, char**, char**);

	public:
		/** Faz a conexão com o database e monta o ambiente necessário */
		Command(string) throw (PersError);
		/** Desfaz a conexão com o database */
		~Command() throw (PersError);

		/** Retorna a lista de retornos */
		inline list<ReturnClass> getResult();

		/** Executa o código SQL */
		void execute() throw (PersError);
};

void Command<class ReturnClass> :: connect()
{
	rc = sqlite3_open(dataBaseName, &db);

	if(rc)
	{
		sqlite3_close(db);
		throw PersError(PERS_ERROR_MSG);
	}
}

void Command<class ReturnClass> :: disconnect()
{
	sqlite3_close(db);
}

int Command<class ReturnClass> :: callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	list<ReturnClass> returnList;

	for(int i=0; i<argc; ++i)
	{
		if(argv[i])
		{
			try{
				ReturnClass curr(argv[i]);
				returnList.push_back(curr);
			} catch (invalid_argument except)
			{
				throw PersError("Valor inesperado para campo em database. Erro na leitura");
			}
		}
	}

	this->returnList = returnList;
}

Command<class ReturnClass> :: Command(string dbName)
{
	dataBaseName = dbName;
	connect();
}

Command<class ReturnClass> :: ~Command()
{
	disconnect();
}

Command<class ReturnClass> :: execute()
{
	rc = sqlite3_exec(db, sqlCode, callback, &message);
	if(rc != SQLITE_OK)
	{
		sqlite3_free(message);
		throw PersError("Ocorreu um erro ao tentar executar o codigo SQL.");
	}
}

//========================== Interfaces PERS =====================================

/** Classe Command que retorna o Balance de uma conta de número AccNumber */
class PersGetBalance : public Command<Money>
{
	public:
		virtual void configure(AccNumber);
};

/** Classe Command que define no database o Balance da conta de número AccNumber */
class PersSetBalance : public Command<Money>
{
	public:
		virtual void configure(AccNumber, Money*);
}

//===============================Stubs============================================

class StubPersGetBalance : public PersGetBalance
{
	public:
		void configure(AccNumber);
}

class StubPersGetBalance : public PersGetBalance
{
	public:
		void configure(AccNumber, Money*);
}

#endif
