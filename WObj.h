#ifndef _WOBJ_H_
#define _WOBJ_H_

#include <glut.h>
#include "glm.h"

extern GLint dragonList;

class WObj{
private:
	char file[128];
	GLMmodel *mBox;
	GLuint mBoxList;
public:
	WObj(char* addr){
		strcpy(file,addr);
		LoadObjFile();
	}
	~WObj(){
		glmDelete(mBox);
	}

	void LoadObjFile(){
		GLfloat scalefactor = 0.0;
		mBox = glmReadOBJ(file);
		if (!scalefactor)
		{
			scalefactor = glmUnitize(mBox);
		}
		else
		{
			glmScale(mBox, scalefactor);
		}
		glmScale(mBox, 4);
	}

	void DrawObj()
	{
		glRotatef(-120, 1, 0, 0);
		glmDraw(mBox, GLM_MATERIAL | GLM_TEXTURE | GLM_SMOOTH);
	}
};

#endif // !1
