#include "EntityUnit.h"
 
User::User (UsrName name, UsrPassword password)
{
		this->name = name;
		this->password = password;
}

void User::setName (const UsrName& name) {
		this->name = name;
}

void User::setPassword (const UsrPassword& password){
		this->password = password;
}


Client::Client (UsrId usrId)
{
		this->usrId = usrId;
}

void Client::setUsrId(const UsrId& usrId){
		this->usrId = usrId;
}


Account::Account (AccNumber accNumber, AccType accType, Money limit, UsrId usrId)
{
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

void Account::setMoney (const Money& limit)
{
		this->limit = limit;
}

void Account::setUsrId (const UsrId& usrId)
{
		this->usrId = usrId;
}


Manager::Manager (AccType accType, UsrMatric usrMatric)
{
		this->accType = accType;
		this->usrMatric = usrType;
}

void Manager::setAccType (const AccType& accType){
		this->accType = accType;
}

void Manager::setUsrMatric (const UsrMatric& usrMatric){
		this->usrMatric = usrMatric;
}


Payment::Payment (PayNumber payNumber, PayDay payDay, PayValue payValue){
		this->payNumber = payNumber;
		this->payDay = payDay;
		this->payValue = payValue;
}

void Payment::setPayNumber (const PayNumber& payNumber){
		this->payNumber = payNumber;
}

void Payment::setPayDay (const PayDay& payDay){
		this->payDay = payDay;
}

void Payment::setPayValue (const PayDay& payDay){
		this->payValeu = payValue;
}
