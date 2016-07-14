#include <iostream>
#include "maincontent.h"
#include "MainChioce.h"

using namespace std;


int main() {
	//cout << "hello, world!" << endl;
	MainContent maincontent;
	maincontent.PrintContent();
	MainChioce mainchioce;
	mainchioce.Print();
	mainchioce.Transform();
	
	system("pause");
	return 0;
}