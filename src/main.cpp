#include <GL/glew.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <stdio.h>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

const char* windowTitle = "SVMonitor";

sf::Vector2f speedo[] = {
    {50, -120}, {50, -119}, {50, -119}, {50, -118}, {50, -118}, {50, -117},
    {50, -117}, {50, -116}, {50, -116}, {50, -115}, {50, -115}, {50, -114},
    {50, -114}, {50, -113}, {50, -113}, {50, -112}, {50, -112}, {50, -111},
    {50, -111}, {50, -110}, {50, -110}, {50, -109}, {50, -109}, {50, -108},
    {50, -108}, {50, -107}, {50, -107}, {50, -106}, {50, -106}, {50, -105},
    {50, -105}, {50, -104}, {50, -104}, {50, -103}, {50, -103}, {50, -102},
    {50, -102}, {50, -101}, {50, -101}, {50, -100}, {50, -100}, {50, -99},
    {50, -99}, {50, -98}, {50, -98}, {50, -97}, {50, -97}, {50, -96},
    {50, -96}, {50, -95}, {50, -95}, {50, -94}, {50, -94}, {50, -93},
    {50, -93}, {50, -92}, {50, -92}, {50, -91}, {50, -91}, {50, -90},
    {50, -90}, {50, -89}, {50, -89}, {50, -88}, {50, -88}, {50, -87},
    {50, -87}, {50, -86}, {50, -86}, {50, -85}, {50, -85}, {50, -84},
    {50, -84}, {50, -83}, {50, -83}, {50, -82}, {50, -82}, {50, -81},
    {50, -81}, {50, -80}, {50, -80}, {50, -79}, {50, -79}, {50, -78},
    {50, -78}, {50, -77}, {50, -77}, {50, -76}, {50, -76}, {50, -75},
    {50, -75}, {50, -74}, {50, -74}, {50, -73}, {50, -73}, {50, -72},
    {50, -72}, {50, -71}, {50, -71}, {50, -70}, {50, -70}, {50, -69},
    {50, -69}, {50, -68}, {50, -68}, {50, -67}, {50, -67}, {50, -66},
    {50, -66}, {50, -65}, {50, -65}, {50, -64}, {50, -64}, {50, -63},
    {50, -63}, {50, -62}, {50, -62}, {50, -61}, {50, -61}, {50, -60},
    {50, -60}, {50, -59}, {50, -59}, {50, -58}, {50, -58}, {50, -57},
    {50, -57}, {50, -56}, {50, -56}, {50, -55}, {50, -55}, {50, -54},
    {50, -54}, {50, -53}, {50, -53}, {50, -52}, {50, -52}, {50, -51},
    {50, -51}, {50, -50}, {50, -50}, {50, -49}, {50, -49}, {50, -48},
    {50, -48}, {50, -47}, {50, -47}, {50, -46}, {50, -46}, {50, -45},
    {50, -45}, {50, -44}, {50, -44}, {50, -43}, {50, -43}, {50, -42},
    {50, -42}, {50, -41}, {50, -41}, {50, -40}, {50, -40}, {50, -39},
    {50, -39}, {50, -38}, {50, -38}, {50, -37}, {50, -37}, {50, -36},
    {50, -36}, {50, -35}, {50, -35}, {50, -34}, {50, -34}, {50, -33},
    {50, -33}, {50, -32}, {50, -32}, {50, -31}, {50, -31}, {50, -30},
    {50, -30}, {50, -29}, {50, -29}, {50, -28}, {50, -28}, {50, -27},
    {50, -27}, {50, -26}, {50, -26}, {50, -25}, {50, -25}, {50, -24},
    {50, -24}, {50, -23}, {50, -23}, {50, -22}, {50, -22}, {50, -21},
    {50, -21}, {50, -20}, {50, -20}, {50, -19}, {50, -19}, {50, -18},
    {50, -18}, {50, -17}, {50, -17}, {50, -16}, {50, -16}, {50, -15},
    {50, -15}, {50, -14}, {50, -14}, {50, -13}, {50, -13}, {50, -12},
    {50, -12}, {50, -11}, {50, -11}, {50, -10}, {50, -10}, {50, -9},
    {50, -9}, {50, -8}, {50, -8}, {50, -7}, {50, -7}, {50, -6},
    {50, -6}, {50, -5}, {50, -5}, {50, -4}, {50, -4}, {50, -3},
    {50, -3}, {50, -2}, {50, -2}, {50, -1}, {50, -1}, {50, 0},
    {50, 0}, {50, 1}, {50, 1}, {50, 2}, {50, 2}, {50, 3},
    {50, 3}, {50, 4}, {50, 4}, {50, 5}, {50, 5}, {50, 6},
    {50, 6}, {50, 7}, {50, 7}, {50, 8}, {50, 8}, {50, 9},
    {50, 9}, {50, 10}, {50, 10}, {50, 11}, {50, 11}, {50, 12},
    {50, 12}, {50, 13}, {50, 13}, {50, 14}, {50, 14}, {50, 15},
    {50, 15}, {50, 16}, {50, 16}, {50, 17}, {50, 17}, {50, 18},
    {50, 18}, {50, 19}, {50, 19}, {50, 20}, {50, 20}, {50, 21},
    {50, 21}, {50, 22}, {50, 22}, {50, 23}, {50, 23}, {50, 24},
    {50, 24}, {50, 25}, {50, 25}, {50, 26}, {50, 26}, {50, 27},
    {50, 27}, {50, 28}, {50, 28}, {50, 29}, {50, 29}, {50, 30},
    {50, 30}, {50, 31}, {50, 31}, {50, 32}, {50, 32}, {50, 33},
    {50, 33}, {50, 34}, {50, 34}, {50, 35}, {50, 35}, {50, 36},
    {50, 36}, {50, 37}, {50, 37}, {50, 38}, {50, 38}, {50, 39},
    {50, 39}, {50, 40}, {50, 40}, {50, 41}, {50, 41}, {50, 42},
    {50, 42}, {50, 43}, {50, 43}, {50, 44}, {50, 44}, {50, 45},
    {50, 45}, {50, 46}, {50, 46}, {50, 47}, {50, 47}, {50, 48},
    {50, 48}, {50, 49}, {50, 49}, {50, 50}, {50, 50}, {50, 51},
    {50, 51}, {50, 52}, {50, 52}, {50, 53}, {50, 53}, {50, 54},
    {50, 54}, {50, 55}, {50, 55}, {50, 56}, {50, 56}, {50, 57},
    {50, 57}, {50, 58}, {50, 58}, {50, 59}, {50, 59}, {50, 60},
    {50, 60}, {50, 61}, {50, 61}, {50, 62}, {50, 62}, {50, 63},
    {50, 63}, {50, 64}, {50, 64}, {50, 65}, {50, 65}, {50, 66},
    {50, 66}, {50, 67}, {50, 67}, {50, 68}, {50, 68}, {50, 69},
    {50, 69}, {50, 70}, {50, 70}, {50, 71}, {50, 71}, {50, 72},
    {50, 72}, {50, 73}, {50, 73}, {50, 74}, {50, 74}, {50, 75},
    {50, 75}, {50, 76}, {50, 76}, {50, 77}, {50, 77}, {50, 78},
    {50, 78}, {50, 79}, {50, 79}, {50, 80}, {50, 80}, {50, 81},
    {50, 81}, {50, 82}, {50, 82}, {50, 83}, {50, 83}, {50, 84},
    {50, 84}, {50, 85}, {50, 85}, {50, 86}, {50, 86}, {50, 87},
    {50, 87}, {50, 88}, {50, 88}, {50, 89}, {50, 89}, {50, 90},
    {50, 90}, {50, 91}, {50, 91}, {50, 92}, {50, 92}, {50, 93},
    {50, 93}, {50, 94}, {50, 94}, {50, 95}, {50, 95}, {50, 96},
    {50, 96}, {50, 97}, {50, 97}, {50, 98}, {50, 98}, {50, 99},
    {50, 99}, {50, 100}, {50, 100}, {50, 101}, {50, 101}, {50, 102},
    {50, 102}, {50, 103}, {50, 103}, {50, 104}, {50, 104}, {50, 105},
    {50, 105}, {50, 106}, {50, 106}, {50, 107}, {50, 107}, {50, 108},
    {50, 108}, {50, 109}, {50, 109}, {50, 110}, {50, 110}, {50, 111},
    {50, 111}, {50, 112}, {50, 112}, {50, 113}, {50, 113}, {50, 114},
    {50, 114}, {50, 115}, {50, 115}, {50, 116}, {50, 116}, {50, 117},
    {50, 117}, {50, 118}, {50, 118}, {50, 119}, {50, 119}, {50, 120},

    {50, -120}, {60, -120}, {50, -110}, {60, -110}, {50, -100}, {60, -100},
    {50, -90}, {60, -90}, {50, -80}, {60, -80}, {50, -70}, {60, -70},
    {50, -60}, {60, -60}, {50, -50}, {60, -50}, {50, -40}, {60, -40},
    {50, -30}, {60, -30}, {50, -20}, {60, -20}, {50, -10}, {60, -10},
    {50, 0}, {60, 0}, {50, 10}, {60, 10}, {50, 20}, {60, 20},
    {50, 30}, {60, 30}, {50, 40}, {60, 40}, {50, 50}, {60, 50},
    {50, 60}, {60, 60}, {50, 70}, {60, 70}, {50, 80}, {60, 80},
    {50, 90}, {60, 90}, {50, 100}, {60, 100}, {50, 110}, {60, 110},
    {50, 120}, {60, 120},

    {0, 0}, {50, 0}
};

// Create a NULL-terminated string by reading the provided file
static char*
readShaderSource(const char* shaderFile)
{
    FILE* fp = fopen(shaderFile, "r");

    if ( fp == NULL ) { return NULL; }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    char* buf = new char[size + 1];
    fread(buf, 1, size, fp);

    buf[size] = '\0';
    fclose(fp);

    return buf;
}


// Create a GLSL program object from vertex and fragment shader files
GLuint
InitShader(const char* vShaderFile, const char* fShaderFile)
{
    struct Shader {
    const char*  filename;
    GLenum       type;
    GLchar*      source;
    }  shaders[2] = {
    { vShaderFile, GL_VERTEX_SHADER, NULL },
    { fShaderFile, GL_FRAGMENT_SHADER, NULL }
    };

    GLuint program = glCreateProgram();

    for ( int i = 0; i < 2; ++i ) {
    Shader& s = shaders[i];
    s.source = readShaderSource( s.filename );
    if ( shaders[i].source == NULL ) {
        std::cerr << "Failed to read " << s.filename << std::endl;
        exit( EXIT_FAILURE );
    }

    GLuint shader = glCreateShader( s.type );
    glShaderSource( shader, 1, (const GLchar**) &s.source, NULL );
    glCompileShader( shader );

    GLint  compiled;
    glGetShaderiv( shader, GL_COMPILE_STATUS, &compiled );
    if ( !compiled ) {
        std::cerr << s.filename << " failed to compile:" << std::endl;
        GLint  logSize;
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &logSize );
        char* logMsg = new char[logSize];
        glGetShaderInfoLog( shader, logSize, NULL, logMsg );
        std::cerr << logMsg << std::endl;
        delete [] logMsg;

        exit( EXIT_FAILURE );
    }

    delete [] s.source;

    glAttachShader( program, shader );
    }

    /* link  and error check */
    glLinkProgram(program);

    GLint  linked;
    glGetProgramiv( program, GL_LINK_STATUS, &linked );
    if ( !linked ) {
    std::cerr << "Shader program failed to link" << std::endl;
    GLint  logSize;
    glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logSize);
    char* logMsg = new char[logSize];
    glGetProgramInfoLog( program, logSize, NULL, logMsg );
    std::cerr << logMsg << std::endl;
    delete [] logMsg;

    exit( EXIT_FAILURE );
    }

    /* use program object */
    glUseProgram(program);

    return program;
}

GLuint sPos;
GLuint sRot;
GLuint color;
GLuint winSize;

void initBuffers()
{
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    glBufferData(GL_ARRAY_BUFFER, sizeof (speedo), speedo, GL_STATIC_DRAW);

    GLuint program = InitShader("./src/vertex.glsl", "./src/fragment.glsl");
    glUseProgram(program);

    GLuint vOff = glGetAttribLocation(program, "vOffset");
    glEnableVertexAttribArray(vOff);
    glVertexAttribPointer(vOff, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    sPos = glGetUniformLocation(program, "sPosition");
    glUniform2f(sPos, 0, 0);

    sRot = glGetUniformLocation(program, "sRot");
    glUniform1f(sRot, 0);

    color = glGetUniformLocation(program, "lineColor");
    glUniform3f(color, 1, 0.2, 0);

    winSize = glGetUniformLocation(program, "winSize");
    glUniform2f(winSize, 800, 600);
}

int main()
{
    sf::ContextSettings windowSettings(
        0, 0, 8, 3, 2, sf::ContextSettings::Core);
    sf::VideoMode defaultWinsize(800, 600);
    sf::Window window(
        defaultWinsize, windowTitle, sf::Style::Default, windowSettings);

    window.setFramerateLimit(60);
    window.setActive(true);

    glewInit();
    glClearColor(0, 0, 0, 1);
    glLineWidth(2);

    initBuffers();

    bool running = true;
    int ctr = -120;
    int direction = 1;
    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                glViewport(0, 0, event.size.width, event.size.height);
                glUniform2f(winSize, event.size.width, event.size.height);
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);

        size_t endP = (sizeof (speedo) / sizeof (speedo[0])) - 2;

        for (int x = 100; x < 1600; x += 200)
            for (int y = 100; y < 1200; y += 100)
            {
                glUniform2f(sPos, x, y);

                glUniform1f(sRot, 0.f);
                glUniform3f(color, 1, 1, 1);
                glDrawArrays(GL_LINES, 0, endP);

                glUniform1f(sRot, (float)ctr);
                glUniform3f(color, 1, 0.2, 0);
                glDrawArrays(GL_LINES, endP, 2);
            }

        window.display();

        ctr += direction;

        if (ctr == 120)
        {
            direction = -1;
        }
        else if (ctr == -120)
        {
            direction = 1;
        }

        glFinish();
    }

    return 0;
}
