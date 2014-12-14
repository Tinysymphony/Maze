#ifndef _MPOINT_H_
#define _MPOINT_H_

#include<glut.h>
class MPoint
{
private:
	GLfloat posX;
	GLfloat posZ;
	GLfloat stdX;
	GLfloat stdZ;
public:
	MPoint(GLfloat x = 0, GLfloat z = 0)
	{ 
		posX = x; 
		posZ = z; 
		standardize();
	}
	bool operator==(const MPoint &point) const
	{
		if (stdX == point.stdX && stdZ == point.stdZ)
			return true;
		return false;
	}
	void move(GLfloat moveX,GLfloat moveZ)
	{
		posX += moveX;
		posZ += moveZ;
		standardize();
	}
	void standardize()
	{
		stdX = (posX * 10 + 0.5) / 10;
		stdZ = (posZ * 10 + 0.5) / 10;	
	}
	GLfloat getX(){ return posX; }
	GLfloat getZ(){ return posZ; }
};

#endif