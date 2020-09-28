#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcolor(int, int);
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void draw_bullet(int, int);
void erase_bullet(int, int);
void setcursor(bool);

int main()
{
	char ch = ' ';
	char direct='S';
	int shot = 0;
	int x = 38, y = 20,x_s,y_s;
	

	setcursor(0);
	draw_ship(x, y);
	do {
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 32&&shot==0)
		    {
			  shot = 1;
			  x_s = x + 3;
			  y_s = y - 1;
			  draw_bullet(x_s, y_s);
		    }
			if (ch == 'a') //L=Left
			{
				direct = 'L';
			}
			if (ch == 'd')//R=Right
			{
				direct = 'R';
			}
			if (ch == 's')//S=Stop
			{
				direct = 'S';
			}
		}
		fflush(stdin);

		if (shot == 1)
		{
			erase_bullet(x_s, y_s);
			if (y_s  != 0)
			{
				draw_bullet(x_s, --y_s);
			}
			else
			{
				shot = 0;
			}
		}
		
		if (direct == 'L' && x != 0)
		{
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direct == 'R' && x != 73)
		{
			erase_ship(x, y);
			draw_ship(++x, y);
		}

		Sleep(100);
	
	} while (ch != 'x');
	printf("\n");
	setcolor(0, 0);
	return 0;
}


void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(1, 11);
	printf(" <-0-> ");
	
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(11,0);
	printf("|");
}
void erase_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}