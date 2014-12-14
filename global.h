#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <glut.h>

using namespace std;

struct POLAR
{
	float r;            //距离r
	float alpha;     //水平偏角α
	float fy;          //竖直偏角φ（单位均用角度）
};

struct POLAR  polar = { 35.0f, 90, 90 };

struct CAMERA   /*用于摄像机定位*/
{
	GLfloat  xeye;
	GLfloat yeye;
	GLfloat zeye;
};
struct CAMERA  camera = { 2, 0, 0 };

GLint centerPoint[] = { 0, 0 };
GLint previousPoint[] = { 0, 0 };

GLfloat initPos[] = { 0, 0, 0 };
GLfloat initScale[] = { 0.3, 0.3, 0.3 };

GLsizei initialSize[] = { 1200, 660 }; 

int   RButtonDown = false;
float fTranslate;
float fRotate;
Box box[2];
GLfloat singleStep = 0.2;
GLfloat rotateRatio = 0.3;
GLfloat m_PosX = 15;
GLfloat m_PosY = 10;
GLfloat m_PosZ = 15;
GLsizei currentSize[] = { 0, 0 };
bool ignoreMsg = false;
bool bshow = false;
bool bjump = false;
bool lightOn = false;

GLint lightS = 0;

GLint bList = 0;

GLint wallList = 0;
GLint singleLineList = 0;
GLint singleColumnList = 0;
GLint dragonList = 0;

GLuint Tex[20];
int texindex = 0;

WObj dragon("Data/dragon/alduin.obj");
WObj heli("Data/heli/heli.obj");

#endif // !_GLOBAL_H_
