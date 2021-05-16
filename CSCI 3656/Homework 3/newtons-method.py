
"""
Created on Tue Oct 20 01:22:19 2020

@author: pournasengupta


used http://hplgit.github.io/Programming-for-Computations/pub/p4c/._p4c-solarized-Python031.html 
https://en.wikibooks.org/wiki/Python_Programming/Basic_Math
to help write code 
"""
import sys
import math
import numpy
import matplotlib.pyplot as plt


"Define Newton's Method Function"
"f = intial function f(x) = 0"
"df = derivative of f(x) f'(x)"
"p0 = given initial approximation p_0"
"tol = tolerance -> stopping criteria for |f(x) < tol|"
"n = max number of iterations of newton's method n "
def newtonsMethod(f, df, p0, tol, n):
    
    "create empty arrays to store values"
    astore = []
    bstore = []
    
    "new variable fx to represent f(x) at each iteration of p"
    "f(p0) = f(p_0) initial approximation value"
    "set f(x) = f(p_0)"
    fx = f(p0)
        
    "new variable i iteration counter"
    i = 0
 
    
    "RUN NEWTON'S METHOD FOR N ITERATIONS" 
    "while loop with 2 conditions"
    "|fNorm| > tol and i < n"
    "fNorm must be greater than the tolerance"
    "iteration must be less than max iterations"
    while abs(fx) > tol and i < n: 
        "solve p_i = p_o - (f(p_0)/f'(p_0))"
        "set p_i as new value"
        "p0 = p0 - float(fx)/df(p0)"
        
        try: 
            p0 = p0 - float(fx)/(df(p0))
        except ZeroDivisionError: 
            print("Zero Derivative for x = %f", p0)
            sys.exit("Solution not found")
        
        "update value of fx"
        "fx = f(p_0)"
        fx = f(p0)
        
        "append values to arrays"
        astore.append(p0)
        bstore.append(fx)
        
        "update iterator"
        i +=1
        
        
    if abs(fx) > tol: 
        "update iterator if solution is found"
        "or max number of iterations reached"
        i = -1
    
    return p0, i, astore, bstore
            
def f(p0):
    return (1)/(1 + math.exp(p0)) - 1/2

def df(p0): 
    return -(math.exp(p0))/(1 + math.exp(p0))**2

solution, zeroI, avalues, bvalues = newtonsMethod(f, df, p0 = 0.25, tol=1.0e-14, n=100)

"if the solution is found"
if zeroI > 0: 
    print ("Number of iterations: %d" % (1+2*zeroI))
    print ("Solution: %f" %(solution))
else: 
    print("Solution not found")
    
    

a = numpy.array([i for i in avalues])
b = numpy.array(bvalues)

fig = plt.figure()
plt.plot(a, b, label = 'Newtons Method')
plt.legend()

def f1(x): 
    return numpy.int((1)/(1 + math.exp(x)) - 1/2)

def derive(x): 
    h = 0.000000001
    return (f1(x+h) - f1(x)/h)

def tanLine(): 
    x = numpy.linspace(-5, 5, 100)
    y = x**2 + 2; 
    plt.plot(x, y, 'b-', 'LineWidth', 2);
    plt.grid(True)


    
    xTangent = -4.5;
   
    slope = 2 * xTangent;
    
    yTangent = xTangent**2 + 2;  

    plt.plot(xTangent, yTangent, 'r*', 'LineWidth', 2, 'MarkerSize', 10);
   
    yTangentLine = slope * (x - xTangent) + yTangent;
    plt.plot(x, yTangentLine, 'b-', 'LineWidth', 2);

    
    
    
    
    