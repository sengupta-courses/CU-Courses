# scenev2.py
# Scene in 3D
# CSCI 4229 - Homework 2
# Created by Pourna Sengupta

# This scene renders a holographic flamingo
# (or what I hoped would look close to a flamingo)

# OpenGL Imports
from OpenGL.GL import *
from OpenGL.GLUT import *


def init():
    glClearColor(0.75, 0.35, 0.50, 1.0)
    glColor3f(1.0, 1.0, 1.0)

    glEnable(GL_CULL_FACE)
    glCullFace(GL_BACK)

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glFrustum(-2, 2, -1.5, 1.5, 1, 40)

    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    # gluPerspective(30, float(width)/height, 1, 1000)
    glTranslate(0, 0, -3)
    glRotatef(50, 1, 0, 0)
    glRotatef(70, 0, 1, 0)


def tri():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glColor3f(1.0, 1.0, 1.0)

    glBegin(GL_LINES)
    i = -2.5
    GLfloat(i)
    while i <= 2.5:
        glVertex3f(i, 0, 2.5)
        glVertex3f(i, 0, -2.5)
        glVertex3f(2.5, 0, i)
        glVertex3f(-2.5, 0, i)
        i += 0.25
    glEnd()

    glBegin(GL_TRIANGLE_STRIP)
    #Positive y
    glColor3f(1, 1, 1)
    glVertex3f(0, 2, 0)

    glColor3f(1, 0, 0)
    glVertex3f(-1, 0, 0)

    glColor3f(0, 1, 0)
    glVertex3f(1, 0, 0)

    glColor3f(0, 0, 1)
    glVertex3f(0, 0, -1.4)

    glColor3f(1, 1, 1)
    glVertex3f(0, 2, 0)

    glColor3f(1, 0, 0)
    glVertex3f(-1, 0, 0)

    # Negative y

    glColor3f(1, 1, 1)
    glVertex3f(0, -2, 0)

    glColor3f(1, 0, 0)
    glVertex3f(-1, 0, 0)

    glColor3f(0, 1, 0)
    glVertex3f(1, 0, 0)

    glColor3f(0, 0, 1)
    glVertex3f(0, 0, -1.4)

    glColor3f(1, 1, 1)
    glVertex3f(1, 0, -1)

    glColor3f(1, 0, 0)
    glVertex3f(-1, 0, -1)

    # Positive x

    glColor3f(1, 1, 1)
    glVertex3f(2, 0, 0)

    glColor3f(1, 0, 0)
    glVertex3f(0, 1, 0)

    glColor3f(0, 1, 0)
    glVertex3f(0, -1, 0)

    glColor3f(0, 0, 1)
    glVertex3f(0, 0, -1.4)

    glColor3f(1, 1, 1)
    glVertex3f(0, -1, -1)

    glColor3f(1, 0, 0)
    glVertex3f(0, 1, -1)

    # Negative x

    glColor3f(1, 1, 1)
    glVertex3f(-2, 0, 0)

    glColor3f(1, 0, 0)
    glVertex3f(0, 1, 0)

    glColor3f(0, 1, 0)
    glVertex3f(0, -1, 0)

    glColor3f(0, 0, 1)
    glVertex3f(0, 0, -1.4)

    glColor3f(1, 1, 1)
    glVertex3f(0, -1, -1)

    glColor3f(1, 0, 0)
    glVertex3f(0, 1, -1)
    glEnd()
    glFlush()


def main():
    glutInit()
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
    glutInitWindowPosition(100, 100)
    glutInitWindowSize(800, 600)
    glutCreateWindow("Scene in 3D")

    glutDisplayFunc(tri)

    init()
    glutMainLoop()


main()
