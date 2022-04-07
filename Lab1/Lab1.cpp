#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm/vec3.hpp"
using namespace std;

GLuint VBO;

void RenderSceneCB() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 03");

    glutDisplayFunc(RenderSceneCB);

    glm::vec3 Vertices[4];
    Vertices[0] = glm::vec3(0.0f, -0.5f, 0.0f);
    Vertices[1] = glm::vec3(0.5f, -0.5f, 0.0f);
    Vertices[2] = glm::vec3(0.0f, 0.0f, 0.0f);
    Vertices[3] = glm::vec3(0.5f, 0.0f, 0.0f);

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glutMainLoop();

    glutMainLoop();



    return 0;
}