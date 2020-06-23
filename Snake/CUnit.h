#pragma once
class CUnit
{
public:
	CUnit();
	CUnit(int x, int y, char c);
	virtual ~CUnit();

	void show();
	void erase();

public:
	int m_iX;
	int m_iY;
	char m_cPic;
};

