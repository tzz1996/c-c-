#pragma once
#include "Chioce.h"

class EditChioce :public Chioce {
private:
	int chioce;

public:
	EditChioce();
	~EditChioce();
	void virtual Print();
	void Transform();
};