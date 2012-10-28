/***
 * RPGii Engine
 * ASCII-based open-source RPG game engine
 *
 * @version 0.0.02
 * @copyright GPL (c) 2007
**/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// System variables
int Key;

int RandomDirection;
 int MoveUp = 0;
 int MoveDown = 0;
 int MoveLeft = 0;
 int MoveRight = 0;
 int MoveURange = 2;
 int MoveDRange = 2;
 int MoveLRange = 2;
 int MoveRRange = 2;

char CurMap[19][79];
char* CurMapName;

int PlayerX = 1;
int PlayerY = 1;

int NPCX_One = 13;
int NPCY_One = 7;

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
char tTestCity[19][59] = {"##########################################################",
						  "#                                                        #",
					  	  "#                                                        #",
					  	  "#                                                        #",
					 	  "#                                                        #",
					 	  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "#                                                        #",
						  "##########################################################"};

char tGUI[25][80] = {"                                                           +------------------+",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           +------------------+",
					 "                                                           |                  |",
					 "                                                           +------------------+",
                     "                                                           +------------------+",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "                                                           |                  |",
					 "+---------------------------------------------------------+|                  |",
				     "| RPGii Engine | [ ]quipment [ ]nventory [ ]inimap [ ]uit ||                  |",
				     "+---------------------------------------------------------+|                  |",
                     "| HP:     | MP:     | Atk/Def:   /   | Exp:     | Lvl:    ||                  |",
                     "+---------------------------------------------------------++------------------+"};

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
		for(int j = 0; j < 58; j++)
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
		for(int j = 0; j < 58; j++)
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
	MoveCur(0,0);
	
	for(int i = 0; i < 25; i++)
	{
		for(int j = 0; j < 79; j++)
		{
			cout << tGUI[i][j];
		}
		cout << endl;
	}
	MoveCur(61,12);
	 Colous(7);
	 cout << CurMapName; // Name of the current map
	 
	MoveCur(18,21);
	 Colous(2);
	 cout << "E"; // [E]quipment decoration
	
	MoveCur(30,21);
	 Colous(2);
	 cout << "I"; // [I]nventory decoration
	 
	MoveCur(42,21);
	 Colous(2);
	 cout << "M"; // [M]inimap decoration
	 
	MoveCur(52,21);
	 Colous(4);
	 cout << "Q"; // [Q]uit decoration
	 
	GUIInfo();
}

void DrawNPC_VillagerOne();

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
			if(CurMap[PlayerY-1][PlayerX] == '#') break;
			
			MoveCur(PlayerX,PlayerY);
			 cout << " ";
			 
			PlayerY--;
			 
			MoveCur(PlayerX,PlayerY);
			 cout << (char)001;
		break;
		
		case 115: // S
			if(CurMap[PlayerY+1][PlayerX] == '#') break;
			
			MoveCur(PlayerX,PlayerY);
			 cout << " ";
			 
			PlayerY++;
			 
			MoveCur(PlayerX,PlayerY);
			 cout << (char)001;
		break;
		
		case 97: // A
			if(CurMap[PlayerY][PlayerX-1] == '#') break;
			
			MoveCur(PlayerX,PlayerY);
			 cout << " ";
			 
			PlayerX--;
			 
			MoveCur(PlayerX,PlayerY);
			 cout << (char)001;
		break;
		
		case 100: // D
			if(CurMap[PlayerY][PlayerX+1] == '#') break;
			
			MoveCur(PlayerX,PlayerY);
			 cout << " ";
			 
			PlayerX++;
			 
			MoveCur(PlayerX,PlayerY);
			 cout << (char)001;
		break;
	}
}
	
/* Engine "boot" */
int main()
{
	SetConsoleTitle(GameTitle);
	
	CurMap_tTestCity();
	 
	DrawGUI();
	DrawMapArray();
	
	MoveCur(PlayerX,PlayerY);
	 Colous(7);
	 cout << (char)001;
	
	MoveCur(NPCX_One,NPCY_One);
	 Colous(7);
	 cout << "M";
	
	while(Key != 113)
	{
		DrawNPC_VillagerOne();
		GUIInfo();
		
		if(kbhit()){Key = getch(); ParseKeys();}
		
		MoveCur(79,0);
		Sleep(100);
	}
	return 0;
}

/* Tile functions */
void CurMap_tTestCity()
{
	CurMapName = " Aurora Village";
	
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 79; j++)
		{
			CurMap[i][j] = tTestCity[i][j];
		}
	
	}
}

void DrawNPC_VillagerOne()
{
	RandomDirection = rand() % 6;
	
	switch(RandomDirection){
		case 0: // No movement and time to randomize the next move
			MoveUp = rand() % MoveURange;
			MoveDown = rand() % MoveDRange;
			MoveLeft = rand() % MoveLRange;
			MoveRight = rand() % MoveRRange;
		break;
		
		case 1: // Simply nothing
		break;
		
		case 2: // Up
			if(CurMap[NPCY_One-1][NPCX_One] == '#') break;
			if(MoveUp == 0) break;
			
			MoveCur(NPCX_One,NPCY_One);
			 cout << " ";
			 
			NPCY_One--;
			 
			MoveCur(NPCX_One,NPCY_One);
			 cout << "M";
		break;
		
		case 3: // Down
			if(CurMap[NPCY_One+1][NPCX_One] == '#') break;
			if(MoveDown == 0) break;
			
			MoveCur(NPCX_One,NPCY_One);
			 cout << " ";
			 
			NPCY_One++;
			 
			MoveCur(NPCX_One,NPCY_One);
			 cout << "M";
		break;
		
		case 4: // Left
			if(CurMap[NPCY_One][NPCX_One-1] == '#') break;
			if(MoveLeft == 0) break;
			
			MoveCur(NPCX_One,NPCY_One);
			 cout << " ";
			 
			NPCX_One--;
			 
			MoveCur(NPCX_One,NPCY_One);
			 cout << "M";
		break;
		
		case 5: // Right
			if(CurMap[NPCY_One][NPCX_One+1] == '#') break;
			if(MoveRight == 0) break;
			
			MoveCur(NPCX_One,NPCY_One);
			 cout << " ";
			 
			NPCX_One++;
			 
			MoveCur(NPCX_One,NPCY_One);
			 cout << "M";
		break;
	}
}
