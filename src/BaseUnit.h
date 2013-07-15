#ifndef BASE_UNIT_H
#define BASE_UNIT_H

#define NORMAL		false
#define ADMIN		true
#define SPECIAL		true

#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

using namespace std;

/**	A base de derivação de todas as classes de tipos básicos.
	Suas diferentes instâncias servem de base para a construção de todos os outros tipos básicos.
*/
template <typename baseType>
class UnitBase
{
	private:
		/** Método que valida automaticamente o valor a ela fornecido contra o padrão do sistema. */
		virtual void validate(const baseType& value) throw (invalid_argument) = 0;
	protected:
		/** O valor comportado pela unidade. Seu tipo varia de acordo com a forma que o template é instanciado. */
		baseType value;
	public:
		/** Método que define o valor do atributo value. 
			A validação ocorre no processo, e o valor não será setado no caso do argumento deste método ser inválido. */
		void setValue(baseType value) throw (invalid_argument)
		{
			validate(value);
			this->value = value;
		}
		/** Método que recupera o valor do atributo value.
			O valor é retornado por este método, e o atributo não é modificado no processo. */
		baseType getValue() const
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
		/** Instância de validate() para strings. 
			Irá verificar se o nome possui menos de 20 caracteres e se possui somente caracteres válidos (pontos, espaços e letras). */
		void validate(const string&) throw (invalid_argument);
	public:
		/** Construtor padrão de UsrName.
			Define a string vazia como valor de não-inicialização deste tipo básico */
		UsrName();
		/** Construtor base de UsrName.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		UsrName(const string&) throw (invalid_argument);
};

/** 	Define a senha de um User (Customer ou Manager).
	Este tipo básico tem a função de controlar o login de usuários em geral.
*/
class UsrPassword:public UnitBase<string>
{
	private:
		/** Instância de validate() para strings.
			Irá verificar se a senha possui menos de seis caracteres ou se ela é formada tão somente por caracteres alfanuméricos.*/
		void validate(const string&) throw (invalid_argument);
	public:
		/** Construtor padrão de UsrPassword.
			Define a string vazia como valor de não-inicialização deste tipo básico */
		UsrPassword();
		/** Construtor base de UsrPassword.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		UsrPassword(const string&) throw (invalid_argument);
};

/**	Define o ID de um Customer.
	Tem a função de identificar de forma única um Customer, independentemente do seu tipo de conta.
*/
class UsrId: public UnitBase<int>
{
	private:
		/** Instância de validate() para inteiros.
			Irá verificar se o ID em questão é maior do que zero.*/
		void validate(const int&) throw (invalid_argument);
	public:
		/** Construtor padrão de UsrId.
			Define o valor 0 como valor de não-inicialização deste tipo básico. */
		UsrId();
		/** Construtor base de UsrId.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		UsrId(const int&) throw (invalid_argument);
};

/** 	Define a matrícula de um Manager.
 	Tem a função de identificar de forma única um Manager, seja ele Administrador ou Gerente.
*/
class UsrMatric:public UnitBase<int>
{
	private:
		/** Instância de validate() para inteiros.
			Irá verificar se a matrícula em questão é menor do que zero e tem até cinco dígitos. */
		void validate(const int&) throw (invalid_argument);
	public:
		/** Construtor padrão de UsrMatric.
			Define o valor 0 como valor de não-inicialização deste tipo básico. */
		UsrMatric();
		/** Construtor base de UsrMatric.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		UsrMatric(const int&) throw (invalid_argument);
};

/**	Codifica tipos de conta.
	Possui duas utilizações:
	AccType: Codifica tipos de conta (Normal / Especial)
 	ManType: Codifica tipos de manager (Gerente / Administrador)
*/
class UsrType : public UnitBase<bool>
{
	private:
		/** Instância de validate() para booleanos.
			Irá verificar se o tipo de usuário em questão é um dos dois tipos permitidos (Normal/Especial ou Gerente/Administrador).*/
		void validate(const bool& value) throw (invalid_argument);
	public:
		/** Construtor padrão de UsrType.
			Define o valor NORMAL/GERENTE como valor de não-inicialização deste tipo básico. */
		UsrType();
		/** Construtor base de UsrType.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		UsrType(const bool&) throw (invalid_argument);
};

///\typedef Instancia UsrType para contas.
typedef UsrType AccType;
///\typedef Instancia UsrType para Managers.
typedef UsrType ManType;

/**	Define o número da conta de um Customer (Cliente).
	Este tipo básico tem a função de atribuir a cada conta um numero unico, identificando-a.
*/
class AccNumber:public UnitBase<int>
{
	private:
		/** Instância de validate() para inteiros.
			Irá verificar se o número de conta em questão é maior do que zero e possui até quatro dígitos. */
		void validate(const int&) throw (invalid_argument);
	public:
		/** Construtor padrão de AccNumber.
			Define o valor 0 como valor de não-inicialização deste tipo básico. */
		AccNumber();
		/** Construtor base de AccNumber.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		AccNumber(const int&) throw (invalid_argument);
};

/**	Define o limite da conta de um Customer (Cliente).
	Atribui a cada conta um limite, limitando a utilização do crédito junto ao banco.
*/
class Money:public UnitBase<float>
{
	private:
		/** Instância de validate() para números reais.
			Irá verificar se a quantia de dinheiro em questão é maior do que zero, menor do que infinito e possui até duas casas decimais. */
		void validate(const float&) throw (invalid_argument);
	public:
		/** Construtor padrão de Money.
			Define o valor 0 como valor de não-inicialização deste tipo básico. */
		Money();
		/** Construtor base de Money.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		Money(const float&) throw (invalid_argument);
};

/**	Define um número de identificação para cada pagamento.
	Atribui a cada pagamento um código, de forma a identificá-lo.
*/
class PayCode:public UnitBase<int>
{
	private:
		/** Instância de validate() para inteiros.
			Irá verificar se o código de pagamento em questão é maior do que zero e possui até seis dígitos. */
		void validate(const int&) throw (invalid_argument);
	public:
		/** Construtor padrão de PayCode.
			Define o valor 0 como valor de não-inicialização deste tipo básico. */
		PayCode();
		/** Construtor base de PayCode.
			É preferível que se utilize este construtor, pois ele já faz a validação automática do valor a ser definido. */
		PayCode(const int&) throw (invalid_argument);
};

/**	Define a data do pagamento.
	Guarda a data de um pagamento num inteiro de formato DDMMAAAA. Dia, mês e ano devem ser acessados através dos atributos day, month, year.
*/
class PayDay:public UnitBase<int>
{
	private:
		/** Instância de validate() para inteiros.
			Irá verificar se a estruturação da data, bem como a data em questão está correta. Anos anteriores a 2013 serão considerados inválidos. */
		void validate(const int&) throw (invalid_argument);
	public:
		/** Construtor padrão de PayDay.
			Define o valor 0 como valor de não-inicialização deste tipo básico. */
		PayDay();
		/** Construtor base de PayDay.
			É preferível que se utilize este construtor pois ele já faz a validação automática do valor a ser definido. */
		PayDay(const int&) throw (invalid_argument);
		/** Método que retorna o dia contido na data.
			Extrai do inteiro contido no objeto o dia a que ele se refere. */
		inline int day();
		/** Método que retorna o mês contido na data.
			Extrai do inteiro contido no objeto o mês a que ele se refere. */
		inline int month();
		/** Método que retorna o ano contido na data.
			Extrai do inteiro contido no objeto o ano a que ele se refere. */
		inline int year();
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

#endif
