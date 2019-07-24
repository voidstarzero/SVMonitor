#include "./GLShader.hpp"
#include "./GLVertexArray.hpp"
#include "./SFMLWindow.hpp"
#include "./Shapes.hpp"
#include "./Util.hpp"

#include <GL/glew.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <stdio.h>

const char* windowTitle = "SVMonitor";

GLuint sScale;
GLuint sLoc;
GLuint sRot;
GLuint color;

void getInitProgramUniforms(GLShader& program)
{
    sScale = program.uniformLocation("shapeScale");
    glUniform2f(sScale, 1, 1);

    sLoc = program.uniformLocation("shapeLocation");
    glUniform2f(sLoc, 400, 300);

    sRot = program.uniformLocation("shapeRotation");
    glUniform1f(sRot, 0);

    color = program.uniformLocation("lineColor");
    glUniform3f(color, 1, 1, 1);
}

int main()
{
    SFMLWindow window(800, 600, windowTitle);
    window.activate();

    window.clearColor(0, 0, 0);
    window.lineWidth(2);

    GLShader program = GLShader::load(
        "./res/shaders/vertex.glsl",
        "./res/shaders/fragment.glsl");
    window.useProgram(program);

    getInitProgramUniforms(program);

    GLVertexArray vaMarks(
        program.attribLocation("vertexPosition"),
        c_array_totsz(dialMarks), dialMarks);

    GLVertexArray vaCircle(
        program.attribLocation("vertexPosition"),
        c_array_totsz(ttCircle), ttCircle);

    while (window.running())
    {
        // Do pre-frame updates
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.markStop();
            }
            else if (event.type == sf::Event::Resized)
            {
                window.resizeContext(event.size.width, event.size.height);
                program.notifyResize(event.size.width, event.size.height);
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape
                    || event.key.code == sf::Keyboard::Q)
                {
                    window.markStop();
                }
            }
        }

        window.clear();

        // Do rendering here
        vaCircle.bind();
        vaCircle.draw(GL_LINES, 0, c_array_nelems(ttCircle));
        vaMarks.bind();
        vaMarks.draw(GL_LINES, 0, c_array_nelems(dialMarks));

        window.display();

        // Do post-frame updates
    }

    window.close();

    return 0;
}
