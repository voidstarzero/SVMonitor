#include "./GLShader.hpp"

#include <cstdlib>
#include <iostream>

// Create a NULL-terminated string by reading the provided file
static char* readShaderSource(const char* shaderFile)
{
    FILE* fp = fopen(shaderFile, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    char* buf = new char[size + 1];
    fread(buf, 1, size, fp);

    buf[size] = '\0';
    fclose(fp);

    return buf;
}

static GLuint compileShaderPart(const char* filename, GLenum type)
{
    GLchar* source = readShaderSource(filename);
    if (!source)
    {
        std::cerr << "Failed to read " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, (const GLchar**)&source, NULL);
    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        std::cerr << filename << " failed to compile:" << std::endl;

        GLint logSize;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
        char* logMsg = new char[logSize];
        glGetShaderInfoLog(shader, logSize, NULL, logMsg);
        std::cerr << logMsg << std::endl;
        delete[] logMsg;

        exit(EXIT_FAILURE);
    }

    delete[] source;
    return shader;
}

// Create a GLSL program object from vertex and fragment shader files
GLuint createShaderProgram(const char* vertexFilename, const char* fragmentFilename)
{
    GLuint program = glCreateProgram();

    GLuint vertexShader = compileShaderPart(vertexFilename, GL_VERTEX_SHADER);
    glAttachShader(program, vertexShader);

    GLuint fragmentShader = compileShaderPart(fragmentFilename, GL_FRAGMENT_SHADER);
    glAttachShader(program, fragmentShader);

    // link and error check
    glLinkProgram(program);

    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked)
    {
        std::cerr << "Shader program failed to link" << std::endl;
        GLint logSize;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
        char* logMsg = new char[logSize];
        glGetProgramInfoLog(program, logSize, NULL, logMsg);
        std::cerr << logMsg << std::endl;
        delete [] logMsg;

        exit(EXIT_FAILURE);
    }

    return program;
}