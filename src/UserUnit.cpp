#include "UserUnit.h"

ManType StubUserLogin::autent(UsrMatric* usrMatric, UsrPassword* usrPassword) throw (invalid_argument, PersError)
{
	ManType manType(NORMAL);

	if(usrMatric->getValue() == 1)
		throw invalid_argument("Login ou Senha incorretos");

	if(usrMatric->getValue() == 2)
		throw PersError("Ocorreu um erro ao se conectar ao database. Favor tentar novamente mais tarde.");

	if(usrMatric->getValue() == 3)
		manType.setValue(ADMIN);

	return manType;
}

void StubUserLogin::autent(AccNumber* accNumber, UsrPassword* usrPassword) throw (invalid_argument, PersError)
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("Login ou Senha incorretos");

	if(accNumber->getValue() == 2)
		throw PersError("Ocorreu um erro ao se conectar ao database. Favor tentar novamente mais tarde.");
}

void StubUserManAdm::changePassword(UsrPassword* newPassword) throw (PersError)
{
	if(newPassword->getValue() == "2")
		throw PersError("Ocorreu um erro aos e conectar ao database. Favor tentar novamente mais tarde.");
}
