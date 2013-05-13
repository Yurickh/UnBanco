#include "BaseUnit.h"

void UsrId::validate(const int &number) throw (invalid_argument)
{
	if(UsrId <= 0)
		throw invalid_argument("Erro 0000: Atribuição invalida de ID.");
}

UsrId :: Id(int valua)
{
	validate(value);
	this->value = value;
}
