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
void showXY(_cube cube, _player player, double Hrad, double Vrad) {
	gotoxy(0, 0);
	printf("cube x:%.4lf y:%.4lf z:%.4lf ax:%.4lf ay:%.4lf az:%.4lf", cube.p[0].x, -cube.p[0].y, cube.p[0].z, cube.p[0].ax, cube.p[0].ay, cube.p[0].az);
	gotoxy(0, 1);
	printf("player x:%.4lf y:%.4lf z:%.4lf", player.x, player.y, player.z);
	gotoxy(0, 2);
	printf("Hrad:%.4lf Vrad:%.4lf", Hrad, Vrad);
	gotoxy(0, 3);
	printf("Hrad xcos:%.4lf Hrad ycos:%.4lf", cube.p[1].dx * cos(Hrad), cube.p[1].dy * sin(Hrad));
	gotoxy(0, 5);
	printf("Hangle:%.4lf Vangle:%.4lf", player.H_angle, player.V_angle);
	gotoxy(0, 6);
	printf("cube x:%.4lf y:%.4lf z:%.4lf ax:%.4lf ay:%.4lf az:%.4lf", cube.p[1].x, -cube.p[1].y, cube.p[1].z, cube.p[1].ax, cube.p[1].ay, cube.p[1].az);
	gotoxy(0, 7);
	printf("cube x:%.4lf y:%.4lf z:%.4lf ax:%.4lf ay:%.4lf az:%.4lf", cube.p[2].x, -cube.p[2].y, cube.p[2].z, cube.p[2].ax, cube.p[2].ay, cube.p[2].az);
}