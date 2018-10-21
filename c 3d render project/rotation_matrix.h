#pragma once
#include "main.h"

#ifndef ROTATION_H
#define ROTATION_H

typedef struct _matrix {
	double m[10];
}_matrix;

_vertex get_Apoint(_vertex vertex, _player player);
int *multiply(int m1, int m2);
#endif