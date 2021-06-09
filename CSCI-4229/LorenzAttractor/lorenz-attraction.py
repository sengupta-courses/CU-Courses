# lorenz-attraction.py
# Created by Pourna Sengupta
# June 6, 2021

# Lorenz Attractor Visualization
# CSCI 4229 - Computer Graphics
# Willem Schreuder


from OpenGL.GL import *
from OpenGL.GLUT import *

global width
global height

# Lorenz Attraction Constants
sigma = 10.00
beta = 2.6666
rho = 28

# Constant Environment
# Starting Co-ordinates
x, y, z = 1, 1, 1


def init():
    # Starting Environment Setup
    glClearColor(1.0, 1.0, 1.0, 1.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    glColor3f(1, 1, 1)
    glPointSize(1)


def attraction(lx, ly, lz):
    # Lorenz Attractor Co-ordinate Calculator
    lx = sigma * (ly - lx)
    ly = lx * (rho - lz) - ly
    lz = (lx * ly) - (beta * lz)
    return [lx, ly, lz]


def lorenzplot():
    # Plotting of Lorenz Attractor Visualization
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()

    # Begin in Starting Environment
    # Initialize Point Variables
    ax, ay, az = x, y, z
    # Lorenz Attraction Co-ordinate
    lx, ly, lz = attraction(x, y, z)
    # Time-Step
    dt = 0.001

    # Explicit Euler Integration
    # 50,000 Steps
    # 50 time units where the time-step is 0.001
    glBegin(GL_POINTS)
    for n in range(1, 50000, 1):
        ax += ax + (lx * dt)
        ay += ay + (ly * dt)
        az += az + (lz * dt)
        glVertex3f(ax, ay, az)
    glEnd()

    glFlush()
    glutSwapBuffers()


def main():
    global width
    global height

    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE)
    glWindowPos2i(5, 5)
    glutInitWindowSize(600, 600)
    glutCreateWindow("Lorenz Attractor")
    glutDisplayFunc(lorenzplot)

    init()
    glutMainLoop()


main()
