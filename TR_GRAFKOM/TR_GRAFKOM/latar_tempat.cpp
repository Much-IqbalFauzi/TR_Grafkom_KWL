#include <iostream>
#include <GL/glut.h>
#include "boxcall.h"
#include "key_keyboard.h"

void latarTempat() {
	
	box_topBottom(1000,-1000,-500,-40,-500);
	box_topBottom(1000,-1000,-500,-50,-500);
	box_frontBack(1000,10,-500,-50,-500);
	box_frontBack(1000,10,-500,-50,500);
	box_sides(-1000,10,-500,-50,-500);
	box_sides(-1000,10,500,-50,-500);



}