#include "CUnit.h"
#include "CTools.h"
#include <iostream>
using namespace std;


CUnit::CUnit()
{

}

CUnit::CUnit(int x = 0, int y = 0, char c = '*') : m_iX(x), m_iY(y), m_cPic(c)
{

}


CUnit::~CUnit()
{

}

void CUnit::show()
{
	CTools::gotoxy(m_iX, m_iY);
	cout << m_cPic;
}

void CUnit::erase()
{
	CTools::gotoxy(m_iX, m_iY);
	cout << " ";
}
