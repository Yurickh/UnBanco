#include "EntityUnit.h"

#include <cstdlib>

User::User(){}

void User::setUsrName (UsrName*& name) {
	this->name = name;
}

void User::setUsrPassword (UsrPassword*& password){
	this->password = password;
}


Customer::Customer (UsrName*& name, UsrPassword*& password, UsrId*& usrId) throw (invalid_argument)
{
	if(name->getValue() == "")
		throw invalid_argument("Nome nao foi inicializado");
	if(password->getValue() == "")
		throw invalid_argument("Password nao foi inicializado");
	if(usrId->getValue() == -1)
		throw invalid_argument("User ID nao foi inicializado");
	this->name = name;
	this->password = password;
	this->usrId = usrId;
}

void Customer::setUsrId(UsrId*& usrId){
	this->usrId = usrId;
}


Account::Account (AccNumber*& accNumber, AccType*& accType, Money*& limit, UsrId*& usrId) throw (invalid_argument)
{
	if(accNumber->getValue() == -1)
		throw invalid_argument("Accout Number nao foi inicializado");
	if(limit->getValue() == -1)
		throw invalid_argument("Limit nao foi inicializado");
	if(usrId->getValue() == -1)
		throw invalid_argument("User ID nao foi inicializado");
	this->accNumber = accNumber;
	this->accType = accType;
	this->limit = limit;
	this->usrId = usrId;
}

void Account::setAccNumber (AccNumber*& accNumber) {
	this->accNumber = accNumber;
}

void Account::setAccType (AccType*& accType)
{
	this->accType = accType;
}

void Account::setLimit (Money*& limit)
{
	this->limit = limit;
}

void Account::setBalance (Money*& balance)
{
	this->balance = balance;
}

void Account::setUsrId (UsrId*& usrId)
{
	this->usrId = usrId;
}


Manager::Manager (UsrName* name, UsrPassword* password, ManType* manType, UsrMatric* usrMatric) throw (invalid_argument)
{
	if(name->getValue() == "")
		throw invalid_argument("Nome nao foi inicializado");
	if(password->getValue() == "")
		throw invalid_argument("Password nao foi inicializado");
	if(usrMatric->getValue() == -1)
		throw invalid_argument("Matricula nao foi inicializada");
	this->name = name;
	this->password = password;
	this->manType = manType;
	this->usrMatric = usrMatric;
}

void Manager::setManType (ManType*& manType){
	this->manType = manType;
}

void Manager::setUsrMatric (UsrMatric*& usrMatric){
	this->usrMatric = usrMatric;
}


Payment::Payment (AccNumber*& accNumber, PayDay*& payDay, Money*& payValue) throw (invalid_argument)
{
	if(accNumber->getValue() == -1)
		throw invalid_argument("Account Number nao foi inicializado");
	if(payDay->getValue() == -1)
		throw invalid_argument("Payment Day nao foi inicializado");
	if(payValue->getValue() == -1)
		throw invalid_argument("Payment Value nao foi inicializado");
	this->accNumber = accNumber;
	this->payDay = payDay;
	this->payValue = payValue;
}

void Payment::setAccNumber (AccNumber*& accNumber){
	this->accNumber = accNumber;
}

void Payment::setPayDay (PayDay*& payDay){
	this->payDay = payDay;
}

void Payment::setPayValue (Money*& payValue){
	this->payValue = payValue;
}
