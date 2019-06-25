#ifndef INTERACTIONS_H
// *.h 的函数 直接拼接 到 代码段中
#define INTERACTIONS_H
#include"kernel.h"

#define W 600
#define H 600
#define DELTA 5 // pixel increament for arrow keys
#define TITLE_STRING "flashlight: distance image display app"

int2 loc = { W / 2, H / 2 };
bool dragMode = false;   //mouse tracking mode

void keyboard(unsigned char key, int x, int y) {
	if (key == 'a')
		dragMode = !dragMode;
	if (key == 27)
	{
		printf("error keyboard.");
		return;
	}//if
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	if (dragMode) return;
	loc.x = x;
	loc.y = y;
	glutPostRedisplay();
}

void mouseDrag(int x, int y) {
	if (!dragMode) return;
	loc.x = x;
	loc.y = y;
	glutPostRedisplay();
}

void handleSpacialKeypress(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) loc.x -= DELTA;
	if (key == GLUT_KEY_RIGHT) loc.x += DELTA;
	if (key == GLUT_KEY_DOWN) loc.y += DELTA;
	if (key == GLUT_KEY_UP) loc.y -= DELTA;
	glutPostRedisplay();
}

void printInstructions() {
	printf("flashlight interactions.\n");
	printf("a: toggle mouse tracking mode.\n");
	printf("arrow keys: move ref location.\n");
	printf("esc: close graphics windows.\n");
}

#endif // !INTERACTIONS_H
