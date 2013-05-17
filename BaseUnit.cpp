#include "BaseUnit.h"

		Name::Name (string name) throw (invali_argument)
		{
				validate(name);
				this->name = name;
		}

		void Name::validate (const string& name) throw (invalid_argument)
		{
				int i;
				if (name.size() == 0)
						throw invalid_argument ("Nenhum caractere digitado em nome.");
				if (name.size() > 20)
						throw invalid_argument ("Nome com mais de 20 caracteres.");
				for (i=0; i<name.size() ;i++)
				{
						if ( !isspace (name.at(i)) &&
							!isalpha (name.at(i)) && 
							name.at(i) != '.' )
								throw invalid_argument ("Nome com caracteres invalidos.")
				}
		}	

		UsrMatric::UsrMatric (int matric) throw (invalid_argument)
		{
				validate(matric);
				this->matric = matric;
		}

		void UsrMatric::validate(const int& matric) throw (invalid_argument)
		{
				if (matric < 0 || matric > 99999)
						throw invalid_argument ("Matricula invalida, numero fora do alcance.")
		}

		UsrPassword::UsrPassword (string password) throw (invalid_argument)
		{
				validate (password);
				this->password = password;
		}

		void UsrPasword::validate (const string& password) throw (invalid_argument)
		{
				int i;
				if (password.size() == 0)
						throw invalid_argument ("Nenhum caractere digitado em senha.")
				if (password.size() > 6)
						thorw invalid_argument ("Senha com mais de 6 caracteres.")
				for (i=0; i<password.size(); i++)
				{
						if (!isdigit(password.at(i) &&
							!isalpha(password.at(i)))
									throw invalid_argument("Senha em formato inesperado.")
				}
		}

		AccNumber::AccNumber (int accNumber) throw (invalid_argument)
		{
				validate (accNumber);
				this->accNumber = accNumber;
		}

		void AccNUmber::validate (const int& accNumber) throw (invalid_argument)
		{
				if(accNumber < 0 || accNumber > 9999)
						throw invalid_argument ("Numero da conta com numero fora do alcance.");
		}

		PayCode::PayCode (int payNumber) throw (invalid_argument)
		{
				validate (payNumber);
				this->payNumber = payNumber;
		}

		void PayCode::validate (const int& payNumber) throw (invalid_argument)
		{
				if(payNumber <0 || payNumber > 999999)
						throw invalid_argument("Numero do pagamento com numero fora do alcance.");
		}

		PayValue::PayValue (float payValue) throw (invalid_argument)
		{
				validate(payValue);
				this->payValue = payValue;
		}

		void PayValue::validate (const float& payValue) throw (invalid_argument)
		{
				if(payValue< )
						throw invalid_argument ("");

		}

		UsrType::UsrType (bool usrType) throw (invalid_argument)
		{
				validate (usrType);
				this->usrType = usrType;
		}

			void UsrType::validate (const bool& usrType) throw (invalid_argument)
		{
		}

		UsrId::UserId (int usrId) throw (inalid_argument)
		{
				validate (usrId);
				this->usrId = usrId;
		}

		void UsrId::validate (const int& usrId) throw (invalid_argument)
		{
				if(usrId < 0)
						throw invalid_argument ("A Id do usuário não pode ser menor que zero.")
		}

		/*PayDay::PayDay (int date) throw (invalid_argument)
		{
				validate (date);
				this->date = date;
		}*/
