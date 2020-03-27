#include "frog.h"

Frog::Frog(glm::vec3 start)
{
	Position = start;
	Direction = glm::vec3(0.0f, 0.0f, 1.0f);
	camera.updateCameraVectors(Position, Direction);
	/*
		Elements indices :
			0: Body
			1: Left Eye
			2: Right Eye
			3: Tongue
			4: Left Top-Leg
			5: Left Bottom-Leg
			6: Right Top-Leg
			7: Right Bottom-Leg
			8: Left Arm
			9: Right arm
			10: Left Pupil
			11: Right Pupil
	*/
	ElementsPos.push_back(glm::vec3( 0.0f,    0.0f,   0.0f));  // 0
	ElementsPos.push_back(glm::vec3( 0.04f,   0.06f,  0.15f)); // 1
	ElementsPos.push_back(glm::vec3(-0.04f,   0.06f,  0.15f)); // 2
	ElementsPos.push_back(glm::vec3( 0.0f,   -0.02f,  0.13f)); // 3
	ElementsPos.push_back(glm::vec3( 0.04f,  -0.1f,  -0.1f));  // 4
	ElementsPos.push_back(glm::vec3( 0.04f,  -0.15f, -0.1f));  // 5
	ElementsPos.push_back(glm::vec3(-0.04f,  -0.1f,  -0.1f));  // 6
	ElementsPos.push_back(glm::vec3(-0.04f,  -0.15f, -0.1f));  // 7
	ElementsPos.push_back(glm::vec3( 0.04f,  -0.11f,  0.1f));  // 8
	ElementsPos.push_back(glm::vec3(-0.04f,  -0.11f,  0.1f));  // 9
	ElementsPos.push_back(glm::vec3( 0.04f,   0.06f,  0.17f)); // 10
	ElementsPos.push_back(glm::vec3(-0.04f,   0.06f,  0.17f)); // 11

	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 0
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 1
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 2
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 3
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,  -45.0f)); // 4
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,   10.0f)); // 5
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,  -45.0f)); // 6
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,   10.0f)); // 7
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 8
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 9
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 10
	ElementsRot.push_back(glm::vec4( 1.0f,   0.0f,   0.0f,    0.0f)); // 11

	ElementsSca.push_back(glm::vec3(0.12f,   0.1f,   0.2f)); // 0
	ElementsSca.push_back(glm::vec3(0.02f,  0.02f,  0.02f)); // 1
	ElementsSca.push_back(glm::vec3(0.02f,  0.02f,  0.02f)); // 2
	ElementsSca.push_back(glm::vec3(0.08f,  0.01f,   0.1f)); // 3
	ElementsSca.push_back(glm::vec3(0.02f,  0.02f,   0.1f)); // 4
	ElementsSca.push_back(glm::vec3(0.02f,  0.02f,   0.1f)); // 5
	ElementsSca.push_back(glm::vec3(0.02f,  0.02f,   0.1f)); // 6
	ElementsSca.push_back(glm::vec3(0.02f,  0.02f,   0.1f)); // 7
	ElementsSca.push_back(glm::vec3(0.02f,   0.1f,  0.02f)); // 8
	ElementsSca.push_back(glm::vec3(0.02f,   0.1f,  0.02f)); // 9
	ElementsSca.push_back(glm::vec3(0.005f,  0.005f,  0.005f)); // 10
	ElementsSca.push_back(glm::vec3(0.005f,  0.005f,  0.005f)); // 11

	ElementsType.push_back(shapeType::SPHERE); // 0
	ElementsType.push_back(shapeType::SPHERE); // 1
	ElementsType.push_back(shapeType::SPHERE); // 2
	ElementsType.push_back(shapeType::SPHERE); // 3
	ElementsType.push_back(shapeType::CUBE);   // 4
	ElementsType.push_back(shapeType::CUBE);   // 5
	ElementsType.push_back(shapeType::CUBE);   // 6
	ElementsType.push_back(shapeType::CUBE);   // 7
	ElementsType.push_back(shapeType::CUBE);   // 8
	ElementsType.push_back(shapeType::CUBE);   // 9
	ElementsType.push_back(shapeType::SPHERE); // 10
	ElementsType.push_back(shapeType::SPHERE); // 11
}

void Frog::reset() {
	jumping = false;
	jumpAngle = 180.0f;

	ElementsPos[0] = glm::vec3( 0.0f,    0.0f,   0.0f);
	ElementsPos[1] = glm::vec3( 0.04f,   0.06f,  0.15f);
	ElementsPos[2] = glm::vec3(-0.04f,   0.06f,  0.15f);
	ElementsPos[3] = glm::vec3( 0.0f,   -0.02f,  0.13f);
	ElementsPos[4] = glm::vec3( 0.04f,  -0.1f,  -0.1f);
	ElementsPos[5] = glm::vec3( 0.04f,  -0.15f, -0.1f);
	ElementsPos[6] = glm::vec3(-0.04f,  -0.1f,  -0.1f);
	ElementsPos[7] = glm::vec3(-0.04f,  -0.15f, -0.1f);
	ElementsPos[8] = glm::vec3( 0.04f,  -0.11f,  0.1f);
	ElementsPos[9] = glm::vec3(-0.04f,  -0.11f,  0.1f);
	ElementsPos[10] = glm::vec3( 0.04f,   0.06f,  0.17f);
	ElementsPos[11] = glm::vec3(-0.04f,   0.06f,  0.17f);

	ElementsRot[0].w =   0.0f; // 0
	ElementsRot[1].w =   0.0f; // 1
	ElementsRot[2].w =   0.0f; // 2
	ElementsRot[3].w =   0.0f; // 3
	ElementsRot[4].w = -45.0f; // 4
	ElementsRot[5].w =  10.0f; // 5
	ElementsRot[6].w = -45.0f; // 6
	ElementsRot[7].w =  10.0f; // 7
	ElementsRot[8].w =   0.0f; // 8
	ElementsRot[9].w =   0.0f; // 9
	ElementsRot[10].w =   0.0f; // 10
	ElementsRot[11].w =   0.0f; // 11
	
}

void Frog::draw(Shader* shader, Texture* texture, int texID)
{
	prevPosition = Position; // saving the previous frame position
	if (jumping && jumpAngle >= 0.0f)
	{
		float step = 5.0f; // the angle goes from 180.0f to 0.0f with a step of 5.0f
		Position += Direction * step/180.0f;
		Position.y = sin(glm::radians(jumpAngle)); // perform a beautiful jump, not following gravity or acceleration but in a perfect circle
		jumpAngle -= step;
	}
	else
	{
		reset();
	}

	// drawing every element of the frog
	drawElement(0,  texType::TEX1,  shader, texture->id[texID]);
	drawElement(1,  texType::NONE,  shader);
	drawElement(2,  texType::NONE,  shader);	
	drawElement(3,  texType::COLOR, shader, 0, glm::vec4(1.0f, 0.72f, 0.54f, 1.0f));	
	drawElement(4,  texType::TEX1,  shader, texture->id[texID]);	
	drawElement(5,  texType::TEX1,  shader, texture->id[texID]);
	drawElement(6,  texType::TEX1,  shader, texture->id[texID]);
	drawElement(7,  texType::TEX1,  shader, texture->id[texID]);
	drawElement(8,  texType::TEX1,  shader, texture->id[texID]);
	drawElement(9,  texType::TEX1,  shader, texture->id[texID]);
	drawElement(10, texType::COLOR, shader, 0, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	drawElement(11, texType::COLOR, shader, 0, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	camera.updateCameraVectors(Position, Direction); // updating the camera vectors after drawing the frog
}

// drawing function which draw meshes based on parameters
// ------------------------------------------------------
void Frog::drawElement(int i, texType t, Shader *shader, int texture, glm::vec4 color)
{
	Cube cube;
	Sphere sphere(10, 10);
	int sphereSize, cubeSize;
	glm::vec3 rotate;
	if (t == texType::TEX1)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	switch(ElementsType[i])
	{
		case (shapeType::SPHERE):
		{
			sphereSize = (sphere.Positions.size() + sphere.UV.size() + sphere.Normals.size()) * sizeof(float);
			glBindVertexArray(sphere.m_VAO);
		}
		break;
		case (shapeType::CUBE):
		{
			cubeSize = cube.Positions.size();
			glBindVertexArray(cube.m_VAO);
		}
		break;
		default:
			std::cout << "Error with the type of element " << i << std::endl;
			break;
	}

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, Position);
	model = glm::rotate(model, glm::radians(Yaw), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::translate(model, (-1.0f)*Position);
	model = glm::translate(model, ElementsPos[i] + Position);
	rotate = glm::vec3(ElementsRot[i].x, ElementsRot[i].y, ElementsRot[i].z);
	model = glm::rotate(model, ElementsRot[i].w, rotate);
	model = glm::scale(model, ElementsSca[i]);
	shader->setMat4("model", model);

	switch(t)
	{
		case (texType::TEX1): shader->setBool("drawTex1", true); break;
		case (texType::COLOR):
			shader->setBool("color", true);
			shader->setVec4("ourColor", color);
			break;
		default:
			break;
	}

	switch(ElementsType[i])
	{
		case (shapeType::SPHERE):
			glDrawElements(GL_TRIANGLES, sphereSize, GL_UNSIGNED_INT, 0);
			break;
		case (shapeType::CUBE):
			glDrawArrays(GL_TRIANGLES, 0, cubeSize);
			break;
	}

	switch(t)
	{
		case (texType::TEX1):
			shader->setBool("drawTex1", false);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, 0);
			break;
		case (texType::COLOR):
			shader->setBool("color", false);
			break;
		default:
			break;
	}

	glBindVertexArray(0);

	glDeleteVertexArrays(1, &sphere.m_VAO);
	glDeleteBuffers(1, &sphere.m_VBO);
	glDeleteBuffers(1, &sphere.m_EBO);
		
	glDeleteVertexArrays(1, &cube.m_VAO);
	glDeleteBuffers(1, &cube.m_VBO);
}

// make jumping bool to true and extend legs
void Frog::jump()
{
		jumping = true;
		ElementsRot[4].w -= 15.0f;
		ElementsRot[5].w += 30.0f;
		ElementsPos[5].z -= ElementsSca[5].z-0.01f;
		ElementsRot[6].w -= 15.0f;
		ElementsRot[7].w += 30.0f;
		ElementsPos[7].z -= ElementsSca[7].z-0.01f;
}

// updating frog rotation based on it's Yaw
void Frog::updateRotation()
{
	glm::vec3 direction;
	direction.x = sin(glm::radians(Yaw));
	direction.y = 0;
	direction.z = cos(glm::radians(Yaw));
	Direction = glm::normalize(direction);
	//std::cout << "Direction: [x:" << Direction.x << ", y:" << Direction.y << ", z:" << Direction.z << "]" << std::endl; 
	camera.updateCameraVectors(Position, Direction);
}