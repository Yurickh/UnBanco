#include "TestUnit.h"
int main ()
{
	string name;
	string pasword;
	int id;
	int matric;
	int accNumber;	
	int PayCode;
	int Payday;
	bool type;
	float money;

	usrName.setValue = "Joao Almeida";
	TestUsrName.execute(name);
	name = "Joao Almeida!!!";
	TestUsrName.execute(name);

	
	password = "joao12";
	TestUsrPassword.execute(password);
	usrPassword = "joao123";
	TestUsrPassword.execute(password);


	id = 1000;
	TestUsrId.execute(id);
	usrId = -1000;
	TestUsrId.execute(id);


	matric = 12345;
	TestUsrMatric.execute(matric);
	usrMatric = 12345678;
	TestUsrMatric.execute(matric);


	type = 0;	
	TestUsrType.execute(type);	
	typ= 1;
	TestUsrType.execute(type);


	accNumber = 1234;
	TestAccNumber.execute(accNumber);
	accNumber = 100000;
	TestAccNumber.execute(accNumber);


	money = 100;
	TestMoney.execute(money);
	money = -100;
	TestMoney.execute(money);


	payCode = 1000;
	TestPayCode.execute(payCode);
	payCode = 99999999;
	TestPayCode.execute(payCode);


	date = 10082013;
	TestPayDay.execute(date);
	date = 10081990;
	TestPayDay.execute(date);

	return 0;
}
