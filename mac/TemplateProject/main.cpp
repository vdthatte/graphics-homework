
#include <GLUT/glut.h>
#include "glsupport.h"

GLuint program;
GLuint vertPositionVBO;
GLuint positionAttribute;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(program);
    glBindBuffer(GL_ARRAY_BUFFER, vertPositionVBO);
    glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(positionAttribute);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(positionAttribute);
    
    glutSwapBuffers();
}

void init() {
    program = glCreateProgram();
    readAndCompileShader(program, "/Users/Vidyadhar/Desktop/Github/graphics-homework/mac/TemplateProject/vertext.glsl", "/Users/Vidyadhar/Desktop/Github/graphics-homework/mac/TemplateProject/fragment.glsl");
    
    glUseProgram(program);
    positionAttribute = glGetAttribLocation(program, "position");
    
    glGenBuffers(1, &vertPositionVBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertPositionVBO);
    GLfloat sqVerts[12] = {
        -0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f,
        0.5f, 0.5f
    };
    glBufferData(GL_ARRAY_BUFFER, 12*sizeof(GLfloat), sqVerts, GL_STATIC_DRAW);
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

void idle(void) {
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("CS-6533");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    
    init();
    glutMainLoop();
    return 0;
}
