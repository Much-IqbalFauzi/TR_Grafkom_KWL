#include <iostream>
#include <GL/glut.h>
#include "key_keyboard.h"
#include "vehicle_part.h"
using namespace std;

Vehicle vehi;
bool inochi = vehi.getKwl();

void piston_down(int) {
    glutPostRedisplay();
    if (pistonH_pos > -40) {
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
        if (inochi) {
            if (pistonH_pos == -10) {
                glutTimerFunc(0, piston_down, 0);
            }
            else {
                glutTimerFunc(0, piston_up, 0);
            }
        } else {
            cout << "mesin mati oi" << endl;
        }
        break;
    case 'z':
    case 'Z':
        if (inochi) {
            if (sudutLengan < 20) {
                sudutLengan += 1;
            }
        } else {
            cout << "mesin mati oi" << endl;
        }
        break;
    case 'x':
    case 'X':
        if (inochi) {
            if (sudutLengan > -40) {
                sudutLengan -= 1;
            }
        }
        else {
            cout << "mesin mati oi" << endl;
        }
        break;
    case 'c':
    case 'C':
        if (inochi) {
            if (sudutCiduk < 45) {
                sudutCiduk += 1;
            }
        }
        else {
            cout << "mesin mati oi" << endl;
        }
        break;
    case 'v':
    case 'V':
        if (inochi) {
            if (sudutCiduk > -40) {
                sudutCiduk -= 1;
            }
        }
        else {
            cout << "mesin mati oi" << endl;
        }
        break;
    case 'b':
    case 'B':
        if (inochi) {
            inochi = false;
            cout << "mematikan mesin" << endl;
        } else {
            inochi = true;
            cout << "menghidupkan mesin" << endl;
        }
        break;
    }
    cout << key << endl;
    show();

}