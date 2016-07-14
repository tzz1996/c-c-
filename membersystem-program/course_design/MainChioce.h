#pragma once
#include "Chioce.h"

class MainChioce:public Chioce {
private:
	int chioce;
public:
	MainChioce();
	~MainChioce();
	void virtual Print();
	void Transform();
	void PrintScoreRule();
};

