#include "TestUnit.h"

int main()
{
	Test<string, UsrName> 		usrName;
	Test<string, UsrPassword> 	usrPassword;
	Test<int, UsrId> 		usrId;
	Test<int, UsrMatric>		usrMatric;
	Test<bool, UsrType>		usrType;
	Test<int, AccNumber>		accNumber;
	Test<float, Money>		money;
	Test<int, PayCode>		payCode;
	Test<int, PayDay>		payDay;

	cout << "Unidade UsrName:" << endl;
	usrName.run("Yurick.Hauschild C", "Andre@Accioly-Lima");

	cout << endl << "Unidade UsrPassword:" << endl;
	usrPassword.run("andre0", "yurick66'@#$%6543");
	
	cout << endl << "Unidade UsrId:" << endl;
	usrId.run(500, -200);

	cout << endl << "Unidade UsrMatric:" << endl;
	usrMatric.run(12345, 987654321);

	cout << endl << "Unidade UsrType:" << endl;
	usrType.run(false, "independe o que eu for colocar aqui, sempre irá passar no teste, porque equivale a true ou false.");

	cout << endl << "Unidade AccNumber:" << endl;
	accNumber.run(1234, -12);

	cout << endl << "Unidade Money:" << endl;
	money.run(14.79, 1.0/0.0);

	cout << endl << "Unidade PayCode:" << endl;
	payCode.run(200, -50);

	cout << endl << "Unidade PayDay:" << endl;
	payDay.run(4122015, 31022015);

	cout << endl << "Finalizando unidade de testes." << endl;

	return 0;
}
