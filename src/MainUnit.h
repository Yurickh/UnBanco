#ifndef MAIN_UNIT_H
#define MAIN_UNIT_H

#include "EngineUnit.h"
#include "EntityUnit.h"
#include "TransacUnit.h"
#include "UserUnit.h"

using namespace std;

extern Window *win;

/** Classe que armazena, monitora e administra os dados de sessão. */
class Session
{
	/** Armazena a matrícula de login, no caso de administradores ou gerentes. */
	UsrMatric 	usrMatric;
	/** Armazena o número de conta, no caso de clientes. */
	AccNumber	accNumber;
	/** Armazena a senha do usuário, independentemente do tipo. */
	UsrPassword 	usrPassword;

	public:
		/** Construtor para gerentes ou administradores */
		Session(UsrMatric*, UsrPassword*);
		/** Construtor para clientes. */
		Session(AccNumber*, UsrPassword*);

		void setUsrMatric(UsrMatric*);
		void setAccNumber(AccNumber*);
		void setUsrPassword(UsrPassword*);
		UsrMatric getUsrMatric() const;
		AccNumber getAccNumber() const;
		UsrPassword getUsrPassword() const;
};

/** Interface base para criação das classes da camada de apresentação. */
class MainInterface
{
	public:
		/** Passa o controle do programa para a classe em questão. */
		virtual void execute() = 0;
};

/** Menu principal para administradores. 
	Através dele tem-se acesso aos dados cadastrais de todos os gerentes. */
class MainAdmMenu : public MainInterface
{
	/** Armazena o endereço da classe responsável pelo negócio de administração de dados de gerentes. */
	UserManAdm* userAdm;

	const static int CHANGE_PASSWORD 	= 0;
	const static int NEW_MANAGER 		= 1;
	const static int LIST_MANAGER 		= 2;
	const static int CHANGE_MANAGER 	= 3;
	const static int DELETE_MANAGER 	= 4;
	const static int LOGOUT 		= 5;

	public:
		void execute();
		/** Define o objeto de negócio de gerentes */
		inline void setUserAdm(UserManAdm*);
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

inline void MainAdmMenu :: setUserAdm(UserManAdm* userAdm)
{
	this->userAdm = userAdm;
}

/** Menu principal para Gerentes.
	Através dele tem-se acesso aos dados cadastrais de todas as contas. */
class MainManMenu : public MainInterface
{
	/** Armazena o endereço da classe responsável pelo negócio de administração de dados de gerentes/administradores. */
	UserManAdm* userAdm;
	/** Armazena o endereço da classe responsável pelo negócio de administração de dados de contas. */
	UserAccAdm* accAdm;
	/** Armazena o endereço da classe responsável pelo negócio de administração de dados de clientes. */
	UserCusAdm* cusAdm;

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
		/** Define o objeto de negócio para administração de dados de gerente. */
		inline void setUserAdm(UserManAdm*);
		/** Define o objeto de negócio para administração de dados de conta. */
		inline void setAccAdm(UserAccAdm*);
		/** Define o objeto de negócio para administração de dados de cliente. */
		inline void setCusAdm(UserCusAdm*);
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
		/** Modifica os dados de uma conta */
		void changeAccount();
};

inline void MainManMenu :: setUserAdm(UserManAdm* userAdm)
{
	this->userAdm = userAdm;
}

inline void MainManMenu :: setAccAdm(UserAccAdm* accAdm)
{
	this->accAdm = accAdm;
}

inline void MainManMenu :: setCusAdm(UserCusAdm* cusAdm)
{
	this->cusAdm = cusAdm;
}

/** Menu principal para Clientes.
	Através dele tem-se acesso aos pagamentos e dinheiro associados à conta do cliente logado. */
class MainCusMenu : public MainInterface
{
	/** Armazena o endereço da classe responsável pelo negócio de administração de dados de usuários. */
	UserCusAdm* userAdm;
	/** Armazena o endereço da classe responsável pelo negócio de administração de dados de contas. */
	UserAccAdm* accAdm;
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

		/** Define a classe responsável pela edição de dados de clientes */
		inline void setUserAdm(UserCusAdm*);
		/** Define a classe responsável pela edição de dados de contas */
		inline void setAccAdm(UserAccAdm*);
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

inline void MainCusMenu :: setUserAdm(UserCusAdm* userAdm)
{
	this->userAdm = userAdm;
}

inline void MainCusMenu :: setTransacAdm(TransacAdm* transacAdm)
{
	this->transacAdm = transacAdm;
}

inline void MainCusMenu :: setAccAdm(UserAccAdm* accAdm)
{
	this->accAdm = accAdm;
}

/** Responsável pela execução do login do usuário. */
class MainLogin : public MainInterface
{
	/** Armazena o endereço da classe responsável pela execução de menu de cliente. */
	MainCusMenu* cusMenu;
	/** Armazena o endereço da classe responsável pela execução de menu de gerente. */
	MainManMenu* manMenu;
	/** Armazena o endereço da classe responsável pela execução de menu de administrador. */
	MainAdmMenu* admMenu;

	/** Armazena o endereço da classe responsável pelo negócio. */
	UserLogin* userLogin;

	static const int MANAGER_LOGIN 	= 0;
	static const int CUSTOMER_LOGIN = 1;
	static const int EXIT 		= 2;

	public:
		void execute();

		/** Define a classe responsável pelo negócio */
		inline void setUserLogin(UserLogin*);
		/** Define a classe responsável pela execução do menu de Administrador. */
		inline void setMainAdmMenu(MainAdmMenu*);
		/** Define a classe responsável pela execução do menu de Gerente. */
		inline void setMainManMenu(MainManMenu*);
		/** Define a classe responsável pela execução do menu de Clinete. */
		inline void setMainCusMenu(MainCusMenu*);
	private:
		/** Autentica um Gerente / Administrador */
		void manLogin();
		/** Autentica um Cliente */
		void cusLogin();
};

inline void MainLogin :: setUserLogin(UserLogin* userLogin)
{
	this->userLogin = userLogin;
}

inline void MainLogin::setMainAdmMenu(MainAdmMenu* admMenu)
{
	this->admMenu = admMenu;
}

inline void MainLogin::setMainManMenu(MainManMenu* manMenu)
{
	this->manMenu = manMenu;
}

inline void MainLogin::setMainCusMenu(MainCusMenu* cusMenu)
{
	this->cusMenu = cusMenu;
}


#endif
