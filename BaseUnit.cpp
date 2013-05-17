#define NORMAL_MAN	false
#define ADMIN_MAN	true
#define NORMAL_ACC	false
#define SPECIAL_ACC	true
#include "BaseUnit.h"

using namespace std;

UsrName::UsrName ()
{
	this->value = "";
}

UsrName::UsrName (const string& name) throw (invalid_argument)
{
	validate(name);
	this->value = name;
}

void UsrName::validate (const string& name) throw (invalid_argument)
{
	int i;
	if (name.size() == 0)
		throw invalid_argument ("Nenhum caractere digitado em nome.");
	if (name.size() > 20)
		throw invalid_argument ("Nome com mais de 20 caracteres.");
	for (i=0; i<name.size() ;i++)
	{
		if ( !isspace (name.at(i)) && !isalpha (name.at(i)) && name.at(i) != '.' )
			throw invalid_argument ("Nome com caracteres invalidos.");
	}
}

UsrMatric::UsrMatric ()
{
	this->value = -1;
}

UsrMatric::UsrMatric (const int& matric) throw (invalid_argument)
{
	validate(matric);
	this->value = matric;
}

void UsrMatric::validate(const int& matric) throw (invalid_argument)
{
	if (matric < 0 || matric > 99999)
		throw invalid_argument ("Matricula invalida, numero fora do alcance.");
}

UsrPassword::UsrPassword ()
{
	this->value = "";
}

UsrPassword::UsrPassword (const string& password) throw (invalid_argument)
{
	validate (password);
	this->value = password;
}

void UsrPassword::validate (const string& password) throw (invalid_argument)
{
	int i;
	if (password.size() > 6)
		throw invalid_argument ("A senha deve ter ate seis caracteres.");
	if (password.size() == 0)
		throw invalid_argument ("A senha deve conter pelo menos um caractere.");
	for (i=0; i<6; i++)
	{
		if (!isdigit(password.at(i)) && !isalpha(password.at(i)))
			throw invalid_argument("A senha deve ser formada apenas por caracteres alfanumericos.");
	}
}

AccNumber::AccNumber()
{
	this->value = -1;
}

AccNumber::AccNumber (const int& accNumber) throw (invalid_argument)
{
	validate (accNumber);
	this->value = accNumber;
}

void AccNumber::validate (const int& accNumber) throw (invalid_argument)
{
	if(accNumber < 0 || accNumber > 9999)
		throw invalid_argument ("Numero da conta com numero fora do alcance.");
}

Money::Money()
{
	this->value = -1;
}

Money::Money (const float& money) throw (invalid_argument)
{
	validate (money);
	this->value = money;
}

void Money::validate (const float& money) throw (invalid_argument)
{
	if(!(std::isnormal(money)) || money < 0)
		throw invalid_argument ("Nao e possivel executar esta operacao com a dada quantidade de dinheiro");
}

PayCode::PayCode()
{
	this->value = -1;
}

PayCode::PayCode (const int& payNumber) throw (invalid_argument)
{
	validate (payNumber);
	this->value = payNumber;
}

void PayCode::validate (const int& payNumber) throw (invalid_argument)
{
	if(payNumber <0 || payNumber > 999999)
		throw invalid_argument("Numero do pagamento com numero fora do alcance.");
}

UsrType::UsrType()
{
	this->value = NORMAL_ACC;
}

UsrType::UsrType (const bool& usrType) throw (invalid_argument)
{
	validate (usrType);
	this->value = usrType;
}

void UsrType::validate (const bool& usrType) throw (invalid_argument)
{
	if(usrType != NORMAL_ACC || usrType != SPECIAL_ACC)
		throw invalid_argument("Valor inesperado para UsrType");
}

UsrId::UsrId()
{
	this->value = -1;
}

UsrId::UsrId (const int& usrId) throw (invalid_argument)
{
	validate (usrId);
	this->value = usrId;
}

void UsrId::validate (const int& usrId) throw (invalid_argument)
{
	if(usrId < 0)
		throw invalid_argument ("A Id do usuário não pode ser menor que zero.");
}

PayDay::PayDay()
{
	this->value = -1;
}

PayDay::PayDay (const int& date) throw (invalid_argument)
{
	validate (date);
	this->value = date;
}

void PayDay::validate (const int& date) throw (invalid_argument)
{
	int day, month, year;

	day = date/1000000;
	year = date%10000;
	month = (value/10000)%100;

	if(day <= 0 || day>31)
		throw invalid_argument("Dia invalido");
	else
	{
		if(month == 2 && day > 29)
				throw invalid_argument("Dia invalido");
		else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
				throw invalid_argument("Dia invalido");
	}

	if(month <=0 || month >12)
		throw invalid_argument("Mes invalido");

	if(year<=2012)
		throw invalid_argument("Ano invalido");
}
