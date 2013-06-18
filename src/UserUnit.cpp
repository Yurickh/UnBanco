#include "UserUnit.h"

ManType Stub::autent(UsrMatric* usrMatric, UsrPassword* usrPassword) throw (invalid_argument, PersError)
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

void Stub::autent(AccNumber* accNumber, UsrPassword* usrPassword) throw (invalid_argument, PersError)
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("Login ou Senha incorretos");

	if(accNumber->getValue() == 2)
		throw PersError("Ocorreu um erro ao se conectar ao database. Favor tentar novamente mais tarde.");
}
