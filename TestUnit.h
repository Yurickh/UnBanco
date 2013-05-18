#ifndef TESTUNIT_H
#define TESTUNIT_H

#include "BaseUnit.h"
using namespace std;

class Test{
	protected:
		virtual static setup();
		virtual static run();
		virtual static tearDown;
}

class TestUsrName{
	private:
		UsrName* usrName;
		string testStr;
	public:
		static execute(string);
};

class TestUsrPassword:public Test{
	private:
		UsrPassword* usrPassword;
		string testStr;
	public:
		static execute(string);
);

class TestUsrId{
	private:
		UsrId* usrId;
		int testInt;
	public:
		static execute(int);
};

class TestUsrMatric{
	private:
		UsrMatric* usrMatric;
		int testInt;
	public:
		static execute(int);
};

class TestUsrType{
	private:
		UsrType* usrType;
		bool tesBool;
	public:
		static execute(bool);
};

class TestAccNumber{
	private:
		AccNumber* accNumber;
		int testInt;
	public:
		static execute(int);
};

class TestMoney{
	private:
		Money* money;
		float testFloat;
	public:
		static execute(float);
};

class PayCode{
	private:
		PayCode* payCode;
		int testInt;
	public:
		static execute(int);
};

class TestPayDay{
	private:
		PayDay* payDay;
		int testInt;
	public:
		static execute(int);
};

#endif
