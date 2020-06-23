#include "CGame.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int main(void)
{
	CGame game;
	game.run();

	cout << endl;
	//system("pause");
	getchar();

	return 0;
}
