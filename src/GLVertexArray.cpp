#include "./GLVertexArray.hpp"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

GLVertexArray::GLVertexArray(GLuint attrib, GLsizeiptr size, const GLvoid* data)
{
    glGenVertexArrays(1, &m_vaoId);
    glBindVertexArray(m_vaoId);

    glGenBuffers(1, &m_vboId);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);

    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(attrib);
    glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}

void GLVertexArray::fill(GLuint attrib, GLsizeiptr size, const GLvoid* data)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(attrib);
    glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}