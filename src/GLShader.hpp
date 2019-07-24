#pragma once

#include <GL/glew.h>

GLuint createShaderProgram(const char* vertexFilename, const char* fragmentFilename);

class GLShader
{
public:
    explicit GLShader(GLuint shaderId) : m_shaderId{shaderId}
    {
        m_uWinSize = uniformLocation("windowSize");
    }

    static GLShader load(const char* vertexFilename, const char* fragmentFilename)
    {
        return GLShader(createShaderProgram(vertexFilename, fragmentFilename));
    }

    void use()
    {
        glUseProgram(m_shaderId);
    }

    void notifyResize(unsigned width, unsigned height)
    {
        glUniform2f(m_uWinSize, width, height);
    }

    GLuint attribLocation(const char* attribName)
    {
        return glGetAttribLocation(m_shaderId, attribName);
    }

    GLuint uniformLocation(const char* uniformName)
    {
        return glGetUniformLocation(m_shaderId, uniformName);
    }

private:
    GLuint m_shaderId;
    GLuint m_uWinSize;
};