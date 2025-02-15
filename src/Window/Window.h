#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

struct WindowSpec
{
    int32_t width = 800, height = 600;
    bool resizable = true, fullscreen = false;
    std::string title;
};

class Window
{
public:
    Window(WindowSpec& spec);
    ~Window();

    void Show();
    bool IsOpen();
    void Clear();
    void Update();

    void Close();

    inline const WindowSpec& GetSpec() const { return m_Spec; }
    inline GLFWwindow* GetHandle() const { return m_Handle; }
private:
    WindowSpec m_Spec{};
    GLFWwindow* m_Handle = nullptr;

    static void SizeCallback(GLFWwindow* window, int w, int h);
};