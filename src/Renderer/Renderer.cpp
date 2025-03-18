#include "Renderer.h"

#include "GuiHelper.h"

#include <imgui/imgui.h>

Renderer::Renderer(std::shared_ptr<Window> window)
{
    m_Window = window;

    m_Fb.Init(m_Window->GetWindowInfo().width, m_Window->GetWindowInfo().height);

    GuiHelper::Init(*m_Window);
}

Renderer::~Renderer()
{
    GuiHelper::Shutdown();

    m_Fb.Destroy();
}

void Renderer::Render()
{
    GuiHelper::StartFrame();

    ImGui::Begin("Scene");

    m_Fb.Resize(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);
    m_Fb.Bind();
    glViewport(0, 0, ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);
    
    // Main Rendering
    {
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    }
    
    m_Fb.Unbind();
    
    ImGui::Image(reinterpret_cast<ImTextureID>(static_cast<uintptr_t>(m_Fb.GetColorAttachment().GetHandle())), 
                        ImVec2(m_Fb.GetColorAttachment().GetWidth(), m_Fb.GetColorAttachment().GetHeight()), 
                        ImVec2(0, 1), ImVec2(1, 0));

    ImGui::End();

    ImGui::Begin("Stats");

    ImGui::Text("Delta Time :- %0.2fms", m_Delta * 1000);
    ImGui::Text("%.0f FPS", 1/m_Delta);

    ImGui::End();

    GuiHelper::EndFrame();

    glViewport(0, 0, m_Window->GetWindowInfo().width, m_Window->GetWindowInfo().height);
    GuiHelper::Update(*m_Window);
}

void Renderer::Update()
{
    float crntTime = (float)glfwGetTime();
    m_Delta = crntTime - m_LastTime;
    m_LastTime = crntTime;
}