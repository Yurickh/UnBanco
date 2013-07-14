#ifndef USER_UNIT_H
#define USER_UNIT_H

#include <stdexcept>
#include <list>
#include <cstdlib>
#include "EntityUnit.h"
#include "PersUnit.h"

/** Interface de interação da camada de apresentação com a camada de negócio responsável pelo login do usuário. */
class UserLogin
{
	public:
		/** Autentica um administrador / gerente */
		virtual ManType autent(UsrMatric*, UsrPassword*) throw (invalid_argument, PersError) = 0;
		/** Autentica um cliente */
		virtual void autent(AccNumber*, UsrPassword*) throw (invalid_argument, PersError) = 0;
};

/** Classe de negócio responsável por controlar os dados de login */
class CtrlUserLogin : public UserLogin
{
	public:
		ManType autent(UsrMatric*, UsrPassword*) throw (invalid_argument, PersError);
		void autent(AccNumber*, UsrPassword*) throw (invalid_argument, PersError);
};

/** Stub utilizado para simular o funcionamento da camada de negócio de login */
class StubUserLogin : public UserLogin
{
	public:
		ManType autent(UsrMatric*, UsrPassword*) throw (invalid_argument, PersError);
		void autent(AccNumber*, UsrPassword*) throw (invalid_argument, PersError);
};

/** Interface de interação da camada de apresentação com a camada de negócio responsável pela administração dos dados de Contas */
class UserAccAdm
{
	public:
		/** Cria uma conta. */
		virtual void createAccount(AccType*, Money*, Money*) throw (PersError) = 0;
		/** Deleta uma conta */
		virtual void deleteAccount(AccNumber*) throw (invalid_argument, PersError) = 0;

		/** Bloqueia uma conta */
		virtual void blockAccount(AccNumber*) throw (invalid_argument, PersError) = 0;
		/** Desbloqueia uma conta */
		virtual void unblockAccount(AccNumber*) throw (invalid_argument, PersError) = 0;

		/** Recupera uma lista com todas as contas registradas */
		virtual list<Account> fetchAccount(void) throw (PersError) = 0;
		/** Recupera os dados da conta de uma conta em específico */
		virtual Account fetchAccount(AccNumber) throw (PersError) = 0;

		/** Edita o tipo de um conta */
		virtual void editAccType(AccNumber*, AccType*) throw (invalid_argument, PersError) = 0;
		/** Edita o Lilimite de uma conta */
		virtual void editAccLimit(AccNumber*, Money*) throw (invalid_argument, PersError) = 0;
};

/** Stub utilizado para simular o funcionamento da camada de negócio responsável pela administração dos dados de contas */
class StubUserAccAdm : public UserAccAdm
{
		void createAccount(AccType*, Money*, Money*) throw (PersError);
		void deleteAccount(AccNumber*) throw (invalid_argument, PersError);

		void blockAccount(AccNumber*) throw (invalid_argument, PersError);
		void unblockAccount(AccNumber*) throw (invalid_argument, PersError);

		list<Account> fetchAccount(void) throw (PersError);
		Account fetchAccount(AccNumber) throw (PersError);

		void editAccType(AccNumber*, AccType*) throw (invalid_argument, PersError);
		void editAccLimit(AccNumber*, Money*) throw (invalid_argument, PersError);
};


/** Interface de interação entre a camada de apresentação e a camada de negócio responsável pela administração de dados de gerentes ou administradores. */
class UserManAdm
{
	public:
		/** Modifica a senha do usuário */
		virtual void changePassword(UsrPassword*) throw (PersError) = 0;
		/** Cria um novo Gerente */
		virtual void createManager(UsrName*, UsrPassword*) throw (PersError) = 0;

		/** Recupera uma lista com todos os gerentes registrados no sistema */
		virtual list<Manager> fetchManager(void) throw (PersError) = 0;
		/** Recupera os dados de um gerente em específico. */
		virtual Manager fetchManager(UsrMatric) throw (PersError) = 0;

		/** Edita o nome de um gerente. Sua matrícula não será afetada */
		virtual void editManName(UsrMatric*, UsrName*) throw (invalid_argument, PersError) = 0;
		/** Deleta os dados de um gerente */
		virtual void deleteManager(UsrMatric*) throw (invalid_argument, PersError) = 0;
};

/** Stub utilizado para simular o funcionamento da camada de negócio responsável pela administração de dados de gerentes*/
class StubUserManAdm : public UserManAdm
{
	public:
		void changePassword(UsrPassword*) throw (PersError);
		void createManager(UsrName*, UsrPassword*) throw (PersError);

		list<Manager> fetchManager(void) throw (PersError);
		Manager fetchManager(UsrMatric) throw (PersError);

		void editManName(UsrMatric*, UsrName*) throw (invalid_argument, PersError);
		void deleteManager(UsrMatric*) throw (invalid_argument, PersError);
};

/** Interface de interação entre a camada de apresentação e a camada de negócio responsável pela administração de dados de clientes. */
class UserCusAdm
{
	public:
		/** Modifica a senha do cliente */
		virtual void changePassword(UsrPassword*) throw (PersError) = 0;
		/** Cria um cliente. */
		virtual void createCustomer(UsrName*, UsrPassword*) throw (invalid_argument, PersError) = 0;
		/** Edita o nome do cliente */		
		virtual void editCusName(AccNumber*, UsrName*) throw (invalid_argument, PersError) = 0;
		/** Recupera so dados do cliente */
		virtual Customer fetchCustomer(UsrId) throw (PersError) = 0;
};

/** Stub utilizado para simular o funcionamento da camada de negócio responsável pela administração de dados de clientes */
class StubUserCusAdm : public UserCusAdm
{
	public:
		void changePassword(UsrPassword*) throw (PersError);
		void createCustomer(UsrName*, UsrPassword*) throw (invalid_argument, PersError);
		void editCusName(AccNumber*, UsrName*) throw (invalid_argument, PersError);
		Customer fetchCustomer(UsrId) throw (PersError);
};

#endif
