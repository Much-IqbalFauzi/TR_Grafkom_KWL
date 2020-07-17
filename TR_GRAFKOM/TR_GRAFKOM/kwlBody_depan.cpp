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

void selebor(float koor_x,float koor_y,float koor_z,float panjang,float lebar,float tinggi)
{
	Warna(0, 0, 212);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3)), koor_y + (tinggi / 2), (koor_z + 2 * lebar));
	glVertex3d((koor_x + (panjang / 3)), koor_y + (tinggi / 2), (koor_z + lebar));
	glVertex3d((koor_x + ((panjang / 3) / 2)), koor_y + (tinggi / 4), (koor_z + lebar));
	glVertex3d((koor_x + ((panjang / 3) / 2)), koor_y + (tinggi / 4), (koor_z + 2 * lebar));
	glEnd();
	box_topBottom(panjang / 2, lebar, koor_x + (panjang / 3), koor_y + (tinggi / 2), (koor_z + 2 * lebar));
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3) + (panjang / 2)), koor_y + (tinggi / 2), (koor_z + 2 * lebar));
	glVertex3d((koor_x + (panjang / 3) + (panjang / 2)), koor_y + (tinggi / 2), (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3) + (panjang / 2) + (panjang / 3) / 2), koor_y + (tinggi / 4), (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3) + (panjang / 2) + (panjang / 3) / 2), koor_y + (tinggi / 4), (koor_z + 2 * lebar));
	glEnd();
}

void init_kwlBody_depan() {
	/*
	 
	 Achsan CODE Here
	 
	 */
	int panjang = 100, tinggi = 100, lebar=50, koor_x=5, koor_y=5, koor_z=5;
	
	//tutup belakang
	Warna(100);
	box_sides(lebar, tinggi, koor_x, koor_y, (koor_z+lebar));
	Warna(79);
	box_frontBack((panjang/3), tinggi, koor_x, koor_y, koor_z);
	box_frontBack((panjang/3), tinggi, koor_x, koor_y, koor_z + lebar);

	//ngarepan
	Warna(0, 222);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3)), koor_y, koor_z);
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), koor_z);
	glVertex3d(koor_x + panjang, koor_y, koor_z);
	glEnd();

	Warna(0, 20, 32);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), koor_z);
	glVertex3d(koor_x + panjang, koor_y, koor_z);
	glVertex3d(koor_x + panjang, koor_y, koor_z + lebar);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x + panjang, koor_y, (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3)), koor_y, (koor_z+lebar));
	glVertex3d((koor_x + (panjang / 3)), (koor_y + tinggi), (koor_z + lebar));
	glEnd();

	//selebor
	selebor(koor_x, koor_y, koor_z-(2*lebar), panjang, lebar, tinggi);
	selebor(koor_x, koor_y, koor_z, panjang, lebar, tinggi);

	//tutup
	box_topBottom(panjang/3,lebar,koor_x, koor_y+tinggi, koor_z+lebar);

	}
