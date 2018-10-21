#include "draw.h"

void drawLine(int x0, int y0, int x1, int y1) {
	extern int data[10000][2]; //점프
	extern int datalong;
	extern int cnt;

	if (x0 < 0 && x1 < 0)return; //선 그릴필요없음
	if (y0 < 0 && y1 < 0)return;
	if (x0 > 200 || x1 > 200)return; //선 그릴필요없음
	if (y0 > 200 || y1 > 200)return;
	if (x0 == INF || x1 == INF)return;

	int dx = abs(x1 - x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy) / 2, e2;

	for (;;) {
		{
			if (x0 < 0 && y0 < 0)return;
			else if (x0 > 105);
			else if (y0 > 60);
			else if (x0 < 0);
			else if (y0 < 0);
			else if (x1 > 105);
			else if (y1 > 60);
			else if (x1 < 0);
			else if (y1 < 0);
			//else if (x0 > 100);
			//else if (y0 > 45);
			//else if (x0 < 0);
			//else if (y0 < 0);
			//else if (x1 > 100);
			//else if (y1 > 45);
			//else if (x1 < 0);
			//else if (y1 < 0);
			else {
				gotoxy(x0 * 2, y0);
				printf("■");
			}
		}
		if (x0 == x1 && y0 == y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}
void drawPoint(int x, int y) {
	gotoxy(x * 2, y);
	printf("□");
}