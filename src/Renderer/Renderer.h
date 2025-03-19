#pragma once

#include "Camera.h"
#include "Mesh.h"
#include "Shader.h"
#include "Framebuffer.h"

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
    Framebuffer m_Fb;
    Camera m_Camera;
    Shader m_Shader;
    Mesh m_Mesh;
};