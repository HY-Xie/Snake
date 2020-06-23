#pragma once
#include "CFood.h"
#include "CSnake.h"

class CGame
{
public:
	CGame();
	virtual ~CGame();

public:
	static const int KLEFT;
	static const int KUP;
	static const int KWIDTH;
	static const int KHEIGHT;
	static const int KSCORE_OFFSET = 30;
	static const int KLEVEL_OFFSET = 55;

public:
	CFood *m_pFood;
	CSnake *m_pSnake;
	int m_iScore;
	int m_iLevel;


public:
	void drawGameArea();
	void drawGameInfo();
	bool checkLevel();
	void run();
	bool checkFailed();
};

