/***
 * RPGii Engine
 * ASCII-based open-source RPG game engine
 *
 * @copyright GPL © 2007
**/

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

// System variables
int Key;

// "Game" config
const char* GameTitle = "RPGii Engine - Tests!";

/* Main engine code */
void MoveCur(int cX, int cY)
{
	COORD CurPos;
	CurPos.X = cX;
	CurPos.Y = cY;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurPos);
}

void Colous(int cO)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cO);
}

void ParseKeys(){
	// Nothing yet
}

void DoTest();

int main()
{
	SetConsoleTitle(GameTitle);
	
	DoTest();
	
    while(Key != 27)
    {
		if(kbhit()){Key = getch(); ParseKeys();}
		
		MoveCur(0,0);
		Sleep(100);
    }
    return 0;
}

/* The testing area! :D */
void DoTest()
{
	MoveCur(20, 8);
	 cout << "Testing the MoveCur function.";
	MoveCur(12, 17);
	 Colous(1); cout << "Testing ";
	 Colous(2); cout << "now ";
	 Colous(3); cout << "Colous ";
	 Colous(4);	cout << "function ";
	 Colous(5); cout << "too.";
}
