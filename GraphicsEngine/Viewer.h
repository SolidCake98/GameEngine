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

namespace GraphicsEngine
{
    class Viewer
    {
    public:
        Viewer(int, int);
        ~Viewer();

        bool IsWindowClose();

        void Clear();
        void Draw();

        void AddObjectToPool(ViewObject*);

    private:
        GLFWwindow *window;

        std::vector<ViewObject *> *m_ObjectsVect;

        int m_Width;
        int m_Height;

        int InitOG();
    };
}
