#include "Viewer.h"


Viewer::Viewer(int width, int height)
{
	m_ObjectsVect = new std::vector<ViewObject*>();

	m_Width = width;
	m_Height = height;

	counter = 0;

	initOG(width, height);
}

int Viewer::initOG(int width, int height)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(m_Width, m_Height, "Window", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version.\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glViewport(0.0f, 0.0f, m_Width, m_Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, m_Width, 0, m_Height, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return 0;
}

void Viewer::gameCycle()
{	
	do 
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		for (auto obj : *m_ObjectsVect)
		{
			obj->draw();
		}
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);


	glfwTerminate();
}

void Viewer::run()
{
	gameCycle();
}

std::vector<ViewObject*>* Viewer::getAllObjects()
{
	return m_ObjectsVect;
}

ViewObject* Viewer::getObjectByID(int _id)
{
	for (int i = 0; i < m_ObjectsVect->size(); i++)
	{
		if (m_ObjectsVect->at(i)->getID() == _id)
			return m_ObjectsVect->at(i);
	}

	return nullptr;
}

int Viewer::generateId()
{
	return counter++;
}

int Viewer::addCircleToPool(Point pos, float radius)
{
	ViewObject* circle = new Circle(pos.x, pos.y, 0, radius);
	int id = generateId();
	circle->setID(id);
	m_ObjectsVect->push_back(circle);

	return id;
}

int Viewer::addRectToPool(Point pos, GLfloat vert[])
{
	ViewObject* rect = new Rectangle(pos.x, pos.y, vert);
	int id = generateId();
	rect->setID(id);
	m_ObjectsVect->push_back(rect);

	return id;
}

int Viewer::addTriangleToPool(Point pos, GLfloat vert[])
{
	ViewObject* triang = new Triangle(pos.x, pos.y, vert);
	int id = generateId();
	triang->setID(id);
	m_ObjectsVect->push_back(triang);

	return id;
}