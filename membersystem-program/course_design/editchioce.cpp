#include <iostream>
#include "editchioce.h"
#include "maincontent.h"
#include "MainChioce.h"
#include "editcontent.h"
#include "connect_to_mysql.h"
//添加mysql
#include <Windows.h>
#include <mysql.h>
#include <string>

using namespace std;

EditChioce::EditChioce() {

}


EditChioce::~EditChioce() {

}


void EditChioce::Print() {
	cout << "请输入您的选择>";
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
	//返回主菜单
	else if (chioce == 5) {
		system("CLS");
		Editcontent editcontent;
		editcontent.ReturnToMain();
	}
	//错误输入处理
	else {
		cout << "输入错误，请重新输入！" << endl;
		EditChioce editchioce;
		editchioce.Print();
		editchioce.Transform();
	}
}