#include "BaseUnit.h"
#include "EntityUnit.h"
 
User::User(const UsrName& name, const UsrPassword& password)
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


Customer::Customer (const UsrId& usrId)
{
		this->usrId = usrId;
}

void Customer::setUsrId(const UsrId& usrId){
		this->usrId = usrId;
}


Account::Account (const AccNumber& accNumber, const AccType& accType, const Money& limit, const UsrId& usrId)
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


Manager::Manager (const ManType& manType, const UsrMatric& usrMatric)
{
		this->manType = manType;
		this->usrMatric = usrMatric;
}

void Manager::setManType (const ManType& manType){
		this->manType = manType;
}

void Manager::setUsrMatric (const UsrMatric& usrMatric){
		this->usrMatric = usrMatric;
}


Payment::Payment (const AccNumber& accNumber, const PayDay& payDay, const Money& payValue){
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

void Payment::setPayValue (const Money& money){
		this->payValue = payValue;
}
