#ifndef TRANSACUNIT_H
#define TRANSACUNIT_H

#include <stdexcept>
#include <list>
#include <cstdlib>
#include "EntityUnit.h"
#include "PersUnit.h"

using namespace std;

/** Interface da camada de apresentação com o negócio responsável pela administração de dados de transação. */
class TransacAdm
{
	public:
		/** Executa a retirada de dinheiro */
		virtual void withdraw(AccNumber, Money*) throw (invalid_argument, PersError) = 0;
		/** Executa um depósito */
		virtual void deposit(AccNumber, Money*) throw (invalid_argument, PersError) = 0;

		/** Agenda um pagamento */
		virtual PayCode* schedulePayment(AccNumber, Money*, PayDay*) throw (invalid_argument, PersError) = 0;
		/** Deleta um pagamento agendado */
		virtual void deletePayment(PayCode*) throw (invalid_argument, PersError) = 0;
		
		/** Recupera uma lista de todos os pagamentos registrados */
		virtual list<Payment> fetchPayment(void) throw (PersError) = 0;

		inline void setGetBalance(PersGetBalance*);
		inline void setSetBalance(PersSetBalance*);
};

/** Classe de negócio responsável pela administração de dados de pegamento e transações */
class CtrlTransacAdm : public TransacAdm
{
	public:
		void withdraw(AccNumber, Money*) throw (invalid_argument, PersError);
		void deposit(AccNumber, Money*) throw (invalid_argument, PersError);

		PayCode* schedulePayment(AccNumber, Money*, PayDay*) throw (invalid_argument, PersError);
		void deletePayment(PayCode*) throw (invalid_argument, PersError);

		list<Payment> fetchPayment(void) throw (PersError);
};

/** Stub utilizado para simular o funcionamento da camada de negócio */
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
