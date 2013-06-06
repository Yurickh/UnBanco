#ifndef TESTUNIT_H
#define TESTUNIT_H

#include <iostream>
#include "BaseUnit.h"

/**Template que irá gerar todas as classes de teste.
A partir desse template, todas as classes de teste podem ser modeladas, com seus respectivos métodos setup(), tearDown() e run().
*/
template <typename infoType, typename classType>
class Test{
	private:
		void test(infoType);
		void setup();
		void tearDown();
	public:
		void run(const infoType&, const infoType&);

	protected:
		classType *object;
};

template <typename infoType, typename classType>
void Test<infoType, classType>::test(infoType test)
{
	cout << "Testando valor " << test << "." << endl;
	try
	{
		object->setValue(test);
	}
	catch(invalid_argument except)
	{
		cout << "\tErro: " << except.what() << endl;
	}
}

template <typename infoType, typename classType>
void Test<infoType, classType>::setup()
{
	object = new classType;
}

template <typename infoType, typename classType>
void Test<infoType, classType>::tearDown()
{
	delete object;
}

template <typename infoType, typename classType>
void Test<infoType, classType>::run(const infoType& testValue1, const infoType& testValue2)
{			
	setup();
	test(testValue1);
	test(testValue2);
	tearDown();
}

#endif
