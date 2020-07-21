#include <iostream>
#include <GL/glut.h>
#include "key_keyboard.h"
using namespace std;

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
    }
    cout << key << endl;
    show();

}