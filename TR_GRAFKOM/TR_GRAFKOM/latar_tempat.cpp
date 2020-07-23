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

void kubus(float px, float py, float pz,float x2, float y2, float z2) {
	box_topBottom(px, pz, x2, y2, z2);
	box_topBottom(px, pz, x2, y2 + py, z2);
	box_frontBack(px, py, x2, y2, z2 - pz);
	box_frontBack(px, py, x2, y2, z2);
	box_sides(pz, py, x2 + px, y2, z2);
	box_sides(pz, py, x2, y2, z2);

}

void kerucut(int jari2, int tinggi, int x_tengah, int y_tengah, int z_tengah) {
	float PI = 3.14;
	glBegin(GL_POLYGON);
	float y = y_tengah;
	for (int j = 0; j <= tinggi; j++) {
		for (int i = 0; i <= 360; i++) {
			float sudut = i * (2 * PI / 360);
			float x = x_tengah + jari2 * cos(sudut);
			float z = z_tengah + jari2 * sin(sudut);
			glVertex3f(x, y, z);
			}
		jari2 -= 1;
		y += 1;
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
	pasir(800, 900, 150, -1100, -40, -300);
	
	kerucut(400, 300, -800, -40, 200);
	// rest box
	float panjang1 = 200, lebar1 = 400, tinggi1 = 150, x1 = 800, y1 = -50, z1 = 500;
	Warna(255, 255, 255);
	box_topBottom(panjang1, lebar1, x1, y1, z1);
	box_topBottom(panjang1, lebar1, x1, y1+tinggi1, z1);
	box_frontBack(panjang1, tinggi1, x1, y1, z1-lebar1);
	box_frontBack(panjang1, tinggi1, x1, y1, z1);
	box_sides(lebar1, tinggi1, x1+panjang1, y1, z1);
	box_sides(lebar1, tinggi1, x1, y1, z1);
	
	// door
	Warna();
	box_sides(4 + lebar1 / 4, 2 + tinggi1 * 3 / 4, x1 - 2, y1, 2 + z1 - lebar1 / 2);
    Warna(200, 200, 200);
	box_sides(lebar1 / 4, tinggi1 * 3 / 4, x1 - 3, y1, z1 - lebar1 / 2);
	Warna();
	box_sides(10, 10, x1 - 4, y1+50, -5+ z1 - lebar1 / 2);
	
	//kursi
	Warna(162,60,30);
	kubus(5, 35, 5, 780, -40, 350);
	kubus(5, 35, 5, 780, -40, 320);
	kubus(5, 35, 5, 750, -40, 350);
	kubus(5, 35, 5, 750, -40, 320);
	kubus(32, 5, -32, 750, -10, 319);

	}