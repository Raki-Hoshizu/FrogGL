#ifndef FROG_H
#define FROG_H

#include <iostream>

#include "includes/glm/glm.hpp"
#include "includes/glm/gtc/matrix_transform.hpp"
#include <unistd.h>

#include "camera/cam3rd.h"
#include "shaders/shader.h"
#include "meshes/sphere.h"
#include "meshes/cube.h"


enum texType {
	TEX1,
	COLOR,
	NONE
};

enum shapeType {
	CUBE,
	SPHERE
};

class Frog
{
public:
	Frog(glm::vec3 start);

	void draw(Shader *shader, Texture *texture, int texID = 0);
	void jump();
	void reset();
	void updateRotation();

	Cam3rd camera;

	float Yaw = 0.0f;
	float Pitch = 0.0f;
	glm::vec3 Position; // actual position of the frog
	glm::vec3 prevPosition; // previous position of the frog
	glm::vec3 Direction; // the direction vector, pointing to where the frog is looking at

	std::vector<glm::vec3> ElementsPos; // Vector of it's element positions
	std::vector<glm::vec4> ElementsRot; // Vector of it's element rotations
	std::vector<glm::vec3> ElementsSca; // Vector of it's element scales
	std::vector<shapeType> ElementsType; // Vector if it's element types

	bool jumping = false;
	float jumpAngle = 180.0f;

private:

	void drawElement(int i, texType t, Shader *shader, int texture = 0, glm::vec4 color = glm::vec4(1.0f));

};

#endif