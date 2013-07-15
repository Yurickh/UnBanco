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


void PersGetBalance :: execute(AccNumber accNumber) throw (PersError, invalid_argument)
{
	SQLquery << "SELECT `balance` FROM `account` WHERE `AccNumber`=";
	SQLquery << accNumber.getValue();

	returnList.clear();

	run();

	if(returnList.empty())
		throw invalid_argument("A conta requisitada nao existe");
}

Money PersGetBalance :: getResult()
{
	return Money(atof(returnList.front().value.c_str()));
}

void PersSetBalance :: execute(AccNumber accNumber, Money* money) throw (PersError)
{
	SQLquery << "UPDATE `account` WHERE `AccNumber`=";
	SQLquery << accNumber.getValue();
	SQLquery << " SET `Balance`=";
	SQLquery << money->getValue();

	returnList.clear();

	run();
}

void PersGetLatestCode :: execute() throw (PersError)
{
	list<TableClass>::iterator it;
	int i=0;
	TableClass a;

	SQLquery << "SELECT `PayCode` FROM `payment` ORDER BY `PayCode`";

	returnList.clear();

	run();

	for(it = returnList.begin(); it != returnList.end(); ++it, ++i)
		if(atoi(it->value.c_str()) <= i) break;

	returnList.clear();
	a.name = "PayCode";
	a.value = ++i;
	returnList.push_back(a);
}

PayCode PersGetLatestCode :: getResult()
{
	PayCode payCode(atoi(returnList.front().value.c_str()));

	return payCode;
}

void PersNewPayment :: execute(Payment* payment) throw (PersError)
{
	SQLquery << "INSERT INTO `payment` (`AccNumber`, `PayCode`, `PayDay`, `PayValue`) VALUES (";
	SQLquery << payment->getAccNumber().getValue();
	SQLquery << ", ";
	SQLquery << payment->getAccNumber().getValue();
	SQLquery << ")";

	returnList.clear();

	run();
}

void PersDelPayment :: execute(PayCode* payCode) throw (PersError)
{
	SQLquery << "DELETE FROM `payment` WHERE `PayCode`=";
	SQLquery << payCode->getValue();

	returnList.clear();

	run();
}

void PersFetchPayment :: execute() throw (PersError)
{
	SQLquery << "SELECT * FROM `payment` ORDER BY `PayCode`";

	returnList.clear();

	run();
}

list<Payment> PersFetchPayment :: getResult()
{
	list<Payment> lPayment;

	AccNumber* accNumber;
	PayCode* payCode;
	PayDay* payDay;
	Money* payValue;

	Payment* payment;

	for(list<TableClass>::iterator it = returnList.begin(); it!=returnList.end(); ++it)
	{
		for(int i=0; i<4; ++i, ++it)
		{
			if(it->name == "AccNumber")
				accNumber = new AccNumber(atoi(it->value.c_str()));
			else if(it->name == "PayCode")
				payCode = new PayCode(atoi(it->value.c_str()));
			else if(it->name == "PayDay")
				payDay = new PayDay(atoi(it->value.c_str()));
			else if(it->name == "PayValue")
				payValue = new Money(atof(it->value.c_str()));
		}

		payment = new Payment(*accNumber, *payCode, *payDay, *payValue);

		lPayment.push_back(*payment);

		delete payment;
		delete accNumber;
		delete payCode;
		delete payDay;
		delete payValue;
	}

	return lPayment;
}

void PersGetManager :: execute(UsrMatric* usrMatric) throw (PersError, invalid_argument)
{
	SQLquery << "SELECT * FROM `manager` WHERE `UsrMatric`=";
	SQLquery << usrMatric->getValue();

	returnList.clear();

	run();

	if(returnList.empty())
		throw invalid_argument("O Gerente requisitado nao existe");
}

Manager PersGetManager :: getResult()
{
	UsrName* usrName;
	UsrPassword* usrPassword;
	ManType* manType;
	UsrMatric* usrMatric;

	for(list<TableClass>::iterator it = returnList.begin(); it != returnList.end(); ++it)
	{
		if(it->name == "UsrName")
			usrName = new UsrName(it->value);
		else if(it->name == "UsrPassword")
			usrPassword = new UsrPassword(it->value);
		else if(it->name == "UsrType")
			manType = new ManType(atoi(it->value.c_str()));
		else if(it->name == "UsrMatric")
			usrMatric = new UsrMatric(atoi(it->value.c_str()));
	}

	Manager manager(*usrName, *usrPassword, *manType, *usrMatric);

	delete usrName;
	delete usrPassword;
	delete manType;
	delete usrMatric;

	return manager;
}

void PersGetAccount :: execute(AccNumber* accNumber) throw (PersError, invalid_argument)
{
	SQLquery << "SELECT * FROM `account` WHERE `AccNumber`=";
	SQLquery << accNumber->getValue();

	returnList.clear();

	run();

	if(returnList.empty())
		throw invalid_argument("A conta requisitada nao existe");
}

Account PersGetAccount :: getResult()
{
	AccNumber* accNumber;
	AccType* accType;
	Money* limit;
	Money* balance;
	UsrId* usrId;

	for(list<TableClass>::iterator it = returnList.begin(); it != returnList.end(); ++it)
	{
		if(it->name == "AccNumber")
			accNumber = new AccNumber(atoi(it->value.c_str()));
		else if(it->name == "AccType")
			accType = new AccType(atoi(it->value.c_str()));
		else if(it->name == "Limit")
			limit = new Money(atof(it->value.c_str()));
		else if(it->name == "Balance")
			balance = new Money(atof(it->value.c_str()));
		else if(it->name == "UsrId")
			usrId = new UsrId(atoi(it->value.c_str()));
	}

	Account acc(*accNumber, *accType, *limit, *balance, *usrId);

	delete accNumber;
	delete accType;
	delete balance;
	delete usrId;

	return acc;
}

void PersGetCustomer :: execute(UsrId usrId) throw (PersError, invalid_argument)
{
	SQLquery << "SELECT * FROM `customer` WHERE `UsrId`=";
	SQLquery << usrId.getValue();

	returnList.clear();

	run();

	if(returnList.empty())
		throw invalid_argument("O Cliente requisitado nao existe");
}

Customer PersGetCustomer :: getResult()
{
	UsrName* usrName;
	UsrPassword* usrPassword;
	UsrId* usrId;

	for(list<TableClass>::iterator it = returnList.begin(); it != returnList.end(); ++it)
	{
		if(it->name == "UsrName")
			usrName = new UsrName(it->value);
		else if(it->name == "UsrPassword")
			usrPassword = new UsrPassword(it->value);
		else if(it->name == "UsrId")
			usrId = new UsrId(atoi(it->value.c_str()));
	}

	Customer cus(*usrName, *usrPassword, *usrId);

	delete usrName;
	delete usrPassword;
	delete usrId;

	return cus;
}

void PersGetLatestNum :: execute() throw (PersError)
{
	list<TableClass>::iterator it;
	int i=0;
	TableClass a;

	SQLquery << "SELECT `AccNumber` FROM `account` ORDER BY `AccNumber`";

	returnList.clear();

	run();

	for(it = returnList.begin(); it != returnList.end(); ++it, ++i)
		if(atoi(it->value.c_str()) <= i) break;

	returnList.clear();
	a.name = "AccNumber";
	a.value = ++i;
	returnList.push_back(a);
}

AccNumber PersGetLatestNum :: getResult()
{
	return AccNumber(atoi(returnList.front().value.c_str()));
}

void PersNewAccount :: execute(Account* acc) throw (PersError)
{
	SQLquery << "INSERT INTO `account` (`AccNumber`, `AccType`, `Limit`, `Balance`, `UsrId`) VALUES (";
	SQLquery << acc->getAccNumber().getValue();
	SQLquery << ", ";
	SQLquery << (acc->getAccType().getValue())? "1" : "0";
	SQLquery << ", ";
	SQLquery << acc->getLimit().getValue();
	SQLquery << ", ";
	SQLquery << acc->getBalance().getValue();
	SQLquery << ", ";
	SQLquery << acc->getUsrId().getValue();
	SQLquery << " )";

	returnList.clear();

	run();
}

void PersDelAccount :: execute(AccNumber* accNumber) throw (PersError)
{
	SQLquery << "DELETE FROM `account` WHERE `AccNumber`=";
	SQLquery << accNumber->getValue();

	returnList.clear();

	run();
}

void PersBlkAccount :: execute(AccNumber* accNumber) throw (PersError)
{
	PersGetAccount getAccount;

	getAccount.execute(accNumber);

	Money limit(getAccount.getResult().getLimit());

	if(limit.getValue() < 0) return;

	limit.setValue(-limit.getValue());

	SQLquery << "UPDATE `account` SET `Limit`=";
	SQLquery << limit.getValue();
	SQLquery << " WHERE `AccNumber`=";
	SQLquery << accNumber->getValue();

	returnList.clear();

	run();	
}

void PersFetchAccount :: execute() throw (PersError)
{
	SQLquery << "SELECT * FROM `account` SORT BY `AccNumber`";

	returnList.clear();

	run();
}

list<Account> PersFetchAccount :: getResult()
{
	list<Account> lAccount;

	AccNumber* accNumber;
	AccType* accType;
	Money* limit;
	Money* balance;
	UsrId* usrId;

	for(list<TableClass>::iterator it = returnList.begin(); it != returnList.end(); ++it)
	{
		for(int i=0; i<5; ++i, ++it)
		{
			if(it->name == "AccNumber")
				accNumber = new AccNumber(atoi(it->value.c_str()));
			else if(it->name == "AccType")
				accType = new AccType(atoi(it->value.c_str()));
			else if(it->name == "Limit")
				limit = new Money(atof(it->value.c_str()));
			else if(it->name == "Balance")
				balance = new Money(atof(it->value.c_str()));
			else if(it->name == "UsrId")
				usrId = new UsrId(atoi(it->value.c_str()));
		}

		Account acc(*accNumber, *accType, *limit, *balance, *usrId);

		delete accNumber;
		delete accType;
		delete limit;
		delete balance;
		delete usrId;

		lAccount.push_back(acc);
	}

	return lAccount;
}

void PersUblkAccount :: execute(AccNumber* accNumber) throw (PersError)
{
	PersGetAccount getAccount;

	getAccount.execute(accNumber);

	Money limit(getAccount.getResult().getLimit());

	if(limit.getValue() > 0) return;

	limit.setValue(-limit.getValue());

	SQLquery << "UPDATE `account` SET `Limit`=";
	SQLquery << limit.getValue();	
	SQLquery << " WHERE `AccNumber`=";
	SQLquery << accNumber->getValue();

	returnList.clear();

	run();	
}

void PersEdtAccount :: execute(AccNumber* accNumber, AccType* accType) throw (PersError)
{
	SQLquery << "UPDATE `account` SET `AccType`=";
	SQLquery << (accType->getValue())?"1":"0";
	SQLquery << " WHERE `AccNumber`=";
	SQLquery << accNumber->getValue();

	returnList.clear();

	run();
}

void PersEdtAccount :: execute(AccNumber* accNumber, Money* limit) throw (PersError)
{
	SQLquery << "UPDATE `account` SET `Limit`=";
	SQLquery << limit->getValue();
	SQLquery << " WHERE `AccNumber`=";
	SQLquery << accNumber->getValue();

	returnList.clear();

	run();
}

void PersGetLatestMatric :: execute() throw (PersError)
{
	list<TableClass>::iterator it;
	int i=0;
	TableClass a;

	stringstream aux;

	SQLquery << "SELECT `UsrMatric` FROM `manager` ORDER BY `UsrMatric`";

	returnList.clear();

	run();

	for(it = returnList.begin(); it != returnList.end(); ++it)
	{
		if(it->name == "UsrMatric")
		{
			if(atoi(it->value.c_str()) <= i) break;
			else i++;
		}
	}

	aux << i+1;

	returnList.clear();
	a.name = "UsrMatric";
	a.value = aux.str();
	returnList.push_back(a);
}

UsrMatric PersGetLatestMatric :: getResult()
{
	return UsrMatric(atoi(returnList.front().value.c_str()));
}


void PersNewManager :: execute(Manager* man) throw (PersError)
{
	SQLquery << "INSERT INTO `manager` (`UsrName`, `UsrPassword`, `UsrMatric`, `UsrType`) VALUES ('";
	SQLquery << man->getName().getValue();
	SQLquery << "', '";
	SQLquery << man->getPassword().getValue();
	SQLquery << "', ";
	SQLquery << man->getUsrMatric().getValue();
	SQLquery << ", ";
	SQLquery << (man->getManType().getValue())?"1":"0";
	SQLquery << " )";

	returnList.clear();

	run();
}

void PersFetchManager :: execute() throw (PersError)
{
	SQLquery << "SELECT * FROM `manager` WHERE `UsrType`= 0";

	returnList.clear();

	run();
}

list<Manager> PersFetchManager :: getResult()
{
	list<Manager> lManager;

	UsrName* usrName;
	UsrPassword* usrPassword;
	ManType* manType;
	UsrMatric* usrMatric;

	for(list<TableClass>::iterator it = returnList.begin(); it != returnList.end();)
	{
		int dealloc = 0;
		for(int i=0; i<4 && it!=returnList.end(); ++i, ++it)
		{
			if(it->name == "UsrName")
			{
				usrName = new UsrName(it->value);
				dealloc += 1;
			}
			else if(it->name == "UsrPassword")
			{
				usrPassword = new UsrPassword(it->value);
				dealloc += 2;
			}
			else if(it->name == "UsrType")
			{
				manType = new ManType(atoi(it->value.c_str()));
				dealloc += 4;
			}
			else if(it->name == "UsrMatric")
			{
				usrMatric = new UsrMatric(atoi(it->value.c_str()));
				dealloc += 8;
			}
		}

		if(dealloc == 15)
		{
			Manager man(*usrName, *usrPassword, *manType, *usrMatric);
			lManager.push_back(man);
		}

		if(dealloc >=8)
		{
			delete usrMatric;
			dealloc -= 8;
		}
		if(dealloc >=4)
		{
			delete manType;
			dealloc -= 4;
		}
		if(dealloc >=2)
		{
			delete usrPassword;
			dealloc -= 2;
		}
		if(dealloc >=1)
		{
			delete usrName;
			dealloc -= 1;
		}
			
	}

	returnList.clear();

	return lManager;
}

void PersEdtManager :: execute(UsrMatric* usrMatric, UsrName* newName) throw (PersError)
{
	SQLquery << "UPDATE `manager` SET `UsrName`='";
	SQLquery << newName->getValue();
	SQLquery << "' WHERE `UsrMatric`=";
	SQLquery << usrMatric->getValue();

	returnList.clear();

	run();
}

void PersDelManager :: execute(UsrMatric* usrMatric) throw (PersError)
{
	SQLquery << "DELETE FROM `manager` WHERE `usrMatric`=";
	SQLquery << usrMatric->getValue();

	returnList.clear();

	run();
}

void PersEdtManager :: execute(UsrMatric* usrMatric, UsrPassword* usrPassword) throw (PersError)
{
	SQLquery << "UPDATE `manager` SET `UsrPassword`='";
	SQLquery << usrPassword->getValue();
	SQLquery << "' WHERE `usrMatric`=";
	SQLquery << usrMatric->getValue();

	returnList.clear();

	run();
}

void PersGetCustomer :: execute(UsrName* usrName) throw (PersError, invalid_argument)
{
	SQLquery << "SELECT * FROM `customer` WHERE `UsrName`='";
	SQLquery << usrName->getValue();

	returnList.clear();

	run();

	if(returnList.empty())
		throw invalid_argument("O Cliente selecionado nao existe");
}

void PersNewCustomer :: execute(Customer* cus) throw (PersError)
{
	SQLquery << "INSERT INTO `customer` (`UsrName`, `UsrPassword`, `UsrId`) VALUES ('";
	SQLquery << cus->getName().getValue();
	SQLquery << "', '";
	SQLquery << cus->getPassword().getValue();
	SQLquery << "', ";
	SQLquery << cus->getUsrId().getValue();

	returnList.clear();

	run();
}

void PersGetLatestId :: execute() throw (PersError)
{
	list<TableClass>::iterator it;
	int i=0;
	TableClass a;

	SQLquery << "SELECT `UsrId` FROM `customer` ORDER BY `UsrId`";

	returnList.clear();

	run();

	for(it = returnList.begin(); it != returnList.end(); ++it, ++i)
		if(atoi(it->value.c_str()) <= i) break;

	returnList.clear();
	a.name = "UsrId";
	a.value = ++i;
	returnList.push_back(a);
}

UsrId PersGetLatestId :: getResult()
{
	return UsrId(atoi(returnList.front().value.c_str()));
}

void PersEdtCustomer :: execute(UsrId* usrId, UsrName* usrName) throw (PersError)
{
	SQLquery << "UPDATE `customer` SET `UsrName`='";
	SQLquery << usrName->getValue();
	SQLquery << "' WHERE `UsrId`=";
	SQLquery << usrId->getValue();

	returnList.clear();

	run();
}

void PersEdtCustomer :: execute(UsrId& usrId, UsrPassword& newPassword) throw (PersError)
{
	SQLquery << "UPDATE `customer` SET `UsrPassword`='";
	SQLquery << newPassword.getValue();
	SQLquery << "' WHERE `UsrId`=";
	SQLquery << usrId.getValue();

	returnList.clear();

	run();
}
