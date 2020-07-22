#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include "boxcall.h"
#include "mouseAct.h"
#include "vehicle_part.h"
#include "key_keyboard.h"
using namespace std;

class Vehicle {
    public:
        void body() {
           
        init_kwlBody_atas();
        init_kwlBody_depan();
        init_kwlBody_belakang();

        latarTempat();
        }

        void movements() {

        }

        void setPistonAct(int itr) {
            pistonAct = itr;
        }

        int getPistonAct() {
            return pistonAct;
        }
    private:
        int pistonAct;
};

Vehicle Vv;

class VehicleKawai : public Vehicle {
    public:

        
};



void show(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    lightOn();
    glMatrixMode(GL_PROJECTION);
    gluLookAt(60, 20, 350, 0, 0, 0, 0, 1, 0);
    mouseActive();

    Vv.body();
    
    glPopMatrix();

    glutSwapBuffers();
}

void myInit() {
    glClearColor((float)77 / 255.0f, (float)72 / 255.0f, (float)63 / 255.0f, 1);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Resize_aspRR(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, -100.0f);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(133, 54);

    glutCreateWindow("Grafkom_Komatsu Wheel Loader");
    myInit();
    glutReshapeFunc(Resize_aspRR);
    glutDisplayFunc(show);
    glutKeyboardFunc(key);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glutMainLoop();
    return 0;
}