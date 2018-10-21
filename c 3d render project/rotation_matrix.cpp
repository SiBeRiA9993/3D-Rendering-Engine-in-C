#include "rotation_matrix.h"

int *multiply(int m1[], int m2[]) {
	int result[9];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result[i * 3 + j] += m1[i * 3 + k] * m2[k * 3 + j];
			}
		}
	}
	return result;
}
_vertex transform(_vertex vertex,int matrix[]) {
	return {
		vertex.x,
		vertex.y,
		vertex.z,
		vertex.x * matrix[0] + vertex.y * matrix[3] + vertex.z * matrix[6],
		vertex.x * matrix[1] + vertex.y * matrix[4] + vertex.z * matrix[7],
		vertex.x * matrix[2] + vertex.y * matrix[5] + vertex.z * matrix[8],
	};
}
_vertex get_Apoint(_vertex vertex, _player player) {
	/* 다시 짜시오!!!
	Rz = cos(H)cos(V) - sin(H)cos(A) + cos(H)sin(V)sin(A) + sin(H)sin(A) + cos(H)sin(V)cos(A)
	Ry = sin(H)cos(V) + cos(H)cos(A) + sin(H)sin(B)sin(A) - cos(H)sin(A) + sin(H)sin(V)cos(A)
	Rx = -sin(V) + cos(V)sin(A) + cos(V)cos(A);
	vertex->ax = (vertex->x - player->x)&cos
	*/
	int H_matrix[] = {
		cosf(player.H_angle*(PI / 180)),0,sinf(player.H_angle*(PI / 180)),
		0,1,0,
		-sinf(player.H_angle*(PI / 180)),0,cosf(player.H_angle*(PI / 180))
	};
	int V_matrix[] = {
		1,0,0,
		0,cosf(player.V_angle*(PI / 180)),sinf(player.V_angle*(PI / 180)),
		0,-sinf(player.V_angle*(PI / 180)),cosf(player.V_angle*(PI / 180))
	};
	for (int i = 0; i < 5; i++) {
		printf("");
	}
	//vertex->ax = (vertex->x - player->x)*cosf(player->H_angle*(PI / 180)) - (vertex->z - player->z)*sinf(player->H_angle*(PI / 180)) + player->x;
	//vertex->ay = (vertex->y - player->y)*cosf(player->V_angle*(PI / 180)) - (vertex->z - player->z)*sinf(player->V_angle*(PI / 180)) + player->y;
	//vertex->az = (vertex->x - player->x)*sinf(player->H_angle*(PI / 180)) + (vertex->z - player->z)*cosf(player->H_angle*(PI / 180)) + player->z;
	return transform(vertex, multiply(H_matrix, V_matrix));
}