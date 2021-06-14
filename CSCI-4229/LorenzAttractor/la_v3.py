# la_v3.py
# Lorenz Attractor Visualization
# Created by Pourna Sengupta

# Imports for OpenGL and OpenGLU
import OpenGL.GL as gl
import OpenGL.GLU as glu

# Imports to Simulate Lorenz Attractor
import pygame
from pygame.locals import *

# Locally Accessible Variables
# Simulation Constants
x = 0.01
y = 0
z = 0
count = 0

display = (1250, 950)
angle = 0.01


def calculate_lorenz(x, y, z, count):
    # Set Lorenz Parameters
    # Time Step
    dt = 0.01
    # Sigma
    s = 10.0
    # Rho
    r = 28
    # Beta
    b = (8/3)
    dx, dy, dz = 0, 0, 0

    # Simulate 50,000 Steps
    while count != 10000:
        # Set Color
        gl.glColor3d(1, 1, 1)

        # Lorenz Attractor Differential Equations
        dx = (s * (y - x)) * dt
        dy = (x * (r - z) - y) * dt
        dz = (x * y - b * z) * dt

        # Plot x, y, z as it is simulated
        x += dx
        y += dy
        z += dz
        count += 1
        gl.glColor3d(1, 1, 1)
        gl.glVertex3d(z, y, z, count)

# Calculation Function: Takes in x, y, z, and count (current state)
# Calculates lorenz attractor differentials


def plot(angle):
    # Initialize instance of pygame
    pygame.init()

    # Set display for OpenGL
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)
    glu.gluPerspective(45, (display[0]/display[1]), 0.1, 1500)

    gl.glVertex3d(0, 0, -1)
    gl.glRotatef(0, 0, 0, 0)

    clock = pygame.time.Clock()
    while True:
        # Quit instance of Pygame
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        clock.tick()

        gl.glClear(gl.GL_COLOR_BUFFER_BIT|gl.GL_DEPTH_BUFFER_BIT)

        # Zoom out and translate the points after rotation
        if angle < 1:
            gl.glRotatef(angle, -0.5, -angle, -5)
            gl.glTranslatef(0, 0, -0.5)
        # Zoom in and translate the points after rotation
        if angle > 1:
            gl.glRotatef(0.9, 5, 1, -1)
            gl.glTranslatef(0, 0, 0.01)

        # Set Plotting Guidelines
        gl.glEnable(gl.GL_POINT_SMOOTH)
        gl.glPointSize(1)

        # Begin Plotting
        gl.glBegin(gl.GL_POINTS)
        calculate_lorenz(x, y, z, count)
        gl.glEnd()

        # Adjust Display
        pygame.display.flip()
        angle += 0.005
# Plot Function: Set up pygame instance & display, plot using OpenGL


plot(angle)
# Main Function: Call to Plot Function, pass angle as parameter
