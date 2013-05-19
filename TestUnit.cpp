#include "TestUnit.h"

static void TestUsrName::test(string usrName)
{
	cout << "Testado valor " << usrName << " em UsrName." << endl;
	try
	{
		object->setValue(usrName);
	}
	catch(invalid_argument except)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestUsrPassword::test(string usrPassword)
{
	cout << "Testado valor " << usrPassword << " em UsrPassword." << endl;
	try
	{
		object->setValue(usrPassword);
	}
	catch(invalid_argument except)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestUsrId::test(int usrId)
{
	cout << "Testado valor " << usrId << " em UsrId." << endl;
	try
	{
		object->setValue(usrId);
	}
	catch(invalid_argument)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestUsrMatric::test(int usrMatric)
{
	cout << "Testado valor " << usrMatric << " em UsrMatric." << endl;
	try
	{
		object->setValue(usrMatric);
	}
	catch(invalid_argument)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestUsrType::test(bool usrType)
{
	cout << "Testado valor " << ((!usrType)? "False" : "True") << " em UsrType." << endl;
	try
	{
		object->setValue(usrType);
	}
	catch(invalid_argument)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestAccNumber::test(int accNumber)
{
	cout << "Testado valor " << accNumber << " em AccNumber." << endl;
	try
	{
		object->setValue(accNumber);
	}
	catch(invalid_argument)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestMoney::test(float money)
{
	cout << "Testado valor " << money << " em Money." << endl;
	try
	{
		object->setValue(money);
	}
	catch(invalid_argument)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestPayCode::test(int payCode)
{
	cout << "Testado valor " << payCode << " em PayCode." << endl;
	try
	{
		object->setValue(payCode);
	}
	catch(invalid_argument)
	{
		cout << "\tErro: " << except << endl;
	}
}

static void TestPayDay::test(int PayDay)
{
	cout << "Testado valor " << usrId << " em UsrId." << endl;
	try
	{
		object->setValue(usrId);
	}
	catch(invalid_argument)
	{
		cout << "\tErro: " << except << endl;
	}
}
