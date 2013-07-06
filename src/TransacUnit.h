#ifndef TRANSACUNIT_H
#define TRANSACUNIT_H

#include <stdexcept>
#include <list>
#include <cstdlib>
#include "EntityUnit.h"
#include "PersUnit.h"

using namespace std;

class TransacAdm
{
	public:
		virtual void withdraw(AccNumber, Money*) throw (invalid_argument, PersError) = 0;
		virtual void deposit(AccNumber, Money*) throw (invalid_argument, PersError) = 0;

		virtual PayCode* schedulePayment(AccNumber, Money*, PayDay*) throw (invalid_argument, PersError) = 0;
		virtual void deletePayment(PayCode*) throw (invalid_argument, PersError) = 0;
		
		virtual list<Payment> fetchPayment(void) throw (PersError) = 0;
};

class StubTransacAdm : public TransacAdm
{
	public:
		void withdraw(AccNumber, Money*) throw (invalid_argument, PersError);
		void deposit(AccNumber, Money*) throw (invalid_argument, PersError);

		PayCode* schedulePayment(AccNumber, Money*, PayDay*) throw (invalid_argument, PersError);
		void deletePayment(PayCode*) throw (invalid_argument, PersError);

		list<Payment> fetchPayment(void) throw (PersError);
};

#endif
