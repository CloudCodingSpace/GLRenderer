#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<Window> window)
{
    m_Window = window;
}

Renderer::~Renderer()
{

}

void Renderer::Render()
{
    m_LastTime = (float)glfwGetTime();
}

void Renderer::Update()
{
    float crntTime = (float)glfwGetTime();
    m_Delta = crntTime - m_LastTime;
}