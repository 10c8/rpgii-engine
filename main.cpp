/***
 * RPGii Engine
 * ASCII-based open-source RPG game engine
 *
 * @version 0.0.03
 * @copyright GPL (c) 2007
**/

#include <iostream>
using namespace std;

#include <windows.h>
#include <conio.h>
#include <stdlib.h>

// System variables
int Key;

char* CurNPCName;
int CurNPCX;
int CurNPCY;
int CurNPCColor;

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
void SetNPC(int NPX, int NPY, int Color);
void DrawNPC();

int main()
{
	SetConsoleTitle(GameTitle);
	
	CurMap_tTestCity();
	
	DrawGUI();
	DrawMapArray();
	
	MoveCur(PlayerX,PlayerY);
	 Colous(7);
	 cout << (char)001;
	
	SetNPC(NPCX_One, NPCY_One, 3);

	while(Key != 113)
	{
		DrawNPC();
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

/* NPC Functions */
void NPC_MoveUp();
void NPC_MoveDown();
void NPC_MoveLeft();
void NPC_MoveRight();

void SetNPC(int NPX, int NPY, int Color){
	CurNPCX = NPX;
	CurNPCY = NPY;
	CurNPCColor = Color;
	
	MoveCur(NPX,NPY);
	 Colous(Color);
	 cout << "@";
}

void DrawNPC()
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
			if(CurNPCY-1 == PlayerY and CurNPCX == PlayerX) break; // Player is above NPC
			if(CurNPCY+1 == PlayerY and CurNPCX == PlayerX) break; // NPC is above Player
			if(CurNPCY == PlayerY and CurNPCX-1 == PlayerX) break; // Player is in left side of NPC
			if(CurNPCY == PlayerY and CurNPCX+1 == PlayerX) break; // Player is in right side of NPC
			
			if(CurMap[CurNPCY-1][CurNPCX] == '#') /*NPC_MoveDown();*/ break;
			if(MoveUp == 1) break;
			NPC_MoveUp();
		break;
		
		case 3: // Down
			if(CurNPCY-1 == PlayerY and CurNPCX == PlayerX) break; // Player is above NPC
			if(CurNPCY+1 == PlayerY and CurNPCX == PlayerX) break; // NPC is above Player
			if(CurNPCY == PlayerY and CurNPCX-1 == PlayerX) break; // Player is in left side of NPC
			if(CurNPCY == PlayerY and CurNPCX+1 == PlayerX) break; // Player is in right side of NPC
			
			if(CurMap[CurNPCY+1][CurNPCX] == '#') /*NPC_MoveUp();*/ break;
			if(MoveDown == 1) break;
			NPC_MoveDown();
		break;
		
		case 4: // Left
			if(CurNPCY-1 == PlayerY and CurNPCX == PlayerX) break; // Player is above NPC
			if(CurNPCY+1 == PlayerY and CurNPCX == PlayerX) break; // NPC is above Player
			if(CurNPCY == PlayerY and CurNPCX-1 == PlayerX) break; // Player is in left side of NPC
			if(CurNPCY == PlayerY and CurNPCX+1 == PlayerX) break; // Player is in right side of NPC
			
			if(CurMap[CurNPCY][CurNPCX-1] == '#') /*NPC_MoveRight();*/ break;
			if(MoveLeft == 1) break;
			NPC_MoveLeft();
		break;
		
		case 5: // Right
			if(CurNPCY-1 == PlayerY and CurNPCX == PlayerX) break; // Player is above NPC
			if(CurNPCY+1 == PlayerY and CurNPCX == PlayerX) break; // NPC is above Player
			if(CurNPCY == PlayerY and CurNPCX-1 == PlayerX) break; // Player is in left side of NPC
			if(CurNPCY == PlayerY and CurNPCX+1 == PlayerX) break; // Player is in right side of NPC
			
			if(CurMap[CurNPCY][CurNPCX+1] == '#') /*NPC_MoveLeft();*/ break;
			if(MoveRight == 1) break;
			NPC_MoveRight();
		break;
	}
}

void NPC_MoveUp()
{
	MoveCur(CurNPCX,CurNPCY);
	 cout << " ";
 
	CurNPCY--;
	 
	MoveCur(CurNPCX,CurNPCY);
	 Colous(CurNPCColor);
	 cout << "@";
}

void NPC_MoveDown()
{
	MoveCur(CurNPCX,CurNPCY);
	 cout << " ";
	 
	CurNPCY++;
	 
	MoveCur(CurNPCX,CurNPCY);
	 Colous(CurNPCColor);
	 cout << "@";
}

void NPC_MoveLeft()
{
	MoveCur(CurNPCX,CurNPCY);
	 cout << " ";
	 
	CurNPCX--;
	 
	MoveCur(CurNPCX,CurNPCY);
	 Colous(CurNPCColor);
	 cout << "@";
}

void NPC_MoveRight()
{
	MoveCur(CurNPCX,CurNPCY);
	 cout << " ";
	 
	CurNPCX++;
	 
	MoveCur(CurNPCX,CurNPCY);
	 Colous(CurNPCColor);
	 cout << "@";
}
