#include <iostream>
#include "membership.h"


using namespace std;


Member::Member() {

}


Member::~Member() {
	
}


void Member::SetId(string input) {
	this->id = input;
}


void Member::SetManey(string input) {
	this->maney = input;
}


void Member::SetName(string input) {
	this->name = input;
}


void Member::SetScore(string input) {
	this->score = input;
}


void Member::SetLevel(string input) {
	this->level = input;
}


void Member::Setdiscont(string input) {
	this->discont = input;
}


void Member::GetId(string *output) {
	*output = this->id;
}


void Member::GetName(string *output) {
	*output = this->name;
}


void Member::GetLevel(string *output) {
	*output = this->level;
}


void Member::GetManey(string *output) {
	*output = this->maney;
}


void Member::Getdiscont(string *output) {
	*output = this->discont;
}


void Member::GetScore(string *output) {
	*output = this->score;
}


string Member::IntToString(int input) {
	char buf[20];
	string output;

	sprintf_s(buf, "%d", input);
	output = buf;

	return output;
}


int Member::StringToInt(string input) {
	char buf[20];
	int output;

	strcpy_s(buf, input.c_str());
	sscanf_s(buf, "%d", &output);

	return output;
}


void Member::DecideManey(string inputmaney) {
	int inmaney;
	int curmaney;
	int totalmaney;

	curmaney = StringToInt(this->maney);
	inmaney = StringToInt(inputmaney);
	totalmaney = curmaney + inmaney;
	this->maney = IntToString(totalmaney);
}


void Member::DecideScore() {
	int curmaney;

	curmaney = StringToInt(this->maney);
	this->score = IntToString(curmaney / 10);
}


void Member::DecideLevel() {
	int totalscore;
	string result;

	totalscore = StringToInt(this->score);
	if (0 < totalscore && totalscore <= 100)
		result = "普通会员";
	else if (100 < totalscore && totalscore <= 300)
		result = "白银会员";
	else
		result = "黄金会员";

	this->level = result;
}


void Member::DecideDiscont() {
	string result;
	string currentlevel;

	currentlevel = this->level;

	if (currentlevel == "普通会员")
		result = "10%";
	else if (currentlevel == "白银会员")
		result = "15%";
	else
		result = "19%";

	this->discont = result;
}


void Member::ScoreToManey() {
	int curscore;
	int curmaney;
	string rusmaney;

	curmaney = StringToInt(this->maney);
	curscore = StringToInt(this->score);

	if (curscore >= 100 && curscore < 500)
		curmaney += 10;
	else if (curscore >= 500 && curscore < 1000)
		curmaney += 50;
	else if (curscore >= 1000)
		curmaney += 100;

	rusmaney = IntToString(curmaney);
	this->maney = rusmaney;
}