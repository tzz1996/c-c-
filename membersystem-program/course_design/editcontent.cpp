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
	cout << "###�༭����###" << endl;
	cout << "1.����»�Ա" << endl;
	cout << "2.�˳���Ա" << endl;
	cout << "3.��Ա��ֵ" << endl;
	cout << "4.�鿴��Ա�����Ϣ" << endl;
	cout << "5.�������˵�" << endl;
}

void Editcontent::ReturnToMain() {
	MainContent maincontent;
	maincontent.PrintContent();
	MainChioce mainchioce;
	mainchioce.Print();
	mainchioce.Transform();
}


void Editcontent::IfReturnEdit() {
	cout << "�Ƿ񷵻ر༭�˵���(1.�� 2.��)" << endl;
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
			cout << "�����������������" << endl;
	}
}