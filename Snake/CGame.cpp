#include "CGame.h"
#include "CTools.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int CGame::KLEFT = 5;
const int CGame::KUP = 2;
const int CGame::KWIDTH = 70;
const int CGame::KHEIGHT = 20;
const int KSCORE_OFFSET = 30;
const int KLEVEL_OFFSET = 55;

CGame::CGame()
{
	this->m_pFood = new CFood(0, 0, '*');
	this->m_pSnake = new CSnake(20, 10, 4, UP, 200, 'O');
	this->m_iScore = 0;
	this->m_iLevel = 1;

	drawGameArea();
	drawGameInfo();
}


CGame::~CGame()
{
	delete m_pFood;
	delete m_pSnake;
	m_pFood = NULL;
	m_pSnake = NULL;
}

void CGame::drawGameArea()
{
	CTools::gotoxy(KLEFT, KUP);
	for(int i = 0; i < KWIDTH; ++i)
		cout << "-";

	for (int i = 0; i < KHEIGHT; ++i)
	{
		CTools::gotoxy(KLEFT, KUP + 1 + i);
		cout << "|";
		CTools::gotoxy(KLEFT + KWIDTH - 1, KUP + 1 + i);
		cout << "|";
	}

	CTools::gotoxy(KLEFT, KUP + KHEIGHT + 1);
	for (int i = 0; i < KWIDTH; ++i)
		cout << "-";

	CTools::gotoxy(KLEFT + 1, KUP + 2);
	for (int i = 0; i < KWIDTH - 2; ++i)
		cout << "-";
	
}
void CGame::drawGameInfo()
{
	CTools::gotoxy(KLEFT + 1, KUP + 1);
	cout << "ÓÎÏ·Ãû³Æ£ºÌ°³ÔÉß";
	
	CTools::gotoxy(KLEFT + KSCORE_OFFSET, KUP + 1);
	cout << "SCORE: " << this->m_iScore;

	CTools::gotoxy(KLEFT + KLEVEL_OFFSET, KUP + 1);
	cout << "LEVEL: " << this->m_iLevel;
}

void CGame::run()
{
	m_pFood->createPos(&(m_pSnake->m_vecBody));
	m_pFood->show();
	m_pSnake->showSnake();

	int key = 0;
	bool stopFlag = true;
	bool pauseFlag = true;
	while (key != VK_ESCAPE && stopFlag)  // 0x1b
	{
		if (_kbhit())
		{
			key = _getch();
			m_pSnake->changeDirection(key);
			if (key == VK_SPACE)
			{
				pauseFlag = !pauseFlag;
			}
		}
		else {
			if (pauseFlag)
			{
				continue;
			}
			m_pSnake->move();
			if (m_pSnake->eatFood(m_pFood))
			{
				// score level, chagne info, speed
				m_iScore += 10;
				drawGameInfo();
				if (checkLevel())
				{
					// tongguan
					break;
				}

				m_pFood->createPos(&m_pSnake->m_vecBody);
				m_pFood->show();

			}

			if (checkFailed())
			{
				CTools::gotoxy(0, 0);
				cout << "Failed.";
				stopFlag = false;
			}
		}
	}
}

bool CGame::checkFailed()
{
	// crash
	if (m_pSnake->m_vecBody[0].m_iX <= CGame::KLEFT)
	{
		return true;
	}
	if (m_pSnake->m_vecBody[0].m_iX >= CGame::KLEFT+ KWIDTH -1)
	{
		return true;
	}
	if (m_pSnake->m_vecBody[0].m_iY < CGame::KUP + 3)
	{
		return true;
	}
	if (m_pSnake->m_vecBody[0].m_iY >= CGame::KUP + KHEIGHT+1)
	{
		return true;
	}

	// self-kill
	for (int i = 4; i < m_pSnake->m_iLength; ++i)
	{
		if (m_pSnake->m_vecBody[i].m_iX == m_pSnake->m_vecBody[0].m_iX && m_pSnake->m_vecBody[i].m_iY == m_pSnake->m_vecBody[0].m_iY)
			return true;
	}

	return false;
}


bool CGame::checkLevel()
{
	int temp = m_iScore / 30 + 1;
	if (temp == m_iLevel)
		return false;
	m_iLevel = temp;
	switch (m_iLevel)
	{
	case 1:
		break;
	case 2:
		
		break;
	case 3:
		CTools::gotoxy(0, 0);
		cout << "Very good.";
		return true;
		break;

	}
	return false;
}