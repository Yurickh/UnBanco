#include "TransacUnit.h"

void StubTransacAdm :: withdraw(AccNumber accNumber, Money* with) throw (invalid_argument, PersError)
{
	if(with->getValue() <= 0)
		throw invalid_argument("Nao e possivel retirar quantidades nulas ou negativas de dinheiro");
	if(accNumber.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

void StubTransacAdm :: deposit(AccNumber accNumber, Money* dep) throw (invalid_argument, PersError)
{
	if(dep->getValue() <= 0)
		throw invalid_argument("Nao e possivel depositar quantidades nulas ou negativas de dinheiro");
	if(accNumber.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}
