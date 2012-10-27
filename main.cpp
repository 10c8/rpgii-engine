/***
 * RPGii Engine
 * ASCII-based open-source RPG game engine
 *
 * @copyright GPL (c) 2007
**/

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

// System variables
int Key;

const char* Player = "@";
int x = 0;
int y = 0;

// "Game" config
const char* GameTitle = "RPGii Engine - Tests!";

/* Game Tiles */
char tGUI[6][60] = {"+---------------------------------------------------------+",
				    "| RPGii Engine | [E]quipment [I]nventory [M]inimap [Q]uit |",
				    "+---------------------------------------------------------+",
                    "| HP: 100 | MP: 100 | Atk/Def: 01/01 | Exp: 000 | Lvl: 01 |",
                    "+---------------------------------------------------------+"};

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

void DrawGUI()
{
	MoveCur(0,20);
	
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 60; j++)
		{
			cout << tGUI[i][j];
		}
		cout << endl;
	}
}

void ParseKeys()
{
	switch(Key)
	{
		/* Commands */
		case 101: // E
			// Nothing yet
		break;
		
		case 105: // I
			// Nothing yet
		break;
		
		case 109: // M
			// Nothing yet
		break;
		
		/* Movement and actions */
		case 119: // W
			if(y > 0){
			 MoveCur(x, y);
			  cout << " ";
			 
			 y--;
			 
			 MoveCur(x, y);
			  cout << Player;
			}
		break;
		
		case 115: // S
			if(y < 28){
			 MoveCur(x, y);
			  cout << " ";
			 
			 y++;
			 
			 MoveCur(x, y);
			  cout << Player;
			}
		break;
		
		case 97: // A
			if(x > 0){
			 MoveCur(x, y);
			  cout << " ";
			 
			 x--;
			 
			 MoveCur(x, y);
			  cout << Player;
			}
		break;
		
		case 100: // D
			if(x < 79){
			 MoveCur(x, y);
			  cout << " ";
			 
			 x++;
			 
			 MoveCur(x, y);
			  cout << Player;
			}
		break;
	}
}

void DoTest();
int main()
{
	SetConsoleTitle(GameTitle);
	
	DrawGUI();
	
	MoveCur(0,0);
	cout << Player;
	
	while(Key != 113)
	{
		if(kbhit()){Key = getch(); ParseKeys();}
		
		MoveCur(79,0);
		Sleep(50);
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
