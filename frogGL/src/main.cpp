#include "init.h" // initialize function prototypes

#include "frog.h" // includes sphere.h and cube.h
#include "camera/freecam.h"
#include "meshes/plane.h"

// path variables
// --------------
std::string srcPath = "/home/rakl/Repository/Image-Synthesis/frogGL/src/";
std::string shadersPath = srcPath + "shaders/";
std::string texturesPath = srcPath + "textures/";

// ground variables
// ----------------
const unsigned int nbPlane = 25;
float minPlane = (-1.0f)*sqrt(nbPlane);
float maxPlane = sqrt(nbPlane);

// actors
// ------------------
Frog frog(glm::vec3(0.0f, 0.0f, 0.0f));
Frog frogBot(glm::vec3(0.0f, 0.0f, 3.0f));

// camera variables
// ----------------
Freecam freecam(glm::vec3(0.0f, 2.0f, 3.0f));
// starting in freecam
Camera* currentCamera = &freecam;
bool freeMode = true;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing variables
// ----------------
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main(int argc, char **argv)
{
	// initialize glfw
	// ---------------
	GLFWwindow* window = init();

	// build and compile our shader program
	// ------------------------------------
	Shader ourShader((shadersPath+"shader.vs").c_str(), (shadersPath+"shader.fs").c_str());

	// set up objects and vertex positions
	// ------------------------------------------------------------------
	Plane plane(100, 100); // glfw needs to be initialized first, because Plane and Cube have Buffers and Array objects
	Cube cube;
	// frogs
	frog.setShader(&ourShader);
	frogBot.setShader(&ourShader);
	// world space positions
	glm::vec3 planePositions[] = {
		glm::vec3(-4.0f, -0.2f, -4.0f), glm::vec3(-2.0f, -0.2f, -4.0f), glm::vec3( 0.0f, -0.2f, -4.0f), glm::vec3( 2.0f, -0.2f, -4.0f), glm::vec3( 4.0f, -0.2f, -4.0f),
		glm::vec3(-4.0f, -0.2f, -2.0f), glm::vec3(-2.0f, -0.2f, -2.0f), glm::vec3( 0.0f, -0.2f, -2.0f), glm::vec3( 2.0f, -0.2f, -2.0f), glm::vec3( 4.0f, -0.2f, -2.0f),
		glm::vec3(-4.0f, -0.2f,  0.0f), glm::vec3(-2.0f, -0.2f,  0.0f), glm::vec3( 0.0f, -0.2f,  0.0f), glm::vec3( 2.0f, -0.2f,  0.0f), glm::vec3( 4.0f, -0.2f,  0.0f),
		glm::vec3(-4.0f, -0.2f,  2.0f), glm::vec3(-2.0f, -0.2f,  2.0f), glm::vec3( 0.0f, -0.2f,  2.0f), glm::vec3( 2.0f, -0.2f,  2.0f), glm::vec3( 4.0f, -0.2f,  2.0f),
		glm::vec3(-4.0f, -0.2f,  4.0f), glm::vec3(-2.0f, -0.2f,  4.0f), glm::vec3( 0.0f, -0.2f,  4.0f), glm::vec3( 2.0f, -0.2f,  4.0f), glm::vec3( 4.0f, -0.2f,  4.0f)
	};
	glm::vec3 cubePositions[] = {
		glm::vec3( 0.0f,  2.0f,  0.0f), glm::vec3( 2.0f, 7.0f, -15.0f), glm::vec3(-1.5f,  6.2f, -2.5f), glm::vec3(-3.8f, 2.0f, -12.3f), glm::vec3( 2.4f,  4.4f, -3.5f),
		glm::vec3(-1.7f,  5.0f, -7.5f), glm::vec3( 3.0f, 4.0f, -2.5f),  glm::vec3( 1.5f,  4.0f, -5.5f), glm::vec3( 1.5f,  2.2f, -1.5f), glm::vec3(-1.3f,  3.0f, -1.5f)
	};

    // adding our textures
    // -------------------------
    Texture texture(texturesPath);
    texture.add("frog.png");	// texture.id[0]
    for (int i = 1; i <= 10; ++i) 	// texture.id[1->10]
    {
    	std::string name = "grass"+std::to_string(i)+".jpg";
    	texture.add(name);
    }
    bool rev = false;
    texture.add("container.jpg");	// texture.id[11]
    texture.add("gear.png", GL_RGBA);	// texture.id[12]
	
	// tell OpenGL for each sampler to which texture unit it belongs to
	// -------------------------------------------------------------------------------------------
	ourShader.use();
	ourShader.setInt("texture1", 0);
	ourShader.setInt("texture2", 1);

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// activate shader
		ourShader.use();

		// pass projection matrix to shader
		glm::mat4 projection = glm::perspective(glm::radians(currentCamera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		ourShader.setMat4("projection", projection);

		// camera/view transformation
		glm::mat4 view = currentCamera->GetViewMatrix();
		ourShader.setMat4("view", view);

		// draw ground
		int id = (int)currentFrame%10 + 1;
		for (unsigned int i = 0; i < nbPlane; ++i)
		{
			glm::vec4 rotation = glm::vec4(1.0f, 0.0f, 0.0f, 90.0f);
			plane.draw(planePositions[i], rotation, 1, &ourShader, &texture, id);
		}

		// draw flying cubes
		for (unsigned int i = 0; i < 10; ++i)
		{
			glm::vec4 rotation = glm::vec4(sin(i), 0.3f, 0.2f, 20.0f*glfwGetTime());
			cube.draw(cubePositions[i], rotation, 2, &ourShader, &texture, 11, 12, 0.4f);
		}

		// checking if the frog is inside the playground, otherwise move it to it's previous position
		if(checkOOB(frog.Position)) { frog.Position = glm::vec3(frog.prevPosition.x, frog.Position.y, frog.prevPosition.z); }
		frog.draw(texture.id[0], glm::vec4(1.0f, 0.72f, 0.54f, 1.0f));

		frogBot.draw(texture.id[0], glm::vec4(1.0f, 0.72f, 0.54f, 1.0f));

		// frogBot movement pattern
		// ------------------------
		frogBot.Yaw += 1.0f;
		frogBot.updateRotation();
		if (frogBot.Yaw == 360.0f) { frogBot.Yaw = 0.0f; }
		if (frogBot.Yaw == 0.0f || frogBot.Yaw == 180.0f) { frogBot.jump(); }


		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources
	// -----------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// processing input every frame (long press)
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (freeMode) 	{ freecam.ProcessKeyboard(FORWARD, deltaTime); }
		else 
		{
			glm::vec3 newPos = frog.Position + frog.Direction * deltaTime;
			frog.Position = newPos;
			frog.camera.updateCameraVectors(frog.Position, frog.Direction);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (freeMode)	{ freecam.ProcessKeyboard(BACKWARD, deltaTime); }
		else 
		{
			glm::vec3 newPos = frog.Position - frog.Direction * deltaTime;
			frog.Position = newPos;
			frog.camera.updateCameraVectors(frog.Position, frog.Direction);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		if (freeMode)	{ freecam.ProcessKeyboard(LEFT, deltaTime); }
		else 			{ frog.Yaw += 1.0f; }
		frog.updateRotation();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		if (freeMode)	{ freecam.ProcessKeyboard(RIGHT, deltaTime); }
		else 			{ frog.Yaw -= 1.0f; }
		frog.updateRotation();
	}
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions
	glViewport(0, 0, width, height);
}

// processing unique input (simple press)
// --------------------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_N && action == GLFW_PRESS)
	{
		freeMode = !freeMode;
		if (freeMode) 	{ currentCamera = &freecam; }
		else 			{ currentCamera = &frog.camera; }
	}
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		if (!frog.jumping) frog.jump();
	}
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if(firstMouse) // initially set to true
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
	lastX = xpos;
	lastY = ypos;

	freecam.ProcessMouseMovement(xoffset, yoffset);
}


// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	freecam.ProcessMouseScroll(yoffset);
}

bool checkOOB(glm::vec3 pos)
{
	if (pos.x+0.1f >= maxPlane || pos.x-0.1f <= minPlane) return true;
	if (pos.y < 0) return true;
	if (pos.z+0.1f >= maxPlane || pos.z-0.1f <= minPlane) return true;
	return false;
}