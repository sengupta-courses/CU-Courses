# scenev3.py
# Scene in 3D
# CSCI 4229 - Homework 2
# Created by Pourna Sengupta

# This scene renders 2 lumpy eyes and a nose
# The scene can be viewed using mouse movement
# The escape and return keys can be used to quit the program
# The p key can be used to pause the program


import pygame as pg
from pygame.locals import *
from numpy import *
from OpenGL.GL import *
from OpenGL.GLU import *


def init():
    glEnable(GL_DEPTH_TEST)
    glEnable(GL_LIGHTING)
    glShadeModel(GL_SMOOTH)
    glEnable(GL_COLOR_MATERIAL)
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE)

    glEnable(GL_LIGHT0)
    glLightfv(GL_LIGHT0, GL_AMBIENT, [0.5, 0.5, 0.5, 1])
    glLightfv(GL_LIGHT0, GL_DIFFUSE, [1.0, 1.0, 1.0, 1])

def triangle():
    glBegin(GL_TRIANGLE_STRIP)
    glColor3f(1, 1, 1)
    glVertex3f(0, 4, 0)

    glColor3f(1, 0, 0)
    glVertex3f(-2, 0, 0)

    glColor3f(0, 1, 0)
    glVertex3f(2, 0, 0)

    glColor3f(0, 0, 1)
    glVertex3f(0, 0, -2.8)

    glColor3f(1, 1, 1)
    glVertex3f(0, 4, 0)

    glColor3f(1, 0, 0)
    glVertex3f(-2, 0, 0)
    glEnd()

    glFlush()


def sphere():
    lats = 4
    longs = 4
    r = 2

    for i in range(lats):
        lat0 = pi * (-0.5 + i / lats)
        z0 = sin(lat0)
        zr0 = cos(lat0)

        lat1 = pi * (-0.5 + (i+1) / lats)
        z1 = sin(lat1)
        zr1 = cos(lat1)

        glBegin(GL_QUAD_STRIP)
        for j in range(longs+1):
            lng = 2 * pi * (j+1) / longs
            x = cos(lng)
            y = sin(lng)

            glNormal(x * zr0, y * zr0, z0)
            glVertex(r * x * zr0, r * y * zr0, r * z0)
            glNormal(x * zr1, y * zr1, z1)
            glVertex(r * x * zr1, r * y * zr1, r * z1)

        glEnd()
        glFlush()


def main():
    pg.init()
    display = (1500, 1500)
    screen = pg.display.set_mode(display, DOUBLEBUF | OPENGL)
    init()

    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)

    glMatrixMode(GL_MODELVIEW)
    gluLookAt(0, -10, -2, 0, 0, -2, 0, 0, 1)
    viewMatrix = glGetFloatv(GL_MODELVIEW_MATRIX)
    glLoadIdentity()

    # init mouse movement and center mouse on screen
    displayCenter = [screen.get_size()[i] // 2 for i in range(2)]
    mouseMove = [0, 0]
    pg.mouse.set_pos(displayCenter)

    angle = 0.0
    paused = False
    run = True
    while run:
        for event in pg.event.get():
            if event.type == pg.QUIT:
                run = False
            if event.type == pg.KEYDOWN:
                if event.key == pg.K_ESCAPE or event.key == pg.K_RETURN:
                    run = False
                if event.key == pg.K_p:
                    paused = not paused
                    pg.mouse.set_pos(displayCenter)
            if not paused:
                if event.type == pg.MOUSEMOTION:
                    mouseMove = [event.pos[i] - displayCenter[i] for i in range(2)]
                pg.mouse.set_pos(displayCenter)

        if not paused:
            keypress = pg.key.get_pressed()
            glLoadIdentity()
            angle += mouseMove[1]*0.1
            glRotatef(angle, 1.0, 0.0, 0.0)

            glPushMatrix()
            glLoadIdentity()

            if keypress[pg.K_w]:
                glTranslatef(0,0,0.1)
            if keypress[pg.K_s]:
                glTranslatef(0,0,-0.1)
            if keypress[pg.K_d]:
                glTranslatef(-0.1,0,0)
            if keypress[pg.K_a]:
                glTranslatef(0.1,0,0)

            glRotatef(mouseMove[0]*0.1, 0.0, 1.0, 0.0)
            glMultMatrixf(viewMatrix)
            viewMatrix = glGetFloatv(GL_MODELVIEW_MATRIX)
            glPopMatrix()

            glMultMatrixf(viewMatrix)
            glLightfv(GL_LIGHT0, GL_POSITION, [1, -1, 1, 0])

            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

            glPushMatrix()
            glColor4f(0.5, 0.5, 0.5, 1)
            glBegin(GL_QUADS)
            glVertex3f(-10, -10, -2)
            glVertex3f(10, -10, -2)
            glVertex3f(10, 10, -2)
            glVertex3f(-10, 10, -2)
            glEnd()

            triangle()
            glTranslatef(1.5, 0, 0)
            glColor4f(0.35, 0.50, 0.25, 1)
            sphere()
            glTranslatef(-3, 0, 0)
            glColor4f(.82, 0.35, .75, 1)
            sphere()
            glPopMatrix()

            pg.display.flip()
            pg.time.wait(10)

    pg.quit()


main()
