#include "UserUnit.h"

#include <iostream>

#define PERS_ERROR_MSG "Ocorreu um erro ao se conectar ao database. Favor tentar novamente mais tarde."

ManType StubUserLogin::autent(UsrMatric* usrMatric, UsrPassword* usrPassword) throw (invalid_argument, PersError)
{
	ManType manType(NORMAL);

	if(usrMatric->getValue() == 1)
		throw invalid_argument("Login ou Senha incorretos");

	if(usrMatric->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);

	if(usrMatric->getValue() == 3)
		manType.setValue(ADMIN);

	return manType;
}

void StubUserLogin::autent(AccNumber* accNumber, UsrPassword* usrPassword) throw (invalid_argument, PersError)
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("Login ou Senha incorretos");

	if(accNumber->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

void StubUserManAdm::changePassword(UsrPassword* newPassword) throw (PersError)
{
	if(newPassword->getValue() == "2")
		throw PersError(PERS_ERROR_MSG);

}

void StubUserManAdm :: createManager(UsrName* usrName, UsrPassword* usrPassword) throw (PersError)
{
	if(usrPassword->getValue() == "2")
		throw PersError(PERS_ERROR_MSG);
}

list<Manager*> StubUserManAdm :: fetchManager() throw (PersError)
{
	list<Manager*> manList;
	Manager *n1, *n2, *n3;

	UsrName *n1Name, *n2Name, *n3Name;
	UsrPassword *n1Password, *n2Password, *n3Password;
	UsrMatric *n1Matric, *n2Matric, *n3Matric;
	ManType *n1Type, *n2Type, *n3Type;

	if(!(rand()%2))
		throw PersError(PERS_ERROR_MSG);
	
	n1Name = new UsrName("Giovana");
	n2Name = new UsrName("Yurick");
	n3Name = new UsrName("Andre");

	n1Password = new UsrPassword("s2");
	n2Password = new UsrPassword("eu");
	n3Password = new UsrPassword("outro");

	n1Matric = new UsrMatric(1);
	n2Matric = new UsrMatric(2);
	n3Matric = new UsrMatric(24);

	n1Type = new ManType(NORMAL);
	n2Type = new ManType(NORMAL);
	n3Type = new ManType(NORMAL);

	n1 = new Manager(n1Name, n1Password, n1Type, n1Matric);
	n2 = new Manager(n2Name, n2Password, n2Type, n2Matric);
	n3 = new Manager(n3Name, n3Password, n3Type, n3Matric);

	manList.push_back(n1);
	manList.push_back(n2);
	manList.push_back(n3);

	return manList;
}

void StubUserManAdm :: editManName(UsrMatric* usrMatric, UsrName* usrName) throw (PersError)
{
	if(usrMatric->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

void StubUserCusAdm :: changePassword(UsrPassword* newPassword) throw (PersError)
{
	if(newPassword->getValue() == "2")
		throw PersError(PERS_ERROR_MSG);
}
