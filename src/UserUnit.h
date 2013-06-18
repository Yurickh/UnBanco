#ifndef USER_UNIT_H
#define USER_UNIT_H

#include <stdexcept>
#include "EntityUnit.h"
#include "PersUnit.h"

class UserLogin
{
	public:
		virtual ManType autent(UsrMatric*, UsrPassword*) throw (invalid_argument, PersError) = 0;
		virtual void autent(AccNumber*, UsrPassword*) throw (invalid_argument, PersError) = 0;
};

class Stub : public UserLogin
{
	public:
		ManType autent(UsrMatric*, UsrPassword*) throw (invalid_argument, PersError);
		void autent(AccNumber*, UsrPassword*) throw (invalid_argument, PersError);
};

class UserAdm
{
};

#endif
