import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import math

X = []
Y = []

for x in range(3600):
    X.append(x * 0.1)   
    Y.append(2.0 * math.sqrt(2.0) * math.cos(1.0 * x / 1800.0 * math.pi + math.pi * 0.25) - math.sin(3.0 * x / 1800.0 * math.pi) + math.sin(2.0 * x / 1800.0 * math.pi))

plt.plot(X,Y,'.')


plt.grid(True)
plt.show() 
