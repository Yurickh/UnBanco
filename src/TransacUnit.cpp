#include "TransacUnit.h"

void CtrlTransacAdm :: withdraw(AccNumber accNumber, Money* with) throw (invalid_argument, PersError)
{
	PersSetBalance setBalance;
	PersGetBalance getBalance;

	if(with->getValue() <= 0)
		throw invalid_argument("Nao e possivel retirar quantidades nulas ou negativas de dinheiro");

	getBalance.execute(accNumber);
	Money actMoney(getBalance.getResult());

	if(actMoney.getValue() < with->getValue())
	{
		throw invalid_argument("Voce nao tem dinheiro o suficiente");
	}

	actMoney.setValue(actMoney.getValue() - with->getValue());
	setBalance.execute(accNumber, &actMoney);
}

void StubTransacAdm :: withdraw(AccNumber accNumber, Money* with) throw (invalid_argument, PersError)
{
	if(with->getValue() <= 0)
		throw invalid_argument("Nao e possivel retirar quantidades nulas ou negativas de dinheiro");
	if(accNumber.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

void CtrlTransacAdm :: deposit(AccNumber accNumber, Money* dep) throw (invalid_argument, PersError)
{
	PersSetBalance setBalance;
	PersGetBalance getBalance;

	if(dep->getValue() <= 0)
		throw invalid_argument("Nao e possivel depositar quantidades nulas ou negativas de dinheiro");

	getBalance.execute(accNumber);
	Money actMoney(getBalance.getResult());

	actMoney.setValue(actMoney.getValue() + dep->getValue());
	setBalance.execute(accNumber, &actMoney);
}

void StubTransacAdm :: deposit(AccNumber accNumber, Money* dep) throw (invalid_argument, PersError)
{
	if(dep->getValue() <= 0)
		throw invalid_argument("Nao e possivel depositar quantidades nulas ou negativas de dinheiro");
	if(accNumber.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);
}

PayCode* CtrlTransacAdm :: schedulePayment(AccNumber accNumber, Money* payValue, PayDay* date) throw (invalid_argument, PersError)
{
	Payment* payment;
	PayCode* payCode;

	PersGetLatestCode getLatestCode;
	PersNewPayment newPayment;

	if(payValue->getValue() <= 0)
		throw invalid_argument("Nao e possivel realizar pagamentos com quantidades nulas ou negativas de dinheiro");

	getLatestCode.execute();
	payCode = new PayCode(getLatestCode.getResult());

	payment = new Payment(accNumber, *payCode, *date, *payValue);
	newPayment.execute(payment);
	return payCode;
}

PayCode* StubTransacAdm :: schedulePayment(AccNumber accNumber, Money* payValue, PayDay* date) throw (invalid_argument, PersError)
{
	if(payValue->getValue() <= 0)
		throw invalid_argument("Nao e possivel realizar pagamentos com quantidades nulas ou negativas de dinheiro");
	if(accNumber.getValue() == 2)
		throw PersError(PERS_ERROR_MSG);

	return new PayCode(4);
}

void CtrlTransacAdm :: deletePayment(PayCode* payCode) throw (invalid_argument, PersError)
{
	PersDelPayment delPayment;

	delPayment.execute(payCode);
}

void StubTransacAdm :: deletePayment(PayCode* payCode) throw (invalid_argument, PersError)
{
	if(payCode->getValue() == 2)
		throw invalid_argument("O pagamento solicitado nao esta registrado.");
	if(payCode->getValue() == 1)
		throw PersError(PERS_ERROR_MSG);
}

list<Payment> CtrlTransacAdm :: fetchPayment() throw (PersError)
{
	PersFetchPayment fetchPayment;

	fetchPayment.execute();

	return fetchPayment.getResult();
}

list<Payment> StubTransacAdm :: fetchPayment() throw (PersError)
{
	list<Payment> payList;

	AccNumber accNum1(1), accNum2(2), accNum3(3);
	PayCode   payCode1(1), payCode2(2), payCode3(3);
	PayDay payDay1(4122017), payDay2(21042017), payDay3(25112017);
	Money payVal1(10.25), payVal2(100.0), payVal3(318);

	Payment n1(accNum1, payCode1, payDay1, payVal1);
	Payment n2(accNum2, payCode2, payDay2, payVal2);
	Payment n3(accNum3, payCode3, payDay3, payVal3);

	if(!(rand()%2))
		throw PersError(PERS_ERROR_MSG);

	payList.push_back(n1);
	payList.push_back(n2);
	payList.push_back(n3);

	return payList;
}
