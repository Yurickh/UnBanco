#include "BaseUnit.h"
#include "EntityUnit.h"

User::User()
{
	this->name.setValue("");
	this->password.setValue("");
}

void User::setName (const UsrName& name) {
	this->name = name;
}

void User::setPassword (const UsrPassword& password){
	this->password = password;
}


Customer::Customer (const UsrName& name, const UsrPassword& password, const UsrId& usrId) throw (invalid_argument)
{
	if(name.getValue() == "")
		throw invalid_argument("Nome nao foi inicializado");
	if(password.getValue() == "")
		throw invalid_argument("Password nao foi inicializado");
	if(usrId.getValue() == -1)
		throw invalid_argument("User ID nao foi inicializado");
	this->name = name;
	this->password = password;
	this->usrId = usrId;
}

void Customer::setUsrId(const UsrId& usrId){
	this->usrId = usrId;
}


Account::Account (const AccNumber& accNumber, const AccType& accType, const Money& limit, const UsrId& usrId) throw (invalid_argument)
{
	if(accNumber.getValue() == -1)
		throw invalid_argument("Accout Number nao foi inicializado");
	if(limit.getValue() == -1)
		throw invalid_argument("Limit nao foi inicializado");
	if(usrId.getValue() == -1)
		throw invalid_argument("User ID nao foi inicializado");
	this->accNumber = accNumber;
	this->accType = accType;
	this->limit = limit;
	this->usrId = usrId;
}

void Account::setAccNumber (const AccNumber& accNumber) {
	this->accNumber = accNumber;
}

void Account::setAccType (const AccType& accType)
{
	this->accType = accType;
}

void Account::setLimit (const Money& limit)
{
	this->limit = limit;
}

void Account::setBalance (const Money& balance)
{
	this->balance = balance;
}

void Account::setUsrId (const UsrId& usrId)
{
	this->usrId = usrId;
}


Manager::Manager (const UsrName& name, const UsrPassword& password, const ManType& manType, const UsrMatric& usrMatric) throw (invalid_argument)
{
	if(name.getValue() == "")
		throw invalid_argument("Nome nao foi inicializado");
	if(password.getValue() == "")
	throw invalid_argument("Password nao foi inicializado");
	if(usrMatric.getValue() == -1)
		throw invalid_argument("Matricula nao foi inicializada");
	this->manType = manType;
	this->usrMatric = usrMatric;
}

void Manager::setManType (const ManType& manType){
	this->manType = manType;
}

void Manager::setUsrMatric (const UsrMatric& usrMatric){
	this->usrMatric = usrMatric;
}


Payment::Payment (const AccNumber& accNumber, const PayDay& payDay, const Money& payValue) throw (invalid_argument)
{
	if(accNumber.getValue() == -1)
		throw invalid_argument("Account Number nao foi inicializado");
	if(payDay.getValue() == -1)
		throw invalid_argument("Payment Day nao foi inicializado");
	if(payValue.getValue() == -1)
		throw invalid_argument("Payment Value nao foi inicializado");
	this->accNumber = accNumber;
	this->payDay = payDay;
	this->payValue = payValue;
}

void Payment::setAccNumber (const AccNumber& accNumber){
	this->accNumber = accNumber;
}

void Payment::setPayDay (const PayDay& payDay){
	this->payDay = payDay;
}

void Payment::setPayValue (const Money& payValue){
	this->payValue = payValue;
}
