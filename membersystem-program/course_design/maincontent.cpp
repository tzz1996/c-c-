#include <iostream>
#include "maincontent.h"
#include "MainChioce.h"
using namespace std;

MainContent::MainContent()
{
}

MainContent::~MainContent()
{
}

void MainContent::PrintContent() {
	system("CLS");
	cout << "###会员管理系统###" << endl;
	cout << "###主界面###" << endl;
	cout << "1.编辑菜单" << endl;
	cout << "2.查看菜单" << endl;
	cout << "3.查看会员积分反钱信息" << endl;
	cout << "4.退出" << endl;
	//cout << "请输入您的选择:_";
}

void MainContent::Exit() {
	exit(0);
}

void MainContent::IfReturnMain() {
	cout << "是否返回主菜单？(1.是 2.否)" << endl;
	int chioce;
	while(1) {
		cin >> chioce;
		if (chioce == 1) {
			MainContent maincontent;
			maincontent.PrintContent();
			MainChioce mainchioce;
			mainchioce.Print();
			mainchioce.Transform();
		}
		else if (chioce == 2)
			exit(0);
		else 
			cout << "输入错误，请重新输入" << endl;
	}
}