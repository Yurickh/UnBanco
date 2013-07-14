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

	if(payCode->getValue() != 5)
	{
		AccNumber accNumber(1);
		PayDay payDay(4122015);
		Money payValue(10.0);

		Payment payment(accNumber, *payCode, payDay, payValue);

		returnList.push_back(payment);
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

void PersGetManager :: execute(UsrMatric* usrMatric) throw (PersError)
{
	if(usrMatric->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);

	UsrName usrName("Yurick");
	UsrPassword usrPassword("senha");
	ManType* manType;

	if(usrMatric->getValue() == 3)
		manType = new ManType(ADMIN);
	else
		manType = new ManType(NORMAL);

	Manager man(usrName, usrPassword, *manType, *usrMatric);

	returnList.push_back(man);

	delete manType;
}

void PersGetAccount :: execute(AccNumber* accNumber) throw (PersError)
{
	if(accNumber->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);

	AccType* accType;
	Money limit(400);
	Money balance(200);
	UsrId usrId(accNumber->getValue());

	if(accNumber->getValue() == 3)
		accType = new AccType(SPECIAL);
	else
		accType = new AccType(NORMAL);

	Account acc(*accNumber, *accType, limit, balance, usrId);

	returnList.push_back(acc);

	delete accType;
}

void PersGetCustomer :: execute(UsrId usrId) throw (PersError)
{
	if(usrId.getValue() == 6)
		throw PersError(PERS_ERROR_MSG);

	UsrName usrName("Yurick");
	UsrPassword usrPassword("senha");

	Customer cus(usrName, usrPassword, usrId);

	returnList.push_back(cus);
}

void PersGetLatestNum :: execute() throw (PersError)
{
	AccNumber accNumber(4);

	if(rand() % 2)
		throw PersError(PERS_ERROR_MSG);

	returnList.push_back(accNumber);
}

void PersNewAccount :: execute(Account* acc) throw (PersError)
{
	if(acc->getAccNumber().getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersDelAccount :: execute(AccNumber* accNumber) throw (PersError)
{
	if(accNumber->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersBlkAccount :: execute(AccNumber* accNumber) throw (PersError)
{
	if(accNumber->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersFetchAccount :: execute() throw (PersError)
{
	if(rand() % 2)
		throw PersError(PERS_ERROR_MSG);

	AccNumber* accNumber;
	AccType* accType;
	Money* limit;
	Money* balance;
	UsrId* usrId;

	Account *acc1, *acc2, *acc3;

	accNumber = new AccNumber(1);
	accType = new AccType(NORMAL);
	limit = new Money(100);
	balance = new Money(40);
	usrId = new UsrId(1);

	acc1 = new Account(*accNumber, *accType, *limit, *balance, *usrId);

	delete accNumber;
	delete accType;
	delete limit;
	delete balance;
	delete usrId;

	accNumber = new AccNumber(2);
	accType = new AccType(NORMAL);
	limit = new Money(150);
	balance = new Money(15);
	usrId = new UsrId(2);

	acc2 = new Account(*accNumber, *accType, *limit, *balance, *usrId);

	delete accNumber;
	delete accType;
	delete limit;
	delete balance;
	delete usrId;

	accNumber = new AccNumber(3);
	accType = new AccType(SPECIAL);
	limit = new Money(200);
	balance = new Money(20);
	usrId = new UsrId(3);

	acc3 = new Account(*accNumber, *accType, *limit, *balance, *usrId);

	delete accNumber;
	delete accType;
	delete limit;
	delete balance;
	delete usrId;

	returnList.push_back(*acc1);
	returnList.push_back(*acc2);
	returnList.push_back(*acc3);

	delete acc1;
	delete acc2;
	delete acc3;
}

void PersUblkAccount :: execute(AccNumber* accNumber) throw (PersError)
{
	if(accNumber->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersEdtAccount :: execute(AccNumber* accNumber, AccType* accType) throw (PersError)
{
	if(accNumber->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersEdtAccount :: execute(AccNumber* accNumber, Money* limit) throw (PersError)
{
	if(accNumber->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersGetLatestMatric :: execute() throw (PersError)
{
	if(rand() % 2)
		throw PersError(PERS_ERROR_MSG);

	UsrMatric usrMatric(2);

	returnList.push_back(usrMatric);
}

void PersNewManager :: execute(Manager* man) throw (PersError)
{
	if(man->getUsrMatric().getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersFetchManager :: execute() throw (PersError)
{
	if( rand() % 2)
		throw PersError(PERS_ERROR_MSG);

	UsrName n1Name("Giovana"), n2Name("Yurick"), n3Name("Andre");
	UsrPassword n1Password("s2"), n2Password("eu"), n3Password("outro");
	UsrMatric n1Matric(1), n2Matric(2), n3Matric(24);
	ManType n1Type(NORMAL), n2Type(NORMAL), n3Type(NORMAL);

	Manager n1(n1Name, n1Password, n1Type, n1Matric);
	Manager n2(n2Name, n2Password, n2Type, n2Matric);
	Manager n3(n3Name, n3Password, n3Type, n3Matric);

	returnList.push_back(n1);
	returnList.push_back(n2);
	returnList.push_back(n3);
}

void PersEdtManager :: execute(UsrMatric* usrMatric, UsrName* newName) throw (PersError)
{
	if(usrMatric->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersDelManager :: execute(UsrMatric* usrMatric) throw (PersError)
{
	if(usrMatric->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersEdtManager :: execute(UsrMatric* usrMatric, UsrPassword* usrPassword) throw (PersError)
{
	if(usrMatric->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersGetCustomer :: execute(UsrName* usrName) throw (PersError)
{
	if(usrName->getValue() == "abacate")
		throw PersError(PERS_ERROR_MSG);

	UsrPassword usrPassword("senha");
	UsrId usrId(4);

	Customer cus(*usrName, usrPassword, usrId);

	returnList.push_back(cus);
}

void PersNewCustomer :: execute(Customer* cus) throw (PersError)
{
	if(cus->getUsrId().getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersGetLatestId :: execute() throw (PersError)
{
	if(rand() % 2)
		throw PersError(PERS_ERROR_MSG);

	UsrId usrId(5);

	returnList.push_back(usrId);
}

void PersEdtCustomer :: execute(UsrId* usrId, UsrName* usrName) throw (PersError)
{
	if(usrId->getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}

void PersEdtCustomer :: execute(UsrId& usrId, UsrPassword& newPassword) throw (PersError)
{
	if(usrId.getValue() == 5)
		throw PersError(PERS_ERROR_MSG);
}
