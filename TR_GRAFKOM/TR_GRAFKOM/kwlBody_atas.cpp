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

	//depan atas miring
	Warna(30,20);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3)-55), koor_y+5, koor_z-25);
	glVertex3d((koor_x + (panjang / 3)-55), (koor_y + tinggi-10), koor_z-25);
	glVertex3d(koor_x + panjang-95, koor_y+5, koor_z-25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(koor_x + panjang-95, koor_y+5, (koor_z + lebar-5));
	glVertex3d((koor_x + (panjang / 3) - 55), koor_y+5, (koor_z + lebar-5));
	glVertex3d((koor_x + (panjang / 3) - 55), (koor_y + tinggi-10), (koor_z + lebar-5));
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3) - 55), (koor_y + tinggi - 10), (koor_z + lebar));
	glVertex3d((koor_x + (panjang / 3) - 55), (koor_y + tinggi - 10), koor_z-25);
	glVertex3d(koor_x + panjang - 95, koor_y + 5, koor_z-25);
	glVertex3d(koor_x + panjang - 95, koor_y + 5, koor_z + lebar);
	glEnd();

	//kaca
	Warna(0, 40, 220);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 3) - 50), (koor_y + tinggi - 20), (koor_z + lebar-5));
	glVertex3d((koor_x + (panjang / 3) - 50), (koor_y + tinggi - 20), koor_z-20);
	glVertex3d(koor_x + panjang - 95, koor_y + 15, koor_z-20);
	glVertex3d(koor_x + panjang - 95, koor_y + 15, koor_z + lebar-5);
	glEnd();

	//badan atas
	Warna(30, 50);
	box_sides(lebar+25, tinggi-50, koor_x - (panjang/2)-34, koor_y+5, (koor_z + lebar));
	box_sides(lebar + 25, tinggi - 85, koor_x - (panjang / 2) - 34, koor_y + 75, (koor_z + lebar));
	box_sides(lebar -40, tinggi-15 , koor_x - (panjang / 2) - 34, koor_y + 5, (koor_z + lebar));
	box_sides(lebar - 40, tinggi - 15, koor_x - (panjang / 2) - 34, koor_y + 5, koor_z -15);
	Warna(40, 20);
	box_frontBack((panjang-38), tinggi-15, koor_x-84, koor_y+5, koor_z-25);
	box_frontBack((panjang-38), tinggi-15, koor_x-84, koor_y+5, koor_z + lebar-5);

	box_topBottom(panjang - 35, lebar + 25, koor_x-panjang+15, koor_y + panjang-10, koor_z+lebar);
	Warna(50);
		//pintu//
	//box_frontBack(panjang - 55, tinggi - 25, koor_x - 115, koor_y + 5, koor_z + lebar);
	//box_frontBack(panjang - 55, tinggi - 25, koor_x - 115, koor_y + 5, koor_z);
		//jendela//
	//box_frontBack(panjang - 78, tinggi - 45, koor_x - 65, koor_y + 25, koor_z );
	//glBegin(GL_POLYGON);
	//glVertex3d((koor_x + (panjang / 3) - 77), koor_y + 25, koor_z);
	//glVertex3d((koor_x + (panjang / 3) - 77), (koor_y + tinggi - 20), koor_z);
	//glVertex3d(koor_x -15 , koor_y + 25, koor_z);
	//glEnd();

		//jendela//
//	box_frontBack(panjang - 78, tinggi - 45, koor_x - 65, koor_y + 25, koor_z+lebar);
///	glBegin(GL_POLYGON);
	//glVertex3d((koor_x + (panjang / 3) - 77), koor_y + 25, koor_z+lebar);
//	glVertex3d((koor_x + (panjang / 3) - 77), (koor_y + tinggi - 20), koor_z+lebar);
//	glVertex3d(koor_x - 15, koor_y + 25, koor_z+lebar);
//	glEnd();

	glRotatef(-180, 0, 1, 0);
	glTranslated(-10, 25, -15);

	/*
	//bokong belakang
	Warna(22, 22,21);
	box_frontBack((panjang - 50), tinggi - 30, koor_x - 170, koor_y - 20, koor_z);
	box_frontBack((panjang - 50), tinggi - 30, koor_x - 170, koor_y - 20, koor_z + lebar);
	Warna(0, 2);
	box_topBottom(panjang - 50, lebar, koor_x - (panjang*2)+30, koor_y + panjang - 50, koor_z+lebar );
	Warna(20);
	glBegin(GL_TRIANGLES);
	box_frontBack(20, 20, koor_x - panjang - 90, koor_y + 30, koor_z);
	box_frontBack(20, 50, koor_x - panjang - 90, koor_y-20 , koor_z);

	glBegin(GL_TRIANGLES);
	box_frontBack(20, 20, koor_x - panjang - 90, koor_y + 30, koor_z+lebar);
	box_frontBack(20, 50, koor_x - panjang - 90, koor_y - 20, koor_z+lebar);
	glEnd();

	Warna(0, 0, 212);
	glBegin(GL_POLYGON);
	glVertex3d((koor_x + (panjang / 2)-(panjang*2)-20), koor_y + (tinggi / 2), (koor_z +lebar));
	glVertex3d((koor_x + (panjang / 2) - (panjang * 2)-20), koor_y + (tinggi / 2), (koor_z ));
	glVertex3d((koor_x + ((panjang / 2) / 2) - (panjang * 2)-15), koor_y + (tinggi / 4)+5, (koor_z ));
	glVertex3d((koor_x + ((panjang / 2) / 2) - (panjang * 2)-15), koor_y + (tinggi / 4)+5, (koor_z + lebar ));
	glEnd();
	
	box_sides(lebar, tinggi - 50, koor_x - panjang - 90, koor_y - 20, (koor_z + lebar));


	*/



}