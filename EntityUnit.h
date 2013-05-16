/*
User: Nome, Senha
	Cliente: ID
		Conta: Numero, Tipo, Limite, ID
			Pagamento: Codigo, numero, data, valor
	Gerente: Tipo, Matricula

*/
#ifndef Entity_Unit_H
#define Entity_Unit_H

/** Define a Entidade Usuario.
Define os atributos de um usuario.
*/
class User{
		private:
				Name name;
				Password password;
		public:
				User () {}
				User (name, password);
				Name getName() const;
				void setName(const Name&);
				Password getPassword() const;
				void setPassword(const Password&);				
}
/*Define a Entidade Cliente.
Cliente e uma classe herdada de Usuario que serve para definir um cliente e o que um cliente pode fazer.
*/
class Client:public User{
		private:
				UsrId usrId;
		public:
				Client () {}
				Client (userId);
				UsrId getUsrId () const;
				void setUsrId (const UsrId&);
}
/** Classe da entidade Conta.
Serve para definir uma conta e seus atributos para manipulacoes em geral.
*/
class Account:public Client{
		private:
				AccNumber accNumber;
				AccType accType;
				Money limit;
				UsrId usrId;
		public:
				Account account;
				Account (accNumber, accType, limit, usrId);
				AccNumber getAccNumber () const;
				void setAccNumber (const AccNumber&);
				AccType getAccType () const;
				void setAccType (const AccType&);
				Money getMoney () const;
				void setMoney (const Money&);
				UsrId getUsrId() const;
				void UsrId(const UsrId&);
}
/** Define a Entidade Gerente.
Definir os atibutos relacionados aos gerentes, que sao um tipo de usuario.
*/
class Manager:public User{
		private:
				AccType	accType;
				UsrMaric usrMatric;
		public:
				Manager () {}
				Manager (accType, usrMatric);
				AccType getAccType () const;
				void AccType setAccType (const AccType&);
				UsrMatric getUsrMatric() const;
				void UsrMatric setUsrMatric (const UsrMatric&);
}
/** Classe da Entidade Pagamento.
Serve para definir um Pagamento e seus atributos para manipulacoes em geral.
*/
class Payment:public Account{
		private:
				PayNumber payNumber;
				PayCode payCode;
				PayDay payDay;
				PayValue payValue;						
				
		public:
				Payment () {}
				Payment (payNumber, payDay, payValue);
				PayCode getPayCode () const;
				const PayCode setPayCode (const PayCode&);
				PayNumber getPayNumber () const;
				void PayNumber setPayNumber (const PayNumber&);
				PayDay getPayDay () const;
				void setPayDay (const PayDay&);
				PayValue getPayValue () const;
				void setPayValue (const PayValue&);
}

/**Define os gets.
Os gets servem para retornar o valor assimilado em uma determinada variavel privada.
*/

inline Name User::getName() const{
		return name;
} 

inline Password User::getPassword() const{
		return password;
}

inline AccType Manager::getAccType() const{
		return accType;
}

inline UsrMatric Manager::getUsrMatric() const{
		return usrMatric;
}

inline UsrId Client::getUsrId ()const{
		return usrId;
}

inline  AccNumber Account:getAccNumber() const{
		return accNumber;
}

inline AccType Account::getAccType() const{
		return accType;
}

inline Money Account::getMoney() const{
		return limit;
}

inline UsrId Account::getUsrId() const{
		return usrId;
}

inline PayDay Payment::getPayDay*() const{
		return payDay;
}

inline PayCode Payment::getPayCode() const{
		return payCode;
}

inline PayNumber Payment::getPayNumber() const{
		return payNumber;
}

#endif
