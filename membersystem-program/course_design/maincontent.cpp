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
	cout << "###��Ա����ϵͳ###" << endl;
	cout << "###������###" << endl;
	cout << "1.�༭�˵�" << endl;
	cout << "2.�鿴�˵�" << endl;
	cout << "3.�鿴��Ա���ַ�Ǯ��Ϣ" << endl;
	cout << "4.�˳�" << endl;
	//cout << "����������ѡ��:_";
}

void MainContent::Exit() {
	exit(0);
}

void MainContent::IfReturnMain() {
	cout << "�Ƿ񷵻����˵���(1.�� 2.��)" << endl;
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
			cout << "�����������������" << endl;
	}
}