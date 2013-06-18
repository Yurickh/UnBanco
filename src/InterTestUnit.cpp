#include "EngineUnit.h"

Window* win;

#include "MainUnit.h"

int main()
{
	MainLogin* mainLogin;
	UserLogin* userLogin;

	win = new Textual();
	mainLogin = new MainLogin;
	userLogin = new Stub;

	mainLogin->setUserLogin(userLogin);

	mainLogin->execute();

	return 0;
}
