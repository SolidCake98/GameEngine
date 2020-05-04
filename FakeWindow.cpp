//
// Created by danil on 04.05.2020.
//

#include "FakeWindow.h"
#include "InputSystem/InputSystem.h"

void FakeWindow::OnKeyDown(int key)
{
    if (key == KEY_W)
    {
        std::cout << "up is pressed" << std::endl;
    }
    if (key == KEY_S)
    {
        std::cout << "down is pressed" << std::endl;
    }
    if (key == KEY_A)
    {
        std::cout << "left is pressed" << std::endl;
    }
    if (key == KEY_D)
    {
        std::cout << "right is pressed" << std::endl;
    }
}

void FakeWindow::OnKeyUp(int key)
{
    if (key == KEY_W)
    {
        std::cout << "up is unpressed" << std::endl;
    }
    if (key == KEY_S)
    {
        std::cout << "down is unpressed" << std::endl;
    }
    if (key == KEY_A)
    {
        std::cout << "left is unpressed" << std::endl;
    }
    if (key == KEY_D)
    {
        std::cout << "right is unpressed" << std::endl;
    }
}

void FakeWindow::OnCreate()
{
    InputSystem::get()->AddListener(this);
}

void FakeWindow::OnUpdate()
{
    InputSystem::get()->Update();
}
