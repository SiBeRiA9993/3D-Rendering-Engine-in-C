#pragma once
typedef struct _player {
	const double speed = 1.0;
	int angle_speed=5; //°¨µµ
	int jump_limit = 50;
	bool jump = false;
	int jump_long = 0;
	int jump_tmp = 0;
	int gra = 0;
	double x=0;
	double y=0;
	double z=-0;
	double H_angle=0;
	double V_angle=0;
}_player;