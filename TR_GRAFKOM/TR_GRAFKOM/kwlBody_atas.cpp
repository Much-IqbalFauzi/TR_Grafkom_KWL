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

void init_kwlBody_atas() {
	/*
	
	Hasan CODE here
	
	*/

	int panjang = 100, tinggi = 100, lebar = 50, koor_x = 0, koor_y = 100, koor_z = 5;

	glTranslated(10, 25, 15);
	glRotatef(180, 0, 1, 0);

	//koco
	Warna(0, 30, 50);
	box_miringKK(koor_x +2, koor_x -17, koor_y + 25, koor_y + 80, koor_z - 17, koor_z + 37);

	glBegin(GL_POLYGON);
	glVertex3d(koor_x - 11, koor_y + 30, koor_z - 25);
	glVertex3d(koor_x - 24, koor_y + 70, koor_z - 25);
	glVertex3d(koor_x - 35, koor_y + 70, koor_z - 25);
	glVertex3d(koor_x - 35, koor_y + 30, koor_z - 25);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(koor_x - 11, koor_y + 30, koor_z +lebar-5);
	glVertex3d(koor_x - 24, koor_y + 70, koor_z + lebar - 5);
	glVertex3d(koor_x - 35, koor_y + 70, koor_z + lebar - 5);
	glVertex3d(koor_x - 35, koor_y + 30, koor_z + lebar - 5);
	glEnd();
	box_frontBack(30, 40, koor_x - 70, koor_y + 40, koor_z +lebar-5);
	box_sides(lebar , tinggi - 80, koor_x - (panjang / 2) - 30, koor_y + 55, koor_z +lebar-15);
	//Pintu
	box_frontBack(30, 75, koor_x - 70, koor_y + 5, koor_z - 25);


	//jendela
	Warna(235, 198, 52);
	box_frontBack((panjang - 90), tinggi - 15, koor_x - 80, koor_y + 5, koor_z - 25);
	box_frontBack((panjang - 95), tinggi - 15, koor_x - 40, koor_y + 5, koor_z - 25);

	glBegin(GL_POLYGON);
	glVertex3d(koor_x - 40, koor_y + 80, koor_z - 25);
	glVertex3d(koor_x - 40, koor_y + 90, koor_z - 25);
	glVertex3d(koor_x - 80, koor_y + 90, koor_z - 25);
	glVertex3d(koor_x - 80, koor_y + 80, koor_z - 25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x +10,koor_y+5,koor_z-25);
	glVertex3d(koor_x +1, koor_y + 30, koor_z - 25);
	glVertex3d(koor_x - 40, koor_y + 30, koor_z - 25);
	glVertex3d(koor_x - 40, koor_y + 5, koor_z - 25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x - 13, koor_y + 70, koor_z - 25);
	glVertex3d(koor_x - 20, koor_y +90, koor_z - 25);
	glVertex3d(koor_x - 40, koor_y + 90, koor_z - 25);
	glVertex3d(koor_x - 40, koor_y + 70, koor_z - 25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x+1 , koor_y + 30, koor_z - 25);
	glVertex3d(koor_x - 20, koor_y + 90, koor_z - 25);
	glVertex3d(koor_x - 30, koor_y + 90, koor_z - 25);
	glVertex3d(koor_x -11, koor_y + 30, koor_z - 25);
	glEnd();



	//jendela sebelah

	box_frontBack((panjang - 90), tinggi - 15, koor_x - 80, koor_y + 5, koor_z + lebar - 5);
	box_frontBack((panjang - 95), tinggi - 15, koor_x - 40, koor_y + 5, koor_z + lebar - 5);

	glBegin(GL_POLYGON);
	glVertex3d(koor_x - 40, koor_y + 80, koor_z +lebar-5);
	glVertex3d(koor_x - 40, koor_y + 90, koor_z +lebar - 5);
	glVertex3d(koor_x - 80, koor_y + 90, koor_z +lebar- 5);
	glVertex3d(koor_x - 80, koor_y + 80, koor_z+ lebar - 5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x - 40, koor_y + 40, koor_z + lebar - 5);
	glVertex3d(koor_x - 40, koor_y + 30, koor_z + lebar - 5);
	glVertex3d(koor_x - 80, koor_y + 30, koor_z + lebar - 5);
	glVertex3d(koor_x - 80, koor_y + 40, koor_z + lebar - 5);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(koor_x + 10, koor_y + 5, koor_z + lebar - 5);
	glVertex3d(koor_x + 1, koor_y + 30, koor_z + lebar - 5);
	glVertex3d(koor_x - 80, koor_y + 30, koor_z + lebar - 5);
	glVertex3d(koor_x - 80, koor_y + 5, koor_z +lebar-5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x - 13, koor_y + 70, koor_z + lebar -5);
	glVertex3d(koor_x - 20, koor_y + 90, koor_z +lebar-5);
	glVertex3d(koor_x - 40, koor_y + 90, koor_z + lebar -5);
	glVertex3d(koor_x - 40, koor_y + 70, koor_z +lebar - 5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x + 1, koor_y + 30, koor_z +lebar- 5);
	glVertex3d(koor_x - 20, koor_y + 90, koor_z +lebar-5);
	glVertex3d(koor_x - 30, koor_y + 90, koor_z +lebar-5);
	glVertex3d(koor_x - 11, koor_y + 30, koor_z +lebar-5);
	glEnd();

	//frame kaca Depan
	box_miringKK(koor_x + 10, koor_x - 20, koor_y + 5, koor_y + panjang-10, koor_z + lebar-5, koor_z + lebar-14);
	box_miringKK(koor_x + 10, koor_x - 20, koor_y + 5, koor_y + panjang - 10, koor_z-25 , koor_z -17);
	box_miringKK(koor_x + 10, koor_x+2 , koor_y + 5, koor_y + 25, koor_z - 20, koor_z + 40);
	box_miringKK(koor_x - 16, koor_x-20, koor_y + panjang-20, koor_y +panjang-10, koor_z - 20, koor_z + 40);

	Warna(135, 133, 116);
	box_sides(lebar+20, tinggi-50, koor_x - (panjang/2)-30, koor_y+5, (koor_z + lebar-5));
	box_sides(lebar + 20, tinggi - 85, koor_x - (panjang / 2) - 30, koor_y + 75, (koor_z + lebar-5));
	box_sides(lebar -40, tinggi-15 , koor_x - (panjang / 2) - 30, koor_y + 5, (koor_z + lebar-5));
	box_sides(lebar - 40, tinggi - 15, koor_x - (panjang / 2) - 30, koor_y + 5, koor_z -15);
	

	box_topBottom(panjang - 35, lebar + 20, koor_x-panjang+20, koor_y + panjang-10, koor_z+lebar-5);
	Warna(50);

	glRotatef(-180, 0, 1, 0);
	glTranslated(-10, 25, -15);




}