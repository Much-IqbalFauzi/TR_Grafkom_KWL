#include <iostream>
#include <GL/glut.h>
#include "boxcall.h"
#include "key_keyboard.h"

void pasir(float panjang, float lebar, float tinggi, float x, float y, float z) {
	int k=0;
	while (y != tinggi) {
		glBegin(GL_POLYGON);
		glVertex3d(x+k, y, z);
		glVertex3d((x + panjang / 4)+k, y, (z + lebar / 2)-k);
		glVertex3d((x + panjang / 2), y, (z + lebar / 2)-k);
		glVertex3d((x + panjang * 3 / 4)-k, y, z);
		glVertex3d((x + panjang)-k, y, z-k);
		glVertex3d((x + panjang * 3 / 4)-k, y, (z - lebar / 2)+k);
		glVertex3d((x + panjang / 2), y, (z - lebar / 2)+k);
		y += 1;
		k += 1;
	}
	glEnd();
}


void latarTempat() {
	float panjang = 2000;
	box_topBottom(panjang,-panjang,-panjang/2,-40,-panjang/2);
	box_topBottom(panjang,-panjang,-panjang/2,-50,-panjang/2);
	box_frontBack(panjang,10,-panjang/2,-50,-panjang/2);
	box_frontBack(panjang,10,-panjang/2,-50,panjang/2);
	box_sides(-panjang,10,-panjang/2,-50,-panjang/2);
	box_sides(-panjang,10,panjang/2,-50,-panjang/2);

	pasir(1000, 900, 80, -800, -40, -700);
	pasir(800, 900, 150, -1000, -40, -300);

	}