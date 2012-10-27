/***
 * RPGii Engine
 * ASCII-based open-source RPG game engine
 *
 * @version 0.0.01
 * @copyright GPL (c) 2007
**/

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

// System variables
int Key;
char CurMap[19][79];

const char* Player = "@";
int x = 1;
int y = 1;

int pHP = 100;
int pMP = 100;
int pAtk = 10;
int pDef = 10;
int pExp = 0;
int pLvl = 1;

// "Game" config
const char* GameTitle = "RPGii Engine - Development Version";

/* Game Tiles */
void CurMap_tTestCity();
char tTestCity[19][79] = {"##################################################",
						  "#      #                                         #",
						  "#                                                #",
						  "########                                         #",
						  "#                                                #",
						  "#                                                #",
						  "#                                                #",
						  "#                                                #",
						  "#                                                #",
						  "#                                                #",
						  "#                                                #",
						  "##################################################"};

char tGUI[6][60] = {"+---------------------------------------------------------+",
				    "| RPGii Engine | [E]quipment [I]nventory [M]inimap [Q]uit |",
				    "+---------------------------------------------------------+",
                    "| HP:     | MP:     | Atk/Def:   /   | Exp:     | Lvl:    |",
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

void DrawMap()
{
	MoveCur(0,0);
	
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 79; j++)
		{
			switch(CurMap[i][j])
			{
				case '#':
					MoveCur(j,i);
                     cout << (char)178;
				break;
			}
		}
	}
}

void DrawMapArray()
{
	MoveCur(0,0);
	
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 79; j++)
		{
			cout << CurMap[i][j];
		}
		cout << endl;
	}
	
	DrawMap();
}

void GUIInfo()
{
	MoveCur(6,23);
	 Colous(10);
	 cout << pHP; // Health
	 
	MoveCur(16,23);
	 Colous(9);
	 cout << pMP; // Mana
	
	MoveCur(31,23);
	 Colous(8);
	 cout << pAtk; // Attack Points
	
	MoveCur(34,23);
	 Colous(8);
	 cout << pDef; // Defense Points
	
	MoveCur(44,23);
	 Colous(3);
	 cout << pExp; // Experience Points
	 
	MoveCur(55,23);
	 Colous(2);
	 cout << pLvl; // Player Level
	 
	Colous(7);
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
	
	GUIInfo();
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
			if(CurMap[y-1][x] == '#') break;
			
			MoveCur(x,y);
			 cout << " ";
			 
			y--;
			 
			MoveCur(x,y);
			 cout << Player;
		break;
		
		case 115: // S
			if(CurMap[y+1][x] == '#') break;
			
			MoveCur(x,y);
			 cout << " ";
			 
			y++;
			 
			MoveCur(x,y);
			 cout << Player;
		break;
		
		case 97: // A
			if(CurMap[y][x-1] == '#') break;
			
			MoveCur(x,y);
			 cout << " ";
			 
			x--;
			 
			MoveCur(x,y);
			 cout << Player;
		break;
		
		case 100: // D
			if(CurMap[y][x+1] == '#') break;
			
			MoveCur(x,y);
			 cout << " ";
			 
			x++;
			 
			MoveCur(x,y);
			 cout << Player;
		break;
	}
}

/* Engine "boot" */
int main()
{
	SetConsoleTitle(GameTitle);
	
	CurMap_tTestCity();
	
	DrawMapArray();
	DrawGUI();
	
	MoveCur(x,y);
	 Colous(7);
	 cout << Player;
	
	while(Key != 113)
	{
		GUIInfo();
		 
		if(kbhit()){Key = getch(); ParseKeys();}
		
		MoveCur(79,0);
		Sleep(50);
	}
	return 0;
}

/* CurMap functions */
void CurMap_tTestCity()
{
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 79; j++)
		{
			CurMap[i][j] = tTestCity[i][j];
		}
	
	}
}
