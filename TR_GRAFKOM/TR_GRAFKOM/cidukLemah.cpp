#include <GL/glut.h>
#include <Windows.h>
#include "boxcall.h"
#include "vehicle_part.h"

Vehicle VV;
int sudutLengan = VV.getLenganCiduk();
int sudutCiduk = VV.getSudutCiduk();

void ciduk_engsel(int z = 0) {
	glTranslated(0, 0, z);

	Warna(212, 177, 38);
	box_frontBack(25, 14, -16, -7, 7); box_frontBack(25, 14, -16, -7, -7);
	Warna(235, 198, 96);
	box_topBottom(25, 14, -16, 7, 7); box_topBottom(25, 14, -16, -7, 7);
	Warna(173, 170, 147);
	box_sides(14, 14, 9, -7, 7);

	glTranslated(0, 0, -z);
}

void ciduk() {
	ciduk_engsel();
	ciduk_engsel(50);
	ciduk_engsel(-50);

	Warna(222, 183, 31);
	box_sides(120, 50, -16, -25, 60);
	Warna(219, 180, 26);
	box_sides(120, 10, -40, -35, 60, 24);
	Warna(212, 177, 38);
	box_topBottom(20, 120, -60, -35, 60);
	int zz = 55;
	for (int _ = 0; _ < 6; _++) {
		box_topBottom(10, 10, -70, -35, zz);
		zz -= 20;
	}
	int zzz = 60;
	for (int _ = 0; _ < 2; _++) {
		Warna(235, 198, 96);
		glBegin(GL_POLYGON);
		glVertex3d(-16, 25, zzz);
		glVertex3d(-16, -25, zzz);
		glVertex3d(-40, -35, zzz);
		glVertex3d(-60, -35, zzz);
		glEnd();
		zzz -= 120;
	}
}

void lengan_cidukExtender() {
	Warna(173, 170, 147);
	box_frontBack(80, 14, -129, -7, 40); box_frontBack(80, 14, -129, -7, 26);
	box_frontBack(80, 14, -129, -7, -26); box_frontBack(80, 14, -129, -7, -40);
	Warna(191, 188, 164);
	box_topBottom(80, 14, -129, 7, 40); box_topBottom(80, 14, -129, -7, 40);
	box_topBottom(80, 14, -129, 7, -26); box_topBottom(80, 14, -129, -7, -26);
	Warna(158, 157, 145);
	box_sides(14, 14, -129, -7, 40);
	box_sides(14, 14, -129, -7, -26);

	Warna(48, 48, 48);
	ban(4, 110, -124, 0, -55);

	//rotate ciduk
	glTranslated(-124, 0, 0);
	glRotated(sudutCiduk, 0, 0, 1);
	ciduk();
	glRotated(-sudutCiduk, 0, 0, 1);
	glTranslated(124, 0, 0);
}

void lengan_ciduk() {
	glTranslated(0, 15, 0);
	glRotated(25, 0, 0, 1);

	Warna(173, 170, 147);
	box_frontBack(14, 14, -49, -7, 40);
	box_frontBack(14, 14, -49, -7, -40);
	Warna(191, 188, 164);
	box_topBottom(14, 80, -49, 7, 40);
	box_topBottom(14, 80, -49, -7, 40);
	Warna(158, 157, 145);
	box_sides(80, 14, -49, -7, 40);
	box_sides(80, 14, -35, -7, 40);

	lengan_cidukExtender();

	glRotated(-25, 0, 0, 1);
	glTranslated(0, 15, 0);
}

void init_ciduk() {
	//engsel lengan
	Warna(173, 170, 147);
	box_frontBack(50, 10, -35, -5, 5);
	box_frontBack(50, 10, -35, -5, -5);
	Warna(191, 188, 164);
	box_topBottom(50, 10, -35, 5, 5);
	box_topBottom(50, 10, -35, -5, 5);
	Warna(158, 157, 145);
	box_sides(10, 10, 15, -5, 5);

	//lengan ciduk
	lengan_ciduk();
	
}

void ciduk_move() {
	glTranslated(-25, 96, 0);
	glRotated(sudutLengan, 0, 0, 1);
	
	init_ciduk();
	
	glRotated(-sudutLengan, 0, 0, 1);
	glTranslated(25, -96, 0);
}