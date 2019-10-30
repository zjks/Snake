// snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#define MAP_WIDTH 60
#define MAP_HEIGHT 20
void DrawChar(int x,int y,char ch);
typedef struct Position
{
	int x;
	int y;
}Position;

typedef struct Snake
{
	int size;
	Position pos[MAP_WIDTH * MAP_HEIGHT];
}Snake;

Snake g_snake;

Position g_food;

void InitFood()
{
	srand((unsigned)time( NULL ));
	g_food.x = rand() % MAP_WIDTH;
	g_food.y = rand() % MAP_HEIGHT;

	DrawChar(g_food.x,g_food.y, '#');
}

void InitSnake()
{
	g_snake.size=3;
	g_snake.pos[0].x = MAP_WIDTH / 2 ;
	g_snake.pos[0].y = MAP_HEIGHT / 2 ;

	g_snake.pos[1].x = MAP_WIDTH / 2 -1;
	g_snake.pos[1].y = MAP_HEIGHT / 2 ;

	g_snake.pos[2].x = MAP_WIDTH / 2 -2;
	g_snake.pos[2].y = MAP_HEIGHT / 2 ;
}
void DrawSnake()
{
	for(int i=0;i<g_snake.size ;i++)
	{
		if(i==0)
		{
			DrawChar(g_snake.pos[i].x,g_snake.pos[i].y, '*');
		}
		else
		{
			DrawChar(g_snake.pos[i].x,g_snake.pos[i].y, '#');
		}
	}
}

void DrawChar(int x,int y,char ch)
{
	COORD pos;
	pos.X =x;
	pos.Y =y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	putchar(ch);

}

void InitMap()
{
	for(int i=0;i<=MAP_HEIGHT;i++)
	{
		for(int j=0;j<=MAP_WIDTH;j++)
		{
			if(j == MAP_WIDTH)
			{
				printf("|\n");
			}
			else if(i == MAP_HEIGHT)
			{
			   	printf("-");	
			}
			else
			{
				printf(" ");		
			}
		}
	}
}


void Init()
{
	InitMap();
	InitSnake();
	InitFood();
}

void UpdateScreen()
{
	DrawSnake();
}

void GameLoop()
{
	int key =0;

	while (1)
	{
		if(_kbhit())
		{
			key =_getch();
		}
		
		if(key == 'q' || key == 'Q')
		{
			return;
		}

		UpdateScreen();

		Sleep(100);
	}
}


void Score()
{
}



int main(int argc, char* argv[])
{
	Init();
	GameLoop();
	Score();
	
	
	return 0;
}

