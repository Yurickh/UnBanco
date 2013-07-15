#ifndef PERS_UNIT_H
#define PERS_UNIT_H

#include <string>
#include <sstream>
#include <list>
#include <cstdlib>

#include "../include/sqlite3/sqlite3.h"
#include "EntityUnit.h"

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

/** Classe auxiliar que serve para armazenar as tabelas de comandos SELECT */
class TableClass
{
	public:
		string name;
		string value;
};

/** Stub da camada de persistência */
template <class ReturnClass>
class StubPersUnit
{
	private:
		string dbName;

	protected:
		list<ReturnClass> returnList;

	public:
		void setDBName(string name)
		{
			dbName = name;
		}
		list<ReturnClass> getResult()
		{
			return returnList;
		}
};

/** Classe da camada de Persistência. Dela derivam todas  as classes Command. */
class PersUnit
{
	private:
		string dbName;
		sqlite3* db;
		char* message;
		int rc;

	protected:
		static list<TableClass> returnList;
		stringstream SQLquery;

		void connect() throw (PersError)
		{
			rc = sqlite3_open(dbName.c_str(), &db);
			if(rc != SQLITE_OK ) throw PersError("Ocorreu um erro ao se conectar ao database, favor tentar novamente mais tarde.");
		}

		void disconnect() throw (PersError)
		{
			rc = sqlite3_close(db);
			if(rc != SQLITE_OK ) throw PersError("Ocorreu um erro ao se desconectar do database, favor tentar novamente mais tarde.");
		}

		static int callback(void* X, int argc, char** argv, char** colName)
		{
			TableClass element;
			
			for(int i=0; i<argc; ++i)
			{
				element.name = colName[i];
				element.value = argv[i];

				returnList.push_back(element);
			}

			return 0;
		}

		void run()
		{
			rc = sqlite3_exec(db, SQLquery.str().c_str(), callback, 0, &message);
			if(rc != SQLITE_OK){
				throw PersError("Erro na execucao do comando SQL.");
			}
		}
		
	public:
		PersUnit() throw (PersError)
		{
			dbName = "UnBanco_database";
			connect();
		}
		~PersUnit() throw (PersError)
		{
			disconnect();
		}
};

/** Classe Command que retorna o Balance de uma conta de número AccNumber */
class PersGetBalance : public PersUnit
{
	public:
		void execute(AccNumber) throw (PersError, invalid_argument);
		Money getResult();
};

/** Classe Command que define no database o Balance da conta de número AccNumber */
class PersSetBalance : public PersUnit
{
	public:
		void execute(AccNumber, Money*) throw (PersError);
};

/** Classe Command que retorna o menor PayCode disponível para criação de contas */
class PersGetLatestCode : public PersUnit
{
	public:
		void execute() throw (PersError);
		PayCode getResult();
};

/** Classe Command que cria um novo registro de Payment */
class PersNewPayment : public PersUnit
{
	public:
		void execute(Payment*) throw (PersError);
};

/** Classe Command que deleta o registro de Payment relativo ao PayCode recebido */
class PersDelPayment : public PersUnit
{
	public:
		void execute(PayCode*) throw (PersError);
};

/** Classe Command que retorna uma lista de pagamentos cadastrados no banco de dados */
class PersFetchPayment : public PersUnit
{
	public:
		void execute() throw (PersError);
		list<Payment> getResult();
};

/** Classe Command que retorna o Gerente/Administrador correspondente cadastrado sob a matrícula fornecida */
class PersGetManager : public PersUnit
{
	public:
		void execute(UsrMatric*) throw (PersError, invalid_argument);
		Manager getResult();
};

class PersGetAccount : public PersUnit
{
	public:
		void execute(AccNumber*) throw (PersError, invalid_argument);
		Account getResult();
};

class PersGetLatestNum : public PersUnit
{
	public:
		void execute() throw (PersError);
		AccNumber getResult();
};

class PersNewAccount : public PersUnit
{
	public:
		void execute(Account*) throw (PersError);
};

class PersDelAccount : public PersUnit
{
	public:
		void execute(AccNumber*) throw (PersError);
};

class PersBlkAccount : public PersUnit
{
	public:
		void execute(AccNumber*) throw (PersError);
};

class PersFetchAccount : public PersUnit
{
	public:
		void execute() throw (PersError);
		list<Account> getResult();
};

class PersUblkAccount : public PersUnit
{
	public:
		void execute(AccNumber*) throw (PersError);
};

class PersEdtAccount : public PersUnit
{
	public:
		void execute(AccNumber*, AccType*) throw (PersError);
		void execute(AccNumber*, Money*) throw (PersError);
};

class PersGetLatestMatric : public PersUnit
{
	public:
		void execute() throw (PersError);
		UsrMatric getResult();
};

class PersNewManager : public PersUnit
{
	public:
		void execute(Manager*) throw (PersError);
};

class PersFetchManager : public PersUnit
{
	public:
		void execute() throw (PersError);
		list<Manager> getResult();
};

class PersEdtManager : public PersUnit
{
	public:
		void execute(UsrMatric*, UsrName*) throw (PersError);
		void execute(UsrMatric*, UsrPassword*) throw (PersError);
};

class PersDelManager : public PersUnit
{
	public:
		void execute(UsrMatric*) throw (PersError);
};

class PersGetCustomer : public PersUnit
{
	public:
		void execute(UsrId) throw (PersError, invalid_argument);
		void execute(UsrName*) throw (PersError, invalid_argument);

		Customer getResult();
};

class PersNewCustomer : public PersUnit
{
	public:
		void execute(Customer*) throw (PersError);
};

class PersGetLatestId : public PersUnit
{
	public:
		void execute() throw (PersError);
		UsrId getResult();
};

class PersEdtCustomer : public PersUnit
{
	public:
		void execute(UsrId*, UsrName*) throw (PersError);
		void execute(UsrId&, UsrPassword&) throw (PersError);
};

#endif
