#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

typedef struct matStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess[4];
}Material;

//window size
#define W_WIDTH 400
#define W_HEIGHT 400

// TODO: add headers that you want to pre-compile here
#define print(x)(std::cout << x << "\n")


//my classes
#include "Time.h"
#endif //PCH_H
