#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include "boxcall.h"
#include "key_keyboard.h"
#include "vehicle_part.h"

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

Vehicle v;
int pistonH_pos = v.getPistonAct();

void bokong() {
	glBegin(GL_QUADS);
	glVertex3d(170, 0, 25);
	glVertex3d(220, 20, 25);
	glVertex3d(220, 65, 25);
	glVertex3d(170, 65, 25);

	glVertex3d(170, 0, -25);
	glVertex3d(220, 20, -25);
	glVertex3d(220, 65, -25);
	glVertex3d(170, 65, -25);
	glEnd();
}

void bokong_2() {
	glBegin(GL_TRIANGLES);
	glVertex3d(120, 65, 20);
	glVertex3d(150, 65, 20);
	glVertex3d(150, 90, 20);

	glVertex3d(120, 65, -20);
	glVertex3d(150, 65, -20);
	glVertex3d(150, 90, -20);
	glEnd();
}

void ondo_1() {
	//lebar 4, jarak anak 10
	Warna(212, 177, 38);
	box_frontBack(4, 100, 50, -20, 49); box_frontBack(4, 100, 50, -20, 45);
	box_frontBack(4, 100, 70, -20, 49); box_frontBack(4, 100, 70, -20, 45);

	int _x = 80, _xx = 80, _xxx = 84, __min = 12;
	for (int _ = 0; _ < 8; _++) {
		Warna(212, 177, 38);
		box_frontBack(16, 4, 54, _x -= __min, 49);
		Warna(235, 198, 96);
		box_topBottom(16, 4, 54, _xx -= __min, 49);
		box_topBottom(16, 4, 54, _xxx -= __min, 49);
	}
	
	Warna(209, 180, 98);
	box_sides(4, 100, 50, -20, 49); box_sides(4, 100, 54, -20, 49); box_sides(4, 100, 70, -20, 49); box_sides(4, 100, 74, -20, 49);
}

void sub_cagak(int x = 0, int z = 0) {
	glTranslated(x, 0, z);
	Warna(212, 177, 38);
	box_frontBack(2, 22, 0, 80, 45); box_frontBack(2, 22, 0, 80, 43);
	Warna(209, 180, 98);
	box_sides(2, 22, 0, 80, 45); box_sides(2, 22, 2, 80, 45);
	glTranslated(-x, 0, -z);
}

void cagak() {
	Warna(212, 177, 38);
	box_frontBack(50, 2, 0, 100, 45); box_frontBack(50, 2, 0, 100, 43);
	box_frontBack(26, 2, 74, 100, 45); box_frontBack(26, 2, 74, 100, 43);
	box_frontBack(100, 2, 0, 100, -45); box_frontBack(100, 2, 0, 100, -43);

	Warna(235, 198, 96);
	box_topBottom(50, 2, 0, 100, 45); box_topBottom(50, 2, 0, 102, 45);
	box_topBottom(26, 2, 74, 100, 45); box_topBottom(26, 2, 74, 102, 45);
	box_topBottom(100, 2, 0, 100, -43); box_topBottom(100, 2, 0, 102, -43);

	box_topBottom(2, 90, 98, 100, 45); box_topBottom(2, 90, 98, 102, 45);

	Warna(209, 180, 98);
	box_sides(90, 2, 98, 100, 45); box_sides(90, 2, 100, 100, 45);

	sub_cagak(); sub_cagak(23); sub_cagak(48); sub_cagak(74); sub_cagak(98);
	sub_cagak(0, -88); sub_cagak(23, -88); sub_cagak(48, -88); sub_cagak(73, -88); sub_cagak(98, -88);
	sub_cagak(98, -29); sub_cagak(98, -58);
}

void piston() {
	Warna(217, 217, 217);
	box_frontBack(10, 45, 10, pistonH_pos, 47); box_frontBack(10, 45, 10, pistonH_pos, 37);
	Warna(227, 227, 227);
	box_sides(10, 45, 10, pistonH_pos, 47); box_sides(10, 45, 20, pistonH_pos, 47);
	//alas
	Warna(79, 73, 73);
	box_frontBack(18, 4, 6, pistonH_pos - 4, 51); box_frontBack(18, 4, 6, pistonH_pos - 4, 33);
	Warna(66, 60, 60);
	box_sides(18, 4, 6, pistonH_pos - 4, 51); box_sides(18, 4, 24, pistonH_pos - 4, 51);
	Warna(59, 53, 53);
	box_topBottom(18, 18, 6, pistonH_pos, 51); box_topBottom(16, 16, 6, pistonH_pos - 4, 51);

}

void dkrak_detail(int z = 0) {
	glTranslated(0, 0, z);
	Warna(79, 73, 73);
	box_frontBack(14, 45, 8, -5, 35); box_frontBack(14, 45, 8, -5, 49);
	Warna(66, 60, 60);
	box_sides(14, 45, 8, -5, 49); box_sides(14, 45, 22, -5, 49);
	Warna(59, 53, 53);
	box_topBottom(14, 14, 8, -5, 49); box_topBottom(14, 14, 8, 40, 49);

	Warna(43, 43, 43);
	box_frontBack(8, 20, 22, 5, 44); box_frontBack(8, 20, 22, 5, 40);
	Warna(36, 36, 36);
	box_topBottom(8, 4, 22, 5, 44); box_topBottom(8, 4, 22, 25, 44);

	piston();
	glTranslated(0, 0, -z);
}

void dongkrak() {

	dkrak_detail(-1);
	dkrak_detail(-83);

}

void init_kwlBody_belakang() {

	//kotak main
	Warna(235, 198, 52);
	box_frontBack(70, 80, 30, 0, 45); box_frontBack(70, 80, 30, 0, -45);
	box_frontBack(30, 40, 0, 40, 45); box_frontBack(30, 40, 0, 40, -45);
	box_frontBack(70, 65, 100, 0, 25); box_frontBack(70, 65, 100, 0, -25);
	bokong();
	Warna(140, 130, 91);
	box_frontBack(30, 40, 0, 0, 25); box_frontBack(30, 40, 0, 0, -25);

	Warna(123, 123, 123);
	box_topBottom(70, 90, 30, 0, 45); box_topBottom(70, 50, 0, 0, 25); box_topBottom(100, 90, 0, 80, 45); box_topBottom(120, 50, 100, 65, 25); box_topBottom(70, 50, 100, 0, 25);
	box_miringKK(170, 220, 0, 20, 25, -25);
	Warna(105, 100, 100);
	box_topBottom(30, 20, 0, 40, 45); box_topBottom(30, 20, 0, 40, -25);

	Warna(135, 133, 116);
	box_sides(90, 40, 0, 40, 45); box_sides(50, 40, 0, 0, 25); box_sides(90, 80, 100, 0, 45); box_sides(50, 45, 220, 20, 25);
	box_sides(20, 40, 30, 0, 45); box_sides(20, 40, 30, 0, -25);

	//additional bokong
	Warna(224, 188, 47);
	box_frontBack(50, 25, 150, 65, 20); box_frontBack(50, 25, 150, 65, -20);
	bokong_2();
	Warna(240, 203, 60);
	box_sides(40, 25, 120, 65, 20, 30); box_sides(40, 25, 200, 65, 20);
	Warna(250, 209, 47);
	box_topBottom(50, 40, 150, 90, 20);
	//
	ondo_1();
	cagak();

	dongkrak();
}