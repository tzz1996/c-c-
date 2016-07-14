#include <iostream>
#include <Windows.h>
#include <mysql.h>
#include <string>
#include "membership.h"
#include "connect_to_mysql.h"
#include "editcontent.h"
#include "editchioce.h"
#include "maincontent.h"


using namespace std;

Mysql::Mysql() {

}


Mysql::~Mysql() {

}


bool Mysql::ConnectToMysql() {
	const char user[] = "tzz";         //username  
	const char pswd[] = "123456";         //password  
	const char host[] = "localhost";    //or"127.0.0.1"  
	const char table[] = "kechengsheji";        //database  
	unsigned int port = 3306;           //server port          

	mysql_init(&myCont);
	//mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0);
	ifconnect = mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0);
	//�����ַ�
	mysql_query(&myCont, "set names gbk");
	if (ifconnect)
		return TRUE;
	else 
		return FALSE;
}


bool Mysql::DisconnectToMysql() {
	if (ifconnect) {
		mysql_close(&myCont);
		ifconnect = FALSE;
	}
	if (ifconnect)
		return FALSE;
	else
		return TRUE;
}


void Mysql::CheckConnection() {
	if (ifconnect)
		cout << "���ݿ�����״̬������" << endl;
	else
		cout << "���ݿ�����״̬���Ͽ�" << endl;
}


void Mysql::InsertMember() {
	Member newmeb;
	string insertstr;
	string new_id, new_name, new_maney, new_score, new_level, new_discont, rus_maney;
	system("CLS");
	
	cout << "�������½���Ա��ID�ţ�";
	cin >> new_id;
	cout << "�������»�Ա��������";
	cin >> new_name;
	cout << "�������»�Ա����ֵ��";
	cin >> new_maney;
	
	//���봫��Member�ಢ����
	newmeb.SetId(new_id);
	newmeb.SetName(new_name);
	newmeb.SetManey(new_maney);
	newmeb.DecideScore();
	newmeb.DecideLevel();
	newmeb.DecideDiscont();
	newmeb.ScoreToManey();
	//Member�ഫ��
	newmeb.GetScore(&new_score);
	newmeb.GetLevel(&new_level);
	newmeb.Getdiscont(&new_discont);
	newmeb.GetManey(&rus_maney);

	insertstr = "INSERT INTO membership VALUES('"+new_id+"', '"+new_name+"', '"+new_level+"', '"+rus_maney+"', '"+new_discont+"', '"+new_score+"');";
	if (mysql_query(&myCont, insertstr.c_str()) == 0)
		cout << "�»�Ա�����ɹ�" << endl;
	else
		cout << "�»�Ա����ʧ��" << endl;
	
	Mysql mysql;
	mysql.DisconnectToMysql();

	Editcontent editcontent;
	editcontent.IfReturnEdit();
}


void Mysql::DropMember() {
	string old_id;
	string insertstr;
	system("CLS");

	cout << "�������ɾ����Ա��ID�ţ�" << endl;
	cin >> old_id;
	insertstr = "DELETE FROM membership WHERE meb_id='" + old_id + "'";
	if (mysql_query(&myCont, insertstr.c_str()) == 0)
		cout << "�ϻ�Աɾ���ɹ�" << endl;
	else
		cout << "�ϻ�Աɾ��ʧ��" << endl;

	Mysql mysql;
	mysql.DisconnectToMysql();

	Editcontent editcontent;
	editcontent.IfReturnEdit();
}


void Mysql::InputManey() {
	Member dealmeb;
	string input_maney;
	string search_id;
	string rus_id, rus_name, rus_level, rus_maney, rus_discont, rus_score;
	system("CLS");

	cout << "���������Ļ�ԱID�ţ�" << endl;
	cin >> search_id;
	cout << "���������ĳ�ֵ��" << endl;
	cin >> input_maney;

	//�����ݿ��ȡ���ݲ�����Member��
	string insertstr;
	insertstr = "SELECT * FROM membership WHERE meb_id='" + search_id + "'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	dealmeb.SetId(sql_row[0]);
	dealmeb.SetName(sql_row[1]);
	dealmeb.SetLevel(sql_row[2]);
	dealmeb.SetManey(sql_row[3]);
	dealmeb.Setdiscont(sql_row[4]);
	dealmeb.SetScore(sql_row[5]);
	
	//�������ݴ���
	dealmeb.DecideManey(input_maney);
	dealmeb.DecideScore();
	dealmeb.DecideLevel();
	dealmeb.DecideDiscont();
	dealmeb.ScoreToManey();
	
	//�����ݴ���
	dealmeb.GetId(&rus_id);
	dealmeb.GetName(&rus_name);
	dealmeb.GetManey(&rus_maney);
	dealmeb.GetScore(&rus_score);
	dealmeb.GetLevel(&rus_level);
	dealmeb.Getdiscont(&rus_discont);

	//�ϴ�������
	insertstr = "UPDATE membership SET meb_maney='"+rus_maney+"', meb_score='" + rus_score + "', meb_level='" + rus_level + "', meb_discont='" + rus_discont + "' WHERE meb_id='" + rus_id + "';";
	if (mysql_query(&myCont, insertstr.c_str()) == 0)
		cout << "�����޸ĳɹ�" << endl;
	else
		cout << "�����޸�ʧ��" << endl;
	if (result != NULL)
		mysql_free_result(result);

	Mysql mysql;
	mysql.DisconnectToMysql();

	Editcontent editcontent;
	editcontent.IfReturnEdit();
}


void Mysql::CheckMember() {
	Member chkmeb;
	string search_id;
	string cur_id, cur_name, cur_maney, cur_score, cur_level, cur_discont;
	system("CLS");

	cout << "���������Ļ�ԱID�ţ�" << endl;
	cin >> search_id;

	//�����ݿ��ȡ��Ϣ
	string insertstr;
	insertstr = "SELECT * FROM membership WHERE meb_id='" + search_id + "'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	chkmeb.SetId(sql_row[0]);
	chkmeb.SetName(sql_row[1]);
	chkmeb.SetLevel(sql_row[2]);
	chkmeb.SetManey(sql_row[3]);
	chkmeb.Setdiscont(sql_row[4]);
	chkmeb.SetScore(sql_row[5]);

	//��Ϣ����
	chkmeb.GetId(&cur_id);
	chkmeb.GetName(&cur_name);
	chkmeb.GetManey(&cur_maney);
	chkmeb.GetScore(&cur_score);
	chkmeb.GetLevel(&cur_level);
	chkmeb.Getdiscont(&cur_discont);

	//��ѯ������
	cout << "��ԱID�ţ�";
	cout << cur_id << endl;
	cout << "��Ա������";
	cout << cur_name << endl;
	cout << "��Ա��ֵ�ܽ�";
	cout << cur_maney << endl;
	cout << "��Ա���֣�";
	cout << cur_score << endl;
	cout << "��Ա�ȼ���";
	cout << cur_level << endl;
	cout << "��Ա�ۿۣ�";
	cout << cur_discont << endl;

	if (result != NULL)
		mysql_free_result(result);

	Mysql mysql;
	mysql.DisconnectToMysql();

	Editcontent editcontent;
	editcontent.IfReturnEdit();
}


void Mysql::CheckInformation() {
	string total_meb;
	string total_normal_meb;
	string total_middle_meb;
	string total_super_meb;
	string insertstr;
	system("CLS");

	insertstr = "SELECT count(*) FROM membership";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	total_meb = sql_row[0];
	
	insertstr = "SELECT count(*) FROM membership WHERE meb_level='��ͨ��Ա'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	total_normal_meb = sql_row[0];

	insertstr = "SELECT count(*) FROM membership WHERE meb_level='������Ա'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	total_middle_meb = sql_row[0];

	insertstr = "SELECT count(*) FROM membership WHERE meb_level='�ƽ��Ա'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	total_super_meb = sql_row[0];

	//������
	cout << "���л�Ա������";
	cout << total_meb << endl;
	cout << "��ͨ��Ա������";
	cout << total_normal_meb << endl;
	cout << "������Ա������";
	cout << total_middle_meb << endl;
	cout << "�ƽ��Ա������";
	cout << total_super_meb << endl;

	if (result != NULL)
		mysql_free_result(result);
	
	Mysql mysql;
	mysql.DisconnectToMysql();

	MainContent maincontent;
	maincontent.IfReturnMain();
}