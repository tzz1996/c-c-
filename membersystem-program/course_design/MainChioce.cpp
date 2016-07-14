#include <iostream>
#include "MainChioce.h"
#include "maincontent.h"
#include "editcontent.h"
#include "editchioce.h"
#include "connect_to_mysql.h"
using namespace std;


MainChioce::MainChioce()
{
}


MainChioce::~MainChioce()
{
}


void MainChioce::Transform() {
	cin >> chioce;

	if (chioce == 1) {
		//system("CLS");
		Editcontent editcontent;
		editcontent.PrintContent();
		EditChioce editchioce;
		editchioce.Print();
		editchioce.Transform();
	}
	else if (chioce == 2) {
		Mysql mysql;
		mysql.ConnectToMysql();
		mysql.CheckInformation();
	}
	else if (chioce == 3) {
		PrintScoreRule();
	}
	else if (chioce == 4) {
		exit(0);
	}
	else {
		cout << "输入错误，请重新输入！" << endl;
		MainChioce mainchioce;
		mainchioce.Print();
		mainchioce.Transform();
	}
}

void MainChioce::Print() {
	cout << "请输入您的选择>";
}

void MainChioce::PrintScoreRule() {
	system("CLS");

	cout << "#积分反钱规则#" << endl;
	cout << "积分达100：反10元" << endl;
	cout << "积分达500：反30元" << endl;
	cout << "积分达1000：反100元" << endl;

	MainContent maincontent;
	maincontent.IfReturnMain();
}