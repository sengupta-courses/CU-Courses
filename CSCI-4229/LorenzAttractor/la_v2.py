# la_v2.py
# Lorenz Attractor Visualization

# Imports for Math
import matplotlib.pyplot as plt

# Imports for OpenGL and GLUT
from OpenGL.GL import *
from OpenGL.GLUT import *

# Global width & height
global width
global height

# Correct Here: Create global arrays for integrated x, y, z, and count
# Count is an array from 0 to 50000

# Other Idea... Use a pandas dataframe (comes with built in counter column)
# Allows for easy data access but not sure if it works with OpenGL

# Local Save Location for Program Output
save = '/Users/pournasengupta/Documents/GitHub/CU-Courses/CSCI-4229/LorenzAttractor/visual-outputs'

# Lorenz Attractor Constants
sigma = 10.0
rho = 28.0
beta = 2.6666

# Time Units (50,000 Iterations)
# Start: 0.0
# End: 50.0
steps = 50.0

# Step Interval
dt = 0.001


def init():
    glClearColor(1.0, 1.0, 1.0, 0.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    glPointSize(1)
# Starting Function
# Set Up OpenGL Environment


def calculate(currSys):
    # Set cx, cy, & cz to current system values of x, y, & z
    cx, cy, cz = currSys

    # Lorenz Attractor Co-ordinates
    # Calculate new co-ordinates
    nx = sigma * (cy - cx)
    ny = cx * (rho - cz) - cy
    nz = (cx * cy) - (beta * cz)

    # Integrated Lorenz Attractor Co-ordinates
    # Correct Here: Append to global individual arrays and return (to main)
    # Calculate using step interval (differentiation value)
    cx += nx * dt
    cy += ny * dt
    cz += nz * dt
    return cx, cy, cz
# Calculate Lorenz Attractor Co-ordinates


def plot(xp, yp, zp, n) -> void:
    # Correct Here: xp, yp, and zp are arrays of co-ordinates
    fig = plt.figure(figsize=(12, 9))
    ax = fig.add_subplot(111, projection='3d')

    # Set Pane Color for each axis
    ax.xaxis.set_pane_color((1, 1, 1, 1))
    ax.yaxis.set_pane_color((1, 1, 1, 1))
    ax.zaxis.set_pane_color((1, 1, 1, 1))

    # Plot each co-ordinate on x, y, & z axes
    # GL_POINTS or GL_LINE_STRIP???
    glBegin(GL_POINTS)
    glColor3f(1.0, 1.0, 1.0)
    glVertex3d(xp, yp, zp)
    glEnd()

    # Not sure how to use these effectively
    glFlush()
    glutSwapBuffers()

    # Set Axis Limits
    ax.xaxis.set_xlim((-30, 30))
    ax.y.axis.set_ylim((-30, 30))
    ax.zaxis.set_zlim((0, 60))

    # Set Figure Title
    plt.set_title('Lorenz Attractor System - Visualization')

    # Save Figure as PNG
    plt.savefig('{}/{:03d}.png'.format(save, n), dpi=60, bbox_inches='tight', pad_inches=0.1)
    plt.close()
# Plot Co-Ordinates using OpenGL


def main():
    # original environment
    ox, oy, oz = 0.1, 0, 0
    nx, ny, nz = 0
    # update current system
    currsys = ox, oy, oz
    # Explicit Euler Integration
    # 50
    # 50,000 Iterations
    maxIter = steps * dt
    for i in range(0, maxIter):
        # Calculate for each current system
        # Correct Here: Append to individual arrays for x, y, and z
        nx, ny, nz = calculate(currsys)
        currsys = nx, ny, nz
    # Correct Here: Pass arrays through to plotting function
    plot(nx, ny, nz, i)

    # Begin Program
    init()
    glutMainLoop()


main()
# Call to Main Program

