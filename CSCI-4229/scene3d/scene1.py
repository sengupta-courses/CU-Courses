# scenev1.py
# Scene in 3D
# CSCI 4229 - Homework 2
# Created by Pourna Sengupta

# This scene is renders a rotating octahedron

# Imports for matplotlib
# Used for vector math and other calculations
# Also used for colors
import numpy as np

# Imports for PyGame
# Used for setting display
import pygame as pg
import matplotlib

# Imports for OpenGL
# Use for rendering animation
from OpenGL.GL import *
from OpenGL.GLU import *
from pygame.locals import *

faces = [[(1, 0, 0), (0, 1, 0), (0, 0, 1)],
         [(1, 0, 0), (0, 0, -1), (0, 1, 0)],
         [(1, 0, 0), (0, 0, 1), (0, -1, 0)],
         [(1, 0, 0), (0, -1, 0), (0, 0, -1)],
         [(-1, 0, 0), (0, 0, 1), (0, 1, 0)],
         [(-1, 0, 0), (0, 1, 0), (0, 0, -1)],
         [(-1, 0, 0), (0, -1, 0), (0, 0, 1)],
         [(-1, 0, 0), (0, 0, -1), (0, -1, 0)]]

blue = matplotlib.cm.get_cmap('Blues')


def curr(face):
    x1 = np.subtract(face[1], face[0])
    x2 = np.subtract(face[2], face[0])
    return np.cross(x1, x2)


def shade(f, c, l):
    currface = curr(f)
    shade_here = 1 - np.dot(currface, l)
    return c(shade_here)


def solid_octahedron():
    for face in faces:
        color = shade(face, blue, (1, 2, 3))
        for vertex in face:
            glColor3fv((color[0], color[1], color[2]))
            glVertex3fv(vertex)


def main():
    pg.init()
    display = (400, 400)
    pg.display.set_mode(display, DOUBLEBUF | OPENGL)

    gluPerspective(45, 1, 0.1, 50.0)

    glTranslatef(0.0, 0.0, -5)

    glEnable(GL_CULL_FACE)
    glEnable(GL_DEPTH_TEST)
    glCullFace(GL_BACK)

    clock = pg.time.Clock()
    while True:
        for event in pg.event.get():
            if event.type == pg.QUIT:
                pg.quit()
                quit()

        clock.tick()
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glRotatef(1, 1, 1, 1)
        glBegin(GL_TRIANGLES)
        solid_octahedron()
        glEnd()
        pg.display.flip()
        pg.time.wait(10)


main()
