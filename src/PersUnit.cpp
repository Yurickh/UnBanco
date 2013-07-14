#include "PersUnit.h"

PersError::PersError()
{
	info = "Erro desconhecido.";
}

PersError::PersError(string info)
{
	this->info = info;
}

string PersError::what()
{
	return info;
}

void PersGetBalance :: execute(AccNumber accNumber) throw (PersError)
{
	if(accNumber.getValue() == 5)
	{
		throw PersError(PERS_ERROR_MSG);
	}

	Money mon(10);

	returnList.push_back(mon);
}

void PersSetBalance :: execute(AccNumber accNumber, Money* money) throw (PersError)
{
	if(accNumber.getValue() == 5)
	{
		throw PersError(PERS_ERROR_MSG);
	}
}

void PersGetLatestCode :: execute() throw (PersError)
{
	PayCode payCode(4);

	if(rand() % 2)
	{
		throw PersError(PERS_ERROR_MSG);	
	}

	returnList.push_back(payCode);
}

void PersNewPayment :: execute(Payment* payment) throw (PersError)
{
	if(payment->getAccNumber().getValue() == 5)
	{
		throw PersError(PERS_ERROR_MSG);
	}
}

void PersDelPayment :: execute(PayCode* payCode) throw (PersError)
{
	if(payCode->getValue() == 4)
	{
		throw PersError(PERS_ERROR_MSG);
	}
}

void PersFetchPayment :: execute() throw (PersError)
{
	if(rand() % 3)
	{
		throw PersError(PERS_ERROR_MSG);
	}

	Payment *pay1, *pay2, *pay3;
	AccNumber* accNumber;
	PayCode* payCode;
	PayDay* payDay;
	Money* payValue;

	accNumber = new AccNumber(1);
	payCode = new PayCode(4);
	payDay = new PayDay(4122015);
	payValue = new Money(10.0);

	pay1 = new Payment(*accNumber, *payCode, *payDay, *payValue);

	delete accNumber;
	delete payCode;
	delete payDay;	
	delete payValue;

	accNumber = new AccNumber(2);
	payCode = new PayCode(5);
	payDay = new PayDay(5122016);
	payValue = new Money(20.0);

	pay2 = new Payment(*accNumber, *payCode, *payDay, *payValue);
	
	delete accNumber;
	delete payCode;
	delete payDay;	
	delete payValue;

	accNumber = new AccNumber(3);
	payCode = new PayCode(6);
	payDay = new PayDay(20102014);
	payValue = new Money(30.0);

	pay3 = new Payment(*accNumber, *payCode, *payDay, *payValue);

	delete accNumber;
	delete payCode;
	delete payDay;	
	delete payValue;

	returnList.push_back(*pay1);
	returnList.push_back(*pay2);
	returnList.push_back(*pay3);
}
