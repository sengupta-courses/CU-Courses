import matplotlib.pyplot as plt
import math
import numpy as np
import random
import pylab


def navEff(): 
    w = np.arange(0.0, 1.0, 0.01)
    totalDist = 0.0
    ne = list()
    for i in range(100): 
        #x = v(w[i] * math.cos(thetai + thetaB) + (1.0 - w[i])* math.cos(thetai + thetaC))
        x = (w[i] * math.cos(math.pi/3) + (1.0 - w[i])* math.cos(math.pi/30))
        #y = v(w[i] * math.sin(thetai + thetaB) + (1.0 - w[i])* math.sin(thetai + thetaC))
        y = (w[i] * math.sin(math.pi/3) + (1.0 - w[i])* math.sin(math.pi/30))
        #Navigational Efficiency 
        #NE = Net distance in theta initial direction / total distance 
        d = math.sqrt(math.pow(x, 2) + math.pow(y, 2))
        totalDist = totalDist + d 
        ne.append(d / totalDist)

    #print(ne)
    ne.remove(1.0)
    print(max(ne))

navEff()

