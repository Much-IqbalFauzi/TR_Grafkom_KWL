#pragma once

void Warna(int r = 1, int g = 1, int b = 1, float a = 1);

void box_frontBack(int panjang = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0, int geser_Z = 0);

void box_sides(int lebar = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0, int geser_X = 0);

void box_topBottom(int panjang = 1, int lebar = 1, int p_x = 0, int p_y = 0, int p_z = 0);

void box_miringKK(int x_1 = -1, int x_2 = 1, int y_1 = -1, int y_2 = 1, int z_1 = -1, int z_2 = 1);
