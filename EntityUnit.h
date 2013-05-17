#ifndef ENTITY_UNIT_H
#define ENTITY_UNIT_H

/** Usuário; Base de derivação das classes Customer e Manager.
Herdam dessa classe as duas maiores classes de usuários do sistema, os Clientes e os Gerentes.
*/
class User{
	protected:
		UsrName name;
		UsrPassword password;

		User();
	public:
		UsrName getName() const;
		void setName(const UsrName&);
		UsrPassword getPassword() const;
		void setPassword(const UsrPassword&);
};

inline UsrName User::getName() const{
		return name;
} 

inline UsrPassword User::getPassword() const{
		return password;
}

/** Cliente; Onde ficarão armazenados os dados do usuário padrão do sistema.
O Customer (Cliente) terá acesso a uma ou mais contas através de um UsrId único. Através dessa(s) conta(s), é capaz de realizar transações.
*/
class Customer:public User{
	private:
		UsrId usrId;
	public:
		Customer (const UsrName& name, const UsrPassword& password, const UsrId&) throw (invalid_argument);

		UsrId getUsrId () const;
		void setUsrId (const UsrId&);
};

inline UsrId Customer::getUsrId ()const{
		return usrId;
}

/** Conta; Onde ficarão armazenados os dados de conta de um cliente.
Através de uma conta é possível acessar o módulo de Transações.
*/
class Account{
	private:
		AccNumber accNumber;
		AccType accType;
		Money limit;
		Money balance;
		UsrId usrId;
	public:
		Account (const AccNumber&, const AccType&, const Money&, const UsrId&) throw (invalid_argument);

		AccNumber getAccNumber () const;
		void setAccNumber (const AccNumber&);

		AccType getAccType () const;
		void setAccType (const AccType&);

		Money getLimit () const;
		void setLimit (const Money&);

		Money getBalance() const;
		void setBalance (const Money&);

		UsrId getUsrId() const;
		void setUsrId(const UsrId&);
};

inline UsrId Account::getUsrId() const{
	return usrId;
}

inline AccType Account::getAccType() const{
	return accType;
}

inline Money Account::getLimit() const{
	return limit;
}

inline Money Account::getBalance() const{
	return balance;
}

inline AccNumber Account::getAccNumber() const{
	return accNumber;
}

/** Gerente; Onde ficarão armazenados os dados de usuários com privilégios administrativos sobre o sistema.
Através desta classe é possível acessar o módulo de UsrManage e modificar dados de outros usuários.
*/
class Manager:public User{
	private:
		ManType	manType;
		UsrMatric usrMatric;
	public:
		Manager (const UsrName&, const UsrPassword&, const ManType&, const UsrMatric&) throw (invalid_argument);

		ManType getManType () const;
		void setManType (const ManType&);

		UsrMatric getUsrMatric() const;
		void setUsrMatric (const UsrMatric&);
};

inline ManType Manager::getManType() const{
	return manType;
}

inline UsrMatric Manager::getUsrMatric() const{
	return usrMatric;
}

/** Pagamento; Onde ficarão armazenados dados sobre pagamentos a serem realizados.
Esta classe armazenará os dados de conta bem como a data agendada de pagamentos futuros.
*/
class Payment{
	private:
		AccNumber accNumber;
		PayCode payCode;
		PayDay payDay;
		Money payValue;				

	public:
		Payment (const AccNumber&, const PayDay&, const Money&) throw (invalid_argument);

		PayCode getPayCode () const;
		const PayCode setPayCode (const PayCode&);

		AccNumber getAccNumber () const;
		void setAccNumber (const AccNumber&);

		PayDay getPayDay () const;
		void setPayDay (const PayDay&);

		Money getPayValue () const;
		void setPayValue (const Money&);
};

inline AccNumber Payment::getAccNumber() const{
	return accNumber;
}

inline PayCode Payment::getPayCode() const{
	return payCode;
}

inline PayDay Payment::getPayDay() const{
	return payDay;
}

#endif
