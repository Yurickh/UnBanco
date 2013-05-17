#ifndef _BASEUNIT_H_
#define _BASEUNIT_H_

#include <string>
#include <stdexcept>

/**	A base de derivação de todas as classes de tipos básicos.
	Suas diferentes instâncias servem de base para a construção de todos os outros tipos básicos.
	Seus métodos setValue() e getValue() garantem o acesso ao seu parâmetro Value.
*/
template <typename baseType>
class UnitBase
{
	private:
		virtual void validate(const baseType& value) throw (invalid_argument a) = 0;
	protected:
		baseType value;
	public:
		void setValue(const baseType& value) throw (invalid_argument)
		{
			validate(value);
			this->value = value;
		}
		inline baseType getValue() const
		{
			return value;
		}
};

/**	Define o nome de um User (Customer ou Manager).
	Este tipo serve para regular o login de usuários em geral.
*/
class UsrName:public UnitBase<string>
{
	private:
		void validate(const string&) throw (invalid_argument);
	public:
		Name(string) throw (invalid_argument);
};

/** 	Define a senha de um User (Customer ou Manager).
	Este tipo básico tem a função de controlar o login de usuários em geral.
*/
class UsrPassword:public UnitBase<int>
{
	private:
		void validate(int) throw (invalid_argument);
	public:
		Password(int) throw (invalid_argument);
};

/**	Define o ID de um Customer.
	Tem a função de identificar de forma única um Customer, independentemente do seu tipo de conta.
*/
class UsrId: public UnitBase<int>
{
	private:
		void validate(int) throw (invalid_argument);
	public:
		Id(int) throw (invalid_argument);
};

/** 	Define a matrícula de um Manager.
 	Tem a função de identificar de forma única um Manager, seja ele Administrador ou Gerente.
*/
class UsrMatric:public UnitBase<int>
{
	private:
		void validate(int) throw (invalid_argument);
	public:
		Matric(int) throw (invalid_argument);
};

/**	Codifica tipos de conta.
	Possui duas utilizações:
	AccType: Codifica tipos de conta (Normal / Especial)
 	ManType: Codifica tipos de manager (Gerente / Administrador)
*/
class UsrType : public UnitBase<bool>
{
	private:
		void validate(bool value) throw (invalid_argument);
	public:
		GType(bool);
};

typedef UsrType AccType; ///\typedef Instancia GType para contas.
typedef UsrType ManType; ///\typedef Instancia GType para Managers.

/**	Define o número da conta de um Customer (Cliente).
	Este tipo básico tem a função de atribuir a cada conta um numero unico, identificando-a.
*/
class AccNumber:public UnitBase<int>
{
	private:
		void validate(int) throw (invalid_argument);
	public:
		AccNumber(int) throw (invalid_argument);
};

/**	Define o limite da conta de um Customer (Cliente).
	Atribui a cada conta um limite, limitando a utilização do crédito junto ao banco.
*/
class Money:public UnitBase<float>
{
	private:
		void validate(float) throw (invalid_argument);
	public:
		Money(float) throw (invalid_argument);
};

/**	Define um número de identificação para cada pagamento.
	Atribui a cada pagamento um código, de forma a identificá-lo.
*/
class PayCode:public UnitBase<int>
{
	private:
		void validate(int) throw (invalid_argument);
	public:
		PayCode(int) throw (invalid_argument);
};

/**	Define a data do pagamento.
	Guarda a data de um pagamento. Dia, mês e ano devem ser acessados através dos atributos day, month, year.
*/
class PayDay:public UnitBase<int>
{
	private:
		void validate(const& int) throw (invalid_argument);
	public:
		PayDay(int) throw (invalid_argument);
		inline int day();//\fn retorna o dia.
		inline int month();//\fn retorna o mês.
		inline int year();//\fn Retorna o ano.
};


inline int PayDay::year()
{
	return value%10000; //Retorna os quatro ultimos digitos de value.
}

inline int PayDay::month()
{
	return (value/10000)%100; // Retorna os dois digitos correspondentes ao mês.
}

inline int PayDay::day()
{
	return value/1000000; //Retorna os dois primeiros dígitos.
}

/**	Define o valor do pagamento.
	Recorda o valor de um pagamento.
*/
class PayValue:public UnitBase<float>
{
	private:
		void validate(float) throw (invalid_argument);
	public:
		PayValue(float) throw (invalid_argument);
};

#endif
