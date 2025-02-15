#include "Window.h"

#include <cassert>

Window::Window(WindowSpec& spec)
            : m_Spec{spec}
{
    assert(glfwInit() && "Failed to init glfw!");

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, spec.resizable);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    GLFWmonitor* monitor = nullptr;
    if(spec.fullscreen)
    {
        monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);

        spec.width = vidmode->width;
        spec.height = vidmode->height;

        m_Spec = spec;
    }

    m_Handle = glfwCreateWindow(spec.width, spec.height, spec.title.c_str(), monitor, nullptr);
    assert(m_Handle && "Failed to create the window!");
    glfwSetWindowUserPointer(m_Handle, this);
    glfwSetFramebufferSizeCallback(m_Handle, SizeCallback);

    glfwMakeContextCurrent(m_Handle);

    assert(gladLoadGLLoader((GLADloadproc) glfwGetProcAddress) && "Failed to load opengl functions!");
}

Window::~Window()
{
    glfwDestroyWindow(m_Handle);
    glfwTerminate();
}

void Window::Show()
{
    glfwShowWindow(m_Handle);
}

bool Window::IsOpen()
{
    return !glfwWindowShouldClose(m_Handle);
}

void Window::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Window::Update()
{
    glViewport(0, 0, m_Spec.width, m_Spec.height);

    glfwPollEvents();
    glfwSwapBuffers(m_Handle);
}

void Window::Close()
{
    glfwSetWindowShouldClose(m_Handle, true);
}

void Window::SizeCallback(GLFWwindow* window, int w, int h)
{
    Window* win = (Window*) glfwGetWindowUserPointer(window);
    
    win->m_Spec.width = w;
    win->m_Spec.height = h;
}