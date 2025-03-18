#pragma once

#include "Camera.h"
#include "Shader.h"

#include "Window/Window.h"

#include <memory>

class Renderer
{
public:
    Renderer(std::shared_ptr<Window> window);
    ~Renderer();

    void Render();
    void Update();

private:
    std::shared_ptr<Window> m_Window;
    float m_Delta, m_LastTime;
};