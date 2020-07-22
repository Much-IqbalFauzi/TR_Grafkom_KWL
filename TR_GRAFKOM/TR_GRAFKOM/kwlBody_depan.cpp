#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include "boxcall.h"

/*

	README
	kamera secara default sudah di
	gluLookAt(60, 20, 250, 0, 0, 0, 0, 1, 0);

	>>>><<<<
	SEKEDAR MEMBUAT KOTAK, langsung panggil fungsi berikut
	untuk kotak menghadap muka
	box_frontBack(panjang, tinggi, posisi_x, posisi_y, posisi_z);

	untuk kotak menghadap samping
	box_sides(lebar, tinggi, posisi_x, posisi_y, posisi_z);

	untuk kotak menghadap atas/tutup
	box_topBottom(panjang, lebar, posisi_x, posisi_y, posisi_z);

	>>>><<<<
	PENGGUNAN Warna
	secara otomatis tanpa adanya parameter, akan terisi putih dengan tingkat opacity 1. rbg harus skala 0-255
	https://www.google.com/search?client=firefox-b-d&q=color+picker
	warna(red, green, blue, alpha);

*/

void ban(int jari2, int lebar_ban, int x_tengah, int y_tengah, int z_tengah) {
	float PI = 3.14;
	glBegin(GL_POLYGON);
	float z = z_tengah;
		for (int i = 0; i <= 3600; i++) {
			float sudut = i * (2 * PI / 3600);
			float x = x_tengah + jari2 * cos(sudut);
			float y = y_tengah + jari2 * sin(sudut);
			glVertex3f(x, y, z);
			glVertex3f(x, y, z + lebar_ban);
		}
	glEnd();
}


void selebor(float koor_x,float koor_y,float koor_z,float panjang,float lebar,float tinggi)
{
	Warna(50, 40, 50);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3)), koor_y + (tinggi / 2), (koor_z + 2 * lebar));
	glVertex3d((koor_x + (panjang / 3)), koor_y + (tinggi / 2), (koor_z + lebar));
	glVertex3d((koor_x + ((panjang / 3) / 2)), koor_y + (tinggi / 4), (koor_z + lebar));
	glVertex3d((koor_x + ((panjang / 3) / 2)), koor_y + (tinggi / 4), (koor_z + 2 * lebar));
	glEnd();
	box_topBottom(panjang / 2, lebar, koor_x + (panjang / 3), koor_y + (tinggi / 2), (koor_z + 2 * lebar));

	ban(20, 3, koor_x + (panjang / 1.8), koor_y, (koor_z + 1.25 * lebar)-2);
	ban(20, 3, koor_x + (panjang / 1.8), koor_y, (koor_z + lebar*1.25 + 30));
	Warna();
	ban(38, 30, koor_x + (panjang / 1.8), koor_y , (koor_z +1.25* lebar));
	
}

void init_kwlBody_depan() {
	/*
	 
	 Achsan CODE Here
	 
	 */

	glTranslated(250, 0, 0);
	glRotatef(180, 0, 1, 0);
	int panjang = 100, tinggi = 80, lebar=50, koor_x=250, koor_y=0, koor_z=-25;
	
	//tutup belakang
	Warna(235, 198, 52);
	box_sides(lebar, tinggi, koor_x, koor_y, (koor_z+lebar));
	Warna(235, 198, 52);
	box_frontBack((panjang/3), tinggi, koor_x, koor_y, koor_z);
	box_frontBack((panjang/3), tinggi, koor_x, koor_y, koor_z + lebar);

	//ngarepan
	Warna(235, 198, 52);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3)), koor_y, koor_z);
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), koor_z);
	glVertex3d(koor_x + panjang, koor_y, koor_z);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3d(koor_x + panjang, koor_y, (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3)), koor_y, (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), (koor_z + lebar));
	glEnd();


	Warna(135, 133, 116);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), koor_z);
	glVertex3d(koor_x + panjang, koor_y, koor_z);
	glVertex3d(koor_x + panjang, koor_y, koor_z + lebar);
	glEnd();


	//selebor
	selebor(koor_x, koor_y, koor_z-(2*lebar), panjang, lebar, tinggi);
	selebor(koor_x, koor_y, koor_z, panjang, lebar, tinggi);
	selebor(45, koor_y, koor_z - (2 * lebar), panjang, lebar, tinggi);
	selebor(45, koor_y, koor_z, panjang, lebar, tinggi);
	ban(5, 140, koor_x + (panjang / 1.8), koor_y, -(koor_z + lebar * 1.25 + 30));
	ban(5, 2, koor_x + (panjang / 1.8), koor_y, (koor_z + lebar * 1.25 + 35));

	ban(5, 140, 100, koor_y, -(koor_z + lebar * 1.25 + 30));
	ban(5, 2, 100, koor_y, (koor_z + lebar * 1.25 + 35));
	//tutup
	Warna(135, 133, 116);
	box_topBottom(panjang / 3, lebar, koor_x, koor_y + tinggi, koor_z + lebar);
	Warna(123, 123, 123);
	box_topBottom(panjang, lebar, koor_x, koor_y , koor_z + lebar);
	Warna(255, 255, 255);
	box_frontBack(7,15, (koor_x + (panjang / 5)), (koor_y + tinggi), (koor_z + lebar/5));
	box_frontBack(7,15,  (koor_x + (panjang / 5)), (koor_y + tinggi), (koor_z + lebar/10));
	box_sides(5,15, (koor_x + (panjang / 5)), (koor_y + tinggi), (koor_z + lebar / 5));
	box_sides(5, 15, (koor_x + (panjang / 3.7)), (koor_y + tinggi), (koor_z + lebar / 5));

	ban(3, lebar, (koor_x + (panjang / 4)), (koor_y + tinggi+15), koor_z);

	box_frontBack(7, 15, (koor_x + (panjang / 5)), (koor_y + tinggi), (koor_z + lebar * 0.8));
	box_frontBack(7, 15, (koor_x + (panjang / 5)), (koor_y + tinggi), (koor_z + lebar *0.9));
	box_sides(5, 15, (koor_x + (panjang / 5)), (koor_y + tinggi), (koor_z + lebar *0.9));
	box_sides(5, 15, (koor_x + (panjang / 3.7)), (koor_y + tinggi), (koor_z + lebar  *0.9));



	glRotatef(-180, 0, 1, 0);
	glTranslated(-250, 0, 0);
	}
