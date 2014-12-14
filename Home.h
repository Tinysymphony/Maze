#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <Windows.h>
#include <ctime>
#include <vector>
#include "MPoint.h"
#include "WObj.h"
#include "Tex.h"
#include "box.h"
#include "global.h"
#include "wall.h"
#include "flag.h"
#include "save.h"

#define BITMAP_ID 0x4D42

void DrawWalls();
void DrawObjs();
void DrawBoxes();
void DrawScene();
void Reshape(int width, int height);
void Redraw();
void Idle();
void Delay(int time);
void SetCamera(GLfloat x, GLfloat y);
void OnMouseMove(int x, int y);
void SpaceJump();
void Key(unsigned char k, int x, int y);
void Mouse(int button, int state, int x, int y);
void EnterWindow(int state);
void Init();
void InitDrop(GLfloat z);
void DrawCone(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat radius, GLfloat height, GLint M);
void DrawSphere(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat radius, GLfloat M, GLfloat N);