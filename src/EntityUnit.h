#ifndef ENTITY_UNIT_H
#define ENTITY_UNIT_H

#include "BaseUnit.h"

/** Usuário; Base de derivação das classes Customer e Manager.
Herdam dessa classe as duas maiores classes de usuários do sistema, os Clientes e os Gerentes.
*/
class User{
	protected:
		/** Nome do usuário em questão. */
		UsrName name;
		/** Senha do usuário em questão */
		UsrPassword password;

	public:
		/** Método que recupera o valor contido no campo name. 
			O valor é retornado, e o atributo não é modificado no processo. */
		UsrName getName() const;
		/** Método que define o valor do atributo name. */
		void setUsrName(const UsrName&);
		/** Método que recupera o valor contido no campo password. 
			O valor é retornado, e o atributo não é modificado no processo. */
		UsrPassword getPassword() const;
		/** Método que define o valor do atributo password. */
		void setUsrPassword(const UsrPassword&);
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
		/** O ID de um cliente é sua chave de identificação exclusiva dentro do sistema. 
			Nenhum cliente terá um ID igual a outro. */
		UsrId usrId;


	public:
		/** Construtor base de Customer.
			Define os valores internos da classe automaticamente. */
		Customer (const UsrName&, const UsrPassword&, const UsrId&);

		/** Método que recupera o valor contido no campo usrId. 
			O valor é retornado, e o atributo não é modificado no processo. */
		UsrId getUsrId () const;
		/** Método que define o valor do atributo usrId. */
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
		/** O número de uma conta é a sua chave de identificação exclusiva dentro do sistema.
			Contas nunca compartilharão o mesmo número de conta. */
		AccNumber accNumber;
		/** Define se a conta será normal ou especial.
			Privilégios especiais serão fornecidos para contas especiais. */
		AccType accType;
		/** Limite da conta. */
		Money limit;
		/** Saldo da conta */
		Money balance;
		/** ID do usuário que é proprietário desta conta. */
		UsrId usrId;

	public:
		/** Construtor base de Account.
			Define os valores internos da classe automaticamente. */
		Account (const AccNumber&, const AccType&, const Money&, const Money&, const UsrId&);

		/** Método que retorna o valor contido no atributo accNumber.
			O valor será retornado e o atributo não será modificado. */
		AccNumber getAccNumber () const;
		/** Método que define o valor do atributo accNumber. */
		void setAccNumber (const AccNumber&);

		/** Método que retorna o valor contido no atributo accType.
			O valor será retornado e o atributo não será modificado. */
		AccType getAccType () const;
		/** Método que define o valor do atributo accType. */
		void setAccType (const AccType&);

		/** Método que retorna o valor contido no atributo limit.
			O valor será retornado e o atributo não será modificado. */
		Money getLimit () const;
		/** Método que define o valor do atributo limit. */
		void setLimit (const Money&);

		/** Método que retorna o valor contido no atributo balance.
			O valor será retornado e o atributo não será modificado. */
		Money getBalance() const;
		/** Método que define o valor do atributo balance. */
		void setBalance (const Money&);

		/** Método que retorna o valor contido no atributo usrId.
			O valor será retornado e o atributo não será modificado. */
		UsrId getUsrId() const;
		/** Método que define o valor do atributo usrId. */
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
		/** Tipo de gerente.
			Pode ser definido como normal ou especial (administrador). Neste caso, o gerente terá privilégios especiais. */
		ManType manType;
		/** A matrícula do gerente será sua chave de identificação dentro do sistema.
			Ela será única ao gerente, o que quer dizer que quaisquer dois gerentes nunca terão a mesma matrícula. */
		UsrMatric usrMatric;


	public:
		/** Construtor base de Manager.
			Define automaticamente os valores internos da classe. */
		Manager (const UsrName&, const UsrPassword&, const ManType&, const UsrMatric&);

		/** Método que recupera o valor contido no atributo manType.
			O valor será retornado e o atributo não sofrerá nenhum tipo de alteração. */
		ManType getManType () const;
		/** Método que define o valor do atributo manType. */
		void setManType (const ManType&);

		/** Método que recupera o valor contido no atributo usrMatric.
			O valor será retornado e o atributo não sofrerá nenhum tipo de alteração. */
		UsrMatric getUsrMatric() const;
		/** Método que define o valor do atributo usrMatric. */
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
		/** Número de conta associada.
			O número de conta associará a que conta este pagamento está vinculado. */
		AccNumber accNumber;
		/** O código de pagamento é a chave de identificação do Payment dentro do sistema.
			Nenhum pagamento terá um código igual a outro. */
		PayCode payCode;
		/** Armazena a data em que foi agendada o pagamento.
			Datas anteriores a 2013 (ano de produção desta biblioteca) não serão considerados. */
		PayDay payDay;
		/** Armazena o valor do pagamento em si. */
		Money payValue;				

	public:
		/** Construtor base de Payment.
			Define todos os atributos internos à classe automaticamente. */
		Payment (const AccNumber&, const PayCode&, const PayDay&, const Money&);

		/** Método que recupera o valor contido no atributo payCode.
			O valor será retornado e o atributo não sofrerá nenhum tipo de alteração. */
		PayCode getPayCode () const;
		/** Método que define o valor no atributo payCode. */
		const PayCode setPayCode (const PayCode&);

		/** Método que recupera o valor contido no atributo accNumber.
			O valor será retornado e o atributo não sofrerá nenhum tipo de alteração. */
		AccNumber getAccNumber () const;
		/** Método que define o valor no atributo payCode. */
		void setAccNumber (const AccNumber&);

		/** Método que recupera o valor contido no atributo payDay.
			O valor será retornado e o atributo não sofrerá nenhum tipo de alteração. */
		PayDay getPayDay () const;
		/** Método que define o valor no atributo payCode. */
		void setPayDay (const PayDay&);

		/** Método que recupera o valor contido no atributo payValue.
			O valor será retornado e o atributo não sofrerá nenhum tipo de alteração. */
		Money getPayValue () const;
		/** Método que define o valor no atributo payCode. */
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

inline Money Payment::getPayValue() const{
	return payValue;
}

#endif
