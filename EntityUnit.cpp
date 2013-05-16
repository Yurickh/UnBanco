#include "EntityUnit.h"

//Classe usuario>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
User::User (Name name, Password password): name(name), matricula(matricula) {}

void User::setName (const Name& name) {
		this->name = name;
}

void User::setPassword (const Password& password){
		this->password = password;
}

//Classe Cliente>>>>>>>>>>>>>>>>>>>>>>>>>>>>

Client::Client (usrId): usrId(usrId);

void Client::setUsrId(const UsrId& usrId){
		this->usrId = usrId;
}

//Classe Conta>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Account::Account (AccNumber accNumber, AccType accType, Money limit, UsrId usrId): accNumber(accNumber), accType(accType), limit(limit), usrId(usrId){}

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

//Classe Gerente>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Manager::Manager (AccType accType, UsrMatric usrMatric): accType(accType), usrMatric(usrMatric){}

void Manager::setAccType (const AccType& accType){
		this->accType = accType;
}

void Manager::setUsrMatric (const UsrMatric& usrMatric){
		this->usrMatric = usrMatric;
}

//Classe Pagamento>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Payment::Payment (PayNumber payNumber, PayDay payDay, PayValue payValue): payNumber(payNumber), payDay(payDay), payValue(payValue) {}

void Payment::setPayNumber (const PayNumber& payNumber){
		this->payNumber = payNumber;
}

void Payment::setPayDay (const PayDay& payDay){
		this->payDay = payDay;
}

void Payment::setPayValue (const PayDay& payDay){
		this->payValeu = payValue;
}

