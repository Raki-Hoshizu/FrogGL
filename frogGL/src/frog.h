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
	void setShader(Shader* shader);

	void draw(int texture, glm::vec4 color);
	void jump();
	void reset();
	void updateRotation();

	Cam3rd camera;

	float Yaw = 0.0f;
	float Pitch = 0.0f;
	glm::vec3 Position;
	glm::vec3 prevPosition;
	glm::vec3 Direction;

	std::vector<glm::vec3> ElementsPos;
	std::vector<glm::vec4> ElementsRot;
	std::vector<glm::vec3> ElementsSca;
	std::vector<shapeType> ElementsType;

	Shader* ourShader;
	bool jumping = false;
	float jumpAngle = 180.0f;

private:

	void drawElement(int i, texType t, int texture, glm::vec4 color);

	std::vector<glm::vec3> jumpPositions;
};

#endif