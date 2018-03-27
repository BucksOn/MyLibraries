#include "stdafx.h"

bool CGraphicsManager::initWindow()
{
	if (!initGLFW()) return false;

	windowSetting();

	if (!createWindow()) return false;
	
	if (!initGLEW()) return false;

	glClearColor(1, 1, 1, 1);			 //!< while background
	glfwSetInputMode(_Window, GLFW_STICKY_KEYS, GL_TRUE); //!< Set Keyboard Input

	return true;
}

void CGraphicsManager::LoopWindow()
{
	_fTime = (float)timeGetTime();

	while (!glfwWindowShouldClose(_Window))
	{
		float currTime = (float)timeGetTime();
		int	nFrame = 1000 / __D_FRAME_MAX__ - (currTime - _fTime);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glMatrixMode(GL_MODELVIEW);

		//!< Fixed Frame 
		if (nFrame > 0)
			_cManager.Update();

		_cManager.Render();

		glfwSwapBuffers(_Window);
		glfwPollEvents();

		_fTime = currTime;
	}
}

void CGraphicsManager::EndWIndow()
{
	_cManager.Exit();
	glfwTerminate();
}

bool CGraphicsManager::initGLFW()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return false;
	}

	return true;
}

void CGraphicsManager::windowSetting()
{
	glfwWindowHint(GLFW_SAMPLES, 4); //!< Anti-aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //!< GL Version Setting _ max
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //!< GL Version Setting _ min
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


bool CGraphicsManager::createWindow()
{
	_Window = glfwCreateWindow(__D_SCREEN_WIDTH__, __D_SCREEN_HEIGHT__, "GAME", NULL, NULL);
	if (_Window == NULL) {
		fprintf(stderr, "Do not Open GL Window\n");
		getchar();
		glfwTerminate();
		return false;
	}
	return true;
}

bool CGraphicsManager::initGLEW()
{
	glfwMakeContextCurrent(_Window); //!< Initialize GLEW
	glewExperimental = true; //!< Needed for core profile / CPU & GPU 
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return false;
	}

	return true;
}