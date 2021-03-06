#include "UserUnit.h"

#include <iostream>

extern list<TableClass> PersUnit::returnList;

//===============CtrlUserLogin=====================

ManType CtrlUserLogin::autent(UsrMatric* usrMatric, UsrPassword* usrPassword) throw (invalid_argument, PersError)
{
	PersGetManager getManager;

	getManager.execute(usrMatric);
	Manager man(getManager.getResult());

	if(man.getPassword().getValue() != usrPassword->getValue())
		throw invalid_argument("Login ou Senha incorretos");

	return man.getManType();
}

void CtrlUserLogin :: autent(AccNumber* accNumber, UsrPassword* usrPassword) throw (invalid_argument, PersError)
{
	PersGetAccount getAccount;
	PersGetCustomer getCustomer;

	getAccount.execute(accNumber);
	Account acc(getAccount.getResult());

	getCustomer.execute(acc.getUsrId());
	Customer cus(getCustomer.getResult());

	if(cus.getPassword().getValue() != usrPassword->getValue())
		throw invalid_argument("Login ou Senha incorretos");
}

//===============StubUserLogin=====================

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


//=================CtrlUserAccAdm======================

void CtrlUserAccAdm :: createAccount( AccType* accType, Money* limit, Money* balance, UsrId usrId) throw (PersError)
{
	PersGetLatestNum getLatestNum;
	PersNewAccount newAccount;
	Account* acc;

	getLatestNum.execute();
	AccNumber accNumber(getLatestNum.getResult());

	acc = new Account(accNumber, *accType, *limit, *balance, usrId);

	newAccount.execute(acc);

	delete acc;
}

void CtrlUserAccAdm :: deleteAccount( AccNumber* accNumber ) throw (invalid_argument, PersError)
{
	PersDelAccount delAccount;
	PersGetAccount getAccount;

	getAccount.execute(accNumber);

	delAccount.execute(accNumber);
}

void CtrlUserAccAdm :: blockAccount(AccNumber* accNumber) throw (invalid_argument, PersError)
{
	PersBlkAccount blkAccount;
	PersGetAccount getAccount;

	getAccount.execute(accNumber);

	blkAccount.execute(accNumber);
}

list<Account> CtrlUserAccAdm :: fetchAccount() throw (PersError)
{
	PersFetchAccount fetchAccount;

	fetchAccount.execute();

	return fetchAccount.getResult();
}

Account CtrlUserAccAdm :: fetchAccount(AccNumber number) throw (PersError)
{
	PersGetAccount getAccount;

	getAccount.execute(&number);

	return getAccount.getResult();
}

void CtrlUserAccAdm :: unblockAccount( AccNumber* accNumber ) throw (invalid_argument, PersError)
{
	PersUblkAccount ublkAccount;
	PersGetAccount getAccount;

	getAccount.execute(accNumber);

	ublkAccount.execute(accNumber);
}

void CtrlUserAccAdm :: editAccType( AccNumber* accNumber, AccType* accType ) throw (invalid_argument, PersError )
{
	PersGetAccount getAccount;
	PersEdtAccount edtAccount;

	getAccount.execute(accNumber);

	edtAccount.execute(accNumber, accType);
}

void CtrlUserAccAdm :: editAccLimit( AccNumber* accNumber, Money* accLimit ) throw (invalid_argument, PersError )
{
	PersGetAccount getAccount;
	PersEdtAccount edtAccount;

	getAccount.execute(accNumber);

	edtAccount.execute(accNumber, accLimit);
}

//=================StubUserAccAdm======================

void StubUserAccAdm :: createAccount( AccType* accType, Money* limit, Money* balance, UsrId usrId) throw (PersError)
{
	if(limit->getValue() <= 100)
		throw PersError(PERS_ERROR_MSG);
}

void StubUserAccAdm :: deleteAccount( AccNumber* accNumber ) throw (invalid_argument, PersError)
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("A conta requisitada nao existe");
	if(accNumber->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

void StubUserAccAdm :: blockAccount( AccNumber* accNumber ) throw (invalid_argument, PersError)
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("A conta requisitada nao existe");
	if(accNumber->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
	if(accNumber->getValue() == 3)
		throw invalid_argument("A conta requisitada ja esta bloqueada");
}

list<Account> StubUserAccAdm :: fetchAccount() throw (PersError)
{
	list<Account> accList;

	AccNumber accNum1(1), accNum2(2), accNum3(3);
	AccType accType1(NORMAL), accType2(SPECIAL), accType3(NORMAL);
	Money accLimit1(10), accLimit2(20), accLimit3(-1);
	Money accBal1(5), accBal2(20), accBal3(15);
	UsrId accUsrId1(1), accUsrId2(2), accUsrId3(24);

	Account n1(accNum1, accType1, accLimit1, accBal1, accUsrId1);
	Account n2(accNum2, accType2, accLimit2, accBal2, accUsrId2);
	Account n3(accNum3, accType3, accLimit3, accBal3, accUsrId3);

	if(!(rand()%2))
		throw PersError(PERS_ERROR_MSG);

	accList.push_back(n1);
	accList.push_back(n2);
	accList.push_back(n3);

	return accList;
}

Account StubUserAccAdm :: fetchAccount(AccNumber number) throw (PersError)
{
	AccNumber accNumber(number);
	AccType accType(NORMAL);
	Money limit(400.0);
	Money balance(20.0);
	UsrId usrId(number.getValue()+1);

	if(number.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);

	Account acc(accNumber, accType, limit, balance, usrId);

	return acc;
}

void StubUserAccAdm :: unblockAccount( AccNumber* accNumber ) throw (invalid_argument, PersError)
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("A conta requisitada nao existe");
	if(accNumber->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
	if(accNumber->getValue() == 3)
		throw invalid_argument("A conta requisitada ja esta desbloqueada");
}

void StubUserAccAdm :: editAccType( AccNumber* accNumber, AccType* accType ) throw (invalid_argument, PersError )
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("A conta requisitada nao existe");
	if(accNumber->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

void StubUserAccAdm :: editAccLimit( AccNumber* accNumber, Money* accLimit ) throw (invalid_argument, PersError )
{
	if(accNumber->getValue() == 1)
		throw invalid_argument("A conta requisitada nao existe");
	if(accNumber->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

//=================CtrlUserManAdm======================

void CtrlUserManAdm :: changePassword(UsrMatric usrMatric, UsrPassword* newPassword) throw (PersError)
{
	PersEdtManager edtManager;

	edtManager.execute(&usrMatric, newPassword);
}

void CtrlUserManAdm :: createManager(UsrName* usrName, UsrPassword* usrPassword) throw (PersError)
{
	PersGetLatestMatric getLatestMatric;
	PersNewManager newManager;

	Manager* man;
	ManType manType(NORMAL);

	getLatestMatric.execute();
	UsrMatric usrMatric(getLatestMatric.getResult());

	man = new Manager(*usrName, *usrPassword, manType, usrMatric);

	newManager.execute(man);

	delete man;
}

list<Manager> CtrlUserManAdm :: fetchManager() throw (PersError)
{
	PersFetchManager fetchManager;

	fetchManager.execute();

	return fetchManager.getResult();
}

Manager CtrlUserManAdm :: fetchManager(UsrMatric matric) throw (PersError)
{
	PersGetManager getManager;

	getManager.execute(&matric);

	return getManager.getResult();
}

void CtrlUserManAdm :: editManName(UsrMatric* usrMatric, UsrName* usrName) throw (invalid_argument, PersError)
{
	PersGetManager getManager;
	PersEdtManager edtManager;

	getManager.execute(usrMatric);

	edtManager.execute(usrMatric, usrName);
}

void CtrlUserManAdm :: deleteManager(UsrMatric* usrMatric) throw (invalid_argument, PersError)
{
	PersGetManager getManager;
	PersDelManager delManager;

	getManager.execute(usrMatric);

	delManager.execute(usrMatric);
}
//=================StubUserManAdm======================

void StubUserManAdm::changePassword(UsrMatric usrMatric, UsrPassword* newPassword) throw (PersError)
{
	if(newPassword->getValue() == "2")
		throw PersError(PERS_ERROR_MSG);

}

void StubUserManAdm :: createManager(UsrName* usrName, UsrPassword* usrPassword) throw (PersError)
{
	if(usrPassword->getValue() == "2")
		throw PersError(PERS_ERROR_MSG);
}

list<Manager> StubUserManAdm :: fetchManager() throw (PersError)
{
	list<Manager> manList;

	UsrName n1Name("Giovana"), n2Name("Yurick"), n3Name("Andre");
	UsrPassword n1Password("s2"), n2Password("eu"), n3Password("outro");
	UsrMatric n1Matric(1), n2Matric(2), n3Matric(24);
	ManType n1Type(NORMAL), n2Type(NORMAL), n3Type(NORMAL);

	Manager n1(n1Name, n1Password, n1Type, n1Matric);
	Manager n2(n2Name, n2Password, n2Type, n2Matric);
	Manager n3(n3Name, n3Password, n3Type, n3Matric);

	if(!(rand()%2))
		throw PersError(PERS_ERROR_MSG);

	manList.push_back(n1);
	manList.push_back(n2);
	manList.push_back(n3);

	return manList;
}

Manager StubUserManAdm :: fetchManager(UsrMatric matric) throw (PersError)
{
	UsrName usrName("Yurick");
	UsrPassword usrPassword("eu");
	UsrMatric usrMatric(matric);
	ManType manType(NORMAL);

	if(matric.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);

	Manager man(usrName, usrPassword, manType, usrMatric);

	return man;
}

void StubUserManAdm :: editManName(UsrMatric* usrMatric, UsrName* usrName) throw (invalid_argument, PersError)
{
	if(usrMatric->getValue() == 1)
		throw invalid_argument("O Gerente requisitado nao existe");
	if(usrMatric->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

void StubUserManAdm :: deleteManager(UsrMatric* usrMatric) throw (invalid_argument, PersError)
{
	if(usrMatric->getValue() == 1)
		throw invalid_argument("O Gerente requisitado nao existe");
	if(usrMatric->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}


//================CtrlUserCusAdm============================

void CtrlUserCusAdm :: changePassword(UsrId usrId, UsrPassword* newPassword) throw (PersError)
{
	PersEdtCustomer edtCustomer;

	edtCustomer.execute(usrId, *newPassword);
}

UsrId CtrlUserCusAdm :: createCustomer(UsrName* name, UsrPassword* pass) throw (invalid_argument, PersError)
{
	PersGetCustomer getCustomer;
	PersNewCustomer newCustomer;
	PersGetLatestId getLatestId;

	Customer* cus;

	try
	{
		getCustomer.execute(name);
		throw PersError("temp");
	} catch(invalid_argument except) {}
	catch (PersError except)
	{
		throw invalid_argument("A conta requisitada ja existe");
	}

	getLatestId.execute();
	UsrId usrId (getLatestId.getResult());

	cus = new Customer(*name, *pass, usrId);

	newCustomer.execute(cus);

	delete cus;

	return usrId;
}

void CtrlUserCusAdm :: editCusName(UsrId* usrId, UsrName* usrName) throw (invalid_argument, PersError)
{
	PersGetCustomer getCustomer;
	PersEdtCustomer edtCustomer;

	getCustomer.execute(*usrId);

	edtCustomer.execute(usrId, usrName);
}

Customer CtrlUserCusAdm :: fetchCustomer(UsrId id) throw (PersError)
{
	PersGetCustomer getCustomer;

	getCustomer.execute(id);

	return getCustomer.getResult();
}

//================StubUserCusAdm============================

void StubUserCusAdm :: changePassword(UsrId usrId, UsrPassword* newPassword) throw (PersError)
{
	if(newPassword->getValue() == "2")
		throw PersError(PERS_ERROR_MSG);
}

UsrId StubUserCusAdm :: createCustomer(UsrName* name, UsrPassword* pass) throw (invalid_argument, PersError)
{
	if(name->getValue() == "A")
		throw invalid_argument("Este nome de usuario ja esta em uso");
	if(name->getValue() == "B")
		throw PersError(PERS_ERROR_MSG);

	UsrId usrId(5);

	return usrId;
}

void StubUserCusAdm :: editCusName(UsrId* usrId, UsrName*  usrName) throw (invalid_argument, PersError)
{
	if(usrId->getValue() == 1)
		throw invalid_argument("A conta requisitada nao existe");
	if(usrId->getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

Customer StubUserCusAdm :: fetchCustomer(UsrId id) throw (PersError)
{
	UsrName usrName("Yurick");
	UsrPassword usrPassword("eu");
	UsrId usrId(id);

	if(id.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);

	Customer cus(usrName, usrPassword, usrId);

	return cus;
}
