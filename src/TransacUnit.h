#ifndef TRANSACUNIT_H
#define TRANSACUNIT_H

#include <stdexcept>
#include "EntityUnit.h"
#include "PersUnit.h"

using namespace std;

class TransacAdm
{
	public:
		virtual void withdraw(AccNumber, Money*) throw (invalid_argument, PersError) = 0;
		virtual void deposit(AccNumber, Money*) throw (invalid_argument, PersError) = 0;
};

class StubTransacAdm : public TransacAdm
{
	public:
		void withdraw(AccNumber, Money*) throw (invalid_argument, PersError);
		void deposit(AccNumber, Money*) throw (invalid_argument, PersError);
};

#endif
