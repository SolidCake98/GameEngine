#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <mutex>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <vector>

#include "ViewObject.h"

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include "Point.h"

#include "Types.h"

namespace GraphicsEngine {
    class Viewer {
    private:
        int counter;

        GLFWwindow *window;

        std::vector<ViewObject *> *m_ObjectsVect;

        int m_Width;
        int m_Height;

        int initOG(int, int);
    public:
        Viewer(int, int);
        ~Viewer();

        std::vector<ViewObject *> *getAllObjects();

        ViewObject *getObjectByID(int);

        void clear();

        void draw();

        int generateId();

        void addObjectToPool(ViewObject*);

        int addCircleToPool(Point, float);

        int addRectToPool(Point, GLfloat[]);

        int addTriangleToPool(Point, GLfloat[]);
    };
}
