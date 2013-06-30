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
	public:
		virtual void changePassword(UsrPassword*) throw (invalid_argument, PersError) = 0;
};

class StubUserManAdm : public UserManAdm
{
	public:
		void changePassword(UsrPassword*) throw (PersError);
};

class UserCusAdm
{
};

class StubUserCusAdm : public UserCusAdm
{
};

#endif
