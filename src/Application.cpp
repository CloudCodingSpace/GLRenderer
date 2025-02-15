#include "Application.h"

Application::Application()
{
    // Window
    {
        WindowSpec spec{};
        spec.title = "GLRenderer";
        spec.fullscreen = true;

        m_Window = std::make_shared<Window>(spec);
    }
}

Application::~Application()
{
}

void Application::Run()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    m_Window->Show();
    while(m_Window->IsOpen())
    {
        m_Window->Clear();

        Render();

        Update();
    }
}

void Application::Render()
{

}

void Application::Update()
{
    m_Window->Update();

    if(glfwGetKey(m_Window->GetHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        m_Window->Close();
}