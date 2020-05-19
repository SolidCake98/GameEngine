cmake_minimum_required(VERSION 3.15)
project(GameEngine)

set(SOURCE_FILES main.cpp InputSystem/InputListener.h InputSystem/InputSystem.h InputSystem/InputSystem.cpp InputSystem/CKeyboard.h InputSystem/CKeyboard.cpp CTimer/CTimer.h CTimer/CTimer.cpp FakeWindow.cpp FakeWindow.h PhysicsEngine/Shapes/Point.h PhysicsEngine/Shapes/Point.cpp PhysicsEngine/Shapes/Vertex.h PhysicsEngine/Shapes/Vertex.cpp PhysicsEngine/Shapes/Shape.h PhysicsEngine/Shapes/Circle.h PhysicsEngine/Shapes/Circle.cpp PhysicsEngine/Shapes/Polygon.h PhysicsEngine/Shapes/Polygon.cpp PhysicsEngine/Shapes/PolygonIterator.h PhysicsEngine/Shapes/PolygonIterator.cpp PhysicsEngine/Shapes/ConvexPolygon.h PhysicsEngine/Shapes/ConvexPolygon.cpp PhysicsEngine/Shapes/ShapeFactory.h PhysicsEngine/Shapes/ShapeFactory.cpp PhysicsEngine/Rigidbody.h PhysicsEngine/Rigidbody.cpp PhysicsEngine/Mathematics.h PhysicsEngine/Mathematics.cpp PhysicsEngine/Physics.h PhysicsEngine/Physics.cpp PhysicsEngine/BodyPair.h PhysicsEngine/BodyPair.cpp PhysicsEngine/PhysicsEngine.h PhysicsEngine/PhysicsEngine.cpp EngineCore/Components/ComponentBase.h EngineCore/Components/PositionComponent.cpp EngineCore/Components/PositionComponent.h EngineCore/Components/VelocityComponent.cpp EngineCore/Components/VelocityComponent.h EngineCore/Components/BodyComponent.cpp EngineCore/Components/BodyComponent.h EngineCore/Shapes/Shape.h EngineCore/Shapes/Polygon.cpp EngineCore/Shapes/Polygon.h EngineCore/Shapes/Point.h EngineCore/Shapes/Point.cpp EngineCore/Shapes/Circle.cpp EngineCore/Shapes/Circle.h EngineCore/Components/ShapeComponent.cpp EngineCore/Components/ShapeComponent.h EngineCore/Nodes/PhysicsNode.cpp EngineCore/Nodes/PhysicsNode.h EngineCore/Nodes/NodeBase.h EngineCore/Entity.cpp EngineCore/Entity.h InputSystem/Input.cpp InputSystem/Input.h)
add_executable(GameEngine ${SOURCE_FILES})

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