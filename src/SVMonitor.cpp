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
    glUniform2f(sScale, 8, 1);

    sLoc = program.uniformLocation("shapeLocation");
    glUniform2f(sLoc, 400, 350);

    sRot = program.uniformLocation("shapeRotation");
    glUniform1f(sRot, -120);
}

float clamp(float val, float min, float max)
{
    if (val < min) return min;
    else if (val > max) return max;
    return val;
}

int main()
{
    SFMLWindow window(800, 600, windowTitle);
    window.activate();

    window.clearColor(0, 0, 0);
    window.lineWidth(3);

    GLShader program = GLShader::load(
        "./res/shaders/polar_shape.vert",
        "./res/shaders/single_opaque.frag");
    window.useProgram(program);

    program.lineColor(1, 1, 1);

    getInitProgramUniforms(program);

    GLuint vPosAttr = program.attribLocation("vertexPosition");

    GLVertexArray vaNeedle(vPosAttr, c_array_totsz(needle), needle);
    GLVertexArray vaSmallSpurs(vPosAttr, c_array_totsz(smallSpurs), smallSpurs);
    GLVertexArray vaSpurs(vPosAttr, c_array_totsz(circleSpurs), circleSpurs);
    GLVertexArray vaCircle(vPosAttr, c_array_totsz(circle), circle);

    float vel = 0;
    float pos = 120;
    int eventDown = (sf::Mouse::isButtonPressed(sf::Mouse::Left) ? 1 : 0)
                     + (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ? 1 : 0);
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
                else if (event.key.code == sf::Keyboard::Space)
                {
                    eventDown += 1;
                }
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    eventDown -= 1;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    eventDown += 1;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    eventDown -= 1;
            }
        }

        // Post-event updates
        vel += (eventDown ? 0.1 : -0.12);
        vel = clamp(vel, -4, 4);
        pos += vel;
        pos = clamp(pos, -120, 120);
        if (pos == -120 || pos == 120) vel = 0;

        window.clear();
        program.lineColor(1, 1, 1);

        // Do rendering here
        vaCircle.bind();
        vaCircle.draw(GL_LINES, 0, 240 * 2);

        vaSmallSpurs.bind();
        vaSmallSpurs.draw(GL_LINES, 0, (48 + 1) * 2);
        vaSpurs.bind();
        vaSpurs.draw(GL_LINES, 0, (24 + 1) * 2);

        glUniform1f(sRot, pos);
        vaNeedle.bind();
        program.lineColor(1, 0.2, 0);
        vaNeedle.draw(GL_TRIANGLES, 0, 9);
        glUniform1f(sRot, -120);

        window.display();
    }

    window.close();

    return 0;
}
