#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printPole(int x, int y) {
	gotoxy(y, x);
	putchar('X');
}

int main()
{
	int down = 23;
	int up = 0;
	int right = 79;
	int left = 0;
	int xEnd = -1;
	int yEnd = -1;
	int x = 0;
	int y = 79;
	int diagonal = 0;
	int pole[25][80] = { 0 };
	while (x != xEnd && y != yEnd)
	{
		if (x == down)
		{
			pole[x][y] = 1;
			printPole(x, y);
			y--;
			pole[x][y] = 1;
			printPole(x, y);
			y--;
			x--;
			pole[x][y] = 1;
			printPole(x, y);
			diagonal = 1;
		}
		else if (x == up)
		{
			pole[x][y] = 1;
			printPole(x, y);
			y--;
			pole[x][y] = 1;
			printPole(x, y);
			x++;
			y++;
			pole[x][y] = 1;
			printPole(x, y);
			diagonal = 2;
		}
		else if (y == right)
		{
			x++;
			pole[x][y] = 1;
			printPole(x, y);
			y--;
			x--;
			pole[x][y] = 1;
			printPole(x, y);
			diagonal = 1;
		}
		else if (y == left)
		{
			pole[x][y] = 1;
			printPole(x, y);
			x++;
			pole[x][y] = 1;
			printPole(x, y);
			x++;
			y++;
			pole[x][y] = 1;
			printPole(x, y);
			diagonal = 2;
		}
		else if (diagonal == 1)
		{
			x--;
			y--;
			pole[x][y] = 1;
			printPole(x, y);
		}
		else if (diagonal == 2)
		{
			x++;
			y++;
			pole[x][y] = 1;
			printPole(x, y);
		}
		Sleep(1);
	}
	getchar();
	return 0;
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 80; j++) {
			if (pole[i][j] != 0) {
				printf("%d", pole[i][j]);
			}
		}
		printf("\n");
	}
}

