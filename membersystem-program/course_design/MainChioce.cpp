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
		cout << "����������������룡" << endl;
		MainChioce mainchioce;
		mainchioce.Print();
		mainchioce.Transform();
	}
}

void MainChioce::Print() {
	cout << "����������ѡ��>";
}

void MainChioce::PrintScoreRule() {
	system("CLS");

	cout << "#���ַ�Ǯ����#" << endl;
	cout << "���ִ�100����10Ԫ" << endl;
	cout << "���ִ�500����30Ԫ" << endl;
	cout << "���ִ�1000����100Ԫ" << endl;

	MainContent maincontent;
	maincontent.IfReturnMain();
}