//
// Created by danil on 04.05.2020.
//

#include "FakeWindow.h"
#include "InputSystem/InputSystem.h"
#include "InputSystem/Input.h"

void FakeWindow::KeyDown()
{
    if (Input::GetKeyDown(KEY_W))
    {
        std::cout << "up is pressed" << std::endl;
    }
    if (Input::GetKeyDown(KEY_S))
    {
        std::cout << "down is pressed" << std::endl;
    }
    if (Input::GetKeyDown(KEY_A))
    {
        std::cout << "left is pressed" << std::endl;
    }
    if (Input::GetKeyDown(KEY_D))
    {
        std::cout << "right is pressed" << std::endl;
    }
}

void FakeWindow::KeyUp()
{
    if (Input::GetKeyUp(KEY_W))
    {
        std::cout << "up is unpressed" << std::endl;
    }
    if (Input::GetKeyUp(KEY_S))
    {
        std::cout << "down is unpressed" << std::endl;
    }
    if (Input::GetKeyUp(KEY_A))
    {
        std::cout << "left is unpressed" << std::endl;
    }
    if (Input::GetKeyUp(KEY_D))
    {
        std::cout << "right is unpressed" << std::endl;
    }
}

void FakeWindow::OnCreate()
{

}

void FakeWindow::OnUpdate()
{
    InputSystem::get()->Update();
    KeyDown();
    KeyUp();
}
