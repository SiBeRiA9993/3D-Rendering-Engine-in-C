#include "main.h"

//int data[10000][2]; //점프
//int datalong = 0;
int cnt = 0;

void main() {
	setup(); //콘솔셋
	_player player; //플레이어
	_cube cube; //정육면체
	//dif_cubeset; //정육면체 선언 main.h define 참고

	//도형 선언
	int cubeline[12][2] = { { 0,1 },{ 2,3 },{ 0,2 },{ 1,3 },{ 4,6 },{ 5,7 },{ 4,5 },{ 6,7 },{ 0,4 },{ 1,5 },{ 2,6 },{ 3,7 } };
	cube.p[0].z = 5; cube.p[0].x = 0; cube.p[0].y = -5;
	cube.p[1].z = 10; cube.p[1].x = 0; cube.p[1].y = -5;
	cube.p[2].z = 5; cube.p[2].x = 5; cube.p[2].y = -5;
	cube.p[3].z = 10; cube.p[3].x = 5; cube.p[3].y = -5;
	cube.p[4].z = 5; cube.p[4].x = 0; cube.p[4].y = 5;
	cube.p[5].z = 10; cube.p[5].x = 0; cube.p[5].y = 5;
	cube.p[6].z = 5; cube.p[6].x = 5; cube.p[6].y = 5;
	cube.p[7].z = 10; cube.p[7].x = 5; cube.p[7].y = 5;
	_cube figure2;
	figure2.p[0].z = 0; figure2.p[0].x = -10; figure2.p[0].y = -5;
	figure2.p[1].z = 5; figure2.p[1].x = -10; figure2.p[1].y = -5;
	figure2.p[2].z = 0; figure2.p[2].x = -15; figure2.p[2].y = -5;
	figure2.p[3].z = 5; figure2.p[3].x = -15; figure2.p[3].y = -5;
	figure2.p[4].z = 2.5; figure2.p[4].x = -12.5; figure2.p[4].y = 3;
	figure2.p[5].z = 2.5; figure2.p[5].x = -12.5; figure2.p[5].y = 3;
	figure2.p[6].z = 2.5; figure2.p[6].x = -12.5; figure2.p[6].y = 3;
	figure2.p[7].z = 2.5; figure2.p[7].x = -12.5; figure2.p[7].y = 3;
	_cube figure3;
	figure3.p[0].z = -10; figure3.p[0].x = 10; figure3.p[0].y = 3;
	figure3.p[1].z = -5; figure3.p[1].x = 10; figure3.p[1].y = 3;
	figure3.p[2].z = -10; figure3.p[2].x = 15; figure3.p[2].y = 3;
	figure3.p[3].z = -5; figure3.p[3].x = 15; figure3.p[3].y = 3;	
	figure3.p[4].z = 2.5; figure3.p[4].x = 12.5; figure3.p[4].y = -9;
	figure3.p[5].z = 2.5; figure3.p[5].x = 12.5; figure3.p[5].y = -9;
	figure3.p[6].z = 2.5; figure3.p[6].x = 12.5; figure3.p[6].y = -9;
	figure3.p[7].z = 2.5; figure3.p[7].x = 12.5; figure3.p[7].y = -9;
	int c = 0;
	for (int i = 0; i < 8; i++) { //미리 angle계산해서 좌표 구해두기
		cube.p[i] = get_Apoint(cube.p[i], player);
		figure2.p[i] = get_Apoint(figure2.p[i], player);
		figure3.p[i] = get_Apoint(figure3.p[i], player);
	}
	while (1) {
		//p = -d cos(s + π / 2)
		//q = d sin(s + π / 2)
		//p = d cos(s + π)
		//q = -d sin(s + π)
		//p = -d cos(s - π / 2)
		//q = d sin(s - π / 2)
		//p = d cos(s)
		//q = -d sin(s)
		bool chk = 0;
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) {
			player.x += (player.speed*cosf((player.H_angle*(PI / 180)) + PI));
			player.z += (-player.speed*sinf((player.H_angle*(PI / 180)) + PI));
			chk = true;
		}
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
			player.x += (player.speed*cosf((player.H_angle*(PI / 180))));
			player.z += (-player.speed*sinf((player.H_angle*(PI / 180))));
			chk = true;
		}
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) {
			player.x += (-player.speed*cosf((player.H_angle*(PI / 180)) + PI / 2));
			player.z += (player.speed*sinf((player.H_angle*(PI / 180)) + PI / 2));
			chk = true;
		}
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) {
			player.x += (-player.speed*cosf((player.H_angle*(PI / 180)) - PI / 2));
			player.z += (player.speed*sinf((player.H_angle*(PI / 180)) - PI / 2));
			chk = true;
		}
		//x_2 = xcos(s) - ysin(s)
		//y_2 = xsin(s) + ycos(s)
		//x_2 = (x - player.x)cos(s) - (z - player.z)sin(s) + player.x 
		//z_2 = (x - player.x)sin(s) + (z - player.z)cos(s) + player.z
		if (GetAsyncKeyState((unsigned short)VK_LEFT) & 0x8000) {
			if (player.H_angle - player.angle_speed < 0) player.H_angle = 359 + player.H_angle - player.angle_speed;
			else player.H_angle-=player.angle_speed;
			chk = true;
		}
		if (GetAsyncKeyState((unsigned short)VK_RIGHT) & 0x8000){
			if (player.H_angle + player.angle_speed >= 360) player.H_angle = (360-player.H_angle) - player.angle_speed;
			else player.H_angle += player.angle_speed;
			chk = true;
		}
		if ((GetAsyncKeyState((unsigned short)VK_SPACE) & 0x8000)&&player.jump!=true&&player.y==0) {
			player.jump = true;
			player.jump_tmp = player.jump_limit;
		}
		if (player.jump) {
			player.jump_long = player.jump_tmp / 6;
			player.jump_tmp %= 6;
			player.y += player.jump_long;
			if (player.jump_tmp == 0)player.jump = false;
			else if (player.jump_tmp <= 6)player.y += player.jump_tmp, player.jump = false;
		}
		else if (player.jump == false && player.y != 0) {
			if (player.y - player.gra < 0)player.y = 0, player.gra = 0;
			if (player.y - player.gra == 0)player.gra = 0;
			player.y-=player.gra++;
		}
		//if (GetAsyncKeyState((unsigned short)VK_UP) & 0x8000) {
		//	if (player.V_angle + player.angle_speed > 50);
		//	else player.V_angle+=player.angle_speed;
		//	chk = true;
		//	//for (int i = 0; i < 8; i++) {
		//	//	cube.p[i].ay = (cube.p[i].y - player.y)*cosf(player.V_angle*(PI / 180)) - (cube.p[i].z - player.z)*sinf(player.V_angle*(PI / 180)) + player.y;
		//	//	cube.p[i].az = (cube.p[i].x - player.x)*sinf(player.H_angle*(PI / 180)) + (cube.p[i].z - player.z)*cosf(player.H_angle*(PI / 180)) + player.z;
		//	//	cube.p[i].ax = (cube.p[i].x - player.x)*cosf(player.H_angle*(PI / 180)) - (cube.p[i].z - player.z)*sinf(player.H_angle*(PI / 180)) + player.x;
		//	//}
		//}
		//if (GetAsyncKeyState((unsigned short)VK_DOWN) & 0x8000) {
		//	if (player.V_angle - player.angle_speed < -50);
		//	else player.V_angle -= player.angle_speed;
		//	chk = true;
		//	//for (int i = 0; i < 8; i++) {
		//	//	cube.p[i].ay = (cube.p[i].y - player.y)*cosf(player.V_angle*(PI / 180)) - (cube.p[i].z - player.z)*sinf(player.V_angle*(PI / 180)) + player.y;
		//	//	cube.p[i].az = (cube.p[i].x - player.x)*sinf(player.H_angle*(PI / 180)) + (cube.p[i].z - player.z)*cosf(player.H_angle*(PI / 180)) + player.z;
		//	//	cube.p[i].ax = (cube.p[i].x - player.x)*cosf(player.H_angle*(PI / 180)) - (cube.p[i].z - player.z)*sinf(player.H_angle*(PI / 180)) + player.x;
		//	//}
		//}

		//(cube.p[i].x - player.x)*sinf(player.H_angle*(PI / 180)) + (cube.p[i].z - player.z)*cosf(player.H_angle*(PI / 180)) + player.z;
		//(cube.p[i].y - player.y)*sinf(player.V_angle*(PI / 180)) + (cube.p[i].z - player.z)*cosf(player.V_angle*(PI / 180)) + player.z;
		if (GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000)return;
		if (chk) {
			for (int i = 0; i < 8; i++) {
				cube.p[i] = get_Apoint(cube.p[i], player);
				figure2.p[i] = get_Apoint(figure2.p[i], player);
				figure3.p[i] = get_Apoint(figure3.p[i], player);
			}
			chk = false;
		}
		for (int i = 0; i < 8; i++) { //전-월드 좌표계(기준 0,0,0)  현-카메라 좌표계(기준 player member x,y,z)
			//if (cube.p[i].z <= player.z)cube.p[i].dx = INF; //해당 포인트가 플레이어보다 뒤에잇음
			if (0);
			else {
				cube.p[i].dx = (((cube.p[i].ax - player.x) * 50) / (cube.p[i].az - player.z) + 50);
				cube.p[i].dy = (((-(cube.p[i].ay - player.y)) * 50) / (cube.p[i].az - player.z) + 30);

				figure2.p[i].dx = (((figure2.p[i].ax - player.x) * 50) / (figure2.p[i].az - player.z) + 50);
				figure2.p[i].dy = (((-(figure2.p[i].ay - player.y)) * 50) / (figure2.p[i].az - player.z) + 30);

				figure3.p[i].dx = (((figure3.p[i].ax - player.x) * 50) / (figure3.p[i].az - player.z) + 50);
				figure3.p[i].dy = (((-(figure3.p[i].ay - player.y)) * 50) / (figure3.p[i].az - player.z) + 30);
			}
			//cube.p[i].dx = (cube.p[i].dx * cos(Hrad)) - (cube.p[i].dy * sin(Hrad));
			//cube.p[i].dy = (cube.p[i].dx * sin(Hrad)) + (cube.p[i].dy * cos(Hrad));
			//cube.p[i].dy += Vrad*100;
		}

		system("cls"); //후 변경
		/* jump*cls
		if (cnt == 10)system("cls");
		else {
			for (int i = 0; i < datalong; i++) {
				gotoxy(data[i][0], data[i][1]);
				printf("  ");
			}
			datalong = 0;
			cnt++;
		}
		*/

		for (int i = 0; i < 12; i++) {
			drawLine(cube.p[cubeline[i][0]].dx, cube.p[cubeline[i][0]].dy, cube.p[cubeline[i][1]].dx, cube.p[cubeline[i][1]].dy);
			drawLine(figure2.p[cubeline[i][0]].dx, figure2.p[cubeline[i][0]].dy, figure2.p[cubeline[i][1]].dx, figure2.p[cubeline[i][1]].dy);
			//drawLine(figure3.p[cubeline[i][0]].dx, figure3.p[cubeline[i][0]].dy, figure3.p[cubeline[i][1]].dx, figure3.p[cubeline[i][1]].dy);
		}
		//drawLine(0, 45, 100, 45);
		//drawLine(100, 0, 100, 45);
		double Hrad = (double)player.H_angle*(PI / 180);
		double Vrad = (double)player.V_angle*(PI / 180);
		//showXY(cube, player,Hrad,Vrad);
		Sleep(10);
	}
	return;
}
