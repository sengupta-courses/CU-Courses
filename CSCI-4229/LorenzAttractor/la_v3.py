# la_v3.py
# Lorenz Attractor Visualization
# Inspiration from raymas (Github)
# Created by Pourna Sengupta

import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.animation as animation

from OpenGL.GL import *
from OpenGL.GLUT import *

import time
import sys
import threading

# Lorenz Attractor Constants
sigma = 10
beta = 2.6666
rho = 28

# Time-step Constant
dt = 0.001
path = []


def calculate(x, y, z):
    global sigma
    global beta
    global rho
    global dt

    newX = x + dt * sigma * (y - x)
    newY = y + dt * (x * (rho - z) - y)
    newZ = z + dt * (x * y - beta * z)

    return (newX, newY, newZ)


