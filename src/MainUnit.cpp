#include "MainUnit.h"

#define SIZEOF(a) sizeof(a)/sizeof(a[0])

#include <cstdlib>
#include <ctime>
#include <list>

Session* session;

string randomPassword()
{
	string pass;

	for(int i=0; i<6; ++i)
		pass.push_back(rand() % 10 + '0');

	return pass;
}

Session :: Session(UsrMatric* usrMatric, UsrPassword* usrPassword)
{
	setUsrMatric(usrMatric);
	setUsrPassword(usrPassword);
}

Session :: Session(AccNumber* accNumber, UsrPassword* usrPassword)
{
	setAccNumber(accNumber);
	setUsrPassword(usrPassword);
}

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

UsrMatric Session :: getUsrMatric() const
{
	return this->usrMatric;
}

AccNumber Session :: getAccNumber() const
{
	return this->accNumber;
}

UsrPassword Session :: getUsrPassword() const
{
	return this->usrPassword;
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

		session = new Session(matric, password);

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

		session = new Session(accNumber, password);

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

void MainAdmMenu::changePassword()
{
	string oldPassStr;
	string newPassStr1;
	string newPassStr2;
	UsrPassword* newPass;

	bool invalidOld, invalidNew, invalidEnd;

	do
	{
		invalidEnd = true;
		do
		{
			invalidOld = true;
			win->print("Insira a senha atual:");
			win->read(oldPassStr);
			if(oldPassStr != session->getUsrPassword().getValue())
				win->error("Senha invalida.");
			else
				invalidOld = false;
		} while(invalidOld);

		do
		{
			invalidNew = true;
			win->print("Insira a nova senha:");
			win->read(newPassStr1);
			win->print("Insira a nova senha novamente:");
			win->read(newPassStr2);
			if(newPassStr1 == newPassStr2)
			{
				try
				{
					newPass = new UsrPassword(newPassStr1);
					invalidNew = false;
				} catch (invalid_argument except)
				{
					win->error(except.what());
				}
			}
			else
				win->error("As senhas nao batem.");
		}while(invalidNew);

		try
		{
			userAdm->changePassword(newPass);
			session->setUsrPassword(newPass);
			win->success("Senha modificada com sucesso.");
			win->cont();
			invalidEnd = false;
		} catch (PersError except)
		{
			win->error(except.what());
		}
	}while(invalidEnd);
}


void MainAdmMenu::newManager()
{
	string newManNameStr;
	string newManPassStr;
	UsrName* newManName;
	UsrPassword* newManPass;

	bool invalidName, invalidEnd;

	srand(time(NULL));

	do
	{
		invalidEnd = true;

		do
		{
			invalidName = true;

			win->print("Digite o nome do novo Gerente: ");
			win->read(newManNameStr);

			newManPassStr = randomPassword();

			try
			{
				newManName = new UsrName(newManNameStr);
				newManPass = new UsrPassword(newManPassStr);
				invalidName = false;
			}
			catch(invalid_argument except)
			{
				win->error(except.what());
			}
		} while(invalidName);

		try
		{
			userAdm->createManager(newManName, newManPass);
			invalidEnd = false;
		}
		catch(PersError except)
		{
			win->error(except.what());
		}
	} while(invalidEnd);

	win->success("Gerente devidamente registrado.");
	win->print("Dados do novo gerente:");
	win->print("Nome: " + newManNameStr);
	win->print("Senha: " + newManPassStr);
	win->cont();
}

void MainAdmMenu::listManager()
{
	list<Manager*>::iterator it;
	list<Manager*> manList;

	bool invalidList;

	invalidList = true;
	try
	{
		manList = userAdm->fetchManager();
		invalidList = false;
	} catch (PersError except)
	{
		win->error(except.what());
		win->cont();
	}

	if(invalidList) return;

	for(it = manList.begin(); it!=manList.end(); ++it)
	{
		win->print("Nome: ");
		win->print((*it)->getName()->getValue());
		win->print("Matricula: ");
		win->print((*it)->getUsrMatric()->getValue());
		win->print("\n");
	}
	win->cont();
}


void MainAdmMenu::changeManager()
{
	int manMatricInt;
	UsrMatric* manMatric;
	string manNameStr;
	UsrName* manName;

	bool invalidMatric, invalidName, invalidEnd;

	do{
		invalidEnd = true;
		do{
			invalidMatric = true;
			win->print("Insira a matricula do Gerente a ser renomeado:");
			win->read(manMatricInt);

			try
			{
				manMatric = new UsrMatric(manMatricInt);
				invalidMatric = false;
			} catch (invalid_argument except)
			{
				win->error(except.what());
			}
		} while (invalidMatric);

		do{
			invalidName = true;
			win->print("Insira o novo nome do Gerente em questão.");
			win->read(manNameStr);

			try
			{
				manName = new UsrName(manNameStr);
				invalidName = false;
			} catch (invalid_argument except)
			{
				win->error(except.what());
			}
		} while (invalidName);

		try
		{
			userAdm->editManName(manMatric, manName);
			invalidEnd = false;
		} catch (PersError except)
		{
			win->error(except.what());
		} catch (invalid_argument except)
		{
			win->error(except.what());
		}
	} while(invalidEnd);

	win->success("Nome devidamente editado.");
	win->cont();
}

void MainAdmMenu::deleteManager()
{
	int manMatricInt;
	UsrMatric* manMatric;

	bool invalidMatric, invalidEnd;

	do
	{
		invalidEnd = true;
		do
		{
			invalidMatric = true;
			win->print("Insira a matrícula do Gerente a ser deletado:");
			win->read(manMatricInt);

			try
			{
				manMatric = new UsrMatric(manMatricInt);
				invalidMatric = false;
			}catch(invalid_argument except)
			{
				win->error(except.what());
			}
		}while(invalidMatric);

		try
		{
			userAdm->deleteManager(manMatric);
			invalidEnd = false;
		} catch (PersError except)
		{
			win->error(except.what());
		} catch (invalid_argument except)
		{
			win->error(except.what());
		}
	}while(invalidEnd);

	win->success("Gerente devidamente deletado");
	win->cont();
}

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

void MainManMenu::changePassword()
{
	string oldPassStr;
	string newPassStr1;
	string newPassStr2;
	UsrPassword* newPass;

	bool invalidOld, invalidNew, invalidEnd;

	do
	{
		invalidEnd = true;
		do
		{
			invalidOld = true;
			win->print("Insira a senha atual:");
			win->read(oldPassStr);
			if(oldPassStr != session->getUsrPassword().getValue())
				win->error("Senha invalida.");
			else
				invalidOld = false;
		} while(invalidOld);

		do
		{
			invalidNew = true;
			win->print("Insira a nova senha:");
			win->read(newPassStr1);
			win->print("Insira a nova senha novamente:");
			win->read(newPassStr2);
			if(newPassStr1 == newPassStr2)
			{
				try
				{
					newPass = new UsrPassword(newPassStr1);
					invalidNew = false;
				} catch (invalid_argument except)
				{
					win->error(except.what());
				}
			}
			else
				win->error("As senhas nao batem.");
		}while(invalidNew);

		try
		{
			userAdm->changePassword(newPass);
			session->setUsrPassword(newPass);
			win->success("Senha modificada com sucesso.");
			win->cont();
			invalidEnd = false;
		} catch (PersError except)
		{
			win->error(except.what());
		}
	}while(invalidEnd);
}
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
void MainCusMenu::changePassword()
{
	string oldPassStr;
	string newPassStr1;
	string newPassStr2;
	UsrPassword* newPass;

	bool invalidOld, invalidNew, invalidEnd;

	do
	{
		invalidEnd = true;
		do
		{
			invalidOld = true;
			win->print("Insira a senha atual:");
			win->read(oldPassStr);
			if(oldPassStr != session->getUsrPassword().getValue())
				win->error("Senha invalida.");
			else
				invalidOld = false;
		} while(invalidOld);

		do
		{
			invalidNew = true;
			win->print("Insira a nova senha:");
			win->read(newPassStr1);
			win->print("Insira a nova senha novamente:");
			win->read(newPassStr2);
			if(newPassStr1 == newPassStr2)
			{
				try
				{
					newPass = new UsrPassword(newPassStr1);
					invalidNew = false;
				} catch (invalid_argument except)
				{
					win->error(except.what());
				}
			}
			else
				win->error("As senhas nao batem.");
		}while(invalidNew);

		try
		{
			userAdm->changePassword(newPass);
			session->setUsrPassword(newPass);
			win->success("Senha modificada com sucesso.");
			invalidEnd = false;
		} catch (PersError except)
		{
			win->error(except.what());
		}
	}while(invalidEnd);
}
void MainCusMenu::listCustomer(){}
void MainCusMenu::showBalance(){}
void MainCusMenu::withdraw(){}
void MainCusMenu::deposit(){}
void MainCusMenu::schedulePayment(){}
void MainCusMenu::cancelPayment(){}
void MainCusMenu::listPayment(){}
