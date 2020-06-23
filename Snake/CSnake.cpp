#include "CSnake.h"
#include <Windows.h>


CSnake::CSnake(int headX = 50, int headY = 40, int length = 4, Directions direction = RIGHT, int speed = 2000, char pic = 'o')
{
	m_iHeadX = headX;
	m_iHeadY = headY;
	m_iLength = length;
	m_enumCurrentDirection = direction;
	m_iSpeed = speed;
	m_cPic = pic;
	m_vecBody.clear();

	int tempX = 0;
	int tempY = 0;
	for (int i = 0; i < length; ++i)
	{
		switch (direction)
		{
		case UP:
			tempX = m_iHeadX;
			tempY = m_iHeadY + i;
			break;
		case DOWN:
			tempX = m_iHeadX;
			tempY = m_iHeadY - i;
			break;
		case LEFT:
			tempX = m_iHeadX + i;
			tempY = m_iHeadY;
			break;
		case RIGHT:
			tempX = m_iHeadX-i;
			tempY = m_iHeadY;
			break;
		}
		CUnit unit(tempX, tempY, pic);
		m_vecBody.push_back(unit);
	}
}


CSnake::~CSnake()
{
}


void CSnake::showSnake()
{
	for (auto unit = m_vecBody.begin(); unit != m_vecBody.end(); ++unit)
	{
		unit->show();
	}
}
void CSnake::eraseSnake()
{
	for (auto unit = m_vecBody.begin(); unit != m_vecBody.end(); ++unit)
	{
		unit->erase();
	}
}
void CSnake::growup()
{
	CUnit unit(0, 0, m_cPic);
	m_vecBody.push_back(unit);
	m_iLength++;
}

void CSnake::changeDirection(int vkValue) // W, S, A, D 
{
	switch (vkValue)
	{
	case 119: // W
		if (m_enumCurrentDirection == LEFT || m_enumCurrentDirection == RIGHT)	m_enumCurrentDirection = UP;
		break;
	case 115: // S
		if (m_enumCurrentDirection == LEFT || m_enumCurrentDirection == RIGHT)	m_enumCurrentDirection = DOWN;
		break;
	case 97:  // A
		if (m_enumCurrentDirection == UP || m_enumCurrentDirection == DOWN)	m_enumCurrentDirection = LEFT;
		break;
	case 100:
		if (m_enumCurrentDirection == UP || m_enumCurrentDirection == DOWN)	m_enumCurrentDirection = RIGHT;
		break;
	default:
		break;
	}
}
void CSnake::move()
{
	eraseSnake();
	for (int i = m_iLength - 2; i >= 0; i--)
	{
		m_vecBody[i + 1].m_iX = m_vecBody[i].m_iX;
		m_vecBody[i + 1].m_iY = m_vecBody[i].m_iY;
	}
	switch (m_enumCurrentDirection)
	{
	case UP:
		m_vecBody[0].m_iY--;
		break;
	case DOWN:
		m_vecBody[0].m_iY++;
		break;
	case LEFT:
		m_vecBody[0].m_iX--;
		break;
	case RIGHT:
		m_vecBody[0].m_iX++;
		break;
	}
	showSnake();
	Sleep(m_iSpeed);
	//_sleep(m_iSpeed);
}
bool CSnake::eatFood(CFood* pFood)
{
	if (m_vecBody[0].m_iX == pFood->m_iX && m_vecBody[0].m_iY == pFood->m_iY)
	{
		growup();
		return true;
	}
	return false;
}
