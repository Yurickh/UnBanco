#ifndef USER_UNIT_H
#define USER_UNIT_H

#include <stdexcept>
#include <list>
#include <cstdlib>
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
	public:
		virtual void createAccount(AccType*, Money*, Money*) throw (PersError) = 0;
		virtual void deleteAccount(AccNumber*) throw (invalid_argument, PersError) = 0;
		virtual void blockAccount(AccNumber*) throw (invalid_argument, PersError) = 0;
		virtual void unblockAccount(AccNumber*) throw (invalid_argument, PersError) = 0;
		virtual list<Account> fetchAccount(void) throw (PersError) = 0;
		virtual void editAccType(AccNumber*, AccType*) throw (invalid_argument, PersError) = 0;
		virtual void editAccLimit(AccNumber*, Money*) throw (invalid_argument, PersError) = 0;
};

class StubUserAccAdm : public UserAccAdm
{
		void createAccount(AccType*, Money*, Money*) throw (PersError);
		void deleteAccount(AccNumber*) throw (invalid_argument, PersError);
		void blockAccount(AccNumber*) throw (invalid_argument, PersError);
		void unblockAccount(AccNumber*) throw (invalid_argument, PersError);
		list<Account> fetchAccount(void) throw (PersError);
		void editAccType(AccNumber*, AccType*) throw (invalid_argument, PersError);
		void editAccLimit(AccNumber*, Money*) throw (invalid_argument, PersError);
};

class UserManAdm
{
	public:
		virtual void changePassword(UsrPassword*) throw (PersError) = 0;
		virtual void createManager(UsrName*, UsrPassword*) throw (PersError) = 0;

		virtual list<Manager> fetchManager(void) throw (PersError) = 0;
		virtual Manager fetchManager(UsrMatric) throw (PersError) = 0;

		virtual void editManName(UsrMatric*, UsrName*) throw (invalid_argument, PersError) = 0;
		virtual void deleteManager(UsrMatric*) throw (invalid_argument, PersError) = 0;
};

class StubUserManAdm : public UserManAdm
{
	public:
		void changePassword(UsrPassword*) throw (PersError);
		void createManager(UsrName*, UsrPassword*) throw (PersError);

		list<Manager> fetchManager(void) throw (PersError);
		Manager fetchManager(UsrMatric) throw (PersError);

		void editManName(UsrMatric*, UsrName*) throw (invalid_argument, PersError);
		void deleteManager(UsrMatric*) throw (invalid_argument, PersError);
};

class UserCusAdm
{
	public:
		virtual void changePassword(UsrPassword*) throw (PersError) = 0;
		virtual void createCustomer(UsrName*, UsrPassword*) throw (invalid_argument, PersError) = 0;
		virtual void editCusName(AccNumber*, UsrName*) throw (invalid_argument, PersError) = 0;
};

class StubUserCusAdm : public UserCusAdm
{
	public:
		void changePassword(UsrPassword*) throw (PersError);
		void createCustomer(UsrName*, UsrPassword*) throw (invalid_argument, PersError);
		void editCusName(AccNumber*, UsrName*) throw (invalid_argument, PersError);
};

#endif
