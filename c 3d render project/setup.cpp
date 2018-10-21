#include "setup.h"

void cursor() {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
void setup() {
	system("mode con cols=200 lines=45");
	HWND hWnd = FindWindow("ConsoleWindowClass", NULL);
	printf("Plz wait...");
	gotoxy(0, 0);
	Sleep(100);
	SendMessage(hWnd, WM_SYSKEYDOWN, VK_RETURN, 0x211C0001);
	cursor();
}