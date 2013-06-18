#ifndef MAIN_UNIT_H
#define MAIN_UNIT_H

#include "EngineUnit.h"
#include "EntityUnit.h"
#include "UserUnit.h"
#include "TransacUnit.h"

extern Window* win;

/** Interface base para criação das classes da camada de apresentação. */
class MainInterface
{
	public:
		/** Passa o controle do programa para a classe em questão. */
		virtual void execute() = 0;
};

/** Responsável pela execução do login do usuário. */
class MainLogin : public MainInterface
{
	/** Armazena o endereço da classe subsequente */
	MainInterface* menu;

	/** Armazena o endereço da classe responsável pelo negócio */
	UserLogin* userLogin;

	static const int MANAGER_LOGIN 	= 0;
	static const int CUSTOMER_LOGIN = 1;
	static const int EXIT 		= 2;

	public:
		void execute();

		/** Define a classe responsável pelo negócio */
		inline void setUserLogin(UserLogin*);
	private:
		/** Autentica um Gerente / Administrador */
		void manLogin();
		/** Autentica um Cliente */
		void cusLogin();
};

inline void MainLogin::setUserLogin(UserLogin* userLogin)
{
	this->userLogin = userLogin;
}

/** Menu principal para administradores. 
	Através dele tem-se acesso aos dados cadastrais de todos os gerentes. */
class MainAdmMenu : public MainInterface
{
	/** Armazena o endereço da classe responsável pelo negócio */
	UserAdm* userAdm;

	const static int CHANGE_PASSWORD 	= 0;
	const static int NEW_MANAGER 		= 1;
	const static int LIST_MANAGER 		= 2;
	const static int CHANGE_MANAGER 	= 3;
	const static int DELETE_MANAGER 	= 4;
	const static int LOGOUT 		= 5;

	public:
		void execute();

		/** Define a classe responsável pelo negócio */
		inline void setUserAdm(UserAdm*);
	private:
		/** Modifica a senha do Administrador */
		void changePassword();
		/** Cria um novo Gerente */
		void newManager();
		/** Gera uma lista com os dados de todos os Gerentes */
		void listManager();
		/** Modifica os dados de um Gerente */
		void changeManager();
		/** Apaga todos os registros de um Gerente */
		void deleteManager();
};

inline void MainAdmMenu :: setUserAdm(UserAdm* userAdm)
{
	this->userAdm = userAdm;
}

/** Menu principal para Gerentes.
	Através dele tem-se acesso aos dados cadastrais de todas as contas. */
class MainManMenu : public MainInterface
{
	/** Armazena o endereço da classe responsável pela classe de negócio. */
	UserAdm* userAdm;

	static const int CHANGE_PASSWORD 	= 0;
	static const int LIST_MANAGER 		= 1;
	static const int MANAGE_ACCOUNTS 	= 2;
	static const int LOGOUT 		= 3;

	static const int NEW_ACCOUNT 		= 0;
	static const int DELETE_ACCOUNT 	= 1;
	static const int BLOCK_ACCOUNT 		= 2;
	static const int UNBLOCK_ACCOUNT 	= 3;
	static const int LIST_ACCOUNT 		= 4;
	static const int CHANGE_ACCOUNT 	= 5;
	static const int GO_BACK 		= 6;

	public:
		void execute();

		/** Define a classe responsável pela edição e constulta de dados de contas de entidades */
		inline void setUserAdm(UserAdm*);
	private:
		/** Modifica a senha do Gerente */
		void changePassword();
		/** Mostra os dados do usuário */
		void listManager();
		/** Cria o menu de administração de contas */
		void manageAccounts();
		/** Cria uma nova conta */
		void newAccount();
		/** Apaga os registros de uma conta */
		void deleteAccount();
		/** Bloqueia uma conta */
		void blockAccount();
		/** Desbloqueia uma conta */
		void unblockAccount();
		/** Gera uma lista com todas as contas */
		void listAccount();
		/** Modifica os dados de uma cotna */
		void changeAccount();
};

inline void MainManMenu :: setUserAdm(UserAdm* userAdm)
{
	this->userAdm = userAdm;
}

/** Menu principal para Clientes.
	Através dele tem-se acesso aos pagamentos e dinheiro associados à conta do cliente logado. */
class MainCusMenu : public MainInterface
{
	/** Armazena o endereço da classe responsável pelo negócio de dados de contas. */
	UserAdm* userAdm;
	/** Armazena o endereço da classe responsável pelo negócio de transações */
	TransacAdm* transacAdm;

	static const int CHANGE_PASSWORD	= 0;
	static const int LIST_CUSTOMER 		= 1;
	static const int SHOW_BALANCE		= 2;
	static const int WITHDRAW		= 3;
	static const int DEPOSIT		= 4;
	static const int MANAGE_PAYMENT		= 5;
	static const int LOGOUT			= 6;

	static const int SCHEDULE_PAYMENT	= 0;
	static const int CANCEL_PAYMENT		= 1;
	static const int LIST_PAYMENT 		= 2;
	static const int GO_BACK		= 3;

	public:
		void execute();

		/** Define a classe responsável pela edição e constula de dados de contas de usuários */
		inline void setUserAdm(UserAdm*);
		/** Define a classe responsável pelo intermédio de transações entre contas */
		inline void setTransacAdm(TransacAdm*);

	private:
		/** Modifica a senha do usuário */
		void changePassword();
		/** Mostra os dados do Cliente */
		void listCustomer();
		/** Consulta o saldo */
		void showBalance();
		/** Retira dinheiro */
		void withdraw();
		/** Deposita dinheiro */
		void deposit();
		/** Cria o menu de administração de pagamentos */
		void managePayment();
		/** Agenda pagamento */
		void schedulePayment();
		/** Cancela pagamento agendado */
		void cancelPayment();
		/** Gera uma lista com os dados dos pagamentos associados àquela conta */
		void listPayment();
};

inline void MainCusMenu :: setUserAdm(UserAdm* userAdm)
{
	this->userAdm = userAdm;
}

inline void MainCusMenu :: setTransacAdm(TransacAdm* transacAdm)
{
	this->transacAdm = transacAdm;
}

#endif
