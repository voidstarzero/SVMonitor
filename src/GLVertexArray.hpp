#pragma once

#include <GL/glew.h>

class GLVertexArray
{
public:
    GLVertexArray(GLuint attrib, GLsizeiptr size, const GLvoid* data);

    void fill(GLuint attrib, GLsizeiptr size, const GLvoid* data);

    void bind()
    {
        glBindVertexArray(m_vaoId);
    }

    void draw(GLenum mode, GLint first, GLsizei count)
    {
        glDrawArrays(mode, first, count);
    }

private:
    GLuint m_vaoId;
    GLuint m_vboId;
};