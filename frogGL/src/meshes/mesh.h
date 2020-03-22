#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include "includes/glm/glm.hpp"
#include "includes/glm/gtc/matrix_transform.hpp"

#include <vector>

enum TOPOLOGY
{
	POINTS,
	LINES,
	LINE_STRIP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN
};

class Mesh
{
public:
	unsigned int m_VAO = 0;
	unsigned int m_VBO;
	unsigned int m_EBO;

	std::vector<glm::vec3> Positions;
	std::vector<glm::vec2> UV;
	std::vector<glm::vec3> Normals;

	TOPOLOGY Topology = TRIANGLES;
	std::vector<unsigned int> Indices;

	Mesh();

	void Finalize(bool interleaved = true);
};

#endif