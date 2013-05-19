#include "TestUnit.h"

int main ()
{
	TestUsrName::run("Yúrick.Hauschild C");
	TestUsrName::run("Andrè@Accioly-Lima-abacate_azedo");
	TestUsrPassword::run("andre0");
	TestUsrPassword::run("yurick66'@#$%6543");
	TestUsrId::run(500);
	TestUsrId::run(-200);
	TestUsrMatric::run(12345);
	TestUsrMatric::run(987654321);
	TestUsrType::run(NORMAL_ACC);
	TestUsrType::run("abacate");
	TestAccNumber::run(1234);
	TestAccNumber::run(-12);
	TestMoney::run(14.79);
	TestMoney::run(1.0/0.0);
	TestPayCode::run(200);
	TestPayCode::run(-50);
	TestPayDay::run(04122015);
	TestPayDay::run(31022015);

	return 0;
}
