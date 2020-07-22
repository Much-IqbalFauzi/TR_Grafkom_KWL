#include <iostream>
#include <GL/glut.h>
#include "key_keyboard.h"
using namespace std;

void piston_down(int) {
    glutPostRedisplay();
    if (pistonH_pos > -30) {
        glutTimerFunc(4000 / 60, piston_down, 0);
        pistonH_pos -= 1;
    }
}

void piston_up(int) {
    glutPostRedisplay();
    if (pistonH_pos < -10) {
        glutTimerFunc(4000 / 60, piston_up, 0);
        pistonH_pos += 1;
    }
}

void key(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'q':
    case 'Q':
        glTranslatef(0.0, 5.0, 0.0);
        break;
    case 'e':
    case 'E':
        glTranslatef(0.0, -5.0, 0.0);
        break;
    case 'f':
    case 'F':
        if (pistonH_pos == -10) {
            glutTimerFunc(0, piston_down, 0);
        } else {
            glutTimerFunc(0, piston_up, 0);
        }
        break;
    }
    cout << key << endl;
    show();

}