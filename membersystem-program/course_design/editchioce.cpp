#include <iostream>
#include "editchioce.h"
#include "maincontent.h"
#include "MainChioce.h"
#include "editcontent.h"
#include "connect_to_mysql.h"
//���mysql
#include <Windows.h>
#include <mysql.h>
#include <string>

using namespace std;

EditChioce::EditChioce() {

}


EditChioce::~EditChioce() {

}


void EditChioce::Print() {
	cout << "����������ѡ��>";
}


void EditChioce::Transform() {
	cin >> chioce;

	if (chioce == 1) {
		Mysql mysql;
		mysql.ConnectToMysql();
		mysql.InsertMember();
		//mysql.DisconnectToMysql();
	}
	else if (chioce == 2) {
		Mysql mysql;
		mysql.ConnectToMysql();
		mysql.DropMember();
		//mysql.DisconnectToMysql();
	}
	else if (chioce == 3) {
		Mysql mysql;
		mysql.ConnectToMysql();
		mysql.InputManey();
		//mysql.DisconnectToMysql();
	}
	else if (chioce == 4) {
		Mysql mysql;
		mysql.ConnectToMysql();
		mysql.CheckMember();
		//mysql.DisconnectToMysql();
	}
	//�������˵�
	else if (chioce == 5) {
		system("CLS");
		Editcontent editcontent;
		editcontent.ReturnToMain();
	}
	//�������봦��
	else {
		cout << "����������������룡" << endl;
		EditChioce editchioce;
		editchioce.Print();
		editchioce.Transform();
	}
}