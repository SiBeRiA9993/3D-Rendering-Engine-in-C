#pragma once
#include "struct.h"
#include "player_state.h"
#ifndef _DEF_H
#define _DEF_H

#pragma warning(disable:4996) //_s warning disable

#define PI 3.141592653f
#define dis(x,y) x-y
#define INF 999999999
//double Hrad = (double)player.H_angle*(PI / 180);
//double Vrad = (double)player.V_angle*(PI / 180);
#define pan rad(player.H_angle)
#define tilt rad(player.V_angle)
#define rad(x) (double)x*(PI/180)
#define dif_cubeset int cubeline[12][2] = { { 0,1 },{ 2,3 },{ 0,2 },{ 1,3 },{ 4,6 },{ 5,7 },{ 4,5 },{ 6,7 },{ 0,4 },{ 1,5 },{ 2,6 },{ 3,7 } };cube.p[0].z = 10; cube.p[0].x = 0; cube.p[0].y = -5;cube.p[1].z = 15; cube.p[1].x = 0; cube.p[1].y = -5;cube.p[2].z = 10; cube.p[2].x = 5; cube.p[2].y = -5;cube.p[3].z = 15; cube.p[3].x = 5; cube.p[3].y = -5;cube.p[4].z = 10; cube.p[4].x = 0; cube.p[4].y = 5;cube.p[5].z = 15; cube.p[5].x = 0; cube.p[5].y = 5;cube.p[6].z = 10; cube.p[6].x = 5; cube.p[6].y = 5;cube.p[7].z = 15; cube.p[7].x = 5; cube.p[7].y = 5;
/*
int cubeline[12][2] = { { 0,1 },{ 2,3 },{ 0,2 },{ 1,3 },{ 4,6 },{ 5,7 },{ 4,5 },{ 6,7 },{ 0,4 },{ 1,5 },{ 2,6 },{ 3,7 } };
cube.p[0].z = 10; cube.p[0].x = 0; cube.p[0].y = -5;
cube.p[1].z = 15; cube.p[1].x = 0; cube.p[1].y = -5;
cube.p[2].z = 10; cube.p[2].x = 5; cube.p[2].y = -5;
cube.p[3].z = 15; cube.p[3].x = 5; cube.p[3].y = -5;
cube.p[4].z = 10; cube.p[4].x = 0; cube.p[4].y = 5;
cube.p[5].z = 15; cube.p[5].x = 0; cube.p[5].y = 5;
cube.p[6].z = 10; cube.p[6].x = 5; cube.p[6].y = 5;
cube.p[7].z = 15; cube.p[7].x = 5; cube.p[7].y = 5;
*/

#endif