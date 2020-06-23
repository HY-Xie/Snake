#pragma once
#include "CUnit.h"
#include <vector>

class CFood :
	public CUnit
{
public:
	CFood();
	CFood(int x = 0, int y = 0, char pic = 'c');
	virtual ~CFood();

	void createPos(std::vector<CUnit> *vec);
};

