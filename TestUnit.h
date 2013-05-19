#ifndef TESTUNIT_H
#define TESTUNIT_H

#include "BaseUnit.h"

template <typename infotype, typename classtype>
class Test{
	protected:
		virtual static void test(infotype) =0;
		static void setup()
		{
			object = new classtype;
		}
		static void tearDown()
		{
			delete object;
		}
	public:
		static void run(infotype testValue)
		{
			setup();
			test(testValue);
			tearDown();
		}

	protected:
		static classtype *object;
}

class TestUsrName	:public Test<string, UsrName>;
class TestUsrPassword	:public Test<string, UsrPassword>;
class TestUsrId		:public Test<int, UsrId>;
class TestUsrMatric	:public Test<int, UsrMatric>;
class TestUsrType	:public Test<bool, UsrType>;
class TestAccNumber	:public Test<int, AccNumber>;
class TestMoney		:public Test<float, Money>;
class TestPayCode	:public Test<int, PayCode>;
class TestPayDay	:public Test<int, PayDay>;

#endif
