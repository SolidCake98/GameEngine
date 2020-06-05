#include "Viewer.h"

namespace GraphicsEngine
{
    Viewer::Viewer(int _width, int _height)
    {
        m_ObjectsVect = new std::vector<ViewObject *>();

        m_Width = _width;
        m_Height = _height;

        InitOG();
    }

    int Viewer::InitOG()
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
        glfwWindowHint(GLFW_RESIZABLE , GL_FALSE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(m_Width, m_Height, "Window", NULL, NULL);
        if (window == NULL)
        {
            fprintf(stderr,
                    "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version.\n");
            getchar();
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);

        glewExperimental = true;
        if (glewInit() != GLEW_OK)
        {
            fprintf(stderr, "Failed to initialize GLEW\n");
            getchar();
            glfwTerminate();
            return -1;
        }

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        return 0;
    }

    void Viewer::AddObjectToPool(ViewObject* _vo)
    {
        m_ObjectsVect->push_back(_vo);
    }

    Viewer::~Viewer()
    {
        m_ObjectsVect->clear();
        delete m_ObjectsVect;
        glfwTerminate();
    }

    void Viewer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Viewer::Draw()
    {
        for (auto obj : *m_ObjectsVect)
        {
            obj->setScreenPosition(m_Width, m_Height);
            obj->draw();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    bool Viewer::IsWindowClose()
    {
        return glfwWindowShouldClose(window);
    }
}