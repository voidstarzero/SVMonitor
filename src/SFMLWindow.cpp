#include "./SFMLWindow.hpp"

SFMLWindow::SFMLWindow(unsigned pxWidth, unsigned pxHeight, const char* title, unsigned aaLevel)
{
    sf::ContextSettings windowSettings(
        0, // Depth buffer size, unneeded for this type of 2D drawing
        0, // Stencil buffer size, similarly
        aaLevel, // Selected antialiasing level
        3, 2, sf::ContextSettings::Core); // Selected OpenGL version (major, minor, profile)
    sf::VideoMode windowSize(pxWidth, pxHeight);

    m_mainWindow.create(windowSize, title, sf::Style::None, windowSettings);
    m_mainWindow.setFramerateLimit(60);

    glewInit();
}