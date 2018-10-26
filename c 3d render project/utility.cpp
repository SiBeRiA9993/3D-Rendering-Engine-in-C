#include "utility.h"

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
