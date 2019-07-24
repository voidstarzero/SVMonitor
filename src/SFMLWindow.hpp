#pragma once

#include <SFML/Window.hpp>
#include <GL/glew.h>

class SFMLWindow
{
public:
    SFMLWindow(unsigned pxWidth, unsigned pxHeight, const char* title, unsigned aaLevel = 8);

    void activate()
    {
        m_mainWindow.setActive(true);
    }

    bool pollEvent(sf::Event& event)
    {
        return m_mainWindow.pollEvent(event);
    }

    void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void display()
    {
        m_mainWindow.display();
        glFinish();
    }

    void clearColor(float r, float g, float b)
    {
        glClearColor(r, g, b, 1);
    }

    void lineWidth(float width)
    {
        glLineWidth(width);
    }

    void resizeContext(unsigned width, unsigned height)
    {
        glViewport(0, 0, (int)width, (int)height);
    }

    bool running()
    {
        return m_running;
    }

    void markStop()
    {
        m_running = false;
    }

    void close()
    {
        m_mainWindow.close();
    }

private:
    bool m_running;
    sf::Window m_mainWindow;
};