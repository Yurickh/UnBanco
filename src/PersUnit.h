#ifndef PERS_UNIT_H
#define PERS_UNIT_H

#include <string>

using namespace std;

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
