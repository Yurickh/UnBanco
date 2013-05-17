#include <TestUnit.h>

void TestUsrName::execute(const string& name){
	testStr = name;
}

void TestUsrPassword::execute(const string& password){
	testStr = password;
}

void TestUsrId::execute(const int& Id){
	testInt = Id;
}

void TestUsrMatric::execute(const int& matric){
	tesInt = matric;
}

void TestUsrType::execute(const bool& type){
	testBool = type;
}

void TestAccNumber::(const int& accNumber){
	testInt = accNumber;
}

void TestMoney::(const float& money){
	testFloat = money;
}

void TestPayCode::execute(const int& payCode){
	testInt = payCode;
}

void TestPayDay::execute(const int& payDay){
	testInt = payDay;
}
