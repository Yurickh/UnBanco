#ifndef TESTUNIT_H
#define TESTUNIT_H

#include "BaseUnit.h"

template <typename infotype, typename classtype>
class Test{
	protected:
		virtual static void test(infotype);
		virtual static void setup() = 0;
		virtual static void tearDown() = 0;
	public:
		static void run() = 0;

	protected:
		static classtype *object;
		static infotype testValue;
}

class TestUsrName:public Test{
	private:
		static void test(string);
		static UsrName *usrName;
		static string valid;
		static string invalid;
}

class TestUsrPassword:public Test{
	private:
		static void test(string);
		static UsrPassword *usrPassword;
		static string valid;
		static string invalid;
}

class TestUsrId{
	private:
		static void test(string);
		static UsrId *usrId;
		static int valid;
		static int invalid;
}

class TestUsrMatric{
	private:
		static void test(int);
		static UsrMatric *usrMatric;
		static int valid;
		static int invalid;
}

class TestUsrType{
	private:
		static UsrType *usrType;
		static bool valid;
		static bool invalid;
}

class TestAccNumber{
	private:
		static AccNumber *accNumber;
		static int valid;
		static int invalid;
}

class TestMoney{
	private:
		static Money *money;
		static float valid;
		static float invalid;
}

class TestPayCode{
	private:
		static PayCode *payCode;
		static int valid;
		static int invalid;
}

class TestPayDay{
	private:
		static PayDay *payDay;
		static int valid;
		static int invalid;
}

#endif
