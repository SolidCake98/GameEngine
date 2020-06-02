cmake_minimum_required(VERSION 3.15)
project(GameEngine)

include_directories(GraphicsEngine/Includes/glm)
include_directories(GraphicsEngine/Includes/glm/detail)
include_directories(GraphicsEngine/Includes/glm/ext)
include_directories(GraphicsEngine/Includes/glm/gtc)
include_directories(GraphicsEngine/Includes/glm/gtx)
include_directories(GraphicsEngine/Includes/glm/simd)

set(SOURCE_FILES
        main.cpp
        InputSystem/InputListener.h
        InputSystem/InputSystem.h
        InputSystem/InputSystem.cpp
        InputSystem/CKeyboard.h
        InputSystem/CKeyboard.cpp
        CTimer/CTimer.h
        CTimer/CTimer.cpp
        FakeWindow.cpp
        FakeWindow.h
        PhysicsEngine/Shapes/Point.h
        PhysicsEngine/Shapes/Point.cpp
        PhysicsEngine/Shapes/Vertex.h
        PhysicsEngine/Shapes/Vertex.cpp
        PhysicsEngine/Shapes/Shape.h
        PhysicsEngine/Shapes/Circle.h
        PhysicsEngine/Shapes/Circle.cpp
        PhysicsEngine/Shapes/Polygon.h
        PhysicsEngine/Shapes/Polygon.cpp
        PhysicsEngine/Shapes/PolygonIterator.h
        PhysicsEngine/Shapes/PolygonIterator.cpp
        PhysicsEngine/Shapes/ConvexPolygon.h
        PhysicsEngine/Shapes/ConvexPolygon.cpp
        PhysicsEngine/Shapes/ShapeFactory.h
        PhysicsEngine/Shapes/ShapeFactory.cpp
        PhysicsEngine/Rigidbody.h
        PhysicsEngine/Rigidbody.cpp
        PhysicsEngine/Mathematics.h
        PhysicsEngine/Mathematics.cpp
        PhysicsEngine/Physics.h
        PhysicsEngine/Physics.cpp
        PhysicsEngine/BodyPair.h
        PhysicsEngine/BodyPair.cpp
        PhysicsEngine/PhysicsEngine.h
        PhysicsEngine/PhysicsEngine.cpp
        EngineCore/Components/ComponentBase.h
        EngineCore/Components/PositionComponent.cpp
        EngineCore/Components/PositionComponent.h
        EngineCore/Components/VelocityComponent.cpp
        EngineCore/Components/VelocityComponent.h
        EngineCore/Components/BodyComponent.cpp
        EngineCore/Components/BodyComponent.h
        EngineCore/Shapes/Shape.h
        EngineCore/Shapes/Polygon.cpp
        EngineCore/Shapes/Polygon.h
        EngineCore/Shapes/Point.h
        EngineCore/Shapes/Point.cpp
        EngineCore/Shapes/Circle.cpp
        EngineCore/Shapes/Circle.h
        EngineCore/Components/ShapeComponent.cpp
        EngineCore/Components/ShapeComponent.h
        EngineCore/Nodes/PhysicsNode.cpp
        EngineCore/Nodes/PhysicsNode.h
        EngineCore/Nodes/NodeBase.h
        EngineCore/Entity.cpp
        EngineCore/Entity.h
        EngineCore/Systems/SystemBase.h
        EngineCore/Systems/PhysicsSystem.cpp
        EngineCore/Systems/PhysicsSystem.h
        InputSystem/Input.h
        InputSystem/Input.cpp
        EngineCore/Core.cpp
        EngineCore/Core.h
        GraphicsEngine/Circle.cpp
        GraphicsEngine/Circle.h
        GraphicsEngine/IndexBuffer.cpp
        GraphicsEngine/IndexBuffer.h
        GraphicsEngine/Point.h
        GraphicsEngine/Rectangle.cpp
        GraphicsEngine/Rectangle.h
        GraphicsEngine/Renderer.cpp
        GraphicsEngine/Renderer.h
        GraphicsEngine/Shader.cpp
        GraphicsEngine/Shader.h
        GraphicsEngine/Triangle.cpp
        GraphicsEngine/Triangle.h
        GraphicsEngine/Types.h
        GraphicsEngine/VertexArray.cpp
        GraphicsEngine/VertexArray.h
        GraphicsEngine/VertexBuffer.cpp
        GraphicsEngine/VertexBuffer.h
        GraphicsEngine/VertexBufferLayout.h
        GraphicsEngine/Viewer.cpp
        GraphicsEngine/Viewer.h
        GraphicsEngine/ViewObject.cpp
        GraphicsEngine/ViewObject.h
        EngineCore/Nodes/GraphicsNode.cpp
        EngineCore/Nodes/GraphicsNode.h
        EngineCore/Systems/GraphicsSystem.cpp
        EngineCore/Systems/GraphicsSystem.h EngineCore/Systems/TestSystem.cpp EngineCore/Systems/TestSystem.h EngineCore/Nodes/TestNode.cpp EngineCore/Nodes/TestNode.h EngineCore/Systems/ControlSystem.cpp EngineCore/Systems/ControlSystem.h EngineCore/Components/VelocityChangeComponent.cpp EngineCore/Components/VelocityChangeComponent.h EngineCore/Nodes/ControlNode.cpp EngineCore/Nodes/ControlNode.h EngineCore/Components/TranslateComponent.cpp EngineCore/Components/TranslateComponent.h EngineCore/Components/DemoComponent.cpp EngineCore/Components/DemoComponent.h EngineCore/Nodes/DemoNode.cpp EngineCore/Nodes/DemoNode.h EngineCore/Systems/DemoSystem.cpp EngineCore/Systems/DemoSystem.h)
        
add_executable(GameEngine ${SOURCE_FILES})

set(_glm_HEADER_SEARCH_DIRS
        "/GraphicsEngine/Includes/glm")

FIND_PATH(GLM_INCLUDE_DIR "glm/glm.hpp"
        PATHS ${_glm_HEADER_SEARCH_DIRS})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLM DEFAULT_MSG
        GLM_INCLUDE_DIR)

IF(GLM_FOUND)
    SET(GLM_INCLUDE_DIRS "${GLM_INCLUDE_DIR}")

    MESSAGE(STATUS "GLM_INCLUDE_DIR = ${GLM_INCLUDE_DIR}")
ENDIF(GLM_FOUND)


find_package(OpenGL REQUIRED)

if (OPENGL_FOUND)
    message("opengl found")
    message("include dir: ${OPENGL_INCLUDE_DIR}")
    message("link libraries: ${OPENGL_LIBRARY}")
else (OPENGL_FOUND)
    message("opengl not found")
endif()


find_package(glfw3 3.2 REQUIRED)

target_link_libraries(GameEngine ${OPENGL_LIBRARY} GLEW glfw pthread)
