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

class StubUserLogin : public UserLogin
{
	public:
		ManType autent(UsrMatric*, UsrPassword*) throw (invalid_argument, PersError);
		void autent(AccNumber*, UsrPassword*) throw (invalid_argument, PersError);
};

class UserAccAdm
{
};

class StubUserAccAdm : public UserAccAdm
{
};

class UserManAdm
{
};

class StubUserManAdm : public UserManAdm
{
};

class UserCusAdm
{
};

class StubUserCusAdm : public UserCusAdm
{
};

#endif
