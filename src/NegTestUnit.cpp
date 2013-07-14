#include "EngineUnit.h"

/** Objeto janela.
	Onde os eventos de entrada e saída irão ocorrer. */
Window* win;

#include "UserUnit.h"
#include "TransacUnit.h"
#include "MainUnit.h"

/** Builder. */
int main()
{
	MainLogin* mainLogin;
	MainCusMenu* cusMenu;
	MainManMenu* manMenu;
	MainAdmMenu* admMenu;
	UserLogin* userLogin;
	UserManAdm* userManAdm;
	UserAccAdm* userAccAdm;
	UserCusAdm* userCusAdm;
	TransacAdm* transacAdm;

	win		= new Textual;
	mainLogin	= new MainLogin;
	cusMenu		= new MainCusMenu;
	manMenu		= new MainManMenu;
	admMenu		= new MainAdmMenu;
	userLogin	= new CtrlUserLogin;
	userManAdm	= new StubUserManAdm;
	userAccAdm	= new StubUserAccAdm;
	userCusAdm	= new StubUserCusAdm;
	transacAdm	= new CtrlTransacAdm;

	admMenu->setUserAdm(userManAdm);
	manMenu->setUserAdm(userManAdm);
	manMenu->setAccAdm(userAccAdm);
	manMenu->setCusAdm(userCusAdm);
	cusMenu->setUserAdm(userCusAdm);
	cusMenu->setAccAdm(userAccAdm);
	cusMenu->setTransacAdm(transacAdm);

	mainLogin->setUserLogin(userLogin);
	mainLogin->setMainCusMenu(cusMenu);
	mainLogin->setMainManMenu(manMenu);
	mainLogin->setMainAdmMenu(admMenu);

	mainLogin->execute();

	return 0;
}
