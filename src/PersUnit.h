#ifndef PERS_UNIT_H
#define PERS_UNIT_H

#include <string>
#include <list>
#include <cstdlib>
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

/** Classe Command que retorna o Balance de uma conta de número AccNumber */
class PersGetBalance : public StubPersUnit<Money>
{
	public:
		void execute(AccNumber) throw (PersError);
};

/** Classe Command que define no database o Balance da conta de número AccNumber */
class PersSetBalance : public StubPersUnit<Money>
{
	public:
		void execute(AccNumber, Money*) throw (PersError);
};

/** Classe Command que retorna o menor PayCode disponível para criação de contas */
class PersGetLatestCode : public StubPersUnit<PayCode>
{
	public:
		void execute() throw (PersError);
};

/** Classe Command que cria um novo registro de Payment */
class PersNewPayment : public StubPersUnit<Payment>
{
	public:
		void execute(Payment*) throw (PersError);
};

/** Classe Command que deleta o registro de Payment relativo ao PayCode recebido */
class PersDelPayment : public StubPersUnit<Payment>
{
	public:
		void execute(PayCode*) throw (PersError);
};

/** Classe Command que retorna uma lista de pagamentos cadastrados no banco de dados */
class PersFetchPayment : public StubPersUnit<Payment>
{
	public:
		void execute() throw (PersError);
};

/** Classe Command que retorna o Gerente/Administrador correspondente cadastrado sob a matrícula fornecida */
class PersGetManager : public StubPersUnit<Manager>
{
	public:
		void execute(UsrMatric*) throw (PersError);
};

class PersGetAccount : public StubPersUnit<Account>
{
	public:
		void execute(AccNumber*) throw (PersError);
};

class PersGetCustomer : public StubPersUnit<Customer>
{
	public:
		void execute(UsrId) throw (PersError);
};

#endif
