#ifndef _BOX_H_
#define _BOX_H_

#include<glut.h>
#include "Tex.h"
#include "MPoint.h"

class Box{
private:
	GLint btype = 1;
	GLfloat bsize = 1;
	GLfloat posX = 0;
	GLfloat posY = 0;
	GLfloat posZ = 0;
	GLfloat rotate = 0;
	GLuint*boxTex=(GLuint*)malloc(sizeof(GLuint));
public:
	Box(){}

	Box(GLfloat posx = 0, GLfloat posy = 0, GLfloat posz = 0, GLfloat size = 1, GLfloat type = 1)
	{
		bsize = size;
		
		posX = posx;
		posY = posy;
		posZ = posz;
	}

	~Box(){}
	void DrawBox()
	{
		if (btype == 1)
			texload(boxTex, "box1.bmp");
		else if (btype == 2)
			texload(boxTex, "box2.bmp");
		else if (btype == 3)
			texload(boxTex, "box3.bmp");

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, *boxTex);

		glPushMatrix();

		glScalef(bsize, bsize, bsize);
		glTranslatef(posX, posY, posZ);

		glRotatef(rotate,0,1,0);

		glBegin(GL_QUADS);
		glTexCoord2i(1, 1);glVertex3f(1, 1, 1);
		glTexCoord2i(0, 1); glVertex3f(1, -1, 1);
		glTexCoord2i(0, 0); glVertex3f(1, -1, -1);
		glTexCoord2i(1, 0); glVertex3f(1, 1, -1);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2i(1, 1); glVertex3f(-1, 1, 1);
		glTexCoord2i(0, 1); glVertex3f(-1, -1, 1);
		glTexCoord2i(0, 0); glVertex3f(-1, -1, -1);
		glTexCoord2i(1, 0); glVertex3f(-1, 1, -1);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2i(1, 1); glVertex3f(1, 1, 1);
		glTexCoord2i(0, 1); glVertex3f(-1, 1, 1);
		glTexCoord2i(0, 0); glVertex3f(-1, 1, -1);
		glTexCoord2i(1, 0); glVertex3f(1, 1, -1);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2i(1, 1); glVertex3f(1, -1, 1);
		glTexCoord2i(0, 1); glVertex3f(-1, -1, 1);
		glTexCoord2i(0, 0); glVertex3f(-1, -1, -1);
		glTexCoord2i(1, 0); glVertex3f(1, -1, -1);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2i(1, 1); glVertex3f(1, 1, -1);
		glTexCoord2i(0, 1); glVertex3f(-1, 1, -1);
		glTexCoord2i(0, 0);	glVertex3f(-1, -1, -1);
		glTexCoord2i(1, 0);	glVertex3f(1, -1, -1);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2i(1, 1); glVertex3f(1, 1, 1);
		glTexCoord2i(0, 1);	glVertex3f(-1, 1, 1);
		glTexCoord2i(0, 0);	glVertex3f(-1, -1, 1);
		glTexCoord2i(1, 0);	glVertex3f(1, -1, 1);
		glEnd();

		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

		MPoint c(3, 6);

		//for (GLfloat x = xbegin; x <= xend; x += accuracy)
		//	for (GLfloat z = zbegin; z <= zend; z += accuracy)
		//		PointList.push_back(MPoint(x, z));
	}

	GLfloat MinX(){
		return posX - bsize;
	}

	GLfloat MaxX(){
		return posX + bsize;
	}

	GLfloat MinZ(){
		return posZ - bsize;
	}

	GLfloat MaxZ(){
		return posZ + bsize;
	}

};

#endif