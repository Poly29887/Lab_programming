#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void setcolor(int, int);
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void draw_star();
void re_star();
void check_star(int);
void clear_star(int , int);
void draw_bullet(int, int);
void erase_bullet(int, int);
void setcursor(bool);
int random_num(int, int);
char cursor(int, int);
void check_score(int);

//Globals variables
int x_star[21], y_star[21];
int score=0; //shot status

int main()
{
	char ch = ' '; 
	char direct = 'S',firstRound='Y';
	int x = 38, y = 20, x_bullet[5] , y_bullet[5] ;
	int beep = 0, shot[5] = { 0,0,0,0,0 };
	int i;

	srand(time(NULL));
	setcursor(0);
	draw_ship(x, y);
	check_score(0);
	for (i = 0; i < 20; i++)
	{
		x_star[i] = 0;
		y_star[i] = 0;
	}
	//randomStar
    draw_star();

	do {
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 32)
			{
				for (i = 0; i < 5; i++)
				{
					if (shot[i] == 0)
					{
						shot[i] = 1;
						x_bullet[i] = x + 3;
						y_bullet[i] = y - 1;
						draw_bullet(x_bullet[i], y_bullet[i]);
						break;
					}
				}
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

		for (i = 0; i < 5; i++)
		{
 			if (shot[i] == 1)
			{
				erase_bullet(x_bullet[i], y_bullet[i]);
				if (y_bullet[i] != 1)
				{
					if (cursor(x_bullet[i], y_bullet[i]-1)=='*')
					{
						shot[i] = 0;
						check_score(1);
						Beep(700, 100);
						clear_star(x_bullet[i], y_bullet[i] - 1);
						draw_star();
						
					}
					else 
					{
						draw_bullet(x_bullet[i], --y_bullet[i]);
					}
				}
				else
				{
					shot[i] = 0;
				}
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
void draw_star()
{
	setcolor(6,0);
	int i;
	for (i = 0; i < 20; i++)
	{
		if (x_star[i] == 0 && y_star[i] == 0)
		{
			x_star[i] = random_num(10, 70);
			y_star[i] = random_num(2, 5);
			check_star(i);
			gotoxy(x_star[i], y_star[i]);
			printf("*");
		}
	}
}
void clear_star(int x_b, int y_b)
{
	int j;
	for (j = 0; j < 20; j++)
	{
		if (x_star[j] == x_b && y_star[j] == y_b)
		{
			x_star[j] = 0;
			y_star[j] = 0;
			break;
		}
	}
	gotoxy(x_b, y_b);
	setcolor(0, 0);
	printf(" ");
}
void check_star(int round)
{
	int j;
	for (j = 0; j < round;j++)
	{
		if (x_star[round] == x_star[j]&& y_star[round] == y_star[j])
		{
			x_star[round] = random_num(10, 70);
			y_star[round] = random_num(2, 5);
			j = 0;
		}
	}
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(11, 0);
	printf("^");
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
int random_num(int a,int b)
{
	int n;
	n = rand();
	while (n<a || n>b)
	{
		n = rand();
	}
	return n;
}
char cursor(int x, int y) 
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}
void check_score(int collide)
{   
	if (collide == 1)
	{
		score += 1;
	}
	gotoxy(71, 0);
	setcolor(7, 0);
	printf("SCORE %d",score);
}
