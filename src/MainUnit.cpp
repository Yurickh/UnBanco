#include "MainUnit.h"

#define SIZEOF(a) sizeof(a)/sizeof(a[0])

#include <cstdlib>

Session* session;

void Session :: setUsrMatric(UsrMatric* usrMatric)
{
	this->usrMatric = *usrMatric;
}

void Session :: setAccNumber(AccNumber* accNumber)
{
	this->accNumber = *accNumber;
}

void Session :: setUsrPassword(UsrPassword* usrPassword)
{
	this->usrPassword = *usrPassword;
}

void MainLogin :: execute()
{
	int opt;

	string options[] = {"Administrador ou Gerente", "Cliente", "Sair"};

	while(1)
	{
		opt = win->menu(SIZEOF(options), options, "Forma de Login:");

		switch(opt)
		{
			case MANAGER_LOGIN:
				manLogin();
			break;
			case CUSTOMER_LOGIN:
				cusLogin();
			break;
			case EXIT:
			return;
		}
	}
}

void MainLogin :: manLogin()
{
	bool invalidFormat, loginFailed = true;;

	int mat;
	string passw;

	UsrMatric* matric;
	UsrPassword* password;
	ManType manType;

	do
	{
		invalidFormat = true;
		do
		{
			win->print("Matricula:");
			win->read(mat);
			win->print("Senha:");
			win->read(passw);

			try
			{
				matric = new UsrMatric(mat);
				password = new UsrPassword(passw);
				invalidFormat = false;
			}
			catch(invalid_argument except)
			{
				win->error(except.what());
			}
		}while(invalidFormat);

		try
		{
			manType = userLogin->autent(matric, password);
			loginFailed = false;
		}
		catch(PersError except)
		{
			win->error(except.what());
		}
		catch(invalid_argument except)
		{
			win->error(except.what());
		}

		delete matric;
		delete password;
	}while(loginFailed);

	if(manType.getValue() == NORMAL)
	{
		manMenu->execute();
	}
	else
	{
		admMenu->execute();
	}
}

void MainLogin :: cusLogin()
{
	bool invalidFormat, loginFailed=true;

	int accNum;
	string passw;

	AccNumber* accNumber;
	UsrPassword* password;

	do
	{
		invalidFormat = true;
		do
		{
			win->print("Numero de Conta:");
			win->read(accNum);
			win->print("Senha:");
			win->read(passw);

			try
			{
				accNumber = new AccNumber(accNum);
				password = new UsrPassword(passw);
				invalidFormat = false;
			}
			catch(invalid_argument except)
			{
				win->error(except.what());
			}
		}while(invalidFormat);

		try
		{
			userLogin->autent(accNumber, password);
			loginFailed = false;
		}
		catch(PersError except)
		{
			win->error(except.what());
		}
		catch(invalid_argument except)
		{
			win->error(except.what());
		}

		session = new Session();

		session->setAccNumber(accNumber);
		session->setUsrPassword(password);

		delete accNumber;
		delete password;
	}while(loginFailed);

	cusMenu->execute();
}

//=======================MainAdmMenu==============================
void MainAdmMenu :: execute()
{
	int opt;

	string options[] = {"Trocar Senha", "Cadastrar Gerente", "Listar Gerentes", "Alterar nome de Gerente", "Deletar Gerente", "Deslogar"};


	while(1)
	{
		opt = win->menu(SIZEOF(options), options, "Acao Desejada:");

		switch(opt)
		{
			case CHANGE_PASSWORD:
				changePassword();
			break;
			case NEW_MANAGER:
				newManager();
			break;
			case LIST_MANAGER:
				listManager();
			break;
			case CHANGE_MANAGER:
				changeManager();
			break;
			case DELETE_MANAGER:
				deleteManager();
			break;
			case LOGOUT:
				delete session;
			return;
		}
	}
}

void MainAdmMenu::changePassword(){}
void MainAdmMenu::newManager(){}
void MainAdmMenu::listManager(){}
void MainAdmMenu::changeManager(){}
void MainAdmMenu::deleteManager(){}

//======================MainManMenu===============================
void MainManMenu::execute(){
	int opt;

	string options[] = {"Trocar senha", "Listar dados", "Gerenciar contas", "Logout"};

	while(1)
	{
		opt = win->menu(SIZEOF(options), options, "Acao desejada:");
		
		switch(opt)
		{
			case CHANGE_PASSWORD:
				changePassword();
			break;
			case LIST_MANAGER:
				listManager();
			break;
			case MANAGE_ACCOUNTS:
				manageAccounts();
			break;
			case LOGOUT:
				delete session;
			return;
		}
	}
}

void MainManMenu::manageAccounts()
{
	int opt;

	string options[] = {"Criar conta", "Deletar conta", "Bloquear conta", "Desbloquear conta", "Listar dados de contas", "Alterar dados de contas", "Voltar"};

	while(1)
	{
		opt = win->menu(SIZEOF(options), options, "Acao desejada:");

		switch(opt)
		{
			case NEW_ACCOUNT:
				newAccount();
			break;
			case DELETE_ACCOUNT:
				deleteAccount();
			break;
			case BLOCK_ACCOUNT:
				blockAccount();
			break;
			case UNBLOCK_ACCOUNT:
				unblockAccount();
			break;
			case LIST_ACCOUNT:
				listAccount();
			break;
			case CHANGE_ACCOUNT:
				changeAccount();
			break;
			case GO_BACK:
			return;
		}
	}
}

void MainManMenu::changePassword(){}
void MainManMenu::listManager(){}
void MainManMenu::newAccount(){}
void MainManMenu::deleteAccount(){}
void MainManMenu::blockAccount(){}
void MainManMenu::unblockAccount(){}
void MainManMenu::listAccount(){}
void MainManMenu::changeAccount(){}	

//======================MainCusMenu===============================
void MainCusMenu::execute()
{
	int opt;

	string options[] = {"Trocar senha", "Consultar dados cadastrais", "Consultar saldo", "Retirar dinheiro", "Depositar dinheiro", "Administrar Pagamentos", "Logout"};

	while(1)
	{
		opt = win->menu(SIZEOF(options), options, "Acao desejada:");

		switch(opt)
		{
			case CHANGE_PASSWORD:
				changePassword();
			break;
			case LIST_CUSTOMER:
				listCustomer();
			break;
			case SHOW_BALANCE:
				showBalance();
			break;
			case WITHDRAW:
				withdraw();
			break;
			case DEPOSIT:
				deposit();
			break;
			case MANAGE_PAYMENT:
				managePayment();
			break;
			case LOGOUT:
				delete session;
			return;
		}
	}
}

void MainCusMenu::managePayment()
{
	int opt;

	string options[] = {"Agendar pagamento", "Cancelar pagamento", "Listar pagamentos", "Voltar"};

	while(1)
	{
		opt = win->menu(SIZEOF(options), options, "Acao desejada:");

		switch(opt)
		{
			case SCHEDULE_PAYMENT:
				schedulePayment();
			break;
			case CANCEL_PAYMENT:
				cancelPayment();
			break;
			case LIST_PAYMENT:
				listPayment();
			break;
			case GO_BACK:
			return;
		}
	}
}
void MainCusMenu::changePassword(){}
void MainCusMenu::listCustomer(){}
void MainCusMenu::showBalance(){}
void MainCusMenu::withdraw(){}
void MainCusMenu::deposit(){}
void MainCusMenu::schedulePayment(){}
void MainCusMenu::cancelPayment(){}
void MainCusMenu::listPayment(){}
