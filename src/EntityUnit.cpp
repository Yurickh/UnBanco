#include "EntityUnit.h"

#include <cstdlib>

//=====================User========================

void User::setUsrName (const UsrName& name) {
	this->name = name;
}

void User::setUsrPassword (const UsrPassword& password){
	this->password = password;
}

//====================Customer=====================

Customer::Customer (const UsrName& name, const UsrPassword& password, const UsrId& usrId)
{
	this->name = name;
	this->password = password;
	this->usrId = usrId;
}

void Customer::setUsrId(const UsrId& usrId){
	this->usrId = usrId;
}

//====================Account=======================

Account::Account (const AccNumber& accNumber, const AccType& accType, const Money& limit, const Money& balance, const UsrId& usrId)
{
	this->accNumber = accNumber;
	this->accType = accType;
	this->limit = limit;
	this->balance = balance;
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

//====================Manager======================

Manager::Manager (const UsrName& name, const UsrPassword& password, const ManType& manType, const UsrMatric& usrMatric)
{
	this->name = name;
	this->password = password;
	this->manType = manType;
	this->usrMatric = usrMatric;
}

void Manager::setManType (const ManType& manType){
	this->manType = manType;
}

void Manager::setUsrMatric (const UsrMatric& usrMatric){
	this->usrMatric = usrMatric;
}

//====================Payment======================

Payment::Payment (const AccNumber& accNumber, const PayDay& payDay, const Money& payValue)
{
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
