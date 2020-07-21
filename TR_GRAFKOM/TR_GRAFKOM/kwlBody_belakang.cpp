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

	warna maz fauzi
	kuning 1 = 235, 198, 52
	kuning cerah 1 = 255, 221, 87
	kuning gelap = 212, 177, 38
	abu-abu cerah = 161, 151, 112

*/
void bokong() {
	glBegin(GL_QUADS);
	glVertex3d(200, 0, 25);
	glVertex3d(250, 20, 25);
	glVertex3d(250, 65, 25);
	glVertex3d(200, 65, 25);

	glVertex3d(200, 0, -25);
	glVertex3d(250, 20, -25);
	glVertex3d(250, 65, -25);
	glVertex3d(200, 65, -25);
	glEnd();
}

void ondo() {
	//lebar 4, jarak anak 10
}

void init_kwlBody_belakang() {
	/*
	
	Fauzi CODE here
	
	*/
	//kotak
	Warna(235, 198, 52);
	box_frontBack(100, 80, 0, 0, 45); box_frontBack(100, 80, 0, 0, -45);
	box_frontBack(100, 65, 100, 0, 25); box_frontBack(100, 65, 100, 0, -25);
	bokong();

	Warna(123, 123, 123);
	box_topBottom(100, 90, 0, 0, 45); box_topBottom(100, 90, 0, 80, 45); box_topBottom(150, 50, 100, 65, 25); box_topBottom(100, 50, 100, 0, 25);

	box_miringKK(200, 250, 0, 20, 25, -25);

	Warna(222, 14, 100);
	box_sides(90, 80, 0, 0, 45); box_sides(90, 80, 100, 0, 45); box_sides(50, 45, 250, 20, 25);

	ondo();
}