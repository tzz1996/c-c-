#pragma once
#include <iostream>
#include <string>

using namespace std;


class Member {
private:
	string id;
	string name;
	string level;
	string maney;
	string discont;
	string score;

public:
	Member();
	~Member();

	void SetId(string input);
	void SetName(string input);
	void SetLevel(string input);
	void SetManey(string input);
	void Setdiscont(string input);
	void SetScore(string input);

	void GetId(string* output);
	void GetName(string* output);
	void GetLevel(string* output);
	void GetManey(string* output);
	void Getdiscont(string* output);
	void GetScore(string* output);

	string IntToString(int input);
	int StringToInt(string input);

	void DecideManey(string inputmaney);
	void DecideScore();
	void DecideLevel();
	void DecideDiscont();
	void ScoreToManey();
};