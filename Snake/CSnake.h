#pragma once
#include <vector>
#include "CUnit.h"
#include "CFood.h"
using namespace std;
typedef enum {
	UP, DOWN, LEFT, RIGHT
} Directions;

class CSnake
{
public:
	CSnake(int headX, int headY, int length, Directions direction, int speed, char pic);
	virtual ~CSnake();

	void showSnake();
	void eraseSnake();
	void growup();
	void changeDirection(int vkValue); // W, S, A, D 
	void move();
	bool eatFood(CFood* pFood);
	
public:
	int m_iLength;
	int m_iHeadX;
	int m_iHeadY;
	int m_iSpeed;
	char m_cPic;
	Directions m_enumCurrentDirection;
	vector<CUnit> m_vecBody;




	
};

