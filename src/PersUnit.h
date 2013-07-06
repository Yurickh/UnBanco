#ifndef PERS_UNIT_H
#define PERS_UNIT_H

#include <string>

using namespace std;

#define PERS_ERROR_MSG "Ocorreu um erro ao se conectar ao database. Favor tentar novamente mais tarde."

class PersError
{
	private:
		string info;

	public:

		PersError();
		PersError(string);

		string what();
};

#endif
