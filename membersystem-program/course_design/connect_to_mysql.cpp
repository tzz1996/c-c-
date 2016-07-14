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
	//设置字符
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
		cout << "数据库连接状态：连接" << endl;
	else
		cout << "数据库连接状态：断开" << endl;
}


void Mysql::InsertMember() {
	Member newmeb;
	string insertstr;
	string new_id, new_name, new_maney, new_score, new_level, new_discont, rus_maney;
	system("CLS");
	
	cout << "请输入新建会员的ID号：";
	cin >> new_id;
	cout << "请输入新会员的姓名：";
	cin >> new_name;
	cout << "请输入新会员卡充值金额：";
	cin >> new_maney;
	
	//输入传入Member类并处理
	newmeb.SetId(new_id);
	newmeb.SetName(new_name);
	newmeb.SetManey(new_maney);
	newmeb.DecideScore();
	newmeb.DecideLevel();
	newmeb.DecideDiscont();
	newmeb.ScoreToManey();
	//Member类传出
	newmeb.GetScore(&new_score);
	newmeb.GetLevel(&new_level);
	newmeb.Getdiscont(&new_discont);
	newmeb.GetManey(&rus_maney);

	insertstr = "INSERT INTO membership VALUES('"+new_id+"', '"+new_name+"', '"+new_level+"', '"+rus_maney+"', '"+new_discont+"', '"+new_score+"');";
	if (mysql_query(&myCont, insertstr.c_str()) == 0)
		cout << "新会员建立成功" << endl;
	else
		cout << "新会员建立失败" << endl;
	
	Mysql mysql;
	mysql.DisconnectToMysql();

	Editcontent editcontent;
	editcontent.IfReturnEdit();
}


void Mysql::DropMember() {
	string old_id;
	string insertstr;
	system("CLS");

	cout << "请输入待删除会员的ID号：" << endl;
	cin >> old_id;
	insertstr = "DELETE FROM membership WHERE meb_id='" + old_id + "'";
	if (mysql_query(&myCont, insertstr.c_str()) == 0)
		cout << "老会员删除成功" << endl;
	else
		cout << "老会员删除失败" << endl;

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

	cout << "请输入您的会员ID号：" << endl;
	cin >> search_id;
	cout << "请输入您的充值金额：" << endl;
	cin >> input_maney;

	//从数据库获取数据并存入Member类
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
	
	//类内数据处理
	dealmeb.DecideManey(input_maney);
	dealmeb.DecideScore();
	dealmeb.DecideLevel();
	dealmeb.DecideDiscont();
	dealmeb.ScoreToManey();
	
	//类数据传出
	dealmeb.GetId(&rus_id);
	dealmeb.GetName(&rus_name);
	dealmeb.GetManey(&rus_maney);
	dealmeb.GetScore(&rus_score);
	dealmeb.GetLevel(&rus_level);
	dealmeb.Getdiscont(&rus_discont);

	//上传新数据
	insertstr = "UPDATE membership SET meb_maney='"+rus_maney+"', meb_score='" + rus_score + "', meb_level='" + rus_level + "', meb_discont='" + rus_discont + "' WHERE meb_id='" + rus_id + "';";
	if (mysql_query(&myCont, insertstr.c_str()) == 0)
		cout << "数据修改成功" << endl;
	else
		cout << "数据修改失败" << endl;
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

	cout << "请输入您的会员ID号：" << endl;
	cin >> search_id;

	//从数据库获取信息
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

	//信息传出
	chkmeb.GetId(&cur_id);
	chkmeb.GetName(&cur_name);
	chkmeb.GetManey(&cur_maney);
	chkmeb.GetScore(&cur_score);
	chkmeb.GetLevel(&cur_level);
	chkmeb.Getdiscont(&cur_discont);

	//查询结果输出
	cout << "会员ID号：";
	cout << cur_id << endl;
	cout << "会员姓名：";
	cout << cur_name << endl;
	cout << "会员充值总金额：";
	cout << cur_maney << endl;
	cout << "会员积分：";
	cout << cur_score << endl;
	cout << "会员等级：";
	cout << cur_level << endl;
	cout << "会员折扣：";
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
	
	insertstr = "SELECT count(*) FROM membership WHERE meb_level='普通会员'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	total_normal_meb = sql_row[0];

	insertstr = "SELECT count(*) FROM membership WHERE meb_level='白银会员'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	total_middle_meb = sql_row[0];

	insertstr = "SELECT count(*) FROM membership WHERE meb_level='黄金会员'";
	res = mysql_query(&myCont, insertstr.c_str());
	if (!res) {
		result = mysql_store_result(&myCont);
		if (result) {
			sql_row = mysql_fetch_row(result);
		}
	}
	total_super_meb = sql_row[0];

	//输出结果
	cout << "所有会员数量：";
	cout << total_meb << endl;
	cout << "普通会员数量：";
	cout << total_normal_meb << endl;
	cout << "白银会员数量：";
	cout << total_middle_meb << endl;
	cout << "黄金会员数量：";
	cout << total_super_meb << endl;

	if (result != NULL)
		mysql_free_result(result);
	
	Mysql mysql;
	mysql.DisconnectToMysql();

	MainContent maincontent;
	maincontent.IfReturnMain();
}