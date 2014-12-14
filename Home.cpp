#include "Home.h"


#define DEG_TO_RAD 0.017453
#define PI 3.141592654

vector<MPoint>PointList;

GLint SingleWall(GLfloat x,GLfloat z,GLint type)
{
	Wall p1(0, 0, 1);
	Wall p2(0, 0, 2);
	if (type == 1)
	{
		GLint lid = glGenLists(1);
		glNewList(lid, GL_COMPILE);
		
		glTranslatef(0, 0, -1);
		p1.DrawWall();
		glTranslatef(0, 0, 2);
		p1.DrawWall();
		glTranslatef(0, 0, -1);

		glEndList();
		return lid;
	}
	else{
		GLint lid = glGenLists(1);
		glNewList(lid, GL_COMPILE);
		//glRotatef(90 * type, 0, 1, 0);

		glTranslatef(-1, 0, 0);
		p2.DrawWall();
		glTranslatef(2, 0, 0);
		p2.DrawWall();
		glTranslatef(-1, 0, 0);

		glEndList();
		return lid;
	}
}

GLint DragonList()
{
	GLint lid = glGenLists(1);
	glNewList(lid, GL_COMPILE);
	glRotatef(125, 1, 0, 0);
	dragon.DrawObj();
	glEndList();
	return lid;
}

GLint WallList()
{
	GLint lid = glGenLists(10);
	glNewList(lid, GL_COMPILE);
	Wall p(0, 0, 1);
	glPushMatrix();
	glTranslatef(0, 0, -15);
	for (int i = 1; i <= 16;i++)
	{
	    p.DrawWall();
		glTranslatef(0, 0, 2);
	}
	glPopMatrix();

	glEndList();
	return lid;
}

void DrawBarrier()
{
	glPushMatrix();
	glTranslatef(0,0.5,0);
	//line 12
	glPushMatrix();
	glTranslatef(-10, 0, 12);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glPopMatrix();

	//line 8
	glPushMatrix();
	glTranslatef(-10, 0, 8);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(8, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glPopMatrix();

	//line 4
	glPushMatrix();
	glTranslatef(-2, 0, 4);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glPopMatrix();

	//line 0
	glPushMatrix();
	glTranslatef(-14, 0, 0);
	glCallList(singleLineList);
	glTranslatef(24, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glPopMatrix();

	//line -4
	glPushMatrix();
	glTranslatef(-2, 0, -4);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glPopMatrix();

	//line -8
	glPushMatrix();
	glTranslatef(-6, 0, -8);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glPopMatrix();

	//line -12
	glPushMatrix();
	glTranslatef(-10, 0, -12);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glTranslatef(8, 0, 0);
	glCallList(singleLineList);
	glTranslatef(4, 0, 0);
	glCallList(singleLineList);
	glPopMatrix();

    //column -12
	glPushMatrix();
	glTranslatef(-12, 0, -10);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glPopMatrix();

	//column -8
	glPushMatrix();
	glTranslatef(-8, 0, -6);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glPopMatrix();

	//column -4
	glPushMatrix();
	glTranslatef(-4, 0, -2);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glPopMatrix();

	//column 0
	glPushMatrix();
	glTranslatef(0, 0, -14);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 8);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 16);
	glCallList(singleColumnList);
	glPopMatrix();

	//column 4

	//column 8
	glPushMatrix();
	glTranslatef(8, 0, -2);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glPopMatrix();

	//column 12
	glPushMatrix();
	glTranslatef(12, 0, -10);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 12);
	glCallList(singleColumnList);
	glTranslatef(0, 0, 4);
	glCallList(singleColumnList);
	glPopMatrix();
	glPopMatrix();

}

void DrawWalls()
{

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glTranslatef(-16, 0, 0);
	glCallList(wallList);
	glTranslatef(32, 0, 0);
	glCallList(wallList);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,0,-16);
	glTranslatef(0, 0.5, 0);
	glRotatef(90, 0, 1, 0);
	glCallList(wallList);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glTranslatef(0, 0, 16);
	glRotatef(90, 0, 1, 0);
	glCallList(wallList);
	glPopMatrix();
}

void DrawFloor()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[texindex]);
	glTranslatef(0, -0.5, 0);

	glBegin(GL_QUADS);

	glTexCoord2i(50, 50); glVertex3f(-50, 0, 50);
	glTexCoord2i(50, 0); glVertex3f(-50, 0, -50);
	glTexCoord2i(0, 0); glVertex3f(50, 0, -50);
	glTexCoord2i(0, 50); glVertex3f(50, 0, 50);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


}

void DrawObjs()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[6]);
	glPushMatrix();
	glTranslatef(4, 5, 7);
	glCallList(dragonList);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[6]);
	glPushMatrix();
	glTranslatef(-4, 8, 1);
	glCallList(dragonList);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[6]);
	glPushMatrix();
	glTranslatef(-1, 6, -3);
	glScalef(0.5, 0.5, 0.5);
	glCallList(dragonList);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[6]);
	glPushMatrix();
	glTranslatef(3, 12, -1);
	glScalef(0.6, 0.6, 0.6);
	glCallList(dragonList);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[6]);
	glPushMatrix();
	glTranslatef(-4, 6, 3);
	glScalef(0.5, 0.5, 0.5);
	glCallList(dragonList);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[10]);
	glPushMatrix();
	glTranslatef(0, 1.3, 0);
	glRotatef(120, 1, 0, 0);
	glScalef(0.8, 0.8, 0.8);
    heli.DrawObj();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}

void DrawSphere(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat radius, GLfloat M, GLfloat N)
{
	GLfloat stepZ = PI / M;
	GLfloat stepXY = 2 * PI / N;
	GLfloat x[4], y[4], z[4];
	GLfloat angleZ = 0;
	GLfloat angleXY = 0;
	GLint i = 0, j = 0;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[7]);
	for (i = 0; i < M; i++)
	{
		angleZ = i*stepZ;
		
		for (j = 0; j < N; j++)
		{
			angleXY = j*stepXY;

			x[0] = radius*sin(angleZ)*cos(angleXY);
			y[0] = radius*sin(angleZ)*sin(angleXY);
			z[0] = radius*cos(angleZ);

			x[1] = radius*sin(angleZ + stepZ)*cos(angleXY);
			y[1] = radius*sin(angleZ + stepZ)*sin(angleXY);
			z[1] = radius*cos(angleZ + stepZ);

			x[2] = radius*sin(angleZ + stepZ)*cos(angleXY + stepXY);
			y[2] = radius*sin(angleZ + stepZ)*sin(angleXY + stepXY);
			z[2] = radius*cos(angleZ + stepZ);

			x[3] = radius*sin(angleZ)*cos(angleXY + stepXY);
			y[3] = radius*sin(angleZ)*sin(angleXY + stepXY);
			z[3] = radius*cos(angleZ);

			glBegin(GL_QUADS);
			for (int k = 0; k < 4; k++)
			{
				glTexCoord2f(k>=2,k<=2);
				glVertex3f(posX+x[k],posY+y[k],posZ+z[k]);
			}
			glEnd();

		}
	}
	glDisable(GL_TEXTURE_2D);
}

void DrawCone(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat radius, GLfloat height, GLint M = 20)
{
	GLfloat angle = 0;
	GLfloat step = 2 * PI / M;
	GLfloat x[2], z[2];

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[13]);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < M; i++)
	{
		angle = i*step;
		x[0] = radius*sin(angle);
		z[0] = radius*cos(angle);
		x[1] = radius*sin(angle + step);
		z[1] = radius*cos(angle + step);
		
		glTexCoord2f(0, 0);
		glVertex3f(posX + x[0], posY, posZ + z[0]);
		glTexCoord2f(1, 0);
		glVertex3f(posX + x[1], posY, posZ + z[1]);
		glTexCoord2f(1, 1);
		glVertex3f(posX, posY, posZ);

		glTexCoord2f(0, 0);
		glVertex3f(posX + x[0], posY, posZ + z[0]);
		glTexCoord2f(1, 0);
		glVertex3f(posX + x[1], posY, posZ + z[1]);
		glTexCoord2f(1, 1);
		glVertex3f(posX, posY + height, posZ);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

}

void DrawPrismoid(GLfloat posX, GLfloat posY, GLfloat posZ,GLfloat radiusA,GLfloat radiusB, GLfloat height, GLint M=20)
{
	GLfloat angle = 0;
	GLfloat step = 2 * PI / M;
	GLfloat x[4], z[4];
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[13]);
	for (int i = 0; i < M; i++)
	{
		angle = i*step;
		x[0] = radiusA*sin(angle);
		z[0] = radiusA*cos(angle);
		x[1] = radiusA*sin(angle + step);
		z[1] = radiusA*cos(angle + step);
		x[2] = radiusB*sin(angle);
		z[2] = radiusB*cos(angle);
		x[3] = radiusB*sin(angle + step);
		z[3] = radiusB*cos(angle + step);

		glBegin(GL_TRIANGLES);
		glTexCoord2f(0, 0);
		glVertex3f(posX + x[0], posY, posZ + z[0]);
		glTexCoord2f(1, 0);
		glVertex3f(posX + x[1], posY, posZ + z[1]);
		glTexCoord2f(1, 1);
		glVertex3f(posX, posY, posZ);

		glTexCoord2f(0, 0);
		glVertex3f(posX + x[2], posY+height, posZ + z[2]);
		glTexCoord2f(1, 0);
		glVertex3f(posX + x[3], posY+height, posZ + z[3]);
		glTexCoord2f(1, 1);
		glVertex3f(posX, posY + height, posZ);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(posX + x[0], posY, posZ + z[0]);
		glTexCoord2f(1, 0);
		glVertex3f(posX + x[1], posY, posZ + z[1]);
		glTexCoord2f(1, 1);
		glVertex3f(posX + x[3], posY+height, posZ + z[3]);
		glTexCoord2f(0, 1);
		glVertex3f(posX + x[2], posY+height, posZ + z[2]);
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);

}

void DrawCylinder(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat radius, GLfloat height, GLint M = 20)
{
	GLfloat angle = 0;
	GLfloat step = 2 * PI / M;
	GLfloat x[2], z[2];

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[13]);
	for (int i = 0; i < M; i++)
	{
		angle = i*step;
		x[0] = radius*sin(angle);
		z[0] = radius*cos(angle);
		x[1] = radius*sin(angle + step);
		z[1] = radius*cos(angle + step);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1, 1);
		glVertex3f(posX + x[0], posY, posZ + z[0]);
		glTexCoord2f(0, 1);
		glVertex3f(posX + x[1], posY, posZ + z[1]);
		glTexCoord2f(0, 0);
		glVertex3f(posX, posY, posZ);
		glTexCoord2f(1, 1);
		glVertex3f(posX + x[0], posY + height, posZ + z[0]);
		glTexCoord2f(0, 1);
		glVertex3f(posX + x[1], posY + height, posZ + z[1]);
		glTexCoord2f(0, 0);
		glVertex3f(posX, posY + height, posZ);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2f(1, 1); glVertex3f(posX + x[0], posY + height, posZ + z[0]);
		glTexCoord2f(0, 1); glVertex3f(posX + x[1], posY + height, posZ + z[1]);
		glTexCoord2f(0, 0); glVertex3f(posX + x[1], posY, posZ + z[1]);
		glTexCoord2f(1, 0); glVertex3f(posX + x[0], posY, posZ + z[0]);
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);

}

void DrawBoxes()
{
	glPushMatrix();
	glTranslatef(-2,0,-2);
	glScalef(0.5, 0.5, 0.5);
	box[0].DrawBox();
	glPopMatrix();
}

void DrawInfo()
{
	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Tex[15]);
	glBegin(GL_QUADS);
	glTexCoord2i(1, 1); glVertex3f(13, 2, 15.88);
	glTexCoord2i(1, 0); glVertex3f(13, 0, 15.88);
	glTexCoord2i(0, 0); glVertex3f(15, 0, 15.88);
	glTexCoord2i(0, 1); glVertex3f(15, 2, 15.88);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void DrawScene()
{
	DrawFloor();
	DrawInfo();
	if (!bshow)
	{
		DrawBarrier();
		DrawWalls();
	}
	DrawSphere(0,0,0,60,60,60);
	DrawCone(-2, -0.5, 0.5, 0.5, 0.5, 60);
	DrawPrismoid(-2, -0.5, -2, 0.5, 0.2, 0.5,6);
	DrawCylinder(-2, -0.5, -1, 0.5, 0.5, 3);
	DrawCylinder(-2, -0.5, 2, 0.5, 0.5, 60);
	DrawObjs();
	//DrawBoxes();

	glFlush();
}

void Reshape(int width, int height)
{
	currentSize[0] = width;
	currentSize[1] = height;
	centerPoint[0] = currentSize[0] / 2;
	centerPoint[1] = currentSize[1] / 2;
	if (currentSize[1] == 0)                                        // Prevent A Divide By Zero By
	{
		currentSize[1] = 1;                                        // Making currentSize[1] Equal One
	}

	glViewport(0, 0, currentSize[0], currentSize[1]);                        // Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
	glLoadIdentity();                                    // Reset The Projection Matrix
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)currentSize[0] / (GLfloat)currentSize[1], 0.1f, 100.0f);//透视投影
	glMatrixMode(GL_MODELVIEW);                            // Select The Modelview Matrix
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);

}

void Redraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(m_PosX, m_PosY, m_PosZ,
		m_PosX + camera.xeye, m_PosY + camera.yeye, m_PosZ + camera.zeye,
		0.0, 1.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	GLfloat lightDirection[] = { camera.xeye, camera.yeye+0.5, camera.zeye };

	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_pos[] = { 5, 5, 5, -1 };
	GLfloat spot_direction[] = { -1, -1, -1, 1 };
	GLfloat light_diffuse[] = { 1, 1, 1, 1.0 };
	GLfloat light_specular[] = { 1, 1, 1, 1.0 };

	glLightfv(GL_LIGHT5, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT5, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spot_direction);
	glLightfv(GL_LIGHT5, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT5, GL_AMBIENT, white);

	GLfloat mpos[] = { m_PosX, m_PosY, m_PosZ,1};
	glLightfv(GL_LIGHT2, GL_POSITION, (const GLfloat*)mpos);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 25.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, lightDirection);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, lightS);
	glLightfv(GL_LIGHT2, GL_AMBIENT, white);
	glEnable(GL_LIGHT2);
	DrawScene();

	glutSwapBuffers();
}

void Idle()
{
	glutPostRedisplay();
}

void Delay(int time)
{
	clock_t now = clock();
	while (clock() - now < time);
}

void SetCamera(GLfloat x, GLfloat y)         /*x，y 是水平方向和竖直方向的改变量*/
{
	GLfloat alpha, fy;                  /*和它的名字一样，不过是单位是弧度*/
	if ((polar.fy + y)>5.0f && (polar.fy + y)<175.0f)
	{     /*定义竖直偏角只能在5°到175°之间*/
		polar.alpha += x;                  /*根据鼠标移动的方向设置新的球坐标*/
		polar.fy += y;

		if (polar.alpha>360.0f) polar.alpha -= 360.0f;
		if (polar.alpha<0.0f) polar.alpha += 360.0f;

		alpha = polar.alpha*DEG_TO_RAD;
		fy = polar.fy*DEG_TO_RAD;            /*角度转弧度*/
		camera.xeye = polar.r * sin(fy) * cos(alpha);       /*极坐标转直角坐标*/
		camera.zeye = polar.r * sin(fy) * sin(alpha);
		camera.yeye = -polar.r * cos(fy);
	}
}

void OnMouseMove(int x, int y)          /*当鼠标移动时会回调该函数*/
{
	if (ignoreMsg == true)
	{
		previousPoint[0] = x;
		previousPoint[1] = y;
		ignoreMsg = false;
		return;
	}
	else
	{
		SetCamera(rotateRatio*float(x - previousPoint[0]), rotateRatio*float(previousPoint[1] - y));
		//previousPoint[0] = x;
		//previousPoint[1] = y;
		ignoreMsg = true;
		SetCursorPos(centerPoint[0], centerPoint[1]);
		//redraw();
		return;
	}
}

void FlyHigh()
{
	GLfloat maxHeight = 5;
	GLfloat gravity = 10;
	GLint frequency = 30;
	GLfloat time = sqrt(2 * maxHeight / gravity);

	for (int n = frequency; n >= 1; n--)
	{
		float t1 = (float(n) / frequency)*time;
		float t2 = (float(n - 1) / frequency)*time;
		Delay(1000 * time / frequency);
		m_PosY += 0.5*gravity*(t1*t1 - t2*t2);
		Redraw();
	}
	texindex = 14;
	Redraw();
	Delay(4000);

	exit(0);
}

void SpaceJump()
{
	GLfloat maxHeight = 0.8;
	GLfloat gravity = 10;
	GLint frequency = 30;
	GLfloat time = sqrt(2 * maxHeight / gravity);

	for (int n = frequency; n >=1; n--)
	{
		float t1 = (float (n) / frequency)*time;
		float t2 = (float(n - 1) / frequency)*time;
		Delay(1000 * time / frequency);
		m_PosY += 0.5*gravity*(t1*t1 - t2*t2);
		Redraw();
	}
	if (bjump == false)
	{
		for (int n = 1; n <= frequency; n++)
		{
			float t1 = (float(n) / frequency)*time;
			float t2 = (float(n - 1) / frequency)*time;
			Delay(1000 * time / frequency);
			m_PosY -= 0.5*gravity*(t1*t1 - t2*t2);
			Redraw();
		}
	}
}

void Key(unsigned char k, int x, int y)
{

	MPoint tmp(m_PosX,m_PosZ);
	switch (k) {
		case 'w':
			tmp.move(singleStep*camera.xeye / polar.r,singleStep*camera.zeye / polar.r);
			if (flag(tmp)||bshow==true)
			{
				m_PosZ = tmp.getZ();
				m_PosX = tmp.getX();
			}
			break;
		case 's':
			tmp.move(-singleStep*camera.xeye / polar.r, -singleStep*camera.zeye / polar.r);
			if (flag(tmp) || bshow == true)
			{
				m_PosZ = tmp.getZ();
				m_PosX = tmp.getX();
			}
			break;
		case 'a':
			tmp.move(singleStep*camera.zeye / polar.r, -singleStep*camera.xeye / polar.r);
			if (flag(tmp) || bshow == true)
			{
				m_PosZ = tmp.getZ();
				m_PosX = tmp.getX();
			}
			break;
		case 'd':
			tmp.move(-singleStep*camera.zeye / polar.r, singleStep*camera.xeye / polar.r);
			if (flag(tmp) || bshow == true)
			{
				m_PosZ = tmp.getZ();
				m_PosX = tmp.getX();
			}
			break;
		case ' ':
			SpaceJump();
			break;
		case 'z'://test for set cursor
			if (texindex != 5)
				texindex++;
			else
				texindex = 0;
			break;
		case 'p'://snape  screen
			SnapScreen(initialSize[0],initialSize[1]);
			break;
		case 'i':
			bshow = !bshow;
			break;
		case 'u':
			bjump = !bjump;
			break;
		case 'b':
			InitDrop(m_PosY);
			break;
		case 'c':
			lightS++;
			break;
		case 'x':
			lightS--;
			break;
		case 'o':
			lightOn = !lightOn;
			if (lightOn)
				glEnable(GL_LIGHT5);
			else
				glDisable(GL_LIGHT5);
			break;
		case 27:
			exit(0);
			break;
		default:break;
	}
}

void Mouse(int button, int state, int x, int y)        /*当鼠标按下或拿起时会回调该函数*/
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		ignoreMsg = true;
		SetCursorPos(centerPoint[0], centerPoint[1]);
		//ignoreMsg = false;
	}
}

void EnterWindow(int state){
	if (state == GLUT_LEFT)
	{//pick another window case the following actions such as pause
	}
	else if (state == GLUT_ENTERED)  //initialize the position of the cursor
		SetCursorPos(centerPoint[0],centerPoint[1]);
}

void InitDrop(GLfloat z)
{
	GLfloat gravity = 10;
	GLint frequency = 30;
	GLfloat time = sqrt(2 * z / gravity);
	for (int n = 1; n <= frequency; n++)
	{
		float t1 = (float(n) / frequency)*time;
		float t2 = (float(n - 1) / frequency)*time;
		Delay(1000 * time / frequency);
		m_PosY -= 0.5*gravity*(t1*t1 - t2*t2);
		Redraw();
	}
}
 
void Init(){

	glGenTextures(20, Tex);

	GLuint*tmp = Tex;

	texload(tmp, "1.bmp");
	texload(++tmp, "2.bmp");
	texload(++tmp, "4.bmp");
	texload(++tmp, "5.bmp");
	texload(++tmp, "8.bmp");
	texload(++tmp, "9.bmp");
	texload(++tmp, "sky.bmp");
	texload(++tmp, "sky2.bmp");
	texload(++tmp, "walltext.bmp");
	texload(++tmp, "micai1.bmp");
	texload(++tmp, "micai2.bmp");
	texload(++tmp, "metal1.bmp");
	texload(++tmp, "metal2.bmp");
	texload(++tmp, "blue.bmp");
	texload(++tmp, "win.bmp");
	texload(++tmp, "tip.bmp");

	wallList = WallList();
	dragonList = DragonList();
	singleLineList = SingleWall(0, 0, 2);
	singleColumnList = SingleWall(0, 0, 1);

	//GLuint texture[5];
	centerPoint[0] = currentSize[0] / 2;
	centerPoint[1] = currentSize[1] / 2;
	previousPoint[0] = centerPoint[0];
	previousPoint[1] = centerPoint[1];
	SetCamera(0.0f, 0.0f);
	ShowCursor(false);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	
	currentSize[0] = initialSize[0];
	currentSize[1] = initialSize[1];
	glutInitWindowPosition(GetSystemMetrics(SM_CXSCREEN) / 2 - initialSize[0] / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - initialSize[1] / 2);
	glutInitWindowSize(initialSize[0], initialSize[1]);  //set initial size of the window
	//glutInitWindowSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	glutCreateWindow(argv[0]);
	//glutMenuStateFunc(void(*func)(int state));  //use the menu
	//glutTimerFunc(unsigned int millis, void(*func)(int value), int value);  //do the func when time ends(disposable)
	Init();
	glutDisplayFunc(Redraw);
	glutReshapeFunc(Reshape);
    glutEntryFunc(EnterWindow);  //callback when the mouse enters into the window or moves out of it
	glutKeyboardFunc(Key);
	glutIdleFunc(Idle);
	glutMouseFunc(Mouse);
	glutPassiveMotionFunc(OnMouseMove); //change view direction when the mouse moves
	glutMainLoop();
	return 0;
}


