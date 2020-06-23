#include "CFood.h"
#include <ctime>
#include <cstdlib>  // srand
#include "CGame.h"

CFood::CFood()
{
	srand((unsigned int)time(NULL));
}

CFood::CFood(int x,  int y , char pic) : CUnit(x, y, pic)
{
	srand((unsigned int)time(NULL));
}


CFood::~CFood()
{
}


void CFood::createPos(std::vector<CUnit> *vec)
{
	int x = CGame::KLEFT + 2 + rand() % CGame::KWIDTH - 2;
	int y = CGame::KUP + 2 + rand() % (CGame::KHEIGHT -2);

	while (true)
	{
		size_t i;
		for (i = 0; i < vec->size(); i++)
		{
			if (x == vec->at(i).m_iX && y == vec->at(i).m_iY)
			{
				break;
			}
		}
		if (i == vec->size())
		{
			m_iX = x;
			m_iY = y;
			return;
		}
	}
}
