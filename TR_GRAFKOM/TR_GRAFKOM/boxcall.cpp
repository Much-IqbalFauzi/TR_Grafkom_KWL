#include <GL/glut.h>
#include <windows.h>

void Warna(int r = 1, int g = 1, int b = 1, float a = 1) {
    glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void box_frontBack(int panjang = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
    glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
    glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
    glVertex3d((1 * panjang) + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void box_sides(int lebar = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
    glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
    glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
    glVertex3d(0 + p_x, (1 * tinggi) + p_y, (-1 * lebar) + p_z);
    glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void box_topBottom(int panjang = 1, int lebar = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
    glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
    glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
    glVertex3d((1 * panjang) + p_x, 0 + p_y, (-1 * lebar) + p_z);
    glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
    glEnd();
}

void box_miringKK(int x_1 = -1, int x_2 = 1, int y_1 = -1, int y_2 = 1, int z_1 = -1, int z_2 = 1) {
    glBegin(GL_QUADS);
    glVertex3d(x_1, y_1, z_1);
    glVertex3d(x_2, y_2, z_1);
    glVertex3d(x_2, y_2, z_2);
    glVertex3d(x_1, y_1, z_2);
    glEnd();
}