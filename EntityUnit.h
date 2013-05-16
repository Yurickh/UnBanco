/*
User: Nome, Senha
	Cliente: ID
		Conta: Numero, Tipo, Limite, ID
			Pagamento: Codigo, numero, data, valor
	Gerente: Tipo, Matricula

*/
#ifndef Entity_Unit_H
#define Entity_Unit_H
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

class Client:public User{
		private:
				UsrId usrId;
		public:
				Client () {}
				Client (userId);
				UsrId getUsrId () const;
				void setUsrId (const UsrId&);
}

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

class Manager:public User{
		private:
				AccType	accType;
				UsrMaric usrMatric;
		public:
				Manager () {}
				Manager (accType, usrMatric);
				AccType getAccType () const;
				AccType setAccType (const AccType&);
				UsrMatric setUsrMatric() const;
				void UsrMatric setUsrMatric (const UsrMatric&);
}

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

#endif
