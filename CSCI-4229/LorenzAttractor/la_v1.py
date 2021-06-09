# la_v1.py
# Lorenz Attractor Visualization

import numpy as np
import matplotlib.pyplot as plt
from OpenGL.GL import *
from OpenGL.GLUT import *

global width
global height

# Lorenz Attractor Constants
sigma = 10
beta = 2.6666
rho = 28

# Time-step Constant
dt = 0.001

# Intializing Arrays
arrX = [50000]
arrY = [50000]
arrZ = [50000]
arrN = [50000]


def init():
    glClearColor(1.0, 1.0, 1.0, 0.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    glPointSize(1)


def calculate(a, b, c, n):
    nx = sigma * (b - a)
    ny = a * (rho - c) - b
    nz = (a * b) - (beta * c)

    a += nx * dt
    b += ny * dt
    c += nz * dt

    arrX.append(a)
    arrY.append(b)
    arrZ.append(c)
    arrN.append(n)

    return [a, b, c]


def iterator():
    # Starting Environment
    x, y, z = 1, 1, 1
    # Append values to
    for n in range(0, 50000, 1):
       x, y, z = calculate(x, y, z, n)

    for j in range(0, 5000, 1):
        glBegin(GL_POINTS)
        glColor4f(1.0, 1.0, 1.0, 0.0)
        glVertex4f(arrX[j], arrY[j], arrZ[j], arrN[j])
        glEnd()

        glBegin(GL_LINE_STRIP)
        glColor4d(1.0, 1.0, 1.0, 0.0)
        glVertex4d(arrX[j], arrY[j], arrZ[j], arrN[j])
        glEnd()
        glFlush()

    glutSwapBuffers()


def main():
    global width
    global height

    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE)
    glutInitWindowSize(500, 500)
    glutCreateWindow("Lorenz Attractor Visualization")
    glutDisplayFunc(iterator)

    init()
    glutMainLoop()

main()

