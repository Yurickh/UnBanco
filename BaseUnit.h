#include <string>
#include <stdexcep>

/// Template é a base de derivação de todas as classes de tipos básicos.
template <typename baseType>
class UnitBase
{
	private:
		virtual validate(const baseType& value) throw (invalid_argument) = 0;
	protected:
		baseType value;
	public:
		inline void setValue(const baseType& value) throw (invalid_argument);
		inline baseType getValue();
};

inline void UnitBase<baseType>::setValue(const baseType& value) throw (invalid_argument)
{
	validate(value);
	this->value = value;
}

inline baseType UnitBase<baseType>::getValue()
{
	return value;
}

/// GType codifica tipos de conta.
/// Possui duas utilizações:
/// 	AccType: Codifica tipos de conta (Normal / Especial)
/// 	ManType: Codifica tipos de manager (Gerente / Administrador)
class GType : public UnitBase<bool>
{
	private:
		void validate(const bool& value) throw (invalid_argument);
	public:
		GType() {}
		GType(bool);
};

typedef GType AccType;
typedef GType ManType;

/// Name define o nome de um User (Customer ou Manager)
/// Este tipo serve para regular o login de usuários em geral.
class Name:public UnitBase<string>
{
		private:
				void validate(const string&) throw (invalid_argument);
		public:
				Name() {};
				Name(string) throw (invalid_argument);
};

/// Matric define a matrícula de um Manager.
/// Ela tem a função de identificar de forma única um Manager, seja ele Administrador ou Gerente.
class Matric:public UnitBase<int>
{
		private:
				void validate(const& int) throw (invalid_argument);
		public:
				Matric() {};
				Matric(int) throw (invalid_argument);
};

/// Password define a senha de um User (Customer ou Manager)
/// Este tipo básico tem a função de controlar o login de usuários em geral.
class Password:public UnitBase<int>
{
		private:
				void validate(const& int) throw (invalid_argument);
		public:
				Password() {};
				Password(int) throw (invalid_argument);
};
//--------------------------------------------------------------------------------------

/// AccNumber define o número da conta de um Customer (Cliente).
/// Este tipo básico tem a função de atribuir a cada conta um numero unico, identificando-a.
class AccNumber:public UnitBase<int>
{
		private:
				void validate(const& int) throw (invalid_argument);
		public:
				AccNumber() {};
				AccNumbere(int) throw (invalid_argument);
};
