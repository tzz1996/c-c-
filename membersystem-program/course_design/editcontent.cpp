#include <iostream>
#include "editcontent.h"
#include "editchioce.h"
#include "maincontent.h"
#include "MainChioce.h"
using namespace std;

Editcontent::Editcontent() {

}

Editcontent::~Editcontent() {

}

void Editcontent::PrintContent() {
	system("CLS");
	cout << "###编辑界面###" << endl;
	cout << "1.添加新会员" << endl;
	cout << "2.退出会员" << endl;
	cout << "3.会员充值" << endl;
	cout << "4.查看会员相关信息" << endl;
	cout << "5.返回主菜单" << endl;
}

void Editcontent::ReturnToMain() {
	MainContent maincontent;
	maincontent.PrintContent();
	MainChioce mainchioce;
	mainchioce.Print();
	mainchioce.Transform();
}


void Editcontent::IfReturnEdit() {
	cout << "是否返回编辑菜单？(1.是 2.否)" << endl;
	int chioce;
	while (1) {
		cin >> chioce;
		if (chioce == 1) {
			Editcontent editcont;
			editcont.PrintContent();
			EditChioce editch;
			editch.Print();
			editch.Transform();
		}
		else if (chioce == 2)
			exit(0);
		else
			cout << "输入错误，请重新输入" << endl;
	}
}